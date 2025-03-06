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

#include "Vendor.h"
using namespace std;
namespace seneca {
    void Vendor::setEmpty() {
        orders = nullptr;
        numOrders = 0;
    }

    void Vendor::takeOrders() {
        cout << "Seneca Icecream shop\n"
                "          @\n"
                "        (' .)\n"
                "       (*.`. )\n"
                "        \\###/\n"
                "         \\#/\n"
                "          V"  << endl;
        cout << "How many Icecreams?" << endl;
        cout << "> ";
        cin >> numOrders;
        orders = new Icecream[numOrders];

        for (int i = 0; i < numOrders; ++i) {
            cout << "Order number "; cout << i + 1; cout << ":" << endl;
            orders[i].getOrder(); // Correctly call getOrder for each Icecream
        }
    }

    void Vendor::displayOrders() {
        double total = 0.0;
        double taxRate = 0.13; // Define the tax rate here

        cout << "\n********** Order Summary **********" << endl;
        for (int i = 0; i < numOrders; ++i) {
            cout << "Order No: "; cout << i + 1; cout <<  ":" << endl;
            orders[i].printOrder() ;
            total += orders[i].calculatePrice();
            if (i < numOrders - 1)
            {
                cout << endl;
            }
        }
        double tax = total * taxRate;
        cout << "-----------------------------------" << endl;
        cout << "Price:                        " << total << ".00" << endl;
        cout << "Tax:                           " << tax << endl;
        cout << "Total Price ($):              " << total + tax << endl;

    }

    void Vendor::clearData() {
        delete[] orders;
        setEmpty();
    }
}
