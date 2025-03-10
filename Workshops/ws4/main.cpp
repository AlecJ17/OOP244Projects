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
#include "Guitar.h"
#include "Guitar.h"
using namespace std;
using namespace seneca;

const int linelen = 30;

void printDivider(size_t cnt = linelen){
    for (auto i = 0u; i < cnt; ++i)
        std::cout << "*";
    std::cout << std::endl;
}

void printHeader(const char* head){
    std::cout << std::endl;
    printDivider(linelen);
    std::cout << head << std::endl;
    printDivider(linelen);
}

int main(){

  printHeader("Empty Guitar");
  Guitar gu;
  gu.display();
  printDivider();

  printHeader("Non Empty Guitar");
  GuitarStr gs[2] {
    {"Bronze", 0.74}, {"Steel", 0.92}
  };
  Guitar gu2(gs, 2, "Les Paul");
  gu2.display();
  printDivider();

  printHeader("Change Strings");
  bool act = gu2.changeString(GuitarStr{"Nylon", 0.62}, 0);
  if (act) gu2.display();
  else cout << "Unable to change strings (incorrect)" << endl;
  act = gu2.changeString(GuitarStr{"Nylon", 0.77}, 9);
  if (!act) cout << "Unable to change string (correct)" << endl;
  printDivider();

  printHeader("Destring and Restring");
  gu.reString(gs, 2);
  bool strung = gu.strung();
  if (strung) gu.display();
  else cout << "Guitar isn't strung (incorrect)" << endl;
  gu.deString();
  strung = gu.strung();
  if (!strung) cout << "Guitar is correctly destrung" << endl;
  printDivider();

  printHeader("Check Gauge");
  bool matchg = gu2.matchGauge(0.25);
  if (!matchg) cout << "Gauges don't match (correct)" << endl;
  gu2.changeString(GuitarStr{"Silver", 1.1}, 0);
  gu2.changeString(GuitarStr{"Silver", 1.1}, 1);
  matchg = gu2.matchGauge(1.1);
  if (matchg) cout << "Gauges match (correct)" << endl;
  printDivider();
}
