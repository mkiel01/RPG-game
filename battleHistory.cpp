
#include "battleHistory.h"
// line 20:
battleHistory::battleHistory() {
    head = nullptr;
    tail = nullptr;
    nr_of_battles = 0;
}
battleHistory::~battleHistory() {
    lst_el* node;
    while(head) {
        node = head->next;  // el = node
        delete head;
        head = node;
    }
}
//Method adding an element at the front of the list::: we need to change the code as we have string result as input
lst_el *battleHistory::addBattle(string result) {

    auto* newBattle = new lst_el;
    newBattle->battleResult = result;


    newBattle->next = head;
    head = newBattle;
    if(!tail) tail = head;
    nr_of_battles++;

    if(nr_of_battles >= 11) {
        deleteBattle();
    }
    return head;
}

//Method deleting the last element of the list
lst_el *battleHistory::deleteBattle() {
    lst_el* node;

    if(tail) {
        node = tail;
        if(node == head) head = tail = nullptr;
        else {
            tail = head;
            while(tail-> next != node) tail = tail->next;
            tail->next = nullptr;
        }
        nr_of_battles--;
        return node;
    }
    else return nullptr;
}

//Methods used to display data stored in the list
void battleHistory::displayHistory() {
    lst_el* node;
    int i = 1;
    if(!head) cout<<"No battles yet fought!"<<endl;
    else {
        node = head;
        while (node) {
            cout<<i<<": "<<node->battleResult<<endl;
            node = node -> next;
            i++;
        }
    }


}
