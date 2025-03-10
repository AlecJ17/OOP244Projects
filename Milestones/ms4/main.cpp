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
#include <iostream>
#include <fstream>
#include "Patient.h"
#include "TestPatient.h"
#include "TriagePatient.h"
#include "Utils.h"
using namespace std;
using namespace seneca;
void CPTest(ifstream& input);
void TPTest(ifstream& input);

int main() {
    cout << "Milestone 4 tester" << endl;
    ifstream input("input.txt");
    CPTest(input);
    TPTest(input);
    return 0;
}

void CPTest(ifstream& input) {
    U.setDebugTime(12, 34);
    TestPatient A, B;
    cout << "Testing TestPatient:" << endl
         << "Enter the following values when prompted:" << endl
         << "aaa" << endl
         << "123123123" << endl
         << "------------------------" << endl << endl;
    A.setArrivalTime();
    cout << "Enter Patient information:" << endl;
    cin >> A;
    cout << endl << "Enter the following values when prompted:" << endl
         << "bbb" << endl
         << "234234234" << endl
         << "------------------------" << endl << endl;
    B.setArrivalTime();
    cout << "Enter Patient information:" << endl;
    cin >> B;
    cout << endl << "Patients information entered:" << endl;
    cout << A << endl << B << endl;
    cout << "CSV output:" << endl;
    cerr << A << endl << B << endl << endl;
    cout << "Linear output:" << endl;
    clog << A << endl << B << endl << endl;
    cout << "Testing CSV input;" << endl
         << "   Reading \"ccc,333333333,10,23:45\" from input.txt." << endl;
    input >> A;
    input.ignore(100, '\n');
    cout << endl << "Data read:" << endl;
    cout << A << endl;
    U.setDebugTime(23, 55);
    cout << "Testing global ticket number variable:" << endl
         << "Enter the following values when prompted:" << endl
         << "ddd" << endl
         << "345345345" << endl
         << "------------------------" << endl << endl;
    TestPatient C;
    C.setArrivalTime();
    cin >> C;
    cout << "Patient information entered:" << endl;
    cout << C << endl;
}
void TPTest(ifstream& input) {
    U.setDebugTime(12, 34);
    TriagePatient A, B;
    cout << "Testing TriagePatient:" << endl;
    cout << "Enter the following values when prompted:" << endl
         << "aaa" << endl
         << "123123123" << endl
         << "aaa aaa aaa" << endl
         << "------------------------" << endl << endl;
    A.setArrivalTime();
    cout << "Enter Patient information:" << endl;
    cin >> A;
    cout << endl << "Enter the following values when prompted:" << endl
         << "bbb" << endl
         << "234234234" << endl
         << "bbb bbb bbb" << endl
         << "------------------------" << endl << endl;
    B.setArrivalTime();
    cout << "Enter Patient information:" << endl;
    cin >> B;
    cout << endl << "Patients information entered:" << endl;
    cout << A << endl << B << endl;
    cout << "CSV output: " << endl;
    cerr << A << endl << B << endl << endl;
    cout << "Linear output:" << endl;
    clog << A << endl << B << endl << endl;
    cout << "Testing CSV input;" << endl
         << "   Reading \"ccc,333333333,10,23:45,ccc ccc ccc\" from input.txt." << endl;
    input >> A;
    input.ignore(100, '\n');
    cout << endl << "Data read:" << endl;
    cout << A << endl;
    U.setDebugTime(23, 55);
    cout << "Testing global ticket number variable:" << endl
         << "Enter the following values when prompted:" << endl
         << "ddd" << endl
         << "444444444" << endl
         << "ddd ddd ddd" << endl
         << "------------------------" << endl << endl;
    TriagePatient C;
    C.setArrivalTime();
    cin >> C;
    cout << endl << "Patient information entered:" << endl;
    cout << C << endl;
}