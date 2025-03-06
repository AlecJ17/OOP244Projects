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

#include "Icecream.h"

using namespace std;
namespace seneca {
    void Icecream::getOrder() {
        int flavourChoice;
        bool isValidInput = false; // Flag to track input validity
        cout << "Select flavour:\n----------------\n1: Chocolate\n2: Strawberry\n3: Mango\n4: Tutti fruit\n5: Almond crunch\n----------------\n> ";
        do {
            cin >> flavourChoice;

            // Clear input buffer to handle invalid input
            if (cin.fail()) {
                cin.clear(); // Clear error flags
                cin.ignore(10000, '\n'); // Discard invalid input
                cout << "Invalid entry, retry\n> ";
            } else if (flavourChoice < 1 || flavourChoice > 5) {
                cout << "Invlid value(1<=val<=5)\n> ";
            } else {
                isValidInput = true; // Valid input, break loop
            }
        } while (!isValidInput); // Repeat until valid input is received


        switch (flavourChoice) {
            case 1: flavour = "Chocolate"; break;
            case 2: flavour = "Strawberry"; break;
            case 3: flavour = "Mango"; break;
            case 4: flavour = "Tutti fruit"; break;
            case 5: flavour = "Almond crunch"; break;
        }

        //Reset isValidInput
        isValidInput = false;
        cout << "Number of Scoops (max 3)\n> ";
        do {
            cin >> scoops;

            // Clear input buffer to handle invalid input
            if (cin.fail()) {
                cin.clear(); // Clear error flags
                cin.ignore(10000, '\n'); // Discard invalid input
                cout << "Invalid entry, retry\n> ";
            } else if (scoops < 1 || scoops > 3) {
                cout << "Invlid value(1<=val<=3)\n> ";
            } else {
                isValidInput = true; // Valid input, break loop
            }
        } while (!isValidInput); // Repeat until valid input is received

        string input; // Use a string to capture the input
        cout << "Vanilla wafer cone?\n(Y)es/(N)o > ";
        getline(cin >> ws, input); // Read the whole line, discarding leading whitespace

        // Check only the first character of input and ensure the input length is 1
        while (input.length() != 1 || (input[0] != 'Y' && input[0] != 'y' && input[0] != 'N' && input[0] != 'n')) {
            cout << "Only Y or N are acceptable:\n> ";
            getline(cin >> ws, input); // Again, read the whole line
        }

        vanillaWafer = (input[0] == 'Y' || input[0] == 'y');

    }

    void Icecream::printOrder() const {
        double scoopPrice = 5.0;
        double waferPrice = 5.0;
        double chocolateExtra = 1.0;

        cout << "Order details:                Price\n"
                "-----------------------------------\n";
        cout << "Number of scoops, " << scoops << " total:    " << scoops * scoopPrice << ".00\n";
        if (flavour == "Chocolate") {
            cout << "Chocolate flavour:             " << scoops * chocolateExtra << ".00\n";
        } else {
            cout << flavour << " flavour\n";
        }
        if (vanillaWafer) {
            cout << "Vanilla Wafer:                 " << waferPrice << ".00\n";
        } else {
            cout << "Vanilla Wafer:                 0.00\n";
        }
        cout << "Price:                        " << calculatePrice() << ".00\n";
    }

    double Icecream::calculatePrice() const {
        double scoopPrice = 5.0;
        double waferPrice = 5.0;
        double chocolateExtra = 1.0;

        double total = scoops * scoopPrice;
        if (flavour == "Chocolate") {
            total += scoops * chocolateExtra;
        }
        if (vanillaWafer) {
            total += waferPrice;
        }
        return total;
    }
}
