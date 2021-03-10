#ifndef __TOWN_H__
#define __TOWN_H__

#include "Quest.cpp"
#include "Entity.hpp"
#include "InputReader.cpp"
#include "CombatRoom.cpp"
#include "Factory.hpp"

#include <string>
#include <vector>

//FIXME: Whitespace should be cleaned up throughout the entire program whenever we can :)

struct QuestStub {
   QuestStub() { reward = 0; boss = nullptr; task = ""; }
   QuestStub(unsigned int r, Enemy* b, std::string t) {
      reward = r;
      boss = b;
      task = t;
   }
   ~QuestStub() { delete boss; }
   unsigned int reward;
   Enemy* boss;
   std::string task;
};




class Town {
private:
   //unsigned int condition; //Future project for expansion
   QuestStub* q1;
   QuestStub* q2;
   Quest* nextQuest;
   std::string description;
   std::vector<Item*> supply{ nullptr, nullptr, nullptr };


//Displays the Inn and manages quest selection
   void Inn() {
      if (nextQuest == nullptr) {
         InputReader* read = new InputReader("Invalid response, please press the number of the quest you want to accept. ");
         std::cout << "\nYou enter the Inn and rush to the Quest Board.\n"; //May make this more flavorful later.
         displayBoard();

         int choices[2] = {1, 2};
         int qSelect = read->readInput(choices, 2);
         delete read;

         if (qSelect == 1) { generate(q1); }
         else { generate(q2); }
      }

      else { //a quest has already been selected
         std::cout << "\nYou enter the Inn... and remember that you already have a quest!\n";
      }
   }



//Displays the Store and manages purchases
   void Store(Adventurer* player) {
      std::cout << "\nYou enter the Store and are immediately rushed by the Merchant."
                << "\n\"Welcome, welcome! What do you need today?\"";

      ItemFactory shop;
      int playerGold = player->getGold();
      Item* curItem = nullptr;

      for (unsigned i = 0; i < supply.size(); ++i) {
         curItem = supply.at(i);
         std::cout << "\n" << i + 1 << ".\t" << curItem->getName() << ": " << curItem->getValue() << " gold";
      }
      std::cout << "\n0.\tReturn to Town\n";

      int choices[] = {1, 2, 3, 0};
      InputReader read;
      int select = read.readInput(choices, 4);

      while (select != 0) {
         curItem = supply.at(select - 1);
         if (playerGold >= curItem->getValue()) {
            player->addItem(shop.generate(curItem->getID()));
            player->addGold(-1 * (curItem->getValue()));
            playerGold -= curItem->getValue();
            std::cout << "\nThe Merchant grins. \"Thank you so much! You'll be needing something else, yes?\"\n";
         }
         else {
            std::cout << "\nThe Merchant grimaces. \"So, so, so sorry! It seems you're a little too... poor!\"\n";
         }
         select = read.readInput(choices, 4);
      }
   }



//Displays the Clinic and manages revivals
   void Clinic(Adventurer* player) {
      std::cout << "\nYou walk into the Clinic and are greeted by the Healer."
                << "\n\"Welcome, traveler, I hope you are faring well...\"";
      int health = player->getCurrentHealth();
      int maxHealth = player->getMaxHealth();
      if (health == maxHealth) {
         std::cout << "\nThe Healer gives you a warm smile."
                   << "\n\"It seems you are in no need of my services. Thank you for saying hello!\"";
      }
      else if (health >= (maxHealth * 0.7)) {
         std::cout << "\nThe Healer glances over your injuries."
                   << "\n\"Ah, I see. I have seen worse, I can certainly help with this.\"";
      }
      else if (health >= (maxHealth * 0.3)) {
         std::cout << "\nUpon seeing your state, the Healer lets out a worried sigh."
                   << "\n\"Oh dear... Please be more careful, okay?\"";
      }
      else {
         std::cout << "\nThe Healer regards you with fearful eyes."
                   << "\n\"Dark heavens--! You are lucky to have made it here in one piece!\"";
      }

      InputReader* read = new InputReader();
      int choices[2] = {0,1};
      int select = -1;
      while (select != 0) {
         health = player->getCurrentHealth();
         std::cout << std::endl;
         if (health != maxHealth) { 
            std::cout << "\nHealing will cost " << HealCost((static_cast<double>(health)/maxHealth)) << " gold.";
         }
         std::cout << "\n1.\tAsk for Healing"
                   << "\n0.\tReturn to Town" << std::endl;
         select = read->readInput(choices,2);
         if (select == 1) { Revive(player); }
      }
      delete read;
   }

//Revives characters and subtracts the cost
   void Revive(Adventurer* player) {
      if (player->getCurrentHealth() == player->getMaxHealth()) { std::cout << "\nYou are not in need of revival!"; }
      else { 
         double healCost = HealCost(static_cast<double>(player->getCurrentHealth())/player->getMaxHealth());
         if (player->getGold() < healCost) std::cout << "\nYou don't have the funds to heal!\n";
         else {
            player->addGold(-1 * healCost);
            player->setHealth(player->getMaxHealth());
            std::cout << "\nThe Healer applies a salve over your wounds. It tickles, and you start seeing strange colors..."
                     << "\n...You awaken feeling very refreshed! The Healer removes your bandages and bids you adieu.\n";
         }
      }
   }

//Calculates cost of revival
   unsigned int HealCost(double percentage) { return ((1 - percentage) * 200); } //can be changed to scale properly



//Displays the quest board
   void displayBoard() {
      std::cout << "\n ----------------- QUEST BOARD -----------------"
                << "\n1.\t" << q1->task << q1->boss->getName() << "!"
                << "\n\tReward: " << q1->reward << " gold\n"
                << "\n2.\t" << q2->task << q2->boss->getName() << "!"
                << "\n\tReward: " << q2->reward << " gold"
                << "\n -----------------------------------------------"
                << "\nPress the corresponding number to accept that quest." << std::endl;
   }



//Initializes the chosen quest and deallocates memory
   Quest* generate(QuestStub* q) {
      nextQuest = new Quest(q->reward, q->boss, q->task);
      q->boss = nullptr; //q->boss passed into quest, must not be deleted!
   }



//Displays the town menu
   void displayMenu() {
      std::cout << "\n1.\tVisit the town Inn"
                << "\n2.\tBrowse the town Store"
                << "\n3.\tGo to the Clinic"
                << "\n4.\tHead out on a Quest"
                << "\n5.\tCheck player info"
                << "\n6.\tCheck your inventory"
                << "\n0.\tSave and Quit" << std::endl;
   }



public:
   Town() {
      //condition = (rand() % 100) + 1;
      EnemyFactory bossGen;
      Enemy* q1B = bossGen.generate((rand() % 5) + 10001);
      Enemy* q2B = bossGen.generate((rand() % 5) + 10001);
      q1 = new QuestStub(((rand() % 101) + 50), q1B, "Defeat a dangerous ");
      q2 = new QuestStub(((rand() % 101) + 50), q2B, "Eliminate an evil ");
      ItemFactory itemGen;
      nextQuest = nullptr;
      description = "You are in town.";
      supply.at(0) = itemGen.generate(20004); //guarantee potions in store
      supply.at(1) = itemGen.generate((rand() % 9) + 20001);
      supply.at(2) = itemGen.generate((rand() % 9) + 20001);
   }

   ~Town() {
      if (q1 != nullptr) { delete q1; }
      if (q2 != nullptr) { delete q2; }
      nextQuest = nullptr; //cannot be deleted, quest is needed. Delete quest directly instead
      for (unsigned i = 0; i < supply.size(); ++i) {
         delete supply.at(i);
      }
   }


   //Master function that manages all of the town. Accepts the player and returns the Quest to be started.
   Quest* RoamTown(Adventurer* player) {
      bool questStarted = false;
      InputReader* read = new InputReader();
      int choices[] = {0,1,2,3,4,5,6};
      int select = -1;

      while (select != 0 && !questStarted) {
         std::cout << std::endl << description << std::endl;
         displayMenu();
         
         select = read->readInput(choices,7);
         switch(select) {
            case 0:
               if (nextQuest != nullptr) { delete nextQuest; }
               nextQuest = nullptr;
               break;
            case 1: Inn();    break;
            case 2: Store(player);  break;
            case 3: Clinic(player); break;
            case 4:
               if (nextQuest == nullptr) {
                  std::cout << "\nYou don't have a quest to embark on!\n"
                            << "Head to the Inn first." << std::endl;
               }
               else {
                  //std::cout << "nextQuest should be started now!\n"; //testing statement
                  questStarted = true; 
               }
               break;
            case 5: player->inspect(); break;
            case 6: player->checkInventory(); break;
         }
      }
      delete read;
      return nextQuest;
   }
};

#endif
