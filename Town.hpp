#ifndef __TOWN_H__
#define __TOWN_H__

#include "Quest.cpp"
#include "Entity.hpp"

#include <string>

struct QuestStub {
   QuestStub() { reward = 0; boss = nullptr; task = ""; }
   QuestStub(unsigned int r, Entity* b, std::string t) {
      reward = r;
      boss = b;
      task = t;
   }
   ~QuestStub() { delete boss; }
   unsigned int reward;
   Entity* boss;
   std::string task;
};

class Town {
private:
   //unsigned int condition; //Future project for expansion
   unsigned int clinicPrice;
   QuestStub* q1;
   QuestStub* q2;
   Quest* nextQuest;
   std::string description;

//Displays the Inn and manages quest selection
   void Inn() {
      std::cout << "\nYou enter the Inn and rush to the Quest Board."; //May make this more flavorful later.
      displayBoard();

      int qSelect;
      std::cin >> qSelect;

      while (qSelect != 1 && qSelect != 2) {
         std::cout << "Invalid response, please try again: ";
         std::cin >> qSelect;
      }

      if (qSelect == 1) { generate(q1); delete q2; }
      else { generate(q2); delete q1; }
   }

//Displays the Store and manages purchases
   void Store() {
      std::cout << "FIXME: Town::Store()" << std::endl;
   }

//Displays the Clinic and manages revivals
   void Clinic() {
      std::cout << "FIXME: Town::Clinic()" << std::endl;
   }

//Displays the quest board
   void displayBoard() {
      std::cout << "\n\t--- QUEST BOARD ---"
                << "\n1.\t" << q1->task << q1->boss->getName()
                << "\n\tReward: " << q1->reward << " gold\n"
                << "\n2.\t" << q2->task << q2->boss->getName()
                << "\n\tReward: " << q2->reward << " gold\n"
                << "Press the corresponding key to accept that quest."
                << "\n\t-------------------" << std::endl;
   }


//Initializes the chosen quest and deallocates memory
   Quest* generate(QuestStub* q) {
      nextQuest = new Quest(q->reward, q->boss, q->task);
      q->boss = nullptr; //q->boss passed into quest, must not be deleted!
      delete q;
   }

//Displays the town menu
   void displayMenu() {
      std::cout << "1.\tVisit the town Inn"
                << "\n2.\tBrowse the town Store"
                << "\n3.\tGo to the Clinic"
                << "\n4.\tHead out on a Quest"
                << "\n0.\tSave and Quit" << std::endl;
   }



public:
   Town() {
      //condition = (rand() % 100) + 1;
      clinicPrice = 100; //testing value... to be implemented further
      Entity* q1B = new Entity("Awkward Avocado", "We'd put a description but it'd be awkward", 1, 1, 1, 1, 1, 1);
      Entity* q2B = new Entity("Monopoly Man", "The mustachioed menace himself", 9, 9, 9, 9, 9, 9);
      q1 = new QuestStub(100, q1B, "Please save my kitten from the ");
      q2 = new QuestStub(9000, q2B, "Help! I'm being held at gunpoint by ");
      nextQuest = nullptr;
      description = "You are in town."; //testing value, tbif.
   }

   ~Town() {
      delete q1;
      delete q2;
      delete nextQuest;
   }

   unsigned int RoamTown() { //Master function that manages all of the town
      std::cout << description << std::endl;
      displayMenu();
      int choice;
      bool questStarted = false;

      std::cin >> choice;
      while (choice != 0 && !questStarted) {
         switch(choice) {
            case 0:
               std::cout << "Save and quit has been called!" << std::endl;
               break;
            case 1: Inn();    break;
            case 2: Store();  break;
            case 3: Clinic(); break;
            case 4:
               if (nextQuest == nullptr) {
                  std::cout << "You don't have a quest to embark on!\n"
                            << "Head to the Inn first." << std::endl;
               }
               else {
                  std::cout << "nextQuest should be started now!\n";
                  questStarted = false; 
               }
               break;
            default:
               std::cout << "Invalid response, please try again:\n";
         }
         displayMenu();
         std::cin >> choice;
      }
   }
};

#endif
