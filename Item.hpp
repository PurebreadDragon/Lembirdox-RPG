#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item{
protected:
    std::string name;
    std::string description;
    std::string abilityName;
    std::string abilityDescription;
	int health = 0, physAtk = 0, physDef = 0, magAtk = 0, magDef = 0, speed = 0;
    bool consumable = false;

public:
    Item(){
        this->name = "an item";
        this->description = "a description";
    }

    void inspect(){
        std::cout << "=====" << name << "=====\n" << description << "\n=====================\n";
    }

	virtual void ability(Entity* user, Entity* target) const = 0;

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

    std::string getAbilityName(){
        return abilityName;
    }

    std::string getAbilityDescription(){
        return abilityDescription;
    }
};


class DullBlade : public Item {
	public:
	DullBlade() {
		name = "Dull Blade";
		description = "An ordinary-looking longsword. Scratches along its surface indicate it's passed through the hands of many a traveler.\n";
        abilityName = "Swift Cut";
        abilityDescription = "A powerful slash using the blade of the sword. Hits more through blunt force than anything. Deals 120% PAtk physical damage.";
		physAtk = 10;
        consumable = false;
	}

	void ability(Entity* user, Entity* target) const {
		std::cout << "You slash at " << target->getName() << " with the blade, dealing " 
        << target->dealPDamage(user->getPAtk() * 1.2) << " damage.\n";
	}
};

class StickWand : public Item {
	public:
	StickWand() {
		name = "Ordinary Wand";
		description = "Some say this wand was once touched by a grand sorcerer, who blessed it with magical affinity...or maybe it's just a stick from the pile of kindling he used...";
		abilityName = "Magic Missile";
        abilityDescription = "A bolt of concentrated magic fired from the tip of the wand. Deals 120% MATK magic damage.";
		magAtk = 10;
        consumable = false;
	}

	void ability(Entity* user, Entity* target) const {
		std::cout << "You wave your " << name << " while summoning the traces of magical energy within, dealing " 
        << target->dealMDamage(user->getMAtk() * 1.2) << " damage.\n";
	}
};


class BasicPotion : public Item {
	protected: 
	int healstrength;

	public:
	BasicPotion() {
		name = "Basic Potion";
		description = "A concoction of herbs and magical essence. It carries the soothing scent of medicinal plants. Surely, this would heal a couple of scratches.";
		abilityName = "Drink";
        abilityDescription = "Drink the potion to heal yourself a little.";
        healstrength = 20;
        consumable = true;
	}

	void ability(Entity* user, Entity* target) const {
		std::cout << "You pop off the cap and down the " << name << ", healing yourself for " << healstrength << ". It tastes faintly of cherries.\n";
        user->heal(healstrength);
	}
};

class Swifties : public Item {
	public:
	Swifties() {
		this->name = "Boots of Swiftness";
		this->description = "A pair of lightweight boots fashioned from fine leather. Putting these on, you feel as nimble as lightning.\n";
		speed = 30;
        consumable = false;
	}
	
	void ability(Entity* user, Entity* target) const {
        // this is an example of an item that doesn't do anything
	}
};












#endif
