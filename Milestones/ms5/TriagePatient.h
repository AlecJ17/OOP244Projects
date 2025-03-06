/*
     *****************************************************************************
                   <Milestone 5>
     Full Name         : Alec Josef Serrano
     Student ID#       : 133592238
     Email             : ajserrano2@myseneca.ca
     Section           : NEE
     Date Accomplished : April 07,2024
     Authenticity Declaration:
     I declare this submission is the result of my own work and has not been
     shared with any other student or 3rd party content provider. This submitted
     piece of work is entirely of my own creation.
     *****************************************************************************
*/
#ifndef SENECA_TRIAGEPATIENT_H
#define SENECA_TRIAGEPATIENT_H

#include "Patient.h"
#include "Utils.h"

namespace seneca {
    extern int nextTriageTicket; // Global variable declaration

    class TriagePatient : public Patient {
        char* symptoms;
    public:
        TriagePatient();
        virtual ~TriagePatient();
        TriagePatient(const TriagePatient&) = delete;
        TriagePatient& operator=(const TriagePatient&) = delete;

        virtual char type() const override;
        std::ostream& write(std::ostream& ostr) const override;
        std::istream& read(std::istream& istr) override;
    };
}

#endif // SENECA_TRIAGEPATIENT_H
