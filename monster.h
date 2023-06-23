#ifndef LAB9_M_MONSTER_H
#define LAB9_M_MONSTER_H


#include "character.h"
#include <random>


class monster: character {
public:
    monster();
    void printStats();
    double getS();
    double getI();
    double getD();
    double getE();
    double getC();
    int getExp();


    static void save(monster* moster_get); // statics makes it possible for me to invoke a method of class without a need to invoke it by object of this class (look main)
};

#endif //LAB9_M_MONSTER_H
