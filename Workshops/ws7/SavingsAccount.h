/*
     *****************************************************************************
                        <Workshop - 7>
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
#ifndef SENECA_SAVINGS_ACCOUNT_H
#define SENECA_SAVINGS_ACCOUNT_H

#include "BankAccount.h"

namespace seneca
{
    class SavingsAccount : public BankAccount
    {
    private:
        double m_interest;
        Date m_interestDate;

        void writeInterest(std::ostream& out) const;

    public:
        SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate);
        void applyInterest(Date& dt);
        std::ostream& write(std::ostream& out) const;
        std::istream& read(std::istream& in);

        friend std::istream& operator>>(std::istream& in, SavingsAccount& acct);
    };
}

#endif // SENECA_SAVINGS_ACCOUNT_H
