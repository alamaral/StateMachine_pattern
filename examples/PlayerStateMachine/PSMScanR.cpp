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

#include "PSMScanR.h"

// Constructor.
//
// pStateMachine - the state machine to which this state belongs
PlayerStateScanReverse::PlayerStateScanReverse(StateMachine* pStateMachine) :
    PlayerState(ePlayerStateScanR, "ScanReverse", pStateMachine),
    m_Speed(minScanSpeed)
{

}

int
PlayerStateScanReverse::EnterState(void)
{
    m_Speed = minScanSpeed;

    cout << "State:" << GetName()
         << " Enter speed:" << -1.0/m_Speed << endl;

    DVDSetPlayerSpeed(-1.0/m_Speed);

    return 0;
}   

int
PlayerStateScanReverse::FastForward(void)
{
    cout << "State:" << GetName()
         << " FastReverse pressed, going to ScanReverse State."
         << endl;

    return GetStateMachine()->ChangeState(ePlayerStateScanF);

    return 0;
}

int
PlayerStateScanReverse::FastReverse(void)
{
    if (m_Speed < maxScanSpeed) {
        m_Speed = m_Speed * scanMult + scanIncr;

        cout << "State:" << GetName()
             << " Incremented ScanReverse speed: "
             << -1.0/m_Speed << endl;

        DVDSetPlayerSpeed(-1.0/m_Speed);
    } else {
        cout << "State:" << GetName()
             << " FastReverse pressed, NOP." << endl;
    }

    return 0;
}

// To enable vim modelines:
// put "set modeline" and "set modelines=5" in ~/.vimrc
// vim:ts=4 sw=4 tw=80 expandtab smartindent
