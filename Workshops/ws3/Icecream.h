/*
     *****************************************************************************
                   <Workshop - #3 (Part-2)>
     Full Name         : Alec Josef Serrano
     Student ID#       : 133592238
     Email             : ajserrano2@myseneca.ca
     Section           : NEE
     Date Accomplished : February 06,2024
     Authenticity Declaration:
     I declare this submission is the result of my own work and has not been
     shared with any other student or 3rd party content provider. This submitted
     piece of work is entirely of my own creation.
     *****************************************************************************
*/

#ifndef ICECREAM_H
#define ICECREAM_H

#include <iostream>
#include <string>
#include <cctype>

using namespace std;
namespace seneca {
    class Icecream {
    public:
        string flavour;
        int scoops;
        bool vanillaWafer;
        void getOrder();
        void printOrder() const;
        double calculatePrice() const;
    };
}

#endif
