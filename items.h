
#ifndef LAB10_M_ITEMS_H
#define LAB10_M_ITEMS_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <map>
#include "hero.h"

using namespace std;

// Node Declaration
struct itemNode { // node = itemNode
    string name;
    char attrType;
    int attrValue;
    int rarity;
    int quantity = 0;
    bool isEquipped = false;
    struct itemNode *next;
    struct itemNode *prev;

};

class items {
public:

    void load_items();
    void display_items();
    void display_equipped_items();
    void add_element(string, char, int, int);
    void create_list(string, char, int, int);

    void equipItem(int, hero*);
    void unequipItem(int, hero*);
    void addItem(int);

    int getS();
    int getI();
    int getC();
    int getE();
    int getD();

    items();
    itemNode* start;
    map<char, string> map_of_attr;
    map<int, string> map_of_rarity;

};


#endif //LAB10_M_ITEMS_H
