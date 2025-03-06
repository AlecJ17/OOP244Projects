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
#ifndef SENECA_IOABLE_H
#define SENECA_IOABLE_H

#include <iostream>

namespace seneca
{
    class IOAble
    {
    public:
        virtual std::ostream& write(std::ostream& ostr) const = 0;
        virtual std::istream& read(std::istream& istr) = 0;
        virtual ~IOAble() = default;
    };

    std::ostream& operator<<(std::ostream& ostr, const IOAble& obj);
    std::istream& operator>>(std::istream& istr, IOAble& obj);
}

#endif // SENECA_IOABLE_H