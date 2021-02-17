#ifndef ROOM_H
#define ROOM_H

#include <iostream>

class Room{
    virtual void interact(Entity e) const = 0;
}

#endif