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

#include <string>
#include <iostream>

using namespace std;

#include <stdlib.h>
#include <sys/time.h>

#include "Player.h"
#include "PSM.h"

// Constructor.
Player::Player(void) :
    StateMachineOwner<PlayerStateMachine, PlayerState>()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    
    for (unsigned i = 0; i < NPlayerStates; i++) {
        for (unsigned j = 0; j < NPlayerStates; j++) {
            m_tested[i][j] = 0;
        }
    }

    srand(tv.tv_usec);

    PlayerStateMachine* pSM = GetStateMachine();

    pSM->setHavePlayPause(false);
}

// Destructor.
Player::~Player(void)
{
    for (unsigned i = 0; i < NPlayerStates; i++) {
        cout << endl << m_stateNames[i] << "->" << endl;
        for (unsigned j = 0; j < NPlayerStates; j++) {
            cout << "    " << m_stateNames[j] << " = "
                 << m_tested[i][j] << endl;
        }
    }
}

int Player::Test(void)
{
    StateId_t from, to;
    PlayerStateMachine* pSM = GetStateMachine();
    unsigned s = rand() % NButtons;

    from = pSM->GetCurrentState()->GetId();
    if (m_stateNames[from] == "")
        m_stateNames[from] = pSM->GetCurrentState()->GetName();

    switch (s) {
        case 0: pSM->Play();        break;
        case 1: pSM->Pause();       break;
        case 2: pSM->Stop();        break;
        case 3: pSM->FastForward(); break;
        case 4: pSM->FastReverse(); break;
        case 5: pSM->ChapterUp();   break;
        case 6: pSM->ChapterDown(); break;
    }

    to = pSM->GetCurrentState()->GetId();
    if (m_stateNames[to] == "")
        m_stateNames[to] = pSM->GetCurrentState()->GetName();

    m_tested[from][to]++;

    return 0;
}

// To enable vim modelines:
// put "set modeline" and "set modelines=5" in ~/.vimrc
// vim:ts=4 sw=4 tw=80 expandtab smartindent
