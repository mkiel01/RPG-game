#ifndef LAB8_M_CLASSES_H
#define LAB8_M_CLASSES_H
#include "character.h"


class mage {
public:
    friend class character;

    static void increaseAttribute(double*);

};

class warrior {
public:
    friend class character;

    static void increaseAttribute(double*);

};

class berserker {
public:
    friend class character;

    static void increaseAttribute(double*);
};

class thief {
public:
    friend class character;

    static void increaseAttribute(double*);

};


#endif
