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

#ifndef PLAYER_STATE_H
#define PLAYER_STATE_H

#include "PSM.h"
#include "PSMIface.h"
#include "State.h"
#include "DVDPlayer.h"

class PlayerState : public State, public PlayerInterface
{
    public:
        PlayerState(StateId_t stateId, const char *name,
                    StateMachine* pStateMachine);

        // Default/common implementations
        virtual int Play(void);
        virtual int Pause(void);
        virtual int Stop(void);
        virtual int FastForward(void);
        virtual int FastReverse(void);
        virtual int ChapterUp(void);
        virtual int ChapterDown(void);
};

#endif

// To enable vim modelines:
// put "set modeline" and "set modelines=5" in ~/.vimrc
// vim:ts=4 sw=4 tw=80 expandtab smartindent
