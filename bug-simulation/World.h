#ifndef WORLD_H
#define WORLD_H
#include "Doodlebug.h"
#include "Ant.h"
#include <vector>

class Ant;
class Doodlebug;

class World {
    friend class Organism;
    friend class Doodlebug;
    friend class Ant;
public:
    World(int numOfDoods, int numOfAnts);
    void printWorld() const;
    void moveOrganisms();
    void breedAnts();
    void breedDoods();
    bool timeStepWorld();
    bool checkWorldSpace();
    void createNewAnt(int numOfAnts);
    void createNewDood(int numOfDoods);
private:
    int timeStep;
    char** world;
    std::vector<Ant> ants;
    std::vector<Doodlebug> doodlebugs;
    bool canBreed;
};

#endif
