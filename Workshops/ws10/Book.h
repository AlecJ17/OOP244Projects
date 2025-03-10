/*
     *****************************************************************************
                   <Workshop - 10>
     Full Name         : Alec Josef Serrano
     Student ID#       : 133592238
     Email             : ajserrano2@myseneca.ca
     Section           : NEE
     Date Accomplished : April 02,2024
     Authenticity Declaration:
     I declare this submission is the result of my own work and has not been
     shared with any other student or 3rd party content provider. This submitted
     piece of work is entirely of my own creation.
     *****************************************************************************
*/
// Module supplied
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include<iostream>
#include<iomanip>
#include<cstring>
#include "Student.h"

namespace seneca {
    class Student;
    class Book {
        char m_title[256];
        int m_numPages;
        double m_price;
        char m_progs[5][32];
        int m_numProgs;
    public:
        Book();
        Book(const char* title, int pages, double price, const char* disciplines, int numDisciplines);
        const char* Discipline(int n) const;
        int NumDsicplines() const;
        bool operator==(int) const;
        bool operator==(double) const;
        bool operator==(const Student& stu) const;
        std::ostream& display(std::ostream&) const;
    };

    std::ostream& operator<<(std::ostream&, const Book&);




}

#endif