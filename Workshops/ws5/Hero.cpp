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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;
namespace seneca
{
    Hero::Hero() : m_powers(nullptr), m_numPowers(0), m_powerLevel(0)
    {
        m_heroName[0] = '\0';
    }

    Hero::Hero(const char* name, Power* powers, int numPowers)
                     : m_numPowers(numPowers), m_powerLevel(0)
    {
        strncpy(m_heroName, name, MAX_NAME_LENGTH);
        m_heroName[MAX_NAME_LENGTH] = '\0';
        m_powers = new Power[numPowers];
        for (int i = 0; i < numPowers; i++)
        {
            m_powers[i] = powers[i];
        }
        updatePowerLevel();
    }

    Hero::~Hero()
    {
        delete[] m_powers;
    }

    void Hero::updatePowerLevel()
    {
        m_powerLevel = 0;
        for (int i = 0; i < m_numPowers; ++i)
        {
            m_powerLevel += m_powers[i].checkRarity();
        }
        m_powerLevel *= m_numPowers;
    }

    ostream& Hero::display(ostream& out) const
    {
        out << "Name: " << m_heroName << endl
            << "List of available powers: " << endl;
        for (int i = 0; i < m_numPowers; ++i)
        {
            out << "  Name: " << m_powers[i].checkName() << ", Rarity: " <<
                                    m_powers[i].checkRarity() << endl;
        }
        out << "Power Level: " << m_powerLevel;
        return out;
    }

    Hero& Hero::operator+=(const Power& power)
    {
        Power* temp = new Power[m_numPowers + 1];
        for (int i = 0; i < m_numPowers; i++)
        {
            temp[i] = m_powers[i];
        }
        temp[m_numPowers] = power;
        delete[] m_powers;
        m_powers = temp;
        ++m_numPowers;
        updatePowerLevel();
        return *this;
    }

    Hero& Hero::operator-=(int decreaseValue)
    {
        m_powerLevel -= decreaseValue;
        if (m_powerLevel < 0) m_powerLevel = 0;
        return *this;
    }

    // Implementation of non-member comparison operators
    bool operator<(const Hero& a, const Hero& b)
    {
        return a.getPowerLevel() < b.getPowerLevel();
    }

    bool operator>(const Hero& a, const Hero& b)
    {
        return a.getPowerLevel() > b.getPowerLevel();
    }

    // Implementation of custom behavior operators
    Hero& operator>>(Power& power, Hero& hero)
    {
        hero += power;
        return hero;
    }

    Hero& operator<<(Hero& hero, Power& power)
    {
        hero += power;
        return hero;
    }
}