#ifndef LAB10_M_HERO_H
#define LAB10_M_HERO_H
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include "classes.h"
#include "character.h"


class hero : character{
public:
    hero(string,double,double,double,double, double);
    hero(string);
    hero(){}
    void save();
    void printStats();
    void create_character(string);
    void load(string);
    void setClass();
    void changeExp(int);

    double getS();
    double getI();
    double getC();
    double getE();
    double getD();

    void setS(int);
    void setI(int);
    void setC(int);
    void setE(int);
    void setD(int);

protected:
    string name;
    double strength;
    double dexterity;
    double endurance;
    double intelligence;
    double charisma;
    int level;


};


#endif //LAB10_M_HERO_H
