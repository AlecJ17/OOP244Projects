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
#ifndef MENU_H
#define MENU_H
#include "Utils.h"

namespace seneca
{
    class Menu
    {
        char* m_text;
        int m_noOfOptions;
        int m_indentation;

    public:
        Menu(const char* menuContent, int numberOfTabs = 0);
        ~Menu();
        Menu(const Menu&) = delete; // Prevent copy construction
        Menu& operator=(const Menu&) = delete; // Prevent assignment

        void display() const;
        int& operator>>(int& selection);
    };
}

#endif // MENU_H
