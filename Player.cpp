#include <iostream>
#include <string>
#include <vector>
#include "Entity.hpp"
#include "Item.hpp"

class Player : public Entity{
    std::vector<Item> inventory;
};