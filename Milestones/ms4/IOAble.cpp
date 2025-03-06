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
#include "IOAble.h"
using namespace std;
namespace seneca
{
    ostream& operator<<(ostream& ostr, const IOAble& obj)
    {
        return obj.write(ostr);
    }

    istream& operator>>(istream& istr, IOAble& obj)
    {
        return obj.read(istr);
    }

}
