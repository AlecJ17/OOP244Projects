/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: Account.cpp
// Version 1.0
// Date:
// Author: 
// Description
// This file implements the Account class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#include "Account.h"

using namespace std;
namespace seneca{
    Account::Account(double balance){
        if (balance > 0){
            m_balance = balance;
        }
        else{
            m_balance = 0.0;
        }
    }
    bool Account::credit(double val){
       bool flag = val > 0.0;
       if (flag){
           m_balance += val;
       }
       return flag;
    }
    bool Account::debit(double val){
        bool flag = val > 0.0;
        if (flag){
            m_balance -= val;
        }
        return flag;
    }
    double Account::balance() const {
        return m_balance;
    }
}