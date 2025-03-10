/*
     *****************************************************************************
                   <Milestone 4>
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Ticket.h"
using namespace std;
namespace seneca {
    Ticket::Ticket(int number) {
        m_number = number;
    }
    Time Ticket::time() const
    {
        return m_time;
    }

    int Ticket::number() const {
        return m_number;
    }
    void Ticket::resetTime() {
        m_time.reset();
    }


    std::ostream& Ticket::write(std::ostream& ostr) const {
        if (&ostr != &cout) {
            ostr << m_number << "," << m_time;
        }
        else {
            ostr << "Ticket No: " << m_number << ", Issued at: " << m_time;
        }
        return  ostr;
    }
    std::istream& Ticket::read(std::istream& istr) {
        istr >> m_number;
        istr.ignore();
        return istr >> m_time;
    }
}