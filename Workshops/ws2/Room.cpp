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
#include "Room.h"
#include "Guest.h"
#include <cstring>
#include <iostream>

using namespace std;
namespace seneca {

    void set(Room& room, int numberOfGuests, const char* roomNumber)
    {
        if (roomNumber != nullptr)
        {
            strncpy(room.m_roomNumber, roomNumber, sizeof(room.m_roomNumber) - 1);
            room.m_roomNumber[sizeof(room.m_roomNumber) - 1] = '\0'; // Null-terminate the string
        }
        else
        {
            room.m_roomNumber[0] = '\0';
        }

        room.m_noOfGuests = numberOfGuests;
        room.m_guests = new Guest[numberOfGuests];
        for (int i = 0; i < numberOfGuests; ++i)
        {
            room.m_guests[i].m_firstName = nullptr;
            room.m_guests[i].m_lastName = nullptr;
        }
    }

    void print(const Room& room)
    {
        if (room.m_noOfGuests == 0)
        {
            cout << "Empty Room!" << endl;
        }
        else
        {
            cout << "Room Number: " << room.m_roomNumber << endl;
            for (int i = 0; i < room.m_noOfGuests; ++i)
            {
                cout << "    ";
                print(room.m_guests[i]);
            }
        }
    }

    void book(Room& room)
    {
        cout << "Room number: ";
        cin.get(room.m_roomNumber, 6); // Use cin.get to read a fixed length
        cin.ignore(); // Clear the newline character from the buffer
        cout << "Number of guests: ";
        cin >> room.m_noOfGuests;
        cin.ignore();
        room.m_guests = new Guest[room.m_noOfGuests];
        for (int i = 0; i < room.m_noOfGuests; ++i)
        {
            cout  << i + 1 << ":" << endl;
            book(room.m_guests[i]);
        }
    }

    void vacate(Room& room)
    {
        for (int i = 0; i < room.m_noOfGuests; ++i)
        {
            vacate(room.m_guests[i]);
        }
        delete[] room.m_guests;
        room.m_guests = nullptr;
        room.m_noOfGuests = 0;
        room.m_roomNumber[0] = '\0';
    }
}


