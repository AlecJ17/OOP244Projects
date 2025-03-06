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
#ifndef SENECA_ACCOUNT_H
#define SENECA_ACCOUNT_H
#include "iAccount.h"
namespace seneca {
    class Account : public iAccount {
    private:
        double m_balance;
    protected:
        double balance() const;
    public:
        Account(double = 0.0);
        virtual bool credit(double);
        virtual bool debit(double);

    };
}
#endif