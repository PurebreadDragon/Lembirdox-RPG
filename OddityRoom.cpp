#include <iostream>
#include <string>
#include "Room.hpp"
#include "InputReader.cpp"

class GoldStatueRoom : public Room{

    /**
     * interact: This is a unique interact() method for this type of room only.
     * Link the player before using this method.
     * args: none
     * output: none
     * */
    void interact(){
        InputReader reader;
        std::cout << "You're in a damp stone room illuminated by torches. There's a small marble statue in the shape of an angel"
        " with gold engravings sitting on a pedestal in the center of the room.\n"
        "1:\tTouch the statue\n"
        "2:\tBreak the statue\n";
        int choices[]{1, 2};
        int selection = reader.readInput(choices, 2);
        if (selection == 1){
            std::cout << "You rub the statue. You feel a surge of magical energy flow through your fingertips and into your body."
                      << " You feel reinvigorated.\n";
            player->heal(1000);
        } else {
            int amount = rand() % 200 + 100;
            std::cout << "You raise your weapon and smash the statue. Turns out it was full of gold coins! You scoop them all up, "
                      << "adding " << amount << " gold to your funds.\n";
            player->addGold(amount);
        }
    }
};

class DartTrapRoom : public Room{
    void interact(){
        std::cout << "You enter an empty room with stone walls. Vines are obscuring what look like carvings on the walls. "
                  << "As you walk forwards into the center of the room, you hear a click under your feet as darts suddenly "
                  << "fly out from hidden openings in the wall. ";

        if (player->getSpeed() > 100) std::cout << "However, you're quick on your feet, and jump out of the way before they can hit you.\n";
        else std::cout << "You make an attempt to jump out of the way, but you're not fast enough. You dodge most "
                       << "of them but some of them still connect, causing painful wounds. You take " << player->dealPDamage(30) << " physical damage.\n";
    }
};

class CatRoom : public Room{
    void interact(){
        std::cout << "Oddly enough, there's a door to this room";
    }
};