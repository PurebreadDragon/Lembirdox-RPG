#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "./../source/Enemy.cpp"
#include "./Item.hpp"
#include "./../source/OddityRoom.cpp"

/*		   ENEMY    ITEM    O.ROOM    ROOM
 *	   ID   : 10-### , 20-### , 30-### , 35-###
 *      _________________________________________________________
 *	001     : Skeleton, DullBlade, GoldStatueRoom, Tree
 *
 *	002	: BigRat, WindRazor, DartTrapRoom, StoneHall
 *	
 *	003	: GrowSlime, StickWand, CatRoom, Meadow
 *	
 *	004	: ShieldSkeleton, BasicPotion, MirrorRoom, Lake
 *	
 *	005	: StrangeFairy, MediumPotion, , ZenGarden
 *	
 *	006	: , StrongPotion, , Cave
 *	
 *	007	: , MegaPotion, , ColdForge
 *	
 *	008	: , Swifties, , Spiderweb
 *	
 *	009	: , FlareOrb, , TorchlitHall
 *	
 *	010	: , RedPaw, , BrokenTrap
 *
 *	011	: , BluePaw, , ChasmBridge
 *
 *	012	: , GoldPaw, , 
 *
 *	013	: , MirrorKnife, , 
 *
 *	014	: , DebuffStick, , 
 *
 *	015	: , FakePotion, 
 *
 *	016	: , FobWatch,
 */

unsigned NUM_CLASSES = 3;
unsigned NUM_ENEMIES = 9;
unsigned NUM_ITEMS = 16;
unsigned NUM_CONSUMABLES = 4; //Leave this be for now please!
unsigned NUM_ODDITY_ROOMS = 4;
unsigned NUM_AMBIENT_ROOMS = 11;

class EnemyFactory {
public:
    Enemy* generate(unsigned int id) {
        switch(id) {
            case 10001: return new Skeleton();
            case 10002: return new BigRat();
            case 10003: return new GrowSlime();
            case 10004: return new ShieldSkeleton();
            case 10005: return new StrangeFairy();
            case 10006: return new GreenSlime();
            case 10007: return new BowSkeleton();
            case 10008: return new VampireWhelp();
            case 10009: return new TinySpider();
            default: std::cout << "There was an error in generating enemy. Is the ID correct?\n"; exit(1);
        }
    }
};

class ItemFactory {
public:
    Item* generate(unsigned int id) {
        switch(id) {
            case 20001: return new DullBlade();
            case 20002: return new WindRazor();
            case 20003: return new StickWand();
            case 20004: return new BasicPotion();
            case 20005: return new MediumPotion();
            case 20006: return new StrongPotion();
            case 20007: return new MegaPotion();
            case 20008: return new Swifties();
            case 20009: return new FlareOrb();
            case 20010: return new RedPaw();
            case 20011: return new BluePaw();
            case 20012: return new GoldPaw();
            case 20013: return new MirrorKnife();
            case 20014: return new DebuffStick();
	          case 20015: return new FakePotion();
	          case 20016: return new FobWatch(); 
            default: std::cout << "There was an error in generating item. Is the ID correct?\n"; exit(1);
        }
    }
};

class RoomFactory {
public:
    Room* generate(unsigned int id) {
        switch(id) {
            //ODDITY ROOMS BASE FROM ID 30000
            case 30001: return new GoldStatueRoom();
            case 30002: return new DartTrapRoom();
            case 30003: return new CatRoom();
            case 30004: return new MirrorRoom();
            //AMBIENT ROOMS BASE FROM ID 35000
            case 35001: return new Room("A room with a tree","This room has a small tree growing from the cracked earth.\nYou're not quite sure how it is surviving, but you quietly cheer it on.");
            case 35002: return new Room("A stone hallway","Your footsteps echo as you walk down this stone corridor.\nIt's a bit too quiet... you check behind yourself just to make sure, but you're safe.");
            case 35003: return new Room("A meadow","You wander into a calm meadow. It feels out of place, but the spot of tranquility nevertheless is appreciated.");
            case 35004: return new Room("A small lake","To call this a lake is an overstatement... more like a small pool of murky water.\nYou aren't even close to thirsty enough to drink from it.");
            case 35005: return new Room("A room of grey sand","The ground beneath your feet crumbles, and you realize it is sand. A small, broken rake lies in the rubble.\nWas this a zen garden of some kind?");
            case 35006: return new Room("A cave","You hear water droplets echo through this small cave, dripping from a stalactite nearby.\nYou cautiously hold your hand out and taste it.");
            case 35007: return new Room("An abandoned forge","The remains of a forge lay scattered around this room. It seems like it hasn't seen activitiy in years.");
            case 35008: return new Room("A stone hallway","Your footsteps echo as you walk down--- ECKPTH!! You walked into a spiderweb!!");
            case 35009: return new Room("A well-lit hall","This hallway has several torches bolted into their brackets.\nSome are extinguished, but the rest pleasantly light the way.");
            case 35010: return new Room("A stone hallway","Your footsteps echo as you walk down the stone corridor. You hear the click of a pressure plate...\nbut nothing happens. You breathe a sigh of relief for outdated tech.");
            case 35011: return new Room("A wooden bridge","You make your way to a narrow chasm with planks of wood percariously bridging the gap.\nYou take extreme caution, but you make it across without issue.");
            default: std::cout << "There was an error in generating oddity room. Is the ID correct?\n"; exit(1);
        }
    }
};

#endif
