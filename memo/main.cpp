//
//  main.cpp
//  memo
//
//  Created by Nathan Spencer on 2/12/17.
//  Copyright © 2017 Nathan Spencer. All rights reserved.
//

#include <iostream>
#include <string>

#include "printer.hpp"

int main(int argc, const char * argv[]) {
    
    bool validArgument = true;
    
    if(argc == 1)
    {
        // open memo application
    }
    
    else if(argc == 2)
    {
        if(argv[1] == std::string("new"))
        {
          // should open directly into new memo entry with current timestamp
        }
        
        // set validArgument to zero if no valid argument is found
        validArgument = false;
    }
    
    if (!validArgument)
    {
        // show memo help
        printLn(" - memo                      open the memo application");
        printLn(" - memo new                  start a new memo entry");
        printLn(" - memo year [int year]      show memos from specified year");
        printLn(" - memo month [int month]    show memos from a specified month");
    }
    
    return 0;
}
