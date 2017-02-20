//
//  Editor.cpp
//  memo
//
//  Created by Nathan Spencer on 2/17/17.
//  Copyright © 2017 Nathan Spencer. All rights reserved.
//

#include "Editor.hpp"
#include "String.hpp"

Editor::Editor()
{
    int screenHeight, screenWidth;
    getmaxyx(stdscr, screenHeight, screenWidth);
    
    m_height = screenHeight - (EDITOR_BORDER_SIZE * 2);
    m_width = screenWidth - (EDITOR_BORDER_SIZE * 8) - SIDEBAR_WIDTH - DIVIDER_WIDTH;
    
    if(m_height > 20)
    {
        m_height = 20;
    }
    
    if(m_width > 55)
    {
        m_width = 55;
    }
    
    m_window = newwin(m_height, m_width, EDITOR_BORDER_SIZE, (EDITOR_BORDER_SIZE * 6) + SIDEBAR_WIDTH + DIVIDER_WIDTH);
    m_divider = newwin(m_height + 2, DIVIDER_WIDTH + (EDITOR_BORDER_SIZE * 2), EDITOR_BORDER_SIZE - 1, (EDITOR_BORDER_SIZE * 4) + SIDEBAR_WIDTH);
    m_sidebar = newwin(m_height, SIDEBAR_WIDTH, EDITOR_BORDER_SIZE, (EDITOR_BORDER_SIZE * 2));
    
    scrollok(m_window, true);
    wborder(m_divider, 0, ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(m_divider);
    WriteSidebar();
    
    keypad(m_window, TRUE);
    m_cursorIndex = 0;
    m_text = "";
    
    m_insertMode = false;
    m_isClosed = false;
}

Editor::~Editor()
{
    
}

void Editor::Update()
{
    int keystroke = wgetch(m_window);
    switch(keystroke)
    {
        case KEY_DOWN:
            DownArrow();
            break;
        case KEY_UP:
            UpArrow();
            break;
        case KEY_LEFT:
            LeftArrow();
            break;
        case KEY_RIGHT:
            RightArrow();
            break;
        case KEY_HOME:
            Home();
            break;
        case KEY_BACKSPACE_UNIX:
            Backspace();
            break;
        case KEY_IC:
            Insert();
            break;
        case KEY_ENTER:
            Enter();
            break;
        default:
            AddToText(keystroke);
            break;
    }
    
    werase(m_window);
    for(char character : m_text)
    {
        waddch(m_window, character);
    }
    
    SetCursorDisplay();
    wrefresh(m_window);
}

bool Editor::GetIsClosed()
{
    return m_isClosed;
}

void Editor::Close()
{
    endwin();
    m_isClosed = true;
}

void Editor::WriteSidebar()
{
    for(char character : m_datestamp)
    {
        waddch(m_sidebar, character);
    }
    wmove(m_sidebar, 1, 0);
    
    for(char character : m_timestamp)
    {
        waddch(m_sidebar, character);
    }
    wrefresh(m_sidebar);
}

void Editor::DownArrow()
{
    int oldX, oldY, newX, newY, originalCursorIndex;
    originalCursorIndex = m_cursorIndex;
    getyx(m_window, oldY, oldX);
    getyx(m_window, newY, newX);
    
    while(newX < oldX || newY == oldY)
    {
        m_cursorIndex++;
        SetCursorDisplay();
        getyx(m_window, newY, newX);
        if(newX > oldX && newY != oldY)
        {
            m_cursorIndex--;
        }
        if(m_cursorIndex >= m_text.size())
        {
            m_cursorIndex = (int)m_text.size();
            break;
        }
    }
}

void Editor::UpArrow()
{
    int oldX, oldY, newX, newY;
    getyx(m_window, oldY, oldX);
    
    if(oldY > 0)
    {
        getyx(m_window, newY, newX);
        while(newX > oldX || newY == oldY)
        {
            m_cursorIndex--;
            SetCursorDisplay();
            getyx(m_window, newY, newX);
        }
    }
    else
    {
        m_cursorIndex = 0;
    }
}

void Editor::LeftArrow()
{
    if(m_cursorIndex > 0)
    {
        m_cursorIndex--;
    }
}

void Editor::RightArrow()
{
    if(m_cursorIndex < m_text.size())
    {
        m_cursorIndex++;
    }
}

void Editor::Backspace()
{
    if(m_cursorIndex > 0)
    {
        m_text.erase(m_cursorIndex - 1, 1);
        m_cursorIndex--;
    }
}

void Editor::Home()
{
    m_cursorIndex /= m_width;
}

void Editor::Insert()
{
    m_insertMode = !(m_insertMode);
}

void Editor::Enter()
{
    m_text.insert(m_cursorIndex++, 1, '\n');
}

void Editor::AddToText(char keystroke)
{
    if(m_insertMode)
    {
        m_text.erase(m_cursorIndex, 1);
    }
    m_text.insert(m_cursorIndex++, 1, keystroke);
}

void Editor::SetCursorDisplay()
{
    int cursorDisplayIndex = 0;
    for(int i = 0; i < m_cursorIndex; i++)
    {
        if(m_text[i] == '\n')
        {
            cursorDisplayIndex += (m_width - (cursorDisplayIndex % m_width));
        }
        else if(m_text[i] == '\t')
        {
            if(((TAB_SIZE - ((cursorDisplayIndex % m_width) % TAB_SIZE)) + (cursorDisplayIndex % m_width)) > m_width)
            {
                cursorDisplayIndex += (m_width - (cursorDisplayIndex % m_width));
            }
            else
            {
                cursorDisplayIndex += (TAB_SIZE - ((cursorDisplayIndex % m_width) % TAB_SIZE));
            }
        }
        else
        {
            cursorDisplayIndex++;
        }
        
    }
    wmove(m_window, cursorDisplayIndex / m_width, cursorDisplayIndex % m_width);
}
