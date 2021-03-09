#ifndef __ODDROOM__
#define __ODDROOM__

#include <iostream>
#include <string>
#include "Room.hpp"
#include "InputReader.cpp"
#include "Item.hpp"

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
public:
    CatRoom(){
        name = "strange door with cat ears";
        description = "";
    }

    void interact(){
        InputReader reader;
        std::cout << "The entrance to this room is blocked by a round wooden door. You push it open, revealing a cozy interior. The floor is padded with a soft "
                  << "carpet. One side of the room has a cozy brick fireplace, its coals glowing softly. Next to it is a small arrangement of "
                  << "pillows and blankets. A small black cat sits on it. As you enter the room, it turns to face you with its gleaming yellow eyes.\n"
                  << "HUMAN, an uncharacteristically deep voice resonates directly within your mind, presumably coming from the cat. \nWHAT BRINGS YOU HERE?\n"
                  << "1:\t\"You can talk?\"\n";
        int choices[]{1};
        int selection = reader.readInput(choices, 1);

        std::cout << "OF COURSE I CAN. DON'T TELL ME YOU'VE NEVER SEEN A TALKING CAT?\n"
                  << "1:\t\"Uhh...\"\n";
        int choices2[]{1};
        selection = reader.readInput(choices2, 1);

        std::cout << "I KNOW, I CAN TELL YOU'RE TAKEN ABACK BY MY GREATNESS. IT'S NOT EVERY DAY THAT I, THE GREAT MORT, LORD OF THE DARK NIGHT, "
                  << "SLAYER OF THE FOULEST OF VERMIN, WIELDER OF THE ETERNAL BLACK FLAME, DECIDES TO BESTOW HIS PRESENCE UPON MERE MORTALS!\n"
                  << "1:\t\"Okay... What do you want?\"\n"
                  << "2:\t\"Get to the point.\"\n"
                  << "3:\t\"What did you say your name was? *pfft* M-mort?\"\n";
        int choices3[]{1, 2, 3};
        selection = reader.readInput(choices3, 3);

        if (selection == 3){
            std::cout << "If cats could make expressions, Mort would probably be fuming right now. You can feel his embarrassment "
                      << "through your telepathic link. \nCEASE YOUR USELESS CHATTER. I DO NOT RECOGNIZE THIS LABEL. YOU AGREE, DO YOU NOT? WHAT KIND OF "
                      << "DARK LORD IS CALLED \"MORT\"? ALL THE TOWNSFOLK COWER IN TERROR WHEN THEY HEAR EVEN WHISPERS OF MY PRESENCE. I AM FEARED BY "
                      << "EVERY KIND OF BEING ACROSS THE LAND. MY DARK POWER IS LIMITLESS, LIKE THE BLACKEST OF MIDNIGHT. I COULD CRUSH YOUR PUNY HUMAN "
                      << "BODY IN AN INSTANT. AND YET I AM STUCK WITH THIS "
                      << "ACCURSED HUMAN LABEL, THAT OF "
                      << "WHICH I DID NOT ASK FOR. CURSE THAT OLD HAG AND HER AWFUL NAMING SENSE. I WILL GET HER BACK ONE DAY. BUT FOR NOW, I WILL NOT "
                      << "HAVE YOU, A MERE HUMAN, TAUNTING ME.\n"
                      << "1:\tTry to hold back your laughter. \"Okay, I'm sorry. What do you want from me?\"\n"
                      << "2:\tSnicker. \"Mort.\"\n";
            int choices4[]{1, 2};
            selection = reader.readInput(choices4, 2);

            if (selection == 2){
                std::cout << "Mort's hair prickles a bit. \nYOU ARE PLAYING WITH FIRE, HUMAN. ETERNAL BLACK FIRE, TO BE EXACT. "
                          << "BE CAREFUL YOU DO NOT GET BURNED. \n"
                          << "1:\t\"Okay, I'm sorry. What do you want from me?\"\n"
                          << "2:\tUnder your breath, whisper again \"Mort. Can you believe it?\"\n";
                int choices5[]{1, 2};
                selection = reader.readInput(choices5, 2);
            }

            if (selection == 2){
                std::cout << "LAST WARNING, HUMAN. IT WAS FUNNY EARLIER. NOW IT'S NOT.\n"
                          << "1:\t\"Okay, I'm sorry. What do you want from me?\"\n"
                          << "2:\tStop holding it in.\n";
                int choices6[]{1, 2};
                selection = reader.readInput(choices6, 2);
            }

            if (selection == 2){
                std::cout << "Unable to hold it in any longer, you burst out laughing. It's just too funny. A self-proclaimed dark "
                          << "lord, wielder of the whatever whatever, but he's stuck with a name as dumb as MORT? It's almost too comedic.\n"
                          << "Mort gets up from his bed. He stretches his back and a golden aura flares up around him. \nPREPARE YOURSELF, HUMAN.\n"
                          << "You're almost too busy laughing to ready your weapon.\n";
                mortCombat();
            }
        } else selection = 1;
        
        if (selection == 1){
            std::cout << "Mort straightens up a little. \nI COME BEARING GIFTS, HUMAN. FROM THE OLD HAG HERSELF. STATE YOUR WISH.\n"
                    << "1\tPower.\n"
                    << "2\tWealth.\n"
                    << "3\tWisdom.\n";
            int choices7[]{1, 2, 3};
            selection = reader.readInput(choices7, 3);

            std::cout << "CONSIDER IT DONE. The cat gets up, stretches a little, then stares intensely at the spot in front of your feet. ";
            switch(selection){
                case 1:{
                    std::cout << "A flash of light, a bit of smoke, and a red cat's paw materializes in front of you.\n"
                              << "YOU ARE WELCOME, HUMAN. SQUASH SOME VERMIN FOR ME.\n";
                    RedPaw *redpaw = new RedPaw();
                    player->addItem(redpaw);
                } break;
                case 2:{
                    int amount = rand() % 600 + 50;
                    std::cout << "A flash of light, a bit of smoke, and a pile of gold materializes in front of you.\n"
                              << "YOU ARE WELCOME, HUMAN. DON'T SPEND IT ALL IN ONE PLACE.\n"
                              << "You gained " << amount << " gold.\n";
                    player->addGold(amount);
                } break;
                case 3:{
                    std::cout << "A flash of light, a bit of smoke, and a blue cat's paw materializes in front of you.\n"
                              << "YOU ARE WELCOME, HUMAN. EXPAND YOUR BRAIN POWER BEYOND THE HORIZONS.\n";
                    BluePaw *bluepaw = new BluePaw();
                    player->addItem(bluepaw);
                } break;
            }

            std::cout << "Mort abruptly disappears in a puff of smoke. You can still faintly sense his presence, but it seems like he's "
                    << "had his fun for the day. Still a bit perplexed, you head towards the exit.\n";
        }
    }

    void mortCombat(){
        std::cout << "NAME                    00%-----25%------50%------75%-----100%\n"
                  << "                        [        |        |        |        ]\n"
                  << resize(player->getName(), 16) << " (100%) [----------------------------------o] (" << player->getCurrentHealth() << "/" << player->getMaxHealth() <<")\n"
                  << "Mort             (100%) [--------------------------=^ owo ^=] (\?\?\?\?/\?\?\?\?)\n";
        std::cout << "================================[TURN 1]===============================\n"
                  << "It's your turn. Available options:\n"
                  << "1:\tFlail helplessly\n"
                  << "2:\tPray to Jesus\n"
                  << "3:\tFlop around on the floor like a fish\n"
                  << "4:\tFlee\n";

        int choices[]{1, 2, 3, 4};
        InputReader reader;
        int selection = reader.readInput(choices, 4);
        switch(selection){
            case 1:{
                std::cout << "You start wildly flapping your arms around. It doesn't seem to have much of an effect. "
                          << "In your flailing, you trip on the pillows on the floor and land face-first on the carpet.\n";
            } break;
            case 2:{
                std::cout << "You get down on your knees, clasp your hands together and pray that somebody, anybody up there might help you. But nobody came...\n";
            } break;
            case 3:{
                std::cout << "You lay down on your stomach and start flopping on the floor. It's oddly comfy because of the carpet. You flop for a bit"
                          << " before you eventually get tired. Your flopping doesn't seem to have any effect.\n";
            } break;
            case 4:{
                std::cout << "You sprint out the door in the back and slam it behind you. That was close. You weren't expecting him to be that powerful.\n"
                          << "You find yourself in a small passageway. You can see a faint light coming from a room in front of you.\n"
                          << "Available exits:\n"
                          << "1:\tForward\n";
                int choices2[]{1};
                selection = reader.readInput(choices, 1);

                std::cout << "WHERE DO YOU THINK YOU'RE GOING?\n"
                          << "A tendril made of golden light wraps around you and forcibly drags you back into the room, where you find a very "
                          << "angry-looking Mort standing over you.\n";
            } break;
        }

        std::cout << "You look up at Mort. \"Hey.\"\n"
                  << "ANY LAST WORDS?\n"
                  << "Mort doesn't even give you time to speak before the golden aura around him flares up, illuminating the room around you "
                  << "in bright yellow light. Golden rays shoot out from Mort's small frame, piercing your body. Each of them shocks your nerves with searing, white-hot "
                  << "lances of pain. You can only stay conscious for a couple of seconds before passing out.\n";

        std::cout << "You wake up what seems like an eternity later. The fireplace has long burnt out, and Mort is nowhere to be seen. Your head is pounding. "
                  << "You stretch "
                  << "your aching limbs, rolling over onto something solid? You reach out your hand to grab it. It's a... golden severed cat paw? "
                  << "Perplexed, you pocket the cat's paw and proceed onward.\n";
        player->setHealth(1);
        GoldPaw *goldpaw = new GoldPaw();
        player->addItem(goldpaw);
    }
};

class MirrorRoom : public Room {
public:
    MirrorRoom() {
        name = "A hallway of mirrors";
        description = "";
    }

    void interact() {
        InputReader read;
        int select;

        std::cout << "\nYou step into a hallway full of mirrors.\n"
                  << "Many of them are cracked; some are broken entirely, piles of shards in their frames.\n"
                  << "You come to a stop in front of an intact mirror, face to face with your reflection.\n\n"
                  << "1:\tCheck your appearance\n"
                  << "2:\tPlay Rock-Paper-Scissors\n"
                  << "3:\tBreak the mirror\n"
                  << "0:\tIgnore the mirror and carry on\n";
        int choices[4] = {0, 1, 2, 3};
        select = read.readInput(choices,4);

        switch(select) {
            case 0:
                std::cout << "\nYou're pretty familiar with yourself, having been you for many years.\n"
                          << "A mirror is nothing to be surprised about. You turn away and carry on.\n";
                break;
            case 1:
                std::cout << "\nYou check your current state, fuss with your hair, dust off your clothes.\n"
                          << "After a few minutes, you conclude that you're probably the hottest thing in this place.\n"
                          << "Well... maybe except for a monster made of fire or something.\n"
                          << "You finger-gun your reflection and walk away, feeling much more confident.\n";
                break;
            case 2:
                std::cout << "\nYou bring your hand up, challenging your reflection in a classic showdown of ro-sham-bo.\n";
                mirrorMatch();
                break;
            case 3:
                std::cout << "\nYou know better than to trust anything in this place, least of all yourself.\n"
                          << "You spin your trusty weapon into your hand and thrust it into the mirror, dealing"
                          << player->getPAtk() << " physical damage.\n"
                          << "With a deafening crash, the mirror splinters into tiny shards.\n";
                if (player->getMAtk() > 100) {
                    std::cout << "\nAn eerie sense of dread makes your nerves stand on end and tingles your spine.\n"
                              << "Being familiar with magic, you know whatever spirit lived in that mirror perished with it.\n";
                }
                else {
                    std::cout << "\nFear suddenly sets in as you begin to doubt your actions.\n"
                              << "You fall to your knees and crawl away from the broken mirror, but this leads you to another-\nYou crawl away from that one, but this leads you to yet another.\n"
                              << "The panic sends you scampering across hundreds of tiny glass shards in a madness.\nWhen you regain your composure, you are left with many tiny bleeding cuts and a splitting headache.\n";
                    player->dealPDamage(20); player->dealMDamage(20);
                }
                break;
        }
    }

    void mirrorMatch() {
        unsigned matches = 0;
        InputReader read;
        int choices[4] = {0, 1, 2, 3};
        int select;
        std::string choice;
        while (matches < 13 && select != 0) {
            choice = "";
            std::cout << "You stare intently at your reflection, preparing your next move.\n\n"
                      << "1.\tRock\n" << "2.\tPaper\n" << "3.\tScissors\n"
                      << "0.\tThis is stupid, give up and leave.\n";
            select = read.readInput(choices,4);
            if (select == 1) { choice = "Rock"; }
            else if (select == 2) { choice = "Paper"; }
            else { choice = "Scissors"; }
            ++matches;
            if (choice != "" && matches < 13) {
                std::cout << "\nYou make up your mind.\nOne...\tTwo...\tThree!!!"
                          << "\nYou threw " << choice << ". Your reflection threw " << choice << ".\n"
                          << "\tIt's a tie!\n\n";
            }
        }
        if (select == 0) {
            std::cout << "\nYou can't believe you were really playing rock paper scissors with your reflection.\n"
                      << "With an ashamed chuckle at your own stupidity, you turn away and carry on.\n";
        }
        else if (matches == 13) {
            std::string r;
            
            if (choice == "Rock") { r = "Scissors"; }
            else if (choice == "Paper") { r = "Rock"; }
            else { r = "Paper"; }

            std::cout << "\nYou make up your mind.\nOne...\tTwo...\tThree!!!"
                      << "\nYou threw " << choice << ". Your reflection threw " << r << ".\n"
                      << "\tYou... won?\n\n"
                      << "1.\t\"What...\"\n";
            choices[0] = 1;
            select = read.readInput(choices,1);
            std::cout << "\nYou stare in shock at your reflection, then back at your own hand.\n"
                      << "You hold " << choice << ", and your reflection holds " << r << ".\n"
                      << "Your reflection looks equally stunned! Their eyes meet yours.\n\n"
                      << "1.\tPress your hand to the mirror.\n"
                      << "2.\tRun away and try to forget this ever happened.\n";
            choices[1] = 2;
            select = read.readInput(choices,2);
            if (select == 1) {
                std::cout << "\nYou uncurl your hand and gently bring it to the mirror.\n"
                          << "Your reflection does the same, and you watch each other intently.\n"
                          << "You expect the mirror to be cold, but it is... warm, and... soft?\n"
                          << "\t...Like your hand.\n\n"
                          << "1.\tTry to clasp your reflection's hand.\n"
                          << "2.\tThis is terrifying. Leave immediately.\n";
                select = read.readInput(choices,2);
                if (select == 1) {
                    std::cout << "\nYou slowly close your fingers,"
                              << "preparing for the most existential hand holding you've ever seen.\n"
                              << "...but your fingers slide hopelessly against the mirror.\n"
                              << "Your reflection seems disappointed for a moment...\n"
                              << "But then their eyes go wide!\n"
                              << "They give an excited grin. You forget to wonder if you're grinning back.\n"
                              << "Your reflection holds up something shimmery, and slips it into their pocket.\n"
                              << "You feel your own pocket get heavier.\n\n"
                              << "Your reflection holds their hands up in a heart, and waves goodbye.\n"
                              << "The mirror shatters.\n\n";
                    MirrorKnife* mk = new MirrorKnife();
                    player->addItem(mk);
                }
            }
            if (select == 2) {
                std::cout << "\nThat's enough existential crisis for today.\n"
                          << "You turn and break into a sprint out of the hallway, never looking back.\n";
            }
        }
    }
};

#endif
