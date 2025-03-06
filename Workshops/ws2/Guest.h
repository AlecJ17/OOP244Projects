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

#ifndef GUEST_H
#define GUEST_H

namespace seneca
{

    struct Guest{
        char* m_firstName;
        char* m_lastName;
        bool m_adult;
    };

    void set(Guest& guest, const char* first, const char* last, int age);
    void print(const Guest& guest);
    void book(Guest& guest);
    void vacate(Guest& guest);

} // namespace seneca

#endif
