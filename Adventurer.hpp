#ifndef __ADVENTURER_H__
#define __ADVENTURER_H__

#include "Entity.hpp"

class Adventurer : public Entity
{
	public:
		Adventurer(std::string name, std::string description, int maxHealth, int physAtk, int physDef, int magAtk, int magDef, int speed);
		void levelUp();
		void actions();
		void setLevel(int); 
		int getLevel() const; 
	private:
		int level; 
}; 

#endif 
