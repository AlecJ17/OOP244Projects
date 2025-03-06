/*
     *****************************************************************************
                   <Workshop - #2 (Part-2)>
     Full Name         : Alec Josef Serrano
     Student ID#       : 133592238
     Email             : ajserrano2@myseneca.ca
     Section           : NEE
     Date Accomplished : January 27,2024
     Authenticity Declaration:
     I declare this submission is the result of my own work and has not been
     shared with any other student or 3rd party content provider. This submitted
     piece of work is entirely of my own creation.
     *****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Guest.h"
#include <cstring>
#include <iostream>

using namespace std;
namespace seneca
{

    void set(Guest& guest, const char* first, const char* last, int age)
    {
        guest.m_firstName = nullptr;
        guest.m_lastName = nullptr;

        if(first && last && first[0] && last[0])
        {
            guest.m_firstName = new char[strlen(first) + 1];
            strcpy(guest.m_firstName, first);
            guest.m_lastName = new char[strlen(last) + 1];
            strcpy(guest.m_lastName, last);
        }
        guest.m_adult = (age >= 18);

    }

    void print(const Guest& guest)
    {
        if (guest.m_firstName != nullptr && guest.m_lastName != nullptr)
        {
            cout << guest.m_firstName << " " << guest.m_lastName;
            if (!guest.m_adult)
            {
                cout << "(Child)";
            }
        }
        else
        {
            cout << "Vacated!";
        }
        cout << endl;
    }

    void book(Guest& guest)
    {
        char firstName[50], lastName[50];
        int age;
        cout << "Name: ";
        cin.getline(firstName, 50);
        cout << "Lastname: ";
        cin.getline(lastName, 50);
        cout << "Age: ";
        cin >> age;
        cin.ignore(); // Add this line to clear the newline character from the buffer
        set(guest, firstName, lastName, age);
    }

    void vacate(Guest& guest)
    {
            delete[] guest.m_firstName;
            guest.m_firstName = nullptr;
            delete[] guest.m_lastName;
            guest.m_lastName = nullptr;
    }

}
