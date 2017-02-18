//
//  Editor.cpp
//  memo
//
//  Created by Nathan Spencer on 2/17/17.
//  Copyright © 2017 Nathan Spencer. All rights reserved.
//

#include "Editor.hpp"

#include <stdio.h>
#include <string>

Editor::Editor()
{
    int screenHeight, screenWidth;
    getmaxyx(stdscr, screenHeight, screenWidth);
    
    m_height = screenHeight - (EDITOR_BORDER_SIZE * 2);
    m_width = screenWidth - (EDITOR_BORDER_SIZE * 4);
    m_window = newwin(m_height, m_width, EDITOR_BORDER_SIZE, (EDITOR_BORDER_SIZE * 2));
    
    keypad(m_window, TRUE);
    m_cursorIndex = 0;
    m_text = "";
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
           // Home();
            break;
        case KEY_BACKSPACE_UNIX:
            Backspace();
            break;
        case KEY_IC:
         //   Insert();
            break;
        case KEY_ENTER:
           // Enter();
            break;
        case KEY_STAB:
            // Tab();
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
    
    wmove(m_window, m_cursorIndex / m_width, m_cursorIndex % m_width);
    wrefresh(m_window);
}

void Editor::Close()
{
    endwin();
}

void Editor::DownArrow()
{
    if(m_cursorIndex <= m_text.size() - m_width)
    {
        m_cursorIndex += m_width;
    }
}

void Editor::UpArrow()
{
    if(m_cursorIndex >= m_width)
    {
        m_cursorIndex -= m_width;
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

void Editor::AddToText(char keystroke)
{
    m_text.insert(m_cursorIndex++, 1, keystroke);
}
