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
#include "Book.h"
#include <cstring> // For string manipulation
namespace seneca {
// Parameterized constructor
    Book::Book(const char *title, int year, const char *author) : LibraryItem(title, year) {
        m_author = new char[strlen(author) + 1];
        strcpy(m_author, author);
    }

// Copy constructor
    Book::Book(const Book &other) : LibraryItem(other), m_author(nullptr) {
        if (other.m_author) {
            m_author = new char[strlen(other.m_author) + 1];
            strcpy(m_author, other.m_author);
        }
    }

// Copy assignment operator
    Book &Book::operator=(const Book &other) {
        if (this != &other) {
            LibraryItem::operator=(other);
            delete[] m_author;
            m_author = nullptr;
            if (other.m_author) {
                m_author = new char[strlen(other.m_author) + 1];
                strcpy(m_author, other.m_author);
            }
        }
        return *this;
    }

// Destructor
    Book::~Book() {
        delete[] m_author;
    }

// Display function
    std::ostream &Book::display(std::ostream &ostr) const {
        LibraryItem::display(ostr);
        ostr << std::endl << "Author: " << m_author;
        return ostr;
    }

// Operator overloading for comparing authors
    bool Book::operator>(const Book &other) const {
        if (m_author && other.m_author) {
            return strcmp(m_author, other.m_author) > 0;
        }
        return false;
    }
}