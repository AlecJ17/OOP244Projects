/*
     *****************************************************************************
                   <Milestone 5>
     Full Name         : Alec Josef Serrano
     Student ID#       : 133592238
     Email             : ajserrano2@myseneca.ca
     Section           : NEE
     Date Accomplished : April 05,2024
     Authenticity Declaration:
     I declare this submission is the result of my own work and has not been
     shared with any other student or 3rd party content provider. This submitted
     piece of work is entirely of my own creation.
     *****************************************************************************
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include "PreTriage.h"
#include "Utils.h"

using namespace std;
using namespace seneca;
void copyFile(const char* des, const char* src) {
   ifstream infile(src);
   ofstream outfile(des);
   if (outfile) {
      char ch;
      while (infile.get(ch)) {
         outfile.put(ch);
      }
   }
}
void displayFile(const char* fname) {
   ifstream fin(fname);
   char ch;
   cout << endl << "******  Content of file: \"" << fname << "\":" << endl;
   while (fin.get(ch)) cout << ch;
   cout << "***************************************************" << endl << endl;
}
void noFile() {
   PreTriage P("emptyfile.csv");
   P.run();
}
void emptyFile() {
   PreTriage P("emptyfile.csv");
   P.run();
}
void sixteenPatients() {
   U.setDebugTime(14, 40);
   copyFile("smalldata.csv", "smalldata.csv.bak");
   seneca::debug = true;
   PreTriage P("smalldata.csv");
   remove("smalldata.csv");
   P.run();
}
int main() {
   remove("emptyfile.csv");
   noFile();
   displayFile("emptyfile.csv");
   emptyFile();
   displayFile("emptyfile.csv");
   sixteenPatients();
   displayFile("smalldata.csv");
   remove("emptyfile.csv");
   return 0;
}


