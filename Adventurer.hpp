#ifndef __ADVENTURER_H__
#define __ADVENTURER_H__

#include "Entity.hpp"

class Adventurer : public Entity
{
	public:
		Adventurer(std::string, std::string, int, int, int, int, int, int);
		void levelUp();
		void actions();
		void setLevel(int); 
		int getLevel() const; 
	private:
		int level, experience; 
}; 

#endif 
