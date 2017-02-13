//
//  printer.cpp
//  memo
//
//  Created by Nathan Spencer on 2/12/17.
//  Copyright © 2017 Nathan Spencer. All rights reserved.
//

#include "printer.hpp"

#include <iostream>
#include <iomanip>

void print(std::string str)
{
    std::cout << str;
}

void printLn(std::string str)
{
    std::cout << str << std::endl;
}

void printDateStamp()
{
    time_t t = time(0);
    struct tm * local = localtime( & t );
    
    // print zero-padded date
    std::cout << std::setfill('0') << std::setw(2)
    << (local->tm_mon + 1) << '-'
    << local->tm_mday << '-'
    << (local->tm_year - 100)
    << std::endl;
}

void printTimeStamp()
{
    time_t t = time(0);
    struct tm * local = localtime( & t );
    
    // print zero-padded time
    std::cout << std::setfill('0') << std::setw(2)
    << (local->tm_hour + 1) << ':'
    << local->tm_min << ':'
    << local->tm_sec
    << std::endl;
}
