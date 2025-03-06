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
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include "LibraryItem.h"
namespace seneca {
    class Book;

    class Book : public LibraryItem {
    private:
        char *m_author;

    public:
        // Parameterized constructor
        Book(const char *title, int year, const char *author);

        // Copy constructor
        Book(const Book &other);

        // Copy assignment operator
        Book &operator=(const Book &other);

        // Destructor
        ~Book();

        // Display function
        virtual std::ostream &display(std::ostream &ostr = std::cout) const override;

        // Operator overloading for comparing authors
        bool operator>(const Book &other) const;
    };

#endif // SENECA_BOOK_H
}