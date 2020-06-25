#ifndef ANT_H
#define ANT_H

#include "World.h"



class Ant : public Organism {
public:
    void move(World& theWorld);
    void breed(World& theWorld);
};

#endif

