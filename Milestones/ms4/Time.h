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
#ifndef SENECA_TIME_H
#define SENECA_TIME_H

#include <iostream>

namespace seneca
{

    class Time
    {
        unsigned int m_minutes; // Store time in minutes

    public:
        Time(unsigned int min = 0u);
        Time& reset();
        Time& operator-=(const Time& D);
        Time operator-(const Time& T) const;
        Time& operator*=(int val);
        explicit operator unsigned int() const; // Cast to unsigned int to get minutes

        // Display and input methods as per guidelines
        std::ostream& write(std::ostream& ostr = std::cout) const;
        std::istream& read(std::istream& istr = std::cin);
    };
    // Overloaded operators for insertion and extraction
    std::ostream& operator<<(std::ostream& ostr, const Time& time);
    std::istream& operator>>(std::istream& istr, Time& time);

}

#endif // SENECA_TIME_H
