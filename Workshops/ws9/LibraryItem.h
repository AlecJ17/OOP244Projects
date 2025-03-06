/***********************************************************************
// OOP244 Workshop # 9: tester program
//
// File	main.cpp
// Version 1.0
// Author: Razi Iqbal
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                  Date            Reason
//Alec Josef Serrano 2021-03-29          Workshop 9
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_LIBRARYITEM_H
#define SENECA_LIBRARYITEM_H

#include <iostream>
namespace seneca {
    class LibraryItem;

    class LibraryItem {
    private:
        char *m_title;
        int m_year;

    public:
        // Default constructor
        LibraryItem();

        // Parameterized constructor
        LibraryItem(const char *title, int year);

        // Copy constructor
        LibraryItem(const LibraryItem &other);

        // Copy assignment operator
        LibraryItem &operator=(const LibraryItem &other);

        // Destructor
        virtual ~LibraryItem();

        // Display function
        virtual std::ostream &display(std::ostream &ostr = std::cout) const;
    };
}
#endif // SENECA_LIBRARYITEM_H
