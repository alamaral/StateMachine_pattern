/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Alan Amaral
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef PLAYER_STATE_MACHINE_H
#define PLAYER_STATE_MACHINE_H

#include <string>
#include <iostream>

#include "StateMachine.h"
#include "PSMState.h"
#include "PSMIface.h"

using namespace std;

// Player states
typedef enum {
	ePlayerStateStopped,
	ePlayerStatePlaying,
	ePlayerStatePaused,

    ePlayerStateFF,
    ePlayerStateFR,

    ePlayerStateScanF,
    ePlayerStateScanR,

    NPlayerStates           // Must be last
} ePlayerState;

// Values for fast forward and reverse
// When incrementing calculate new speed as speed = speed * fastMult + fastIncr;
static const int minFastSpeed = 2;
static const int maxFastSpeed = 16;
static const int fastMult = 2;
static const int fastIncr = 0;

// Values for scan forward and reverse
// When incrementing calculate new speed as speed = speed * scanMult + scanIncr;
static const int minScanSpeed = 2;
static const int maxScanSpeed = 16;
static const int scanMult = 2;
static const int scanIncr = 0;

class PlayerStateMachine : public StateMachine,
                           public PlayerInterface
{
    public:
        PlayerStateMachine(void);
        virtual ~PlayerStateMachine(void);

        virtual State *CreateState(StateId_t);
        virtual int setHavePlayPause(bool havePlayPause)
            { m_PlayPauseButton = havePlayPause; return 0; };

        // From PlayerInterface
        virtual int Play (void);
        virtual int Pause(void);
        virtual int Stop(void);
        virtual int FastForward(void);
        virtual int FastReverse(void);
        virtual int ChapterUp(void);
        virtual int ChapterDown(void);

    private:
        bool m_PlayPauseButton;
};
	
#endif

// To enable vim modelines:
// put "set modeline" and "set modelines=5" in ~/.vimrc
// vim:ts=4 sw=4 tw=80 expandtab smartindent
