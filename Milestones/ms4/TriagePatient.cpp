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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "TriagePatient.h"
#include "Patient.h"
#include "Utils.h"
using namespace std;
namespace seneca {
    int nextTriageTicket = 1;

    TriagePatient::TriagePatient() : Patient(nextTriageTicket++), symptoms(nullptr) {}

    TriagePatient::~TriagePatient() {
        delete[] symptoms;
    }

    char TriagePatient::type() const {
        return 'T';
    }

    ostream& TriagePatient::write(ostream& os) const {
        if (&os == &cout) {
            os << "TRIAGE" << endl;
            Patient::write(os);
            os << "Symptoms: " << symptoms << endl;
        } else if (&os != &clog) {
            Patient::write(os);
            os << "," << symptoms;
        } else {
            Patient::write(os);
        }
        return os;
    }

    std::istream& TriagePatient::read(std::istream& istr) {
        char symp[512] {};
        Patient::read(istr);
        delete[] symptoms;
        symptoms = nullptr;
        if (&istr != &cin) {
            istr.ignore();
            istr.get(symp, 512, '\n');
            symptoms = new char[strlen(symp) + 1];
            U.strcpy(symptoms, symp);
            nextTriageTicket = Patient::number() + 1;
        }
        else{
            cout << "Symptoms: ";
            istr.get(symp, 512, '\n');
            istr.ignore(10000, '\n');
            symptoms = new char[U.strlen(symp) + 1];
            U.strcpy(symptoms, symp);
        }
        if(!istr)
        {
            delete[] symptoms;
            symptoms = nullptr;
        }
        return istr;
    }
}

