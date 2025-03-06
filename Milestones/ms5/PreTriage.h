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
#ifndef SENECA_PRETRIAGE_H
#define SENECA_PRETRIAGE_H

#include "Time.h"
#include "Menu.h"
#include "Patient.h"
#include "TestPatient.h"
#include "TriagePatient.h"
#include "Patient.h"
#include "Utils.h"

namespace seneca {
    const int maxNoOfPatients = 100;

    class PreTriage {
        Time m_averContWait;
        Time m_averTriageWait;
        Patient* m_lineup[maxNoOfPatients];
        char* m_dataFilename;
        int m_lineupSize;

        Time getWaitTime(const Patient& p) const;
        void setAverageWaitTime(const Patient& p);
        int indexOfFirstInLine(char type) const;

        std::istream& load(std::istream& istr = std::cin);
        std::ostream& save(std::ostream& ostr = std::cout) const;
        void reg();
        void admit();
        void lineUp();

    public:
        PreTriage(const char* dataFilename);
        virtual ~PreTriage();
        std::istream& run(std::istream& istr = std::cin);

    };
}

#endif //SENECA_PRETRIAGE_H
