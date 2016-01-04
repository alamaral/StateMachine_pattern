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

#include "PSM.h"

#include "PSMStopped.h"
#include "PSMPlaying.h"
#include "PSMPaused.h"
#include "PSMFF.h"
#include "PSMFR.h"
#include "PSMScanF.h"
#include "PSMScanR.h"

PlayerStateMachine::PlayerStateMachine(void) :
    StateMachine(NPlayerStates)
{
    // Maybe move this into an init function
    PlayerState *initialState = new PlayerStateStopped(this);

    if (AddInitialState(initialState)) {
        cout << "ERROR Adding initial state!" << endl;
    }
}

PlayerStateMachine::~PlayerStateMachine(void)
{

}

State* PlayerStateMachine::CreateState(StateId_t id)
{
    PlayerState *newState = NULL;

    switch (id) {
        case ePlayerStateStopped:
            newState = new PlayerStateStopped(this);
        break;

        case ePlayerStatePlaying:
            newState = new PlayerStatePlaying(this);
        break;

        case ePlayerStatePaused:
            if (m_PlayPauseButton)
                newState = new PlayerStatePausedNP(this);
            else
                newState = new PlayerStatePaused(this);
        break;

        case ePlayerStateFF:
            newState = new PlayerStateFastForward(this);
        break;

        case ePlayerStateFR:
            newState = new PlayerStateFastReverse(this);
        break;

        case ePlayerStateScanF:
            newState = new PlayerStateScanForward(this);
        break;

        case ePlayerStateScanR:
            newState = new PlayerStateScanReverse(this);
        break;

        default:
            cout << "Bad state id: " << id << endl;
        break;
    }

    return newState;
}

int
PlayerStateMachine::Play(void)
{
    cout << endl
         << ">>> Play pressed, calling into state machine." << endl;

    return static_cast<PlayerState*>(GetCurrentState())->Play();
}

int
PlayerStateMachine::Pause(void)
{
    cout << endl
         << ">>> Pause pressed, calling into state machine." << endl;

    return static_cast<PlayerState*>(GetCurrentState())->Pause();
}

int
PlayerStateMachine::Stop(void)
{
    cout << endl
         << ">>> Stop pressed, calling into state machine." << endl;

    return static_cast<PlayerState*>(GetCurrentState())->Stop();
}

int
PlayerStateMachine::FastForward(void)
{
    cout << endl
         << ">>> FastForward pressed, calling into state machine."
         << endl;

    return static_cast<PlayerState*>(GetCurrentState())->FastForward();
}

int
PlayerStateMachine::FastReverse(void)
{
    cout << endl
         << ">>> FastReverse pressed, calling into state machine."
         << endl;

    return static_cast<PlayerState*>(GetCurrentState())->FastReverse();
}

int
PlayerStateMachine::ChapterUp(void)
{
    cout << endl
         << ">>> ChapterUp pressed, calling into state machine."
         << endl;

    return static_cast<PlayerState*>(GetCurrentState())->ChapterUp();
}

int
PlayerStateMachine::ChapterDown(void)
{
    cout << endl
         << ">>> ChapterDown pressed, calling into state machine."
         << endl;

    return static_cast<PlayerState*>(GetCurrentState())->ChapterDown();
}

// To enable vim modelines:
// put "set modeline" and "set modelines=5" in ~/.vimrc
// vim:ts=4 sw=4 tw=80 expandtab smartindent
