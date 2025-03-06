/***********************************************************************
// OOP244 Workshop #7
//
// File:    DipostiUtitlity.cpp
// Version: 1.0
// Author:  Nick Romanidis
//
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>

#include "DepositUtility.h"
using namespace std;
namespace seneca {

    Date::Date()
    {
        m_day = 0;
        m_month = 0;
        m_year = 0;
    }

    Date::Date(int day, int month, int year) {
        m_day = day;
        m_month = month;
        m_year = year;
    }

    int Date::getDay() const {
        return m_day;
    }

    int Date::getMonth() const {
        return m_month;
    }

    int Date::getYear() const {
        return m_year;
    }

    void Date::write(ostream& out) const {
        char oldFill = out.fill('0');

        out << m_year << "-" << setw(2) << m_month << "-" << setw(2) << m_day;

        out.fill(oldFill);
    }

    void Date::read(istream& in) {
        cout << "(year month day): ";

        in >> m_year >> m_month >> m_day;
    }

    ostream& operator<<(ostream& out, const Date& dt) {
        dt.write(out);
        return out;
    }

    istream& operator>>(istream& in, Date& dt) {
        dt.read(in);
        return in;
    }


    DepositInfo::DepositInfo()
    {
        m_transit[0] = '\0';
        m_institution[0] = '\0';
        m_account[0] = '\0';
    }

    DepositInfo::DepositInfo(const char* transit, const char* institution, const char* account)
    {
        strncpy(m_transit, transit, TRANSIT_NUM_LEN);
        m_transit[TRANSIT_NUM_LEN] = 0;
        strncpy(m_institution, institution, INSTITUTION_NUM_LEN);
        m_institution[INSTITUTION_NUM_LEN] = 0;
        strncpy(m_account, account, ACCT_NUM_LEN);
        m_account[ACCT_NUM_LEN] = 0;
    }

    const char* DepositInfo::getTransit() const {
        return m_transit;
    }

    const char* DepositInfo::getInstitution() const {
        return m_institution;
    }

    const char* DepositInfo::getAccount() const {
        return m_account;
    }

    void DepositInfo::write(ostream& out) const {
        out << m_transit << "," << m_institution << "," << m_account;
    }

    void DepositInfo::read(istream& in) {
        cout << "Transit #: ";
        in >> m_transit;

        cout << "Institution #: ";
        in >> m_institution;

        cout << "Account #: ";
        in >> m_account;
    }


    ostream& operator<<(ostream& out, const DepositInfo& info) {
        info.write(out);
        return out;
    }

    istream& operator>>(istream& in, DepositInfo& info) {
        info.read(in);
        return in;
    }

}