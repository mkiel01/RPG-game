#include "monster.h"

monster::monster() {
    strength = rand()%10 + 1;
    dexterity = rand()%10 + 1;
    endurance = rand()%10 + 1;
    intelligence = rand()%10 + 1;
    charisma = rand()%10 + 1;
    experience = rand()%100 + 1;

}

void monster::printStats() {
    cout<<"Strength = "<<strength<<endl;
    cout<<"Dexterity = "<<dexterity<<endl;
    cout<<"Endurance = "<<endurance<<endl;
    cout<<"Intelligence = "<<intelligence<<endl;
    cout<<"Charisma = "<<charisma<<endl;
    cout<<"Experience = "<<experience<<endl;

}

void monster::save(monster* moster_get) {
    fstream file;

    file.open("monsters.txt", ios::out);

    if (file.good()) {
        for (int i = 0; i < 5; i++) {
            file << "Monster " << i  << endl;
            file << moster_get[i].getS() << endl;
            file << moster_get[i].getD() << endl;
            file << moster_get[i].getE() << endl;
            file << moster_get[i].getI() << endl;
            file << moster_get[i].getC() << endl;
            file << moster_get[i].getExp() << endl;

        }

    }
}

double monster::getS() {
    return strength;
}

double monster::getI() {
    return intelligence;
}

double monster::getD() {
    return dexterity;
}

double monster::getE() {
    return endurance;
}

double monster::getC() {
    return charisma;
}
int monster::getExp() {
    return experience;
}