#ifndef __ADVENTURER_H__
#define __ADVENTURER_H__

#include "Entity.hpp"
#include "Item.hpp"
#include "Enemy.cpp"
#include "InputReader.cpp"
#include <vector>
#include <math.h>

class Adventurer : public Entity
{
	public:
		Adventurer(std::string, std::string, int, int, int, int, int, int);
		void levelUp();
		void setLevel(int); 
		int getLevel() const; 
		void inspect();
		void addGold(int);
		void addExp(int);
		void addItem(Item*);
		void turn(std::vector<Enemy*>);
		void attack(Enemy*);
		void setHealth(double);
		void setHealth(int);
	private:
		int level = 1, experience = 0, gold = 0; 
		int maxHealthBonus = 0, physAtkBonus = 0, physDefBonus = 0, magAtkBonus = 0, magDefBonus = 0, speedBonus = 0;
		std::vector<Item*> inventory;
}; 

#endif 
