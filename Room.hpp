#ifndef ROOM_H
#define ROOM_H

#include <iostream>

class Room{
public:
    virtual ~Room() = default;
    virtual void interact(Entity e) const = 0;
};

#endif