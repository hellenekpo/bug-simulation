#include "Ant.h"

using namespace std;

void Ant::move(World& theWorld) {
    //cout << "Ant moving...\n";
    int direction = rand() % 4 + 1;
    Organism::move(theWorld, direction);
}
Ant::Ant(int row, int column) : Organism(row, column) {}
Ant::Ant() : Organism() {}
void Ant::breed(World& theWorld) {
    int newAntRow = 0, newAntColumn = 0;
    bool hasBred = false;
    //cout << "Ant ";
    //Organism::breed(theWorld);
    if (rowPlace != 0 && theWorld.world[rowPlace-1][columnPlace] == '-') { // breeding up
        newAntRow = rowPlace - 1;
        newAntColumn = columnPlace;
        hasBred = true;
    }
    else if (columnPlace != 19 && theWorld.world[rowPlace][columnPlace+1] == '-') { // breeding right
        newAntRow = rowPlace;
        newAntColumn = columnPlace + 1;
        hasBred = true;
    }
    else if (rowPlace != 19 && theWorld.world[rowPlace+1][columnPlace] == '-') { // breeding down
        newAntRow = rowPlace + 1;
        newAntColumn = columnPlace;
        hasBred = true;
    }
    else if (columnPlace != 0 && theWorld.world[rowPlace][columnPlace-1] == '-') { // breeding left
        newAntRow = rowPlace;
        newAntColumn = columnPlace - 1;
        hasBred = true;
    }
    
    
    if (hasBred) {
        Ant* ant = new Ant(newAntRow, newAntColumn);
        theWorld.ants.push_back(*ant);
        theWorld.world[ant->rowPlace][ant->columnPlace] = 'o';
    }
}

