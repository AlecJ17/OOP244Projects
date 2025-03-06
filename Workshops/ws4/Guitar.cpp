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
#include <iostream>
#include <cstring>
#include "Guitar.h"
using namespace std;
namespace seneca {

    const char* GuitarStr::material() const {
        return m_material;
    }

    double GuitarStr::gauge() const {
        return m_gauge;
    }

    GuitarStr::GuitarStr() {}

    GuitarStr::GuitarStr(const char* ma, double ga) {
        strncpy(m_material, ma, MAT_LEN);
        m_gauge = ga;
    }

    Guitar::Guitar(const char* mod) : m_strings(nullptr), m_numStrings(0) {
        strncpy(m_model, mod, MODEL_LEN);
        m_model[MODEL_LEN] = '\0';
    }

    Guitar::Guitar(GuitarStr strs[], int ns, const char* mod) : m_numStrings(ns) {
        strncpy(m_model, mod, MODEL_LEN);
        m_model[MODEL_LEN] = '\0';
        m_strings = new GuitarStr[ns];
        for (int i = 0; i < ns; ++i) {
            m_strings[i] = strs[i];
        }
    }

    Guitar::~Guitar() {
        delete[] m_strings;
    }

    bool Guitar::changeString(const GuitarStr& gs, int sn) {
        if (sn < 0 || sn >= m_numStrings) {
            return false;
        }
        m_strings[sn] = gs;
        return true;
    }

    void Guitar::reString(GuitarStr strs[], int ns) {
        delete[] m_strings;
        m_strings = new GuitarStr[ns];
        m_numStrings = ns;
        for (int i = 0; i < ns; ++i) {
            m_strings[i] = strs[i];
        }
    }

    void Guitar::deString() {
        delete[] m_strings;
        m_strings = nullptr;
        m_numStrings = 0;
    }

    bool Guitar::strung() const {
        return m_strings != nullptr && m_numStrings > 0;
    }

    bool Guitar::matchGauge(double ga) const {
        if (!strung()) {
            return false;
        }
        for (int i = 0; i < m_numStrings; ++i) {
            if (m_strings[i].gauge() == ga) {
                return true;
            }
        }
        return false;
    }



    ostream& Guitar::display(ostream& os) const
    {
        if (!strung())
        {
            os << "***Empty Guitar***" << endl;
        }
        else
        {
            os << "Guitar Model: " << m_model << endl;
            os << "Strings: " << m_numStrings << endl;
            for (int i = 0; i < m_numStrings; ++i)
            {
                // Convert gauge to string with high precision
                string gaugeStr = to_string(m_strings[i].gauge());
                // Find the position of the decimal point
                size_t dotPos = gaugeStr.find('.');
                // Keep only one digit after the decimal point, if it exists
                if (dotPos != string::npos && dotPos + 2 < gaugeStr.length())
                {
                    gaugeStr = gaugeStr.substr(0, dotPos + 2);
                }

                os << "#";
                os << i + 1;
                cout.setf(ios::right);
                cout.width(MAT_LEN);
                os << m_strings[i].material();
                cout.unsetf(ios::right);
                os << " | ";
                os << gaugeStr << endl;
            }
        }
        return os;
    }

}