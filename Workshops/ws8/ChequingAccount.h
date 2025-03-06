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
#ifndef SENECA_CHEQUINGACCOUNT_H
#define SENECA_CHEQUINGACCOUNT_H
#include "Account.h"
namespace seneca{
    class ChequingAccount : public Account
    {
    private:
        double m_transactionFee;
        double m_monthlyFee;
    public:
        ChequingAccount(double, double, double);
        bool credit(double);
        bool debit(double);
        void monthEnd();
        void display(std::ostream&) const;
    };
}
#endif