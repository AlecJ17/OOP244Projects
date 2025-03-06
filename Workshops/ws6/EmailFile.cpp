/*
     *****************************************************************************
                   <Workshop - #6 (Lab)>
     Full Name         : Alec Josef Serrano
     Student ID#       : 133592238
     Email             : ajserrano2@myseneca.ca
     Section           : NEE
     Date Accomplished : March 06,2024
     Authenticity Declaration:
     I declare this submission is the result of my own work and has not been
     shared with any other student or 3rd party content provider. This submitted
     piece of work is entirely of my own creation.
     *****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <cstring>
#include "EmailFile.h"

using namespace std;
namespace seneca
{

    Email& Email::operator=(const Email& rhs) {

        if (this != &rhs && rhs.m_email && rhs.m_name) {
            delete[] m_email;
            m_email = nullptr;
            m_email = new char[strlen(rhs.m_email) + 1];
            strcpy(m_email, rhs.m_email);
            delete[] m_name;
            m_name = nullptr;
            m_name = new char[strlen(rhs.m_name) + 1];
            strcpy(m_name, rhs.m_name);
            strcpy(m_year, rhs.m_year);
        }

        return *this;
    }

    bool Email::load(std::ifstream& in) {

        char buffer[BUFFER_SIZE];
        bool result = false;

        if (in.getline(buffer, BUFFER_SIZE, ',')) {
            delete[] m_email;
            m_email = new char[strlen(buffer) + 1];
            strcpy(m_email, buffer);

            if (in.getline(buffer, BUFFER_SIZE, ',')) {
                delete[] m_name;
                m_name = new char[strlen(buffer) + 1];
                strcpy(m_name, buffer);

                if (in.getline(buffer, BUFFER_SIZE, '\n')) {
                    strcpy(m_year, buffer);
                    result = true;
                }
            }
        }

        return result;
    }

   Email::~Email() {
      delete[] m_name;
      delete[] m_email;
   }

    void EmailFile::setFilename(const char* filename)
    {
        delete[] m_filename;
        m_filename = nullptr;
        if (filename)
        {
            m_filename = new char[strlen(filename) + 1];
            m_filename[0] = '\0';
            strcpy(m_filename, filename);
        }
    }

    void EmailFile::setEmpty()
    {
        delete[] m_emailLines;
        delete[] m_filename;
        m_emailLines = nullptr;
        m_filename = nullptr;
        m_noOfEmails = 0;
    }

    bool EmailFile::setNoOfEmails() {

        bool isValid = false;
        ifstream file(m_filename);

        if (!file.is_open()) {
            cout << "Failed to open file: " << m_filename << endl;
        }
        else
        {
            m_noOfEmails = 0;
            while (file) {
                m_noOfEmails += (file.get() == '\n');
            }
            file.close();

            if (m_noOfEmails == 0)
            {
                delete[] m_filename;
                m_filename = nullptr;
            }
            else {
                m_noOfEmails++;
                isValid = true;
            }
        }
        return isValid;
    }

    // Default Constructor
    EmailFile::EmailFile() {
        setEmpty();
    }

// Parametric Constructor
    EmailFile::EmailFile(const char* filename) {
        setEmpty();
        if (filename != nullptr) {
            setFilename(filename);
            if (setNoOfEmails()) {
                loadEmails();
            }
        }
    }

    //Rule of Three
    // Copy Constructor
    EmailFile::EmailFile(const EmailFile& other) : m_emailLines(nullptr),
                                    m_filename(nullptr), m_noOfEmails(0)
    {
        if (other) {
            *this = other; // Utilize copy assignment
        }
    }

// Copy Assignment Operator
    EmailFile& EmailFile::operator=(const EmailFile& rhs) {
        if (this != &rhs && rhs) {
            setEmpty(); // Clear current state
            setFilename(rhs.m_filename);
            m_noOfEmails = rhs.m_noOfEmails;
            if (m_noOfEmails > 0) {
                m_emailLines = new Email[m_noOfEmails];
                for (int i = 0; i < m_noOfEmails; ++i) {
                    m_emailLines[i] = rhs.m_emailLines[i];
                }
            }
        }
        return *this;
    }

    // Destructor
    EmailFile::~EmailFile() {
        setEmpty();
    }

    // Boolean cast operator
    EmailFile::operator bool() const {
        return m_filename != nullptr && m_emailLines != nullptr && m_noOfEmails > 0;
    }

    // Load Emails from file
    void EmailFile::loadEmails() {
        if (m_filename) {

            delete[] m_emailLines;
            m_emailLines = new Email[m_noOfEmails];

            std::ifstream file(m_filename);
            int loadedEmails = 0;
            while (loadedEmails < m_noOfEmails && m_emailLines[loadedEmails].load(file)) {
                ++loadedEmails;
            }
            m_noOfEmails = loadedEmails; // Adjust the actual number of loaded emails
        }
    }

    // Save to file
    bool EmailFile::saveToFile(const char* filename) const {
        if (!filename) return false;

        std::ofstream file(filename);
        if (!file) {
            std::cout << "Error: Could not open file: " << filename << std::endl;
            return false;
        }

        for (int i = 0; i < m_noOfEmails; ++i) {
            file << m_emailLines[i].m_email << ',' << m_emailLines[i].m_name
                                << ',' << m_emailLines[i].m_year << std::endl;
        }

        return true;
    }

    // Concatenate files
    void EmailFile::fileCat(const EmailFile& obj, const char* name) {
        if (!*this || !obj) return;

        int totalEmails = m_noOfEmails + obj.m_noOfEmails;
        Email* temp = new Email[totalEmails];

        for (int i = 0; i < m_noOfEmails; ++i) {
            temp[i] = m_emailLines[i];
        }
        for (int j = 0; j < obj.m_noOfEmails; ++j) {
            temp[m_noOfEmails + j] = obj.m_emailLines[j];
        }

        delete[] m_emailLines;
        m_emailLines = temp;
        m_noOfEmails = totalEmails;

        if (name) {
            setFilename(name);
        }

        saveToFile(m_filename); // Optionally save to a new file
    }

    std::ostream& EmailFile::view(std::ostream& ostr) const
    {
        if (m_filename) {
            ostr << m_filename << endl;
            ostr.width(strlen(m_filename));
            ostr.fill('=');
            ostr << "=" << endl;
            ostr.fill(' ');
            for (int i = 0; i < m_noOfEmails; i++) {
                ostr.width(35);
                ostr.setf(ios::left);
                ostr << m_emailLines[i].m_email;
                ostr.width(25);
                ostr << m_emailLines[i].m_name;
                ostr << "Year = " << m_emailLines[i].m_year << endl;
            }
        }

            return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const EmailFile& text)
    {
        return text.view(ostr);
    }

}