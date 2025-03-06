/*
     *****************************************************************************
                   <Workshop - #5 (Part-2)>
     Full Name         : Alec Josef Serrano
     Student ID#       : 133592238
     Email             : ajserrano2@myseneca.ca
     Section           : NEE
     Date Accomplished : February 16,2024
     Authenticity Declaration:
     I declare this submission is the result of my own work and has not been
     shared with any other student or 3rd party content provider. This submitted
     piece of work is entirely of my own creation.
     *****************************************************************************
*/
#ifndef SENECA_HERO_H
#define SENECA_HERO_H

#include <iostream>
#include "Power.h" // Ensure this file exists and is correctly implemented

namespace seneca
{

    class Hero
    {
    private:
        char m_heroName[MAX_NAME_LENGTH + 1];
        Power* m_powers;
        int m_numPowers;
        int m_powerLevel;

        void updatePowerLevel();

    public:
        Hero();
        Hero(const char* name, Power* powers, int numPowers);
        ~Hero();

        // Assuming ostream& for chaining with endl in the main.cpp
        std::ostream& display(std::ostream& out = std::cout) const;

        Hero& operator+=(const Power& power);
        Hero& operator-=(int decreaseValue);

        int getPowerLevel() const
        {
            return m_powerLevel;
        }
    };

    // Comparison operators
    bool operator<(const Hero& a, const Hero& b);
    bool operator>(const Hero& a, const Hero& b);

    // Custom behavior operators
    Hero& operator>>(Power& power, Hero& hero);
    Hero& operator<<(Hero& hero, Power& power);
}

#endif // SENECA_HERO_H
