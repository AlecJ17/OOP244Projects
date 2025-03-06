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
#include <fstream>
#include "PreTriage.h"

using namespace std;

namespace seneca {

    PreTriage::PreTriage(const char* dataFilename)
    {
        m_averContWait = Time(15); // Default initialization
        m_averTriageWait = Time(5);
        m_dataFilename = new char[U.strlen(dataFilename) + 1];
        U.strcpy(m_dataFilename, dataFilename);
        m_lineupSize = 0;

        // Load the data from the file
        load();
    }
    PreTriage::~PreTriage() {
        for (int i = 0; i < m_lineupSize; i++) {
            delete m_lineup[i]; // Delete each patient object.
        }
        delete[] m_dataFilename; // Delete the dynamically allocated filename.
    }

    Time PreTriage::getWaitTime(const Patient& p) const {
        int count = 0;
        for (int i = 0; i < m_lineupSize; i++) {
            if (m_lineup[i]->type() == p.type()) {
                count++;
            }
        }
        return Time(p.type() == 'C' ? m_averContWait : m_averTriageWait) * count;
    }

    void PreTriage::setAverageWaitTime(const Patient& p) {
        Time CT = U.getTime(); // Assuming U.getTime() gives current system time in 'Time' format
        Time PTT = p.time();
        int PTN = p.number();

        // Calculation should factor in the current system time
        if (p.type() == 'C') {
            m_averContWait = ((CT - PTT) + (m_averContWait * (PTN - 1))) / PTN;
        } else {
            m_averTriageWait = ((CT - PTT) + (m_averTriageWait * (PTN - 1))) / PTN;
        }
    }


    int PreTriage::indexOfFirstInLine(char type) const {
        int index = -1;
        bool found = false;
        int i = 0;
        while (i < m_lineupSize && !found) {
            if (*m_lineup[i] == type) {
                index = i; // Set the index of the first matching patient
                found = true; // Set the flag to true if a matching patient is found
            }
            i++;
        }
        return index; // Return the index of the first matching patient or -1 if no matching patient is found
    }

    istream& PreTriage::load(istream& istr) {
        ifstream file(m_dataFilename);
        cout << "Loading data...\n";
        int counter = 0;
        if (file.is_open()) {
            file >> m_averContWait;
            file.ignore(10000, ','); // Skip the rest of the line.
            file >> m_averTriageWait;
            file.ignore(10000, '\n'); // Skip the rest of the line.

            Patient *p = nullptr;
            char type = '\0';
            for (int i = 0; i < maxNoOfPatients && file.peek() != EOF; i++) {
                file.get(type); // Read the patient type (C or T)
                file.ignore();
                if (type == 'C') {
                    p = new TestPatient();
                } else if (type == 'T') {
                    p = new TriagePatient();
                }
                if (p) {
                    p->read(file);
                    m_lineup[m_lineupSize++] = p;
                    counter++;
                    file.ignore();
                }
            }
            if (file.peek() != EOF) {
                cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
            }
            file.close(); // Close the file
        }
        if (counter > 0) {
            cout << counter << " Records imported...\n" << endl;
        } else {
            cout << "No data or bad data file!\n" << endl;
        }
        return istr;
    }

    ostream& PreTriage::save(ostream& ostr) const {
        ofstream file(m_dataFilename);
        cout << "Saving lineup...\n";

        if (file.is_open()) {
            file << m_averContWait << ',' << m_averTriageWait << '\n'; // Save average wait times.

            for (int i = 0; i < m_lineupSize; ++i) {
                m_lineup[i]->write(file);
                file << '\n';
            }

            // Calculate the number of each patient type saved.
            int contTests = 0, triageRecs = 0;
            for (int i = 0; i < m_lineupSize; ++i) {
                if (m_lineup[i]->type() == 'C'){
                    ++contTests;
                }
                else if (m_lineup[i]->type() == 'T'){
                    ++triageRecs;
                }
            }
            cout << contTests << " Contagion Tests and " << triageRecs << " Triage records were saved!\n";
            file.close(); // Close the file
        }
        return ostr;
    }

    void PreTriage::reg() {
        bool proceed = true;

        // Check if the lineup is full
        if (m_lineupSize >= maxNoOfPatients) {
            cout << "Line up full!\n";
            proceed = false;
        }

        // Create a Menu object for patient type selection
        Menu typeMenu("Select Type of Registration:\n"
                      "1- Contagion Test\n"
                      "2- Triage", 1);
        int selection;
        if (proceed) {
            typeMenu >> selection;
        }

        // Create a new patient based on the selection
        Patient* p = nullptr;
        if (proceed) {
            if (selection == 1) {
                p = new TestPatient;
            } else if (selection == 2) {
                p = new TriagePatient;
            } else {
                proceed = false; // Stop the function if the selection is 0
            }
        }

        // Set the patient's arrival time and read the patient information
        if (proceed) {
            p->setArrivalTime();
            cout << "Please enter patient information: \n";
            p->read(cin);
        }

        // Print the ticket
        if (proceed) {
            cout << "\n******************************************\n";
            p->write(cout);
            cout << "Estimated Wait Time: " << getWaitTime(*p) << "\n";
            cout << "******************************************\n\n";
        }

        // Add the patient to the lineup
        if (proceed) {
            m_lineup[m_lineupSize++] = p;
        }
    }

    istream& PreTriage::run(istream& istr){
        int selection;
        bool done = true;
            Menu m_appMenu("General Healthcare Facility Pre-Triage Application\n"
                           "1- Register\n"
                           "2- Admit\n"
                           "3- View Lineup");
        while (done) {
            m_appMenu >> selection;
            switch (selection) {
                case 0:
                    save();
                    done = false;
                    break;
                case 1:
                    reg();
                    break;
                case 2:
                    admit();
                    break;
                case 3:
                     lineUp();
                    break;
                default:
                    break;
            }
        }
        return istr;
    }

    void PreTriage::admit() {
        bool exit = false;
        // Create a Menu object for patient type selection
        Menu admitMenu("Select Type of Admittance:\n"
                       "1- Contagion Test\n"
                       "2- Triage", 1);
        int selection;
        admitMenu >> selection;

        char type;
        if (selection == 1) {
            type = 'C';
        } else if (selection == 2) {
            type = 'T';
        } else {
            exit = true; // Exit the function if the selection is 0
        }

        if (!exit) {
            int index = indexOfFirstInLine(type);
            if (index == -1) {
                cout << "Lineup is empty!\n";
            } else {
                Time CT = U.getTime();
                cout << "\n******************************************\n";
                cout << "Call time: [" << CT << "]" << endl;
                cout << "Calling at for ";
                m_lineup[index]->write(cout);
                cout << "******************************************\n\n";
                setAverageWaitTime(*m_lineup[index]);
                U.removeDynamicElement(m_lineup, index, m_lineupSize);
            }
        }
    }

    void PreTriage::lineUp() {
        // Create a Menu object for patient type selection
        Menu lineupMenu("Select The Lineup:\n"
                        "1- Contagion Test\n"
                        "2- Triage", 1);
        int selection;
        bool validSelection = true;
        lineupMenu >> selection;

        char type;
        if (selection == 1) {
            type = 'C';
        } else if (selection == 2) {
            type = 'T';
        } else {
            validSelection = false; // Exit the function if the selection is 0
        }

        cout << "Row - Patient name                                          OHIP     Tk #  Time\n";
        cout << "-------------------------------------------------------------------------------\n";

        int count = 1;
        for (int i = 0; i < m_lineupSize; ++i) {
            if (m_lineup[i]->type() == type) {
                cout.setf(ios::left);
                cout.width(4);
                cout << count++ << "- ";
                cout.width(53);
                cout.fill('.');
                cout << m_lineup[i]->operator const char *();
                cout.fill(' ');
                cout.unsetf(ios::left);
                cout.width(2);
                cout << m_lineup[i]->getOHIP();
                cout.width(5);
                cout << m_lineup[i]->number();
                cout.width(2);
                cout << m_lineup[i]->time() << "\n";
                validSelection = false;
            }
        }
        if (validSelection) {
            cout << "Line up is empty!\n";
        }
        cout << "-------------------------------------------------------------------------------\n";
    }

}
