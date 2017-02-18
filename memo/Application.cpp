//
//  Application.cpp
//  memo
//
//  Created by Nathan Spencer on 2/12/17.
//  Copyright © 2017 Nathan Spencer. All rights reserved.
//

#include "Editor.hpp"
#include "String.hpp"

#include <iostream>
#include <string>
#include <curses.h>

int main(int argc, const char * argv[])
{
    initscr();
    noecho();

    if(argc == 1)
    {
        Editor editor = Editor();
        
        while(1)
        {
            editor.Update();
        }
        
        return 0;
        
    }
    
    else if(argc == 2)
    {
        if(argv[1] == std::string("new"))
        {
          // should open directly into new memo entry with current timestamp
        }
    }

    // show memo help
    // printLn(" - memo                      open the memo application");
    // printLn(" - memo new                  start a new memo entry");
    // printLn(" - memo year [int year]      show memos from specified year");
    // printLn(" - memo month [int month]    show memos from a specified month");
    
    return 0;
}
