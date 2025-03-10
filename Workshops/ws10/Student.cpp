/*
     *****************************************************************************
                   <Workshop - 10>
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
// Module supplied
#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"

using namespace std;

namespace seneca {
    Student::Student() {
        m_id = 0;
        m_name[0] = '\0';
        m_program[0] = '\0';
        for (int i = 0; i < 32; i++)
            m_marks[i] = 0.0f;
        m_numCourses = 0;
    }
    Student::Student(int id, const char* name, const char* program, const float* marks, int num) {
        *this = Student();
        if (id > 0 && name) {
            m_id = id;
            strcpy(m_name, name);
            if (program)
                strcpy(m_program, program);
            if (marks && num > 0) {
                m_numCourses = num;
                for (int i = 0; i < m_numCourses; i++) {
                    m_marks[i] = marks[i];
                }
            }
        }
    }
    const char* Student::Program() const {
        return m_program;
    }
    bool Student::operator==(int x) const {
        return m_id == x;
    }
    bool Student::operator==(double y) const {
        double avg = 0.0;
        for (int i = 0; i < m_numCourses; i++) {
            avg += m_marks[i];
        }
        avg /= m_numCourses;
        return (avg - y) * (avg - y) < 0.01;
    }

    bool Student::operator==(const Book& bk) const {
        bool retval = false;
        for (int j = 0; j < bk.NumDsicplines(); j++)
            retval = retval || !strcmp(m_program, bk.Discipline(j));
        return retval;
    }

    std::ostream& Student::display(std::ostream& os) const {
        std::string str;
        for (int i = 0; i < m_numCourses; i++) {
            str += to_string(m_marks[i]).substr(0, 4);
            if (i < m_numCourses - 1)
                str += ",";
        }
        os << setw(4) << m_id << ","
           << setw(13) << m_name << ","
           << setw(3) << m_program << ",mks:"
           << setw(20) << str;
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const Student& stu) {
        return stu.display(os);
    }

}