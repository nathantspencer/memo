//
//  Editor.hpp
//  memo
//
//  Created by Nathan Spencer on 2/17/17.
//  Copyright © 2017 Nathan Spencer. All rights reserved.
//

#ifndef Editor_hpp
#define Editor_hpp

#include <ncurses.h>
#include <stdio.h>
#include <string>

const int EDITOR_BORDER_SIZE = 1;
const int KEY_BACKSPACE_UNIX = 127;
const int TAB_SIZE = 8;

class Editor
{
    public:
    
        Editor();
        ~Editor();
    
        void Update();
        void Close();
    
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
        void SetCursorDisplay();
    
        WINDOW * m_window;
        std::string m_text;
        int m_cursorIndex;
    
        int m_height;
        int m_width;
    
        bool m_insertMode;
};

#endif /* Editor_hpp */
