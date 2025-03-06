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
#define _CRT_SECURE_NO_WARNINGS
#include "ChequingAccount.h"
#include <iostream>

using namespace std;
namespace seneca
{
    ChequingAccount::ChequingAccount(double balance, double transFee, double monthlyFee) : Account(balance)
    {
        m_transactionFee = (transFee > 0) ? transFee : 0.0;
        m_monthlyFee = (monthlyFee > 0) ? monthlyFee : 0.0;
    }
    bool ChequingAccount::credit(double val)
    {
        bool flag = Account::credit(val);
        if (flag)
        {
            Account::debit(m_transactionFee);
        }
        return flag;
    }
    bool ChequingAccount::debit(double val)
    {
        bool flag = Account::debit(val);
        if (flag)
        {
            Account::debit(m_transactionFee);
        }
        return flag;
    }
    void ChequingAccount::monthEnd()
    {
        Account::debit(m_monthlyFee);
    }
    void ChequingAccount::display(std::ostream& os) const
    {
        os << "Account type: Chequing" << endl;
        os.setf(ios::fixed);
        os.precision(2);
        os << "Balance: $" << balance() << endl;
        os << "Per Transaction Fee: " << m_transactionFee << endl;
        os << "Monthly Fee: " << m_monthlyFee << endl;
    }
}