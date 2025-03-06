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

#ifndef VENDOR_H
#define VENDOR_H

#include "Icecream.h"

namespace seneca {
    class Vendor {
    private:
        Icecream* orders;
        int numOrders;
    public:
        void setEmpty();
        void takeOrders();
        void displayOrders();
        void clearData();
    };
}


#endif
