/*
     *****************************************************************************
                   <Workshop - #4 (DIY)>
     Full Name         : Alec Josef Serrano
     Student ID#       : 133592238
     Email             : ajserrano2@myseneca.ca
     Section           : NEE
     Date Accomplished : February 12,2024
     Authenticity Declaration:
     I declare this submission is the result of my own work and has not been
     shared with any other student or 3rd party content provider. This submitted
     piece of work is entirely of my own creation.
     *****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_GUITAR_H
#define SENECA_GUITAR_H

#include <iostream>
#include <cstring>
#define MAT_LEN 10
#define MODEL_LEN 15

using namespace std;
namespace seneca {

    class GuitarStr {
        char m_material[MAT_LEN]{};
        double m_gauge{};
    public:
        const char* material()const;
        double gauge()const;
        GuitarStr();
        GuitarStr(const char* ma, double ga);
    };

    class Guitar {
        GuitarStr* m_strings;
        int m_numStrings;
        char m_model[MODEL_LEN + 1]; // 15 characters + 1 for null terminator
    public:
        Guitar(const char* mod = "Stratocaster");
        Guitar(GuitarStr strs[], int ns, const char* mod);
        ~Guitar();

        bool changeString(const GuitarStr& gs, int sn);
        void reString(GuitarStr strs[], int ns);
        void deString();

        bool strung() const;
        bool matchGauge(double ga) const;
        ostream& display(ostream& os = cout) const;
    };
}

#endif

