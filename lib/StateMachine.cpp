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

#include "StateMachine.h"

StateMachine::StateMachine(unsigned nStates) :
    m_pCurrentState(NULL),
    m_nStates(nStates)
{
    // Allocate the state array
    State **states = new State*[nStates];

    // Initialize the state array
    for (unsigned i = 0; i < nStates; i++) {
        states[i] = NULL;
    }

    m_pStates = states;
}

StateMachine::~StateMachine(void)
{
    // Destroy the state objects, if any
    for (unsigned i = 0; i < m_nStates; i++) {
        if (m_pStates[i]) {
            delete m_pStates[i];
            m_pStates[i] = NULL;
        }
    }

    // Free the state array
    delete[] m_pStates;
}

int
StateMachine::AddInitialState(State* pState)
{
    AddState(pState);

    return ChangeState(pState->GetId());
}

// This may be used by the state machine to preload
// some or all of the required states, rather than
// having them created when needed.  Or, the states
// can delete themselves when ExitState is called.
// This can be useful on memory limited machines
// where having a bunch of states using up memory
// is undesirable.
int
StateMachine::AddState(State* pState)
{
    int rtn = 0;
    StateId_t s = pState->GetId();

    if (s < m_nStates) {
        m_pStates[s] = pState;
    } else {
        cout << "ERROR: StateId " << s
             << " is out of range" << endl;
        rtn = -1;
    }

    return rtn;
}

// Remove a state from the state array
int
StateMachine::RemoveState(State* pState)
{
    int rtn = 0;
    StateId_t s = pState->GetId();

    if (s < m_nStates && m_pStates[s]) {
        m_pStates[s] = NULL;
    } else {
        cout << "ERROR: StateId " << s
             << " is out of range" << endl;
        rtn = -1;
    }

    return rtn;
}

// Switch to a given state
int
StateMachine::ChangeState(StateId_t newStateId)
{
    State* pState = NULL;
    int rtn = 0;

    // Validate the requested stateId.
    if (newStateId < m_nStates) {
        pState = m_pStates[newStateId];

        // Doesn't exist, ask the subclassed state machine
        // to create the state for us.
        if (pState == NULL) {

            pState = CreateState(newStateId);

            if (pState) {
                m_pStates[newStateId] = pState;
            } else {
                // It can't...
                cout << "ERROR: Target state "
                     << newStateId
                     << " does not exist in this state machine."
                     << endl;

                rtn = -1;
            }
        }

        if (pState && m_pCurrentState != pState) {
            if (m_pCurrentState != NULL) {
                rtn = m_pCurrentState->ExitState();
            }

            // If ExitState failed, don't enter the new state.
            if (!rtn) {

                // Order here is important.
                m_pCurrentState = pState;

                // Enter the state
                rtn = pState->EnterState();
            } else {
                // Error creating the new state
                cout << "ERROR: creation of StateId " << newStateId
                     << " failed" << endl;
            }
        }
    } else {
        // Error: new state id is bad
        cout << "ERROR: StateId " << newStateId
             << " is out of range" << endl;

        rtn = -1;
    }

    return rtn;
}

// To enable vim modelines:
// put "set modeline" and "set modelines=5" in ~/.vimrc
// vim:ts=4 sw=4 tw=80 expandtab smartindent
