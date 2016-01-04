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

#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "State.h"

class StateMachine
{
    public:

        StateMachine(unsigned nStates);
        virtual ~StateMachine(void);

        State* GetCurrentState(void) const
            { return m_pCurrentState; };

        // Change to the state specified
        virtual int ChangeState(StateId_t newStateId);

        // Remove an existing state the state machine.
        virtual int RemoveState(State* pState);

    protected:

        // Add the initial state into the state machine.
        virtual int AddInitialState(State* pState);

        // Add a new state into the state machine.
        virtual int AddState(State* pState);

        // Callback into derived state machine to ask it
        // to create a new state.
        virtual State* CreateState(StateId_t) { return NULL; };

    private:
        // Current state
        State* m_pCurrentState;

        // Number of states, and state array
        unsigned const m_nStates;
        State** m_pStates;
};

#endif

// To enable vim modelines:
// put "set modeline" and "set modelines=5" in ~/.vimrc
// vim:ts=4 sw=4 tw=80 expandtab smartindent
