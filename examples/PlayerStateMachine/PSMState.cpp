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

// Constructor.
//
// stateId - the ID of this state object
// pStateMachine - the state machine to which this state object belongs
PlayerState::PlayerState(StateId_t stateId, const char *name,
                         StateMachine* pStateMachine) :
	State(stateId, name, pStateMachine)
{
    cout << "   Creating state: " << name << endl;
}

int
PlayerState::Play(void)
{   
    cout << "State:" << GetName()
         << " Play pressed, going to Playing State." << endl;
                     
    return GetStateMachine()->ChangeState(ePlayerStatePlaying);
}

int
PlayerState::Pause(void)
{   
    cout << "State:" << GetName()
         << " Pause pressed, going to Paused State." << endl;

    return GetStateMachine()->ChangeState(ePlayerStatePaused);
}

int
PlayerState::Stop(void)
{
    cout << "State:" << GetName()
         << " Stop pressed, going to Stopped State." << endl;
                     
    return GetStateMachine()->ChangeState(ePlayerStateStopped);
}   

int
PlayerState::FastForward(void)
{
    cout << "State:" << GetName()
         << " FastForward, going to FastForward State." << endl;

    return GetStateMachine()->ChangeState(ePlayerStateFF);
}

int
PlayerState::FastReverse(void)
{
    cout << "State:" << GetName()
         << " FastReverse pressed, going to FastReverse State." << endl;

    return GetStateMachine()->ChangeState(ePlayerStateFR);
}

int
PlayerState::ChapterUp(void)
{
    int newChapter = DVDGetChapter()+1;

    cout << "State:" << GetName()
         << " ChapterUp pressed, changing chapter to " << newChapter
         << " and going to Playing State." << endl;

    DVDSetChapter(newChapter);

    return GetStateMachine()->ChangeState(ePlayerStatePlaying);
}

int
PlayerState::ChapterDown(void)
{
    int chapter = DVDGetChapter();

    if (chapter > 1)
        --chapter;

    cout << "State:" << GetName()
         << " ChapterDown pressed, changing chapter to " << chapter
         << " and going to Playing State." << endl;

    DVDSetChapter(chapter);

    return GetStateMachine()->ChangeState(ePlayerStatePlaying);
}

// To enable vim modelines:
// put "set modeline" and "set modelines=5" in ~/.vimrc
// vim:ts=4 sw=4 tw=80 expandtab smartindent
