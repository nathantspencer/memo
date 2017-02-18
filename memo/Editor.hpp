//
//  Editor.hpp
//  memo
//
//  Created by Nathan Spencer on 2/17/17.
//  Copyright © 2017 Nathan Spencer. All rights reserved.
//

#ifndef Editor_hpp
#define Editor_hpp

#include "String.hpp"

#include <ncurses.h>
#include <string>

const int EDITOR_BORDER_SIZE = 1;
const int SIDEBAR_WIDTH = 8;
const int DIVIDER_WIDTH = 1;
const int KEY_BACKSPACE_UNIX = 127;
const int TAB_SIZE = 8;

class Editor
{
    public:
    
        Editor();
        ~Editor();
    
        void Update();
        bool GetIsClosed();
    
    private:
    
        void DownArrow();
        void UpArrow();
        void LeftArrow();
        void RightArrow();
        void Backspace();
        void Home();
        void Insert();
        void Enter();
    
        void AddToText(char keystroke);
        void WriteSidebar();
        void SetCursorDisplay();
        void Close();
    
        WINDOW * m_window;
        WINDOW * m_divider;
        WINDOW * m_sidebar;
    
        std::string m_text;
        const std::string m_datestamp = GetDateString();
        const std::string m_timestamp = GetTimeString();
    
        int m_cursorIndex;
        int m_height;
        int m_width;
    
        bool m_insertMode;
        bool m_isClosed;
};

#endif /* Editor_hpp */
