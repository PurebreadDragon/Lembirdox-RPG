#ifndef __TOWN_H__
#define __TOWN_H__

#include "Quest.cpp"
#include "Entity.hpp"
#include "InputReader.cpp"

#include <string>
#include <fstream>

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
   QuestStub* q1;
   QuestStub* q2;
   Quest* nextQuest;
   std::string description;



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
         nextQuest->showQuestContent();
      }
   }



//Displays the Store and manages purchases
   void Store() { //TODO: Implement store once Items are added
      std::cout << "\nYou enter the Store... " //Will make this flavorful later as well...
                << "\n...and are promptly shooed out!"
                << "\n\"Sorry, sorry! We aren't open yet, come back later!" << std::endl;
   }



//Displays the Clinic and manages revivals
   void Clinic() { //TODO: Finish implementing this once party is added
      std::cout << "\nYou walk into the Clinic and are greeted by the Healer."
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

      InputReader* read = new InputReader();
      int choices[2] = {0,1};
      int select = -1;
      while (select != 0) {
         std::cout << std::endl;
         if (deceased != 0) { 
            std::cout << "\nReviving your party will cost " << RevCost(deceased) << " gold.";
         }
         std::cout << "\n1.\tRevive the Party"
                   << "\n0.\tReturn to Town" << std::endl;
         select = read->readInput(choices,2);
         if (select == 1) { Revive(deceased); }
      }
   }

//Revives characters and subtracts the cost
   void Revive(int deceased) {
      if (deceased == 0) { std::cout << "\nNobody is in need of revival!"; }
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
                << "\n0.\tSave and Quit" << std::endl;
   }



public:
   Town() {
      //condition = (rand() % 100) + 1;
      //TODO: Implement "randomness". q1B, q2B, q1, q2 should be randomized on each creation of Town.
      Entity* q1B = new Entity("Awkward Avocado", "We'd put a description but it'd be awkward", 1, 1, 1, 1, 1, 1);
      Entity* q2B = new Entity("Monopoly Man", "The mustachioed menace himself", 9, 9, 9, 9, 9, 9);
      q1 = new QuestStub(100, q1B, "Please save my kitten from the ");
      q2 = new QuestStub(9000, q2B, "Help! I'm being held at gunpoint by ");
      nextQuest = nullptr;
      description = "You are in town."; //testing value, tbif.
   }

   ~Town() {
      if (q1 != nullptr) { delete q1; }
      if (q2 != nullptr) { delete q2; }
      nextQuest = nullptr; //cannot be deleted, quest is needed. Delete quest directly instead
   }

   friend void SaveGame(Town*);
   friend Town* LoadGame();

   //Master quest that manages all of the town. Accepts no arguments and returns the Quest to be started.
   Quest* RoamTown() {
      bool questStarted = false;
      InputReader* read = new InputReader();
      int choices[5] = {0,1,2,3,4};
      int select = -1;

      if (nextQuest != nullptr && nextQuest->getBoss() != nullptr) { std::cout << "boss is not null\n"; nextQuest->showQuestContent(); }
      else if (nextQuest->getBoss() == nullptr) { std::cout << "Boss is null!\n"; }
      else { std::cout << "Um\n"; }

      while (select != 0 && !questStarted) {
         std::cout << std::endl << description << std::endl;
         displayMenu();
         
         select = read->readInput(choices,5);
         switch(select) {
            case 0:
               SaveGame(this);
               nextQuest = nullptr;
               break;
            case 1: Inn();    break;
            case 2: Store();  break;
            case 3: Clinic(); break;
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
         }
      }
      delete read;
      return nextQuest;
   }
};


const char SAVE_FILE[] = ("savefile.dat");
void SaveGame(Town* t) {
    remove(SAVE_FILE); //overwrite current file
    std::cout << "Saving..." << std::endl;
    std::ofstream writer;

    writer.open(SAVE_FILE);
    if (!writer.fail()) {
        if(t->nextQuest == nullptr) { //there has to be a better way to write these... I'll look into it
            writer << "q:" << t->q1->reward << ";";
            writer << t->q1->boss->getName() << ",";
            writer << t->q1->boss->getDescription() << ",";
            writer << t->q1->boss->getMaxHealth() << ",";
            writer << t->q1->boss->getPAtk() << ",";
            writer << t->q1->boss->getPDef() << ",";
            writer << t->q1->boss->getMAtk() << ",";
            writer << t->q1->boss->getMDef() << ",";
            writer << t->q1->boss->getSpeed() << ";";
            writer << t->q1->task << ";";
            writer << "\n";

            writer << "q:" << t->q2->reward << ";";
            writer << t->q2->boss->getName() << ",";
            writer << t->q2->boss->getDescription() << ",";
            writer << t->q2->boss->getMaxHealth() << ",";
            writer << t->q2->boss->getPAtk() << ",";
            writer << t->q2->boss->getPDef() << ",";
            writer << t->q2->boss->getMAtk() << ",";
            writer << t->q2->boss->getMDef() << ",";
            writer << t->q2->boss->getSpeed() << ";";
            writer << t->q2->task << ";";
            writer << "\n";
        }
        else {
            writer << "Q:" << t->nextQuest->getReward() << ";";
            writer << t->nextQuest->getBoss()->getName() << ",";
            writer << t->nextQuest->getBoss()->getDescription() << ",";
            writer << t->nextQuest->getBoss()->getMaxHealth() << ",";
            writer << t->nextQuest->getBoss()->getPAtk() << ",";
            writer << t->nextQuest->getBoss()->getPDef() << ",";
            writer << t->nextQuest->getBoss()->getMAtk() << ",";
            writer << t->nextQuest->getBoss()->getMDef() << ",";
            writer << t->nextQuest->getBoss()->getSpeed() << ";";
            writer << t->nextQuest->getTask() << ";";
            writer << "\n";
            delete t->nextQuest;
        }
        
        //TODO: Save the adventuring party

        writer << "#### END SAVE FILE ####";
        std::cout << "Save successful!" << std::endl;
    }
    else {
        std::cout << "There was an error while saving, the file may be oorrupted." << std::endl;
    }
    writer.close();
}

Town* LoadGame() {
    std::cout << "Loading..." << std::endl;
    std::ifstream reader;

    Town* retTown = nullptr;
    Entity* qBoss = nullptr;
    QuestStub* loadQuest = nullptr;

    reader.open(SAVE_FILE);
    if (!reader.fail()) {
        std::string line;
        std::string substring = "";

        unsigned int qReward;
        std::string eName = "";
        std::string eDesc = "";
        int eStat[6] = {0,0,0,0,0,0};
        std::string qTask = "";

        while (!reader.eof() && !reader.fail()) {
            line = "";
            std::getline(reader,line);
            if (line.at(0) == 'Q') {
                unsigned currVal = 0;
                unsigned currStat = 0;
                for (unsigned i = 2; i < line.size(); ++i) {
                    switch (currVal) {
                        case 0:
                            if (line.at(i) != ';') {
                                substring += line.at(i);
                            }
                            else { 
                                qReward = std::stoi(substring);
                                substring = "";
                                ++currVal;
                            }
                            break;
                        case 1:
                            if (line.at(i) != ',') {
                                substring += line.at(i);
                            }
                            else {
                                eName = substring;
                                substring = "";
                                ++currVal;
                            }
                            break;
                        case 2:
                            if (line.at(i) != ',') {
                                substring += line.at(i);
                            }
                            else {
                                eDesc = substring;
                                substring = "";
                                ++currVal;
                            }
                            break;
                        case 3:
                            if (line.at(i) != ',' && line.at(i) != ';') {
                                substring += line.at(i);
                            }
                            else if (line.at(i) == ',') {
                                eStat[currStat] = std::stoi(substring);
                                substring = "";
                                ++currStat;
                            }
                            else {
                                eStat[currStat] = std::stoi(substring);
                                substring = "";
                                ++currVal;
                            }
                            break;
                        case 4:
                            if (line.at(i) != ';') {
                                substring += line.at(i);
                            }
                            else {
                                qTask = substring;
                                substring = "";
                                ++currVal;
                            }
                            break;
                        }
                    }
               } 
            else if (line.at(0) == 'A') {
                //TODO: add adventurers
            }
        }

        //Now that everything is loaded correctly, we can construct the file
        qBoss = new Entity(eName,eDesc,eStat[0],eStat[1],eStat[2],eStat[3],eStat[4],eStat[5]);
        loadQuest = new QuestStub(qReward, qBoss, qTask);
        retTown = new Town();
        retTown->nextQuest = retTown->generate(loadQuest);
    }
    reader.close();
    std::cout << "Loading successful!" << std::endl;
    return retTown;
}

#endif
