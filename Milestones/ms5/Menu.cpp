/*
     *****************************************************************************
                   <Milestone 5>
     Full Name         : Alec Josef Serrano
     Student ID#       : 133592238
     Email             : ajserrano2@myseneca.ca
     Section           : NEE
     Date Accomplished : April 07,2024
     Authenticity Declaration:
     I declare this submission is the result of my own work and has not been
     shared with any other student or 3rd party content provider. This submitted
     piece of work is entirely of my own creation.
     *****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
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
        for (int i = 0; i < m_indentation; ++i)
        {
            cout << "   ";
        }
        cout << "> ";
    }

    int& Menu::operator>>(int& selection)
    {
        bool valid = false;
        display();
        while (!valid)
        {
            cin >> selection;
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
                    cin.ignore(10000, '\n'); // Ignore the incorrect input until the next newline
                    cout << "Only enter an integer, try again: ";
                }
                else if (selection < 0 || selection > m_noOfOptions)
                {
                    cout << "Invalid value enterd, retry[0 <= value <= " << m_noOfOptions << "]: ";
                }
                else
                {
                    valid = true; // Input is valid
                }
            }
        }
        return selection;
    }
}
