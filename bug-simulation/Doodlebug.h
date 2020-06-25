#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include "Organism.h"
#include "Ant.h"
#include "World.h"
#include <iostream>
#include <map>



class Doodlebug : public Organism {
public:
    Doodlebug(int row, int column);
    Doodlebug();
    void move(World& theWorld);
    void starve();
    void breed(World& theWorld);
protected:
    std::map<int, bool> history;
};

#endif
