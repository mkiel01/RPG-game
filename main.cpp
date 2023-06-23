#include "character.h"
#include "monster.h"
#include "hero.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include "battleHistory.h"
#include "items.h"
using namespace std;

int res;

template <class T> class Battle {
public:
    Battle() {}

    int fight_phys(T hero, monster *opponent) {

        int hero_hp = hero.getE() * 100;
        int monster_hp = opponent->getE() * 100;
        int hero_attack_points = hero.getS() * 20;
        int monster_attack_points = opponent->getS() * 20;



        int hero_choice;
        int monster_choice;

        cout << "Hero total attack points: " << hero.getS()<< endl;
        cout << "Monster total attack points: " << opponent->getS()<< endl;

        while (hero_hp > 0 && monster_hp > 0) {

            monster_choice = (rand()%3+1);

            cout<< "1-rock"<<endl;
            cout<< "2-paper"<<endl;
            cout<< "3-scissors"<<endl;
            cout<< "pick your wepon"<<endl;
            cin>> hero_choice;



            if (hero_choice == monster_choice){
                cout<<"draw"<<endl;
            }


            else if(hero_choice == 1 && monster_choice == 2){
                cout<<"you lose!"<<endl;
                cout<<"rock loses to paper: monster attacks"<<endl;
                hero_hp -= monster_attack_points;
            }
            else if(hero_choice == 2 && monster_choice == 1){
                cout <<"you win!"<<endl;
                cout <<"paper beats rock: hero attacks"<<endl;
                monster_hp -= hero_attack_points;
            }
            else if(hero_choice == 3 && monster_choice== 2){
                cout <<"you win!"<<endl;
                cout <<"scissors beats paper: hero attacks"<<endl;
                monster_hp -= hero_attack_points;
            }
            else if(hero_choice == 2 && monster_choice == 3){
                cout <<"you lose!"<<endl;
                cout <<"paper loses to scissors: monster attacks"<<endl;
                hero_hp -= monster_attack_points;
            }
            else if(hero_choice == 1 && monster_choice== 3){
                cout <<"you win!"<<endl;
                cout <<"rock beats scissors: hero attacks"<<endl;
                monster_hp -= hero_attack_points;
            }
            else if(hero_choice == 3 && monster_choice == 1){
                cout <<"you lose!"<<endl;
                cout <<"scissors lose to rock: hero attacks"<<endl;
                hero_hp -= monster_attack_points;
            }

            cout << "\n";
        }
        if (hero_hp > 0) return res = 1;
        return res = 0;


    }
};

int main() {

    hero your_hero;
    monster monsters[5]; // Create an array of monster objects
    Battle<hero> fight;
    battleHistory history;

    struct itemNode* head = nullptr; // struct node
    items items_list; // double_llist dl;
    items_list.load_items();



    while (true) {

        cout << "Choose your action" << endl;
        cout << "pick 1 to make new hero" << endl;
        cout << "pick 2 to select class of hero" << endl;
        cout << "pick 3 to to show stats of hero" << endl;
        cout << "pick 4 to display owned items"<<endl;
        cout << "pick 5 to display equipped items"<<endl;
        cout << "pick 6 to equip item "<<endl;
        cout << "pick 7 to unequip item"<<endl;
        cout << "pick 8 to save current hero" << endl;
        cout << "pick 9 to load existing hero" << endl;
        cout << "pick 10 to generate 5 monsters" << endl;
        cout << "pick 11 to save monsters" << endl;
        cout << "pick 12 to fight with monster"<<endl;
        cout << "pick 13 to show battle history"<<endl;
        cout << "pick 14 to end the game" << endl;

        int choice;
        cin >> choice;

        switch (choice) {

            case 1: {
                string tempname;
                double tempstrength;
                double tempdexterity;
                double tempendurance;
                double tempintelligence;
                double tempcharisma;


                cout << "Set name of character: ";
                cin >> tempname;
                cout << "Set strength of character: ";
                cin >> tempstrength;
                cout << "Set dexterity of character: ";
                cin >> tempdexterity;
                cout << "Set endurance of character: ";
                cin >> tempendurance;
                cout << "Set intelligence of character: ";
                cin >> tempintelligence;
                cout << "Set charisma of character: ";
                cin >> tempcharisma;

                your_hero = hero(tempname, tempstrength, tempdexterity, tempendurance, tempintelligence,
                                 tempcharisma);

                break;
            }
            case 2:
                your_hero.setClass();

                break;

            case 3:
                your_hero.printStats();
                break;


            case 4:
                items_list.display_items();
                break;

            case 5:
                items_list.display_equipped_items();
                break;

            case 6:
                cout<<"Select item to equip by ID: "<<endl;
                cin>>choice;
                items_list.equipItem(choice, &your_hero);
                break;

            case 7:


                cout<<"Select item to unequip by ID: "<<endl;
                cin>>choice;
                items_list.unequipItem(choice, &your_hero);
                break;

            case 8:
                your_hero.save();
                break;

            case 9: {
                cout << "type the name of the hero you would like to load" << endl;
                string hero_name;
                cin >> hero_name;
                your_hero.load(hero_name);
                break;
            }


            case 10: {


                for (int i = 0; i < 5; i++) {
                    monsters[i] = monster();
                    cout << "Monster " << i << " with stats: " << endl;
                    monsters[i].printStats();
                    cout << "\n";

                }

                break;
            }
            case 11:
                monster::save(monsters);
                break;
            case 12:
                cout << "Pick your enemy monster from 0-5" << endl;
                int choosen_monster;
                cin >> choosen_monster;

                if (fight.fight_phys(your_hero, &monsters[choosen_monster]) && res == 1) { //==1 means that return was 1
                    cout << "You won the fight!" << endl;
                    cout << "Monster experience: " << monsters[choosen_monster].getExp() << " was added to hero"
                         << endl;
                    your_hero.changeExp(monsters[choosen_monster].getExp());
                    history.addBattle("You won the fight! " + to_string(monsters[choosen_monster].getExp()) + " experience was added to your hero");
                    items_list.addItem((rand()%20+1)); // alwasy gets item as max i == 10 items_list.addItem((rand()%10+1)); i=itemID
                } else {
                    cout << "You lost the fight!" << endl;
                    cout << "Monster experience: " << monsters[choosen_monster].getExp()
                         << " was subtracted from hero" << endl;
                    your_hero.changeExp(-monsters[choosen_monster].getExp());
                    history.addBattle("You lost the fight! " + to_string(monsters[choosen_monster].getExp()) + " experience was substracted from you hero");
                }
                break;
            case 13:
                history.displayHistory();
                break;
            case 14:
                exit(0);

            default:
                cout << "pick a good option" << endl;
        }

        cout << "\nwish fufilled" << endl;
    }
    }









