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

#include "PSMPaused.h"

// Constructor.
//
// pStateMachine - the state machine to which this state belongs
PlayerStatePaused::PlayerStatePaused(StateMachine* pStateMachine) :
    PlayerState(ePlayerStatePaused, "Paused", pStateMachine)
{

}

int
PlayerStatePaused::EnterState()
{  
    cout << "State:" << GetName()
         << " Entering Paused State." << endl;

    DVDSetPlayerSpeed(0.0);

    return 0;
}

int
PlayerStatePaused::Pause(void)
{
    cout << "State:" << GetName()
         << " Pause pressed, NOP." << endl;

    return 0;
}

int
PlayerStatePaused::FastForward(void)
{
    cout << "State:" << GetName()
         << " FastForward pressed, going to ScanForward State."
         << endl;

    return GetStateMachine()->ChangeState(ePlayerStateScanF);
}

int
PlayerStatePaused::FastReverse(void)
{
    cout << "State:" << GetName()
         << " FastReverse pressed, going to ScanReverse State."
         << endl;

    return GetStateMachine()->ChangeState(ePlayerStateScanR);
}

int
PlayerStatePausedNP::Pause(void)
{
    cout << "State:" << GetName()
         << " Pause pressed, going to Playing State." << endl;

    return GetStateMachine()->ChangeState(ePlayerStatePlaying);
}

// To enable vim modelines:
// put "set modeline" and "set modelines=5" in ~/.vimrc
// vim:ts=4 sw=4 tw=80 expandtab smartindent
