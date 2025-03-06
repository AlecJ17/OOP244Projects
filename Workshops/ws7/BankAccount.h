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
#ifndef SENECA_BANK_ACCOUNT_H
#define SENECA_BANK_ACCOUNT_H

#include "DepositUtility.h" // Include the DepositUtility module
const size_t NAME_LEN = 50;

namespace seneca {
    class BankAccount {
    private:
        char m_name[NAME_LEN + 1]; // Adjust size to include null terminator
        Date m_openDate;
        DepositInfo m_depInfo;
        double m_balance;

    protected:
        double getBalance() const;
        void setBalance(double balance);
        void writeCurrency(std::ostream& out, double amount) const;

    public:
        BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance);

        std::ostream& write(std::ostream& out) const;
        std::istream& read(std::istream& in);

        friend std::istream& operator>>(std::istream& in, BankAccount& acct);
        friend std::ostream& operator<<(std::ostream& out, const BankAccount& acct);
    };
}

#endif // SENECA_BANK_ACCOUNT_H
