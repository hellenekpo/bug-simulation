#include "World.h"
using namespace std;

void World::moveOrganisms() {
    cout << "TimeStep: " << timeStep << endl;
    for (Doodlebug& doodlebug : doodlebugs) {
        doodlebug.move(*this);
    }
    for (Ant& ant : ants) {
        ant.move(*this);
    }
    cout << "Number of Doodlebugs: " << doodlebugs.size() << endl;
    cout << "Number of Ants: " << ants.size() << endl;
}

void World::breedAnts() {
    for (Ant& ant : ants) {
        ant.breed(*this);
    }
}

void World::breedDoods() {
    for (Doodlebug& doodlebug : doodlebugs) {
        doodlebug.breed(*this);
    }
}

void World::printWorld() const {
    for (int row = 0; row < 20; ++row) {
        for (int column = 0; column < 20; ++ column) {
            if (column < 19) cout << world[row][column] << ' ';
            else {
                cout << world[row][column] << endl;
            }
        }
    }
}

void World::timeStepWorld() {
    ++timeStep;
    moveOrganisms();
    if (timeStep % 3 == 0) breedAnts();
    if (timeStep % 8 == 0) breedDoods();
}

World::World(int numOfDoods, int numOfAnts) : timeStep(0) {
    world = new char*[20];
    for (int i = 0; i < 20; ++i) {
        world[i] = new char[20];
    }
    
    for (int row = 0; row < 20; ++row) {
        for (int column = 0; column < 20; ++ column) {
                world[row][column] = '-';
        }
    }
    
    for (int antdex = 0; antdex < numOfAnts; ++antdex) {
        Ant* ant = new Ant();
        if (ants.size() != 0) {
            while(world[ant->rowPlace][ant->columnPlace] != '-') {
                delete ant;
                ant = new Ant();
            }
        }
        ants.push_back(*ant);
        world[ant->rowPlace][ant->columnPlace] = 'o';
    }
    
    for (int doodex = 0; doodex < numOfDoods; ++doodex) {
        Doodlebug* doodlebug = new Doodlebug();
        if (doodlebugs.size() != 0) {
            while(world[doodlebug->rowPlace][doodlebug->columnPlace] != '-') {
                delete doodlebug;
                doodlebug = new Doodlebug();
            }
        }
        doodlebugs.push_back(*doodlebug);
        world[doodlebug->rowPlace][doodlebug->columnPlace] = 'X';
    }
}
