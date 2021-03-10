#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "Enemy.cpp"
#include "Item.hpp"
#include "OddityRoom.cpp"

/*		  ENTITY    ITEM     ROOM  
 *	   ID   : 10-### , 20-### , 30-### 
 *      ___________________________________
 *	001     : Skeleton, DullBlade, GoldStatueRoom
 *
 *	002	: BigRat, WindRazor, DartTrapRoom
 *	
 *	003	: GrowSlime, StickWand, CatRoom
 *	
 *	004	: ShieldSkeleton, BasicPotion, MirrorRoom
 *	
 *	005	: StrangeFairy, MediumPotion,
 *	
 *	006	: , StrongPotion, 
 *	
 *	007	: , MegaPotion, 
 *	
 *	008	: , Swifties, 
 *	
 *	009	: , FlareOrb, 
 *	
 *	010	: , RedPaw,
 *
 *	011	: , BluePaw,
 *
 *	012	: , GoldPaw,
 *
 *	013	: , MirrorKnife,
 *
 *	014	: , DebuffStick,
 *
 *	015	:
 */


class EnemyFactory {
public:
    Enemy* generate(unsigned int id) {
        switch(id) {
            case 10001: return new Skeleton();
            case 10002: return new BigRat();
            case 10003: return new GrowSlime();
            case 10004: return new ShieldSkeleton();
            case 10005: return new StrangeFairy();
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
            default: std::cout << "There was an error in generating item. Is the ID correct?\n"; exit(1);
        }
    }
};

class RoomFactory {
public:
    Room* generate(unsigned int id) {
        switch(id) {
            case 30001: return new GoldStatueRoom();
            case 30002: return new DartTrapRoom();
            case 30003: return new CatRoom();
            case 30004: return new MirrorRoom();
            default: std::cout << "There was an error in generating oddity room. Is the ID correct?\n"; exit(1);
        }
    }
};

#endif
