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
#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
using namespace std;

namespace seneca {

    Book::Book() {
        m_title[0] = '\0';
        m_numPages = 0;
        m_price = 0.0;
        for (int i = 0; i < 5; i++) {
            m_progs[i][0] = '\0';
            m_progs[i][3] = '\0';
        }
        m_numProgs = 0;
    }
    Book::Book(const char* title, int pages, double price, const char* disciplines, int numDisciplines) {
        *this = Book();
        int i, j;
        if (title) {
            strcpy(m_title, title);
            m_numPages = pages;
            m_price = price;
            if (disciplines && numDisciplines > 0) {
                m_numProgs = numDisciplines;
                j = 0;
                for (i = 0; i < (m_numProgs * 3); i += 3) {
                    strncpy(m_progs[j], &disciplines[i], 3);
                    j++;
                }
            }
        }
    }
    const char* Book::Discipline(int n) const {
        return m_progs[n];
    }
    int Book::NumDsicplines() const {
        return m_numProgs;
    }
    bool Book::operator==(int x) const {
        return m_numPages == x;
    }
    bool Book::operator==(double x) const {
        return (m_price - x) * (m_price - x) < 0.01;
    }

    bool Book::operator==(const Student& stu) const {
        bool retval = false;
        for (int i = 0; i < m_numProgs; i++)
            retval = retval || !strcmp(m_progs[i], stu.Program());
        return retval;
    }


    std::ostream& Book::display(std::ostream& os) const {
        char temp[256] = { '\0' };
        for (int i = 0; i < m_numProgs; i++) {
            strcat(temp, m_progs[i]);
            strcat(temp, ",");
        }
        temp[strlen(temp) - 1] = '\0';

        os << setw(25) << m_title << ","
           << setw(3) << m_numPages << ","
           << setw(6) << m_price << ",progs:"
           << setw(16) << temp;
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const Book& bk) {
        return bk.display(os);
    }


}