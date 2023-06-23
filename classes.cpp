#include "classes.h"



void mage::increaseAttribute(double *intelligence) {
    *intelligence += 5;
}

void warrior::increaseAttribute(double *endurance) {
    *endurance += 5;
}

void berserker::increaseAttribute(double *strength) {
    *strength += 5;
}

void thief::increaseAttribute(double *dexterity) {
    *dexterity += 5;
}