//
//  String.cpp
//  memo
//
//  Created by Nathan Spencer on 2/12/17.
//  Copyright © 2017 Nathan Spencer. All rights reserved.
//

#include "String.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>

const std::string GetDateString()
{
    time_t t = time(0);
    struct tm * local = localtime(&t);
    
    std::stringstream outStringStream;
    outStringStream << std::setfill('0') << std::setw(2)
        << (local->tm_mon + 1) << '/'
        << std::setfill('0') << std::setw(2)
        << local->tm_mday << '/'
        << std::setfill('0') << std::setw(2)
        << (local->tm_year - 100)
        << std::endl;
    
    const std::string& outString = outStringStream.str();
    return outString;
}

const std::string GetTimeString()
{
    time_t t = time(0);
    struct tm * local = localtime(&t);
    
    std::stringstream outStringStream;
    outStringStream << std::setfill('0') << std::setw(2)
        << (local->tm_hour) << ':'
        << std::setfill('0') << std::setw(2)
        << local->tm_min << ':'
        << std::setfill('0') << std::setw(2)
        << local->tm_sec
        << std::endl;
    
    const std::string& outString = outStringStream.str();
    return outString;
}
