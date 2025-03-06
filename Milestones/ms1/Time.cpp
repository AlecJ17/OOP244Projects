/*
     *****************************************************************************
                   <Milestone 1>
     Full Name         : Alec Josef Serrano
     Student ID#       : 133592238
     Email             : ajserrano2@myseneca.ca
     Section           : NEE
     Date Accomplished : March 09,2024
     Authenticity Declaration:
     I declare this submission is the result of my own work and has not been
     shared with any other student or 3rd party content provider. This submitted
     piece of work is entirely of my own creation.
     *****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Time.h"
#include "Utils.h" // Include the Utils module for accessing getTime()
using namespace std;
namespace seneca
{

    Time::Time(unsigned int min) : m_minutes(min) {}

    Time& Time::reset()
    {
        m_minutes = U.getTime(); // Assuming U is an instance of Utils available globally
        return *this;
    }

    Time& Time::operator-=(const Time& D)
    {
        if (m_minutes < D.m_minutes)
        {
            m_minutes += 1440; // Add 24 hours in minutes if the result is negative
        }
        m_minutes -= D.m_minutes;
        return *this;
    }

    Time Time::operator-(const Time& T) const
    {
        Time temp(*this);
        return temp -= T;
    }

    Time& Time::operator*=(int val)
    {
        m_minutes *= val;
        return *this;
    }

    Time::operator unsigned int() const
    {
        return m_minutes;
    }

    ostream& Time::write(ostream& ostr) const
    {
        int hours = m_minutes / 60;
        int minutes = m_minutes % 60;
        if (hours < 10) ostr << '0';
        ostr << hours << ":";
        if (minutes < 10) ostr << '0';
        ostr << minutes;
        return ostr;
    }

    istream& Time::read(istream& istr)
    {
        int hours = 0, minutes = 0;
        char delimiter = '\0';
        istr >> hours >> delimiter >> minutes;
        if (delimiter == ':') {
            m_minutes = hours * 60 + minutes;
        } else {
            cin.ignore();
            istr.setstate(ios::failbit);
        }

        return istr;
    }

    ostream& operator<<(ostream& ostr, const Time& time)
    {
        return time.write(ostr);
    }

    istream& operator>>(istream& istr, Time& time)
    {
        return time.read(istr);
    }

}
