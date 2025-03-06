/*
     *****************************************************************************
                   <Milestone 1>
     Full Name         : Alec Josef Serrano
     Student ID#       : 133592238
     Email             : ajserrano2@myseneca.ca
     Section           : NEE
     Date Accomplished : March 09,2024
     Authenticity Declaration:
     I declare this submission is the result of my own work and has not been
     shared with any other student or 3rd party content provider. This submitted
     piece of work is entirely of my own creation.
     *****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <ctime>
#include "Utils.h"
using namespace std;
namespace seneca
{
    // start provided code
    bool debug = false;
    Utils U;
    int Utils::getTime()
    {
        int mins = -1;
        if (debug)
        {
            int duration[]{ 3,5,9,20,30 };
            mins = (m_testMins %= 1440);
            m_testMins += duration[m_testIndex++ % 5];
        }
        else
        {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }
    void Utils::setDebugTime(int hour, int min)
    {
        seneca::debug = true;
        m_testMins = hour * 60 + min;
    }

    // Student's made function/s
    int Utils::selectionCheck(int& num, int min, int max)
    {
        
        int value = 0;
        bool valid = false;
        while (!valid)
        {
            cin >> num;
            if (cin.fail())
            {
                cin.clear(); // Clear the error flag
                cin.ignore(10000, '\n'); // Ignore the incorrect input until the next newline
                cout << "Bad integer value, try again: ";
            }
            else
            {
                char nextChar = cin.get();
                if (nextChar != '\n')
                {
                    ignore(10000, '\n'); // Ignore the incorrect input until the next newline
                    cout << "Only enter an integer, try again: ";
                }
                else if (num < min || num > max)
                {
                    cout << "Invalid value enterd, retry[ "<< min << "<= value <= " << max << "]: ";
                }
                else
                {
                    value = num;
                    valid = true; // Input is valid
                }
            }
        }
        return value;
    }
    

}