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
#include <iostream>
#include <iomanip> // For setprecision
#include <cstring>
#include "BankAccount.h"
#include "DepositUtility.h"
using namespace std;
namespace seneca
{
    // Protected members
    double BankAccount::getBalance() const
    {
        return m_balance;
    }

    void BankAccount::setBalance(double balance)
    {
        m_balance = balance;
    }

    void BankAccount::writeCurrency(ostream& out, double amount) const
    {
        out << "$" << fixed << setprecision(2) << amount;
    }

    // Public members
    BankAccount::BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance)
            : m_openDate(openDate), m_depInfo(depInfo), m_balance(balance)
    {
        strncpy(m_name, name, NAME_LEN);
        m_name[NAME_LEN] = '\0'; // Ensure null termination
    }

    ostream& BankAccount::write(ostream& out) const
    {
        out <<">> "<< m_name << " | ";
        writeCurrency(out, m_balance);
        out << " | " << m_openDate << " | " << m_depInfo;
        return out;
    }


    istream& BankAccount::read(istream& in)
    {
        cout << "Name: ";
        in.getline(m_name, NAME_LEN);

        cout << "Opening Balance: ";
        in >> m_balance;
        in.ignore(10000, '\n');

        cout << "Date Opened ";
        in >> m_openDate;
        in.ignore(10000, '\n');

        in >> m_depInfo;

        return in;
    }


    // Helper functions
    istream& operator>>(istream& in, BankAccount& acct)
    {
        return acct.read(in);
    }

    ostream& operator<<(ostream& out, const BankAccount& acct)
    {
        return acct.write(out);
    }
}
