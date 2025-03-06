/*
     *****************************************************************************
                   <Milestone 2>
     Full Name         : Alec Josef Serrano
     Student ID#       : 133592238
     Email             : ajserrano2@myseneca.ca
     Section           : NEE
     Date Accomplished : March 13,2024
     Authenticity Declaration:
     I declare this submission is the result of my own work and has not been
     shared with any other student or 3rd party content provider. This submitted
     piece of work is entirely of my own creation.
     *****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_IOABLE_H
#define SENECA_IOABLE_H

#include <iostream>

namespace seneca
{

    class IOAble
    {
    public:
        // Pure virtual function for future ostream outputs
        // Receives a reference to an ostream and returns a reference to an ostream
        // Incapable of changing the current object
        virtual std::ostream& write(std::ostream& ostr) const = 0;

        // Pure virtual function for future istream inputs
        // Receives a reference to an istream and returns a reference to an istream
        virtual std::istream& read(std::istream& istr) = 0;

        // Virtual destructor (empty)
        virtual ~IOAble() {}

        // Insertion operator overload
        // Inserts the information of an IOAble object into an ostream using the write function
        friend std::ostream& operator<<(std::ostream& ostr, const IOAble& obj);

        // Extraction operator overload
        // Extracts information from an istream into an IOAble object using the read function
        friend std::istream& operator>>(std::istream& istr, IOAble& obj);


    };

}

#endif
