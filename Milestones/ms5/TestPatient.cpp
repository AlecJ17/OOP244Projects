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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "TestPatient.h"
#include "Patient.h"


using namespace std;
namespace seneca {
    int nextTestTicket = 1;

    TestPatient::TestPatient() : Patient(nextTestTicket++) {}

    char TestPatient::type() const {
        return 'C';
    }

    ostream& TestPatient::write(ostream& os) const {
        if (&os == &cout) {
            os << "Contagion TEST" << endl;
        }
        Patient::write(os);
        return os;
    }

    istream& TestPatient::read(istream& is) {
        Patient::read(is);
        if (&is != &cin) {
            nextTestTicket = Patient::number() + 1;
        }
        return is;
    }
}

