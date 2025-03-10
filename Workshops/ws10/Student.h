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
#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H
#include<cstring>
#include<string>
#include "Book.h"

namespace seneca {
    class Book;
    class Student {
        int m_id;
        char m_name[256];
        float m_marks[32];
        int m_numCourses;
        char m_program[4]; // program student enrolled in
    public:
        Student();
        Student(int id, const char* name, const char* program, const float* marks, int num);
        const char* Program() const;
        bool operator==(int) const;
        bool operator==(double) const;
        bool operator==(const Book& bk) const;
        std::ostream& display(std::ostream&) const;
    };
    std::ostream& operator<<(std::ostream&, const Student&);

}

#endif