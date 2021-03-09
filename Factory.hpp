#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "Enemy.cpp"
#include "Item.hpp"
#include "OddityRoom.cpp"

/*		  ENTITY    ITEM     ROOM  
 *	   ID   : 10-### , 20-### , 30-### 
 *      ___________________________________
 *	001     : Skeleton, 
 *
 *	002	: BigRat,
 *	
 *	003	: GrowSlime,
 *	
 *	004	: ShieldSkeleton,
 *	
 *	005	: StrangeFairy,
 *	
 *	006	:
 *	
 *	007	:
 *	
 *	008	:
 *	
 *	009	:
 *	
 *	010	:
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
    Item* generate(unsigned int id) {
        switch(id) {
            case 20001:
            case 20002:
            case 20003:
            case 20004:
            default: std::cout << "There was an error in generating item. Is the ID correct?\n"; exit(1);
        }
    }
};

class RoomFactory {
    Room* generate(unsigned int id) {
        switch(id) {
            case 30001:
            case 30002:
            case 30003:
            case 30004:
            default: std::cout << "There was an error in generating oddity room. Is the ID correct?\n"; exit(1);
        }
    }
};

#endif
