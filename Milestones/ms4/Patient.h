/*
     *****************************************************************************
                   <Milestone 4>
     Full Name         : Alec Josef Serrano
     Student ID#       : 133592238
     Email             : ajserrano2@myseneca.ca
     Section           : NEE
     Date Accomplished : April 02,2024
     Authenticity Declaration:
     I declare this submission is the result of my own work and has not been
     shared with any other student or 3rd party content provider. This submitted
     piece of work is entirely of my own creation.
     *****************************************************************************
*/
#ifndef SENECA_PATIENT_H_
#define SENECA_PATIENT_H_
#include "IOAble.h"
#include "Ticket.h"

namespace seneca
{
    class Patient : public IOAble
    {
    private:
        char* m_name;
        int m_OHIP;
        Ticket m_ticket;

    public:
        Patient(int ticketNumber = 0);
        Patient(const Patient& other);
        Patient& operator=(const Patient& other);
        virtual ~Patient();

        virtual char type() const = 0;

        bool operator==(char c) const;
        bool operator==(const Patient& other) const;

        void setArrivalTime();
        Time time() const;
        int number() const;

        operator bool() const;
        operator const char*() const;
        virtual std::ostream& write(std::ostream& ostr) const override;
        virtual std::istream& read(std::istream& istr) override;

    };

}
#endif