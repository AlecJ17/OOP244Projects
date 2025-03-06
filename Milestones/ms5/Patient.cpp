/*
     *****************************************************************************
                   <Milestone 5>
     Full Name         : Alec Josef Serrano
     Student ID#       : 133592238
     Email             : ajserrano2@myseneca.ca
     Section           : NEE
     Date Accomplished : April 07,2024
     Authenticity Declaration:
     I declare this submission is the result of my own work and has not been
     shared with any other student or 3rd party content provider. This submitted
     piece of work is entirely of my own creation.
     *****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Ticket.h"
#include "Patient.h"
#include "Time.h"
#include "Utils.h"
#include "IOAble.h"
using namespace std;
namespace seneca
{
    Patient::Patient(int ticketNumber) : m_ticket(ticketNumber)
    {
        m_name = nullptr;
        m_OHIP = 0;
    }

    Patient::Patient(const Patient& other) : m_ticket(other.m_ticket)
    {
        m_name = new char[51];
        strncpy(m_name, other.m_name, 50); // Copy name, truncate if necessary
        m_OHIP = other.m_OHIP;
    }

    Patient& Patient::operator=(const Patient& other)
    {
        if (this != &other) {
            delete[] m_name; // Deallocate existing memory
            m_name = new char[51];
            strncpy(m_name, other.m_name, 50); // Copy name, truncate if necessary
            m_OHIP = other.m_OHIP;
            m_ticket = other.m_ticket;
        }
        return *this;
    }

    Patient::~Patient()
    {
        delete[] m_name;
    }

    bool Patient::operator==(char c) const
    {
        return type() == c;
    }

    bool Patient::operator==(const Patient& other) const
    {
        return type() == other.type();
    }

    void Patient::setArrivalTime()
    {
        m_ticket.resetTime();
    }

    Time Patient::time() const
    {
        return m_ticket.time();
    }

    int Patient::number() const
    {
        return m_ticket.number();
    }

    int Patient::getOHIP() const
    {
        return m_OHIP;
    }

    Patient::operator bool() const
    {
        return m_name != nullptr && m_OHIP >= 100000000 && m_OHIP <= 999999999;
    }

    Patient::operator const char*() const
    {
        return m_name;
    }

    ostream& Patient::write(ostream& ostr) const
    {
        if (*this)
        {
            if (&ostr == &clog)
            {
                ostr.width(53);
                ostr.fill('.');
                ostr.setf(ios::left);
                if (m_name) ostr << m_name;
                ostr << m_OHIP;
                ostr.fill(' ');
                ostr.unsetf(ios::left);
                ostr.setf(ios::right);
                ostr.width(5);
                ostr << m_ticket.number();
                ostr.unsetf(ios::right);
                ostr << " " << m_ticket.time();
            }
            else if (&ostr == &cout)
            {
                ostr << m_ticket << endl;
                ostr << m_name << ", OHIP: " << m_OHIP << endl;
            }
            else
            {
                ostr << type() << ',';
                if (m_name) ostr << m_name;
                ostr << ',' << m_OHIP << ',';
                m_ticket.write(ostr);
            }
        }
        else
        {
            ostr << "Invalid Patient Record" << endl;
        }
        return ostr;
    }

    istream& Patient::read(istream& istr) {
        char temp[51] {};
        delete [] m_name;
        m_name = nullptr;
        if (&istr == &cin) {
            cout << "Name: ";
            istr.get(temp, 51);
            delete[] m_name;
            m_name = new char[strlen(temp) + 1];
            strcpy(m_name, temp);
            cout << "OHIP: ";
            m_OHIP = U.inputInt(100000000, 999999999);
            istr.ignore(1000, '\n');
        } else {
            istr.get(temp, 51, ',');
            delete[] m_name;
            m_name = new char[strlen(temp) + 1];
            strcpy(m_name, temp);
            istr.ignore(1000, ',');

            istr >> m_OHIP;
            istr.ignore(1000, ',');

            m_ticket.read(istr);
        }
        return istr;
    }
}