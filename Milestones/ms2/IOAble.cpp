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
#include "IOAble.h"
using namespace std;
namespace seneca
{
    // Implementation of IOAble member functions

    ostream& IOAble::write(ostream& ostr) const
    {
        // Default implementation
        return ostr;
    }

    istream& IOAble::read(istream& istr)
    {
        // Default implementation
        return istr;
    }
    ostream& operator<<(ostream& ostr, const IOAble& obj)
    {
        return obj.write(ostr);
    }

    istream& operator>>(istream& istr, IOAble& obj)
    {
        return obj.read(istr);
    }

}
