fndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item{
protected:
    std::string name;
    std::string description;
	int health, physAtk, physDef, magAtk, magDef, speed;


public:
    Item(){
        this->name = "an item";
        this->description = "a description";
		health = 0;
		physAtk = 0;
		physDef = 0;
		magAtk = 0;
		magDef = 0;
		speed = 0;
    }

    void inspect(){
        std::cout << "=====" << name << "=====\n" << description << "\n=====================\n";
    }

	virtual void ability() const = 0;

	int gethealthval() {
		return health;
	}

	int getPAtk() {
		return physAtk;
	}

	int getPDef() {
		return physDef;
	}

	int getMAtk() {
		return magAtk;
	}

	int getMDef() {
		return magDef;
	}

	int getSpeed() {
		return speed;
	}

	std::string getName() {
		return name;
	}

	std::string getDescription() {
		return description;
	}


};


class DullBlade : public Item {
	public:
	DullBlade() {
		this->name = "Dull Blade";
		this->description = "An ordinary-looking longsword. Scratches along its surface indicate it's passed through the hands of many a traveler.\n";
		health = 0;
		physAtk = 10;
		physDef = 0;
		magAtk = 0;
		magDef = 0;
		speed = 0;
	}

	void ability () const {
		std::cout << "You slash forward with your Dull Blade, dealing " << physAtk << " damage.\n";
	}

};

class BasicPotion : public Item {
	protected: 
	int healstrength;

	public:
	BasicPotion() {
		this->name = "Basic Potion";
		this->description = "A concoction of herbs and magical essence. It carries the soothing scent of medicinal plants. Surely, this would heal a couple of scratches.\n";
		healstrength = 20;

	}

	void ability() const {
		std::cout << "You pop off the cap and apply " << this->name << ", healing yourself for a total of " << healstrength << " health.\n";


	}
};

class Swifties : public Item {
	public:
	Swifties() {
		this->name = "Boots of Swiftness";
		this->description = "A pair of lightweight boots fashioned from fine leather. Putting these on, you feel as nimble as lightning.\n";
		speed = 30;
	}
	
	void ability() const {
		std::cout << "The " << this->name << " empower your movement.\n";


	}
};












#endif
