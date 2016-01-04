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

#ifndef STATE_MACHINE_OWNER_H
#define STATE_MACHINE_OWNER_H

#include "StateMachine.h"

template <class StateMachineType, class StateType>
class StateMachineOwner
{
    public:
        StateMachineOwner(void);
        virtual ~StateMachineOwner(void);

        StateType* GetState(void) const;

        StateMachineType* GetStateMachine(void) const;

    private:
        StateMachineType* m_pStateMachine;
};

template <class StateMachineType, class StateType>
StateMachineOwner<StateMachineType, StateType>::StateMachineOwner(void) :
   m_pStateMachine(new StateMachineType())
{

}

template <class StateMachineType, class StateType>
StateMachineOwner<StateMachineType, StateType>::~StateMachineOwner(void)
{
    delete m_pStateMachine;
    m_pStateMachine = NULL;
}

template <class StateMachineType, class StateType>
inline StateType*
StateMachineOwner<StateMachineType, StateType>::GetState(void) const
{
    return m_pStateMachine->GetCurrentState();
}

template <class StateMachineType, class StateType>
inline StateMachineType*
StateMachineOwner<StateMachineType, StateType>::GetStateMachine(void) const
{
    return m_pStateMachine;
}

#endif

// To enable vim modelines:
// put "set modeline" and "set modelines=5" in ~/.vimrc
// vim:ts=4 sw=4 tw=80 expandtab smartindent
