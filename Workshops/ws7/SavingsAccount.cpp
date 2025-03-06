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
#include "SavingsAccount.h"
#include <iostream>
#include <iomanip> // For setprecision
using namespace std;
namespace seneca
{
    // Implement the private member
    void SavingsAccount::writeInterest(ostream& out) const
    {
        out << fixed << setprecision(3) << m_interest  << "%";
    }

    // Implement the public members
    SavingsAccount::SavingsAccount(const char* name, Date openDate, DepositInfo depInfo,
                                   double balance, double interest, Date interestDate)
            : BankAccount(name, openDate, depInfo, balance), m_interest(interest), m_interestDate(interestDate) {}

    void SavingsAccount::applyInterest(Date& dt)
    {
        double interestAmount = getBalance() * m_interest;
        setBalance(getBalance() + interestAmount);
        cout << "   ";
        writeCurrency(cout, getBalance() - interestAmount);
        cout << " + ";
        writeCurrency(cout, interestAmount);
        cout << " (";
        writeInterest(cout);
        cout << ") = ";
        writeCurrency(cout, getBalance());
        cout << " | " << m_interestDate << " => " << dt << endl;
        m_interestDate = dt;
    }

    ostream& SavingsAccount::write(ostream& out) const
    {
        BankAccount::write(out); // Direct call to BankAccount's write
        out << " | ";
        writeInterest(out);
        out << " | " << m_interestDate;
        return out;
    }

    istream& SavingsAccount::read(istream& in)
    {
        in.ignore(10000, '\n');
        BankAccount::read(in); // Call base class read to handle common fields

        cout << "Interest Date ";
        in >> m_interestDate;
        in.ignore(10000, '\n'); // Clear the buffer until the newline character

        // Read SavingsAccount specific fields
        cout << "Interest Rate: ";
        in >> m_interest;
        in.ignore(10000, '\n'); // Clear the buffer until the newline character


        return in;
    }


    istream& operator>>(istream& in, SavingsAccount& acct)
    {
        return acct.read(in);
    }
}
