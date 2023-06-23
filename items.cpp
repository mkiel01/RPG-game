#include "items.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip> // for setw
#include <map>
#include "hero.h"

items::items() {

    start = nullptr;

    map_of_attr['s'] = "strength";
    map_of_attr['d'] = "dexterity";
    map_of_attr['e'] = "endurance";
    map_of_attr['i'] = "intelligence";
    map_of_attr['c'] = "charisma";
    

    map_of_rarity[1] = "Common";
    map_of_rarity[2] = "Rare";
    map_of_rarity[3] = "Epic";
    map_of_rarity[4] = "Legendary";

}

// Create Double Link List
void items::create_list(string newname, char newtype, int newval, int newrar) {

    struct itemNode* s;
    struct itemNode* temp;
    temp = new(struct itemNode);
    temp->name = newname;
    temp->attrType = newtype;
    temp->attrValue = newval;
    temp->rarity = newrar;

    temp->next = nullptr;

    if(start == nullptr) {
        temp->prev = nullptr;
        start = temp;
    }
    else {
        s = start;
        while (s->next != nullptr) {
            s = s->next;
            s->next = temp;
            temp->prev = s;
        }
    }
}

// Insertion at the beginning
void items::add_element(string item_name, char type, int value, int rar) {

    if( start == nullptr) {
        cout<<"First Create the list." <<endl;
        return;
    }
    auto *newitem = new(struct itemNode); // temp = new(struct node);
    newitem->name = item_name; //temp = newitem
    newitem->attrType = type;
    newitem->attrValue = value;
    newitem->rarity = rar;

    newitem->prev = nullptr;
    newitem->next = start;
    start->prev = newitem;
    start = newitem;
}

void items::load_items() {

    fstream file;
    file.open("items.txt", ios::in);

    if(file.good()) {
        string temp_name;
        char temp_attrName;
        int temp_attrN;
        int temp_rarity;

        file >> temp_name >> temp_attrName >> temp_attrN>> temp_rarity;

        for (char & i : temp_name) { // goes thought every element in a temp_name (jan -> j,a,n for ex diamond_armor = diamond armor)
            if (i == '_') {
                i = ' ';
            }
        }
        create_list(temp_name,temp_attrName,temp_attrN,temp_rarity);

        while(!file.eof()) {
            file >> temp_name >> temp_attrName >> temp_attrN>> temp_rarity;
            if(file.eof()) break;

            for (char & i : temp_name) {
                if (i == '_') {
                    i = ' ';
                }
            }

            add_element(temp_name, temp_attrName, temp_attrN, temp_rarity);
        }
    }
    else {
        cout<<"...";
    }

}

// Display elements of Doubly Link List
void items::display_items() {
    auto* q = start;


    cout<<setw(5)<<"ID"<<setw(30)<<"name"<<setw(20)<<"type of buff"<<setw(10)<<"+++"<<setw(10)<<"rarity"<<setw(10)<<"quantity"<<endl;
    int i = 0;
    while(q != nullptr) { // start = ptr
        i++;
        if (q->quantity > 0) {

            cout << setw(5) << i << setw(30) << q->name << setw(20) << map_of_attr[q->attrType] << setw(10)
                 << q->attrValue << setw(10) << map_of_rarity[q->rarity] << setw(10) << q->quantity << endl;
        }

        q = q->next;

    }

}
void items::display_equipped_items() {
    auto* q = start;


    cout<<setw(5)<<"ID"<<setw(30)<<"name"<<setw(20)<<"type of buff"<<setw(10)<<"+++"<<setw(10)<<"rarity"<<setw(10)<<"quantity"<<endl;
    int i = 0;
    while(q != nullptr) {
        i++;
        if (q->quantity > 0 && q->isEquipped) {

            cout << setw(5) << i << setw(30) << q->name << setw(20) << map_of_attr[q->attrType] << setw(10)
                 << q->attrValue << setw(10) << map_of_rarity[q->rarity] << setw(10) << q->quantity << endl;
        }

        q = q->next;

    }

}


void items::equipItem(int ID, hero* hero_attr) {
    auto* q = start;
    int i = 1;
    while(q != nullptr) {
        if(i == ID) {

            if(q->quantity < 1) {
                cout<<"you do not posses this item"<<endl;
                return;
            }
            else if(q->isEquipped) {
                cout<<"you have already equipped this item"<<endl;
                return;
            }

            q->isEquipped = true;

            switch (q->attrType) {
                case 's':
                    hero_attr->setS(q->attrValue);
                    break;
                case 'i':
                    hero_attr->setI(q->attrValue);
                    break;
                case 'c':
                    hero_attr->setC(q->attrValue);
                    break;
                case 'd':
                    hero_attr->setD(q->attrValue);
                    break;
                case 'e':
                    cout<< "you are here"<<endl;
                    hero_attr->setE(q->attrValue);
                    break;

                default:
                    cout<<"Something went wrong"<<endl;
                    break;

            }

            return;
        }
        q = q->next;
        i++;
    }
    cout<<"Pick a good ID"<<endl;
}

void items::unequipItem(int ID, hero* hero_attr) {
    auto* q = start;
    int i = 1;
    while(q != nullptr) {
        if(i == ID) {

            if(q->quantity < 1) {
                cout<<"you do not posses this item"<<endl;
                return;
            }
            else if(!q->isEquipped) {
                cout<<"you don't have this item equipped"<<endl;
                return;
            }
            q->isEquipped = false;

            switch (q->attrType) {
                case 's':
                    hero_attr->setS(-q->attrValue);
                    break;
                case 'i':
                    hero_attr->setI(-q->attrValue);
                    break;
                case 'c':
                    hero_attr->setC(-q->attrValue);
                    break;
                case 'd':
                    hero_attr->setD(-q->attrValue);
                    break;
                case 'e':

                    hero_attr->setE(-q->attrValue);
                    break;

                default:
                    cout<<"Something went wrong"<<endl;
                    break;

            }

            return;
        }
        q = q->next;
        i++;
    }

    cout<<"Pick a good ID"<<endl;
}

void items::addItem(int ID) {
    auto* q = start;
    int i = 1;
    while(q != nullptr) {
        if(i == ID) {
            q->quantity += 1;
            cout<<"the monster drooped: "<<q->name<<endl;
            return;
        }
        q = q->next;
        i++;
    }
    cout<<"the monster didn't drop anything :(("<<endl;

}


// Display elements of Doubly Link List

int items::getS() {
    int val = 0;
    auto* q = start;
    while(q != nullptr) {

        if(q-> isEquipped && q->attrType == 's') val += q->attrValue;
        q = q->next;
    }
    return val;
}

int items::getI() {
    int val = 0;
    auto* q = start;
    while(q != nullptr) {

        if(q-> isEquipped && q->attrType == 's') val += q->attrValue;
        q = q->next;
    }
    return val;
}

int items::getD() {
    int val = 0;
    auto* q = start;
    while(q != nullptr) {

        if(q-> isEquipped && q->attrType == 's') val += q->attrValue;
        q = q->next;
    }
    return val;
}

int items::getE() {
    int val = 0;
    auto* q = start;
    while(q != nullptr) {

        if(q-> isEquipped && q->attrType == 's') val += q->attrValue;
        q = q->next;
    }
    return val;
}

int items::getC() {
    int val = 0;
    auto* q = start;
    while(q != nullptr) {

        if(q-> isEquipped && q->attrType == 's') val += q->attrValue;
        q = q->next;
    }
    return val;
}


