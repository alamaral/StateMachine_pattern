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

#include "PSMFR.h"

// Constructor.
//
// pStateMachine - the state machine to which this state belongs
PlayerStateFastReverse::PlayerStateFastReverse(StateMachine* pStateMachine) :
    PlayerState(ePlayerStateFR, "FastReverse", pStateMachine),
    m_Speed(minFastSpeed)
{

}


int
PlayerStateFastReverse::EnterState()
{  
    m_Speed = minFastSpeed;

    cout << "State:" << GetName()
         << " Entering FastReverse State speed: "
         << m_Speed << endl;

    DVDSetPlayerSpeed(-m_Speed);

    return 0;
}

int
PlayerStateFastReverse::FastForward(void)
{
    cout << "State:" << GetName()
         << " FastForward pressed, going to FastForward." << endl;

    return GetStateMachine()->ChangeState(ePlayerStateFF);
}

int
PlayerStateFastReverse::FastReverse(void)
{
    if (m_Speed < maxFastSpeed) {
        m_Speed = m_Speed * fastMult + fastIncr;

        cout << "State:" << GetName()
             << " Incremented FastReverse speed: "
             << m_Speed << endl;

        DVDSetPlayerSpeed(-m_Speed);
    } else {
        cout << "State:" << GetName()
             << " FastReverse pressed, NOP." << endl;
    }

    return 0;
}

// To enable vim modelines:
// put "set modeline" and "set modelines=5" in ~/.vimrc
// vim:ts=4 sw=4 tw=80 expandtab smartindent
