#include <cstring>
#include "Patient.h"
#include "Utils.h"

namespace seneca {
    Patient::Patient(int ticketNumber) : m_ticket(ticketNumber) {
        m_name = nullptr;
        m_OHIP = 0;
    }

    Patient::Patient(const Patient& other) : m_ticket(other.m_ticket) {
        m_name = new char[strlen(other.m_name) + 1];
        strcpy(m_name, other.m_name);
        m_OHIP = other.m_OHIP;
    }

    Patient& Patient::operator=(const Patient& other) {
        if (this != &other) {
            delete[] m_name;
            m_name = new char[strlen(other.m_name) + 1];
            strcpy(m_name, other.m_name);
            m_OHIP = other.m_OHIP;
            m_ticket = other.m_ticket;
        }
        return *this;
    }

    Patient::~Patient() {
        delete[] m_name;
    }

    void Patient::setArrivalTime() {
        m_ticket.resetTime();
    }

    Time Patient::time() const {
        return m_ticket.time();
    }

    int Patient::number() const {
        return m_ticket.number();
    }

    Patient::operator bool() const {
        return m_name != nullptr && m_OHIP >= 100000000 && m_OHIP <= 999999999;
    }

    Patient::operator const char*() const {
        return m_name;
    }

    bool Patient::operator==(char c) const {
        return type() == c;
    }

    bool Patient::operator==(const Patient& other) const {
        return type() == other.type();
    }

    std::ostream& Patient::write(std::ostream& ostr) const {
        if (!*this) {
            ostr << "Invalid Patient Record";
        } else if (&ostr == &std::clog) {
            ostr << m_name << " " << m_OHIP << " " << m_ticket.number() << " " << m_ticket.time();
        } else if (&ostr == &std::cout) {
            ostr << m_ticket << "\n";
            ostr << m_name << ", OHIP: " << m_OHIP << "\n";
        } else {
            ostr << type() << ',' << m_name << ',' << m_OHIP << ',';
            m_ticket.write(ostr);
        }
        return ostr;
    }

    std::istream& Patient::read(std::istream& istr) {
        char temp[51] = {0};
        if (&istr == &std::cin) {
            std::cout << "Name: ";
            istr.get(temp, 51);
            delete[] m_name;
            m_name = new char[strlen(temp) + 1];
            strcpy(m_name, temp);
            istr.ignore(1000, '\n');

            std::cout << "OHIP: ";
            istr >> m_OHIP;
            while (istr.fail() || m_OHIP < 100000000 || m_OHIP > 999999999) {
                istr.clear();
                istr.ignore(1000, '\n');
                std::cout << "Invalid value entered, retry [100000000 <= value <= 999999999]: ";
                istr >> m_OHIP;
            }
        } else {
            istr.get(temp, 51, ',');
            delete[] m_name;
            m_name = new char[strlen(temp) + 1];
            strcpy(m_name, temp);
            istr.ignore(1000, ',');

            istr >> m_OHIP;
            istr.ignore(1000, ',');

            m_ticket.read(istr);
        }
        return istr;
    }
}