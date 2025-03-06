/*
     *****************************************************************************
                   <Workshop-8>
     Full Name         : Alec Josef Serrano
     Student ID#       : 133592238
     Email             : ajserrano2@myseneca.ca
     Section           : NEE
     Date Accomplished : March 19,2024
     Authenticity Declaration:
     I declare this submission is the result of my own work and has not been
     shared with any other student or 3rd party content provider. This submitted
     piece of work is entirely of my own creation.
     *****************************************************************************
*/
#ifndef SENECA_SAVINGSACCOUNT_H
#define SENECA_SAVINGSACCOUNT_H
#include "Account.h"

namespace seneca{
    class SavingsAccount : public Account
    {
    private:
        double m_interestRate;
    public:
        SavingsAccount(double, double);
        virtual void monthEnd();
        virtual void display(std::ostream&) const;
    };
}
#endif