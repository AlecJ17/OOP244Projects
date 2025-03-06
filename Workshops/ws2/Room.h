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
#ifndef ROOM_H
#define ROOM_H

#include "Guest.h"

namespace seneca {

    struct Room {
        char m_roomNumber[6];
        int m_noOfGuests;
        Guest* m_guests;
    };

    void set(Room& room, int numberOfGuests, const char* roomNumber);
    void print(const Room& room);
    void book(Room& room);
    void vacate(Room& room);

} // namespace seneca

#endif
