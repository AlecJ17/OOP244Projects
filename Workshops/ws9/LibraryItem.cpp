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
#include "LibraryItem.h"
#include <cstring> // For string manipulation
namespace seneca {
// Default constructor
    LibraryItem::LibraryItem() : m_title(nullptr), m_year(0) {}

// Parameterized constructor
    LibraryItem::LibraryItem(const char *title, int year) : m_year(year) {
        m_title = new char[strlen(title) + 1];
        strcpy(m_title, title);
    }

// Copy constructor
    LibraryItem::LibraryItem(const LibraryItem &other) : m_year(other.m_year) {
        m_title = new char[strlen(other.m_title) + 1];
        strcpy(m_title, other.m_title);
    }

// Copy assignment operator
    LibraryItem &LibraryItem::operator=(const LibraryItem &other) {
        if (this != &other) {
            delete[] m_title;
            m_year = other.m_year;
            m_title = new char[strlen(other.m_title) + 1];
            strcpy(m_title, other.m_title);
        }
        return *this;
    }

// Destructor
    LibraryItem::~LibraryItem() {
        delete[] m_title;
    }

// Display function
    std::ostream &LibraryItem::display(std::ostream &ostr) const {
        ostr << "Title: " << m_title << " (" << m_year << ")";
        return ostr;
    }
}