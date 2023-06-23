

#ifndef LAB10_M_BATTLEHISTORY_H
#define LAB10_M_BATTLEHISTORY_H


#include <string>
#include <iostream>
using namespace std;

//Element declaration
struct lst_el {
    string battleResult; // name = battleResult
    lst_el *next; //
};

//definition of sinly listed list class
class battleHistory { // TsingleList = battleHistory
    lst_el* head;
    lst_el* tail;
    int nr_of_battles; // cnt = nr_of_battles

// my case
public:
    battleHistory();
    ~battleHistory();
    lst_el* addBattle(string); // for our case its a string from main not a lst_el * el also LINE: 41
    lst_el* deleteBattle();
    void displayHistory();


};


#endif //LAB10_M_BATTLEHISTORY_H
