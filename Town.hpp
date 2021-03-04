#ifndef __TOWN_H__
#define __TOWN_H__

#include "Quest.cpp"
#include "Entity.hpp"

#include <string>

//FIXME: Whitespace should be cleaned up throughout the entire program whenever we can :)

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
      if (nextQuest == nullptr) {
         std::cout << "\n\nYou enter the Inn and rush to the Quest Board."; //May make this more flavorful later.
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

      else { //a quest has already been selected
         std::cout << "You enter the Inn... and remember that you already have a quest!";
      }
   }



//Displays the Store and manages purchases
   void Store() { //TODO: Implement store once Items are added
      std::cout << "You enter the Store... " //Will make this flavorful later as well...
                << "\n...and are promptly shooed out!"
                << "\n\"Sorry, sorry! We aren't open yet, come back later!" << std::endl;
   }



//Displays the Clinic and manages revivals
   void Clinic() { //TODO: Finish implementing this once party is added
      int choice = -1;
      std::cout << "\n\nYou walk into the Clinic and are greeted by the Healer." //Will make this flavorful too~
                << "\n\"Welcome, travelers, I hope you are faring well...\"";
      int deceased = 0; //FIXME: (number of dead characters in the party);
      switch (deceased) {
         case 0:
            std::cout << "\nThe Healer gives you a warm smile."
                      << "\n\"It seems you are in no need of my services. Thank you for saying hello!\"";
            break;
         case 1:
            std::cout << "\nThe Healer nods sadly at your fallen companion."
                      << "\n\"Ah, I see. I have seen worse, I can certainly help with this.\"";
            break;
         case 2:
            std::cout << "\nUpon seeing your party, the Healer lets out a worried sigh."
                      << "\n\"Oh dear... Please be more careful, okay?\"";
            break;
         case 3:
            std::cout << "\nThe Healer regards your party with fearful eyes."
                      << "\n\"Dark heavens--! You are lucky to have made it here in one piece!\"";
            break;
      }

      while (choice != 0) {
         std::cout << std::endl;
         if (deceased != 0) { 
            std::cout << "\nReviving your party will cost " << RevCost(deceased) << " gold.";
         }
         std::cout << "\n1.\tRevive the Party"
                   << "\n0.\tReturn to Town" << std::endl;
         std::cin >> choice;
         
         if (choice == 1) { Revive(deceased); }
      }
   }

//Revives characters and subtracts the cost
   void Revive(int deceased) {
      if (deceased == 0) { std::cout << "\nNobody is in need of revival!\n"; }
      else {
      /* for (each character in party) {
            if (character health = 0) { character health = 1; }
         }
         partyGold -= RevCost(deceased); */
      }
   }

//Calculates cost of revival
   unsigned int RevCost(int n) { return (n * 200); } //can be changed to scale properly



//Displays the quest board
   void displayBoard() {
      std::cout << "\n\t---------- QUEST BOARD ----------"
                << "\n1.\t" << q1->task << q1->boss->getName() << "!"
                << "\n\tReward: " << q1->reward << " gold\n"
                << "\n2.\t" << q2->task << q2->boss->getName() << "!"
                << "\n\tReward: " << q2->reward << " gold\n"
                << "Press the corresponding key to accept that quest."
                << "\n\t---------------------------------" << std::endl;
   }



//Initializes the chosen quest and deallocates memory
   Quest* generate(QuestStub* q) {
      nextQuest = new Quest(q->reward, q->boss, q->task);
      q->boss = nullptr; //q->boss passed into quest, must not be deleted!
      delete q;
   }



//Displays the town menu
   void displayMenu() {
      std::cout << "\n1.\tVisit the town Inn"
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
      q1B = nullptr;
      q2B = nullptr;
      nextQuest = nullptr;
      description = "You are in town."; //testing value, tbif.
   }

   ~Town() {
      delete q1;
      delete q2;
      delete nextQuest;
   }



   unsigned int RoamTown() { //Master function that manages all of the town
      int choice = -1;
      bool questStarted = false;

      std::cout << description << std::endl;
      while (choice != 0 && !questStarted) {
         displayMenu();
         std::cin >> choice;
         switch(choice) {
            case 0:
               std::cout << "Save and quit has been called!" << std::endl; //TODO: Add save and exit routine!
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
                  questStarted = true; 
               }
               break;
            default:
               std::cout << "Invalid response, please try again:\n";
         }
      }
   }

};

#endif
