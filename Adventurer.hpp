#ifndef __ADVENTURER_H__
#define __ADVENTURER_H__

#include "Entity.hpp"
#include "Item.hpp"
#include "Enemy.cpp"
#include "InputReader.cpp"
#include <vector>

class Adventurer : public Entity
{
	public:
		Adventurer(std::string, std::string, int, int, int, int, int, int);
		void levelUp();
		void actions();
		void setLevel(int); 
		int getLevel() const; 
		void addItem(Item*);
		void turn(std::vector<Enemy*>);
	private:
		int level, experience; 
		std::vector<Item*> inventory;
}; 

#endif 
