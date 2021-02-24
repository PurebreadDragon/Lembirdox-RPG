#ifndef __ADVENTURER_H__
#define __ADVENTURER_H__

#include "Entity.hpp"

class Adventurer : public Entity
{
	public:
		Adventurer(string, int); 
		void levelUp();
		void actions();
		void setLevel(int); 
		int getLevel() const; 
	private:
		string class;
		int level; 
}; 

#endif 
