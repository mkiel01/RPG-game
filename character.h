

#ifndef LAB7_M_CHARACTER_H
#define LAB7_M_CHARACTER_H
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include "classes.h"
using namespace std;


class character {
public:
    virtual void printStats() = 0;
    virtual double getS() = 0;
    virtual double getI() = 0;
    virtual double getD() = 0;
    virtual double getE() = 0;
    virtual double getC() = 0;


protected:

    string name;
    double strength;
    double dexterity;
    double endurance;
    double intelligence;
    double charisma;
    int experience;


};



#endif
