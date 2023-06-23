//
// Created by Michał Kiełkowski on 19/06/2023.
//

#include "hero.h"
#include <utility>


hero::hero(string newname, double newstrength, double newdexterity, double newendutance, double newintelligence, double newcharisma) {
    name = newname;
    strength = newstrength;
    dexterity = newdexterity;
    endurance = newendutance;
    intelligence = newintelligence;
    charisma = newcharisma;
    experience = 0;
    level = 0;
}


void hero::load(string filename) {

    fstream file;

    file.open(filename + ".txt", ios::in);
    name = filename;

    if(file.good()) {
        file>>name;
        file>>strength;
        file>>dexterity;
        file>>endurance;
        file>>intelligence;
        file>>charisma;
        file>>experience;

    }
    else {
        cout<<"Something went wrong with opening: "<<filename<<endl;
    }
    file.close();
    level = experience/50;

}

void hero::save() {
    fstream file;

    file.open(name +".txt", ios::out);

    if (file.good()) {
        file<<name<<endl;
        file<<strength<<endl;
        file<<dexterity<<endl;
        file<<endurance<<endl;
        file<<intelligence<<endl;
        file<<charisma<<endl;
        file<<experience<<endl;

    }

}

void hero::printStats() {
    cout<<"Statistics of "<<name<<endl;
    cout<<"Strength = "<<strength<<endl;
    cout<<"Dexterity = "<<dexterity<<endl;
    cout<<"Endurance = "<<endurance<<endl;
    cout<<"Intelligence = "<<intelligence<<endl;
    cout<<"Charisma = "<<charisma<<endl;
    cout<<"Level = "<<level<<endl;

}

void hero::setClass() {

    int choice = 0;
    cout<<"Choose class"<<endl;
    cout<<"1 - mage"<<endl;
    cout<<"2 - warrior"<<endl;
    cout<<"3 - berserk"<<endl;
    cout<<"4 - thief"<<endl;

    cin>>choice;

    switch (choice) {
        case 1:
            mage::increaseAttribute(&intelligence);
            break;

        case 2:
            warrior::increaseAttribute(&endurance);
            break;

        case 3:
            berserker::increaseAttribute(&strength);
            break;

        case 4:
            thief::increaseAttribute(&dexterity);
            break;
    }

    }
    double hero::getS() {
        return strength;
    }

    double hero::getI() {
        return intelligence;
    }

    double hero::getD() {
        return dexterity;
    }

    double hero::getE() {
        return endurance;
    }

    double hero::getC() {
        return charisma;
    }

void hero::changeExp(int exp) {
    experience += exp;
    if(experience < 0) experience = 0;
    level = experience/50;
}

void hero::setS(int toadd) {
    strength += toadd;
}

void hero::setE(int toadd) {
    endurance += toadd;

}

void hero::setI(int toadd) {
    intelligence += toadd;
}

void hero::setD(int toadd) {
    dexterity += toadd;
}

void hero::setC(int toadd) {
    charisma += toadd;
}




