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
#include <iostream>
#include <cstring>
#include "Utils.h"
#include "Menu.h"

using namespace std;
namespace seneca
{
    Menu::Menu(const char* menuContent, int numberOfTabs) : m_noOfOptions(0),
                                                            m_indentation(numberOfTabs)
    {
        if (menuContent)
        {
            m_text = new char[strlen(menuContent) + 1];
            strcpy(m_text, menuContent);
            // Count options
            for (const char* p = menuContent; *p; ++p)
            {
                if (*p == '\n') m_noOfOptions++;
            }
        }
        else
        {
            m_text = nullptr;
        }
    }

    Menu::~Menu()
    {
        delete[] m_text;
    }

    void Menu::display() const
    {
        // Apply initial indentation
        for (int i = 0; i < m_indentation; ++i)
        {
            cout << "   ";
        }

        // Go through each character in m_text
        for (int j = 0; m_text[j] != '\0'; j++)
        {
            // When hit a newline character, print it, then apply indentation again
            if (m_text[j] == '\n')
            {
                cout << '\n';
                for (int i = 0; i < m_indentation; ++i)
                {
                    cout << "   ";
                }
            }
            else
            {
                // Print the current character
                cout << m_text[j];
            }
        }

        // After printing all menu options, move to a new line
        cout << endl;
        // Apply indentation for the "0- Exit" option
        for (int i = 0; i < m_indentation; ++i)
        {
            cout << "   ";
        }
        cout << "0- Exit\n";
        // Apply indentation for the prompt ">"
        for (int i = 0; i < m_indentation; ++i) {
            cout << "   ";
        }
        cout << "> ";
    }

    int& Menu::operator>>(int& selection)
    {
        cin >> selection;
        display();
        U.selectionCheck(selection, 0,m_noOfOptions);
        return selection;
    }
        
}
