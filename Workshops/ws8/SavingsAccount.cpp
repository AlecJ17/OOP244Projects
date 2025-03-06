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
#include "SavingsAccount.h"
using namespace std;
namespace seneca
{
    SavingsAccount::SavingsAccount(double initBalance, double rate) : Account(initBalance)
    {
        if (rate > 0)
        {
            m_interestRate = rate;
        }
        else
        {
            m_interestRate = 0.0;
        }
    }
    void SavingsAccount::monthEnd()
    {
        double interest = balance() * m_interestRate;
        credit(interest);
    }
    void SavingsAccount::display(std::ostream& os) const{
        os << "Account type: Savings" << endl;
        os.setf(ios::fixed);
        os.precision(2);
        os << "Balance: $" << balance() << endl;
        os << "Interest Rate (%): " << m_interestRate * 100 << endl;
    }
}