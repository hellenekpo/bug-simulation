#include "Organism.h"
#include "World.h"

using namespace std;

Organism::Organism() : rowPlace(rand() % 20), columnPlace(rand() % 20){
    code = to_string(rowPlace) + to_string(columnPlace);
}
Organism::Organism(int rowPlace, int columnPlace) : rowPlace(rowPlace), columnPlace(columnPlace) {
    code = to_string(rowPlace) + to_string(columnPlace);
}
const string& Organism::getCode() const {
    return code;
}

void Organism::breed(World &theWorld) {
    cout << " is breeding...\n";
}


void Organism::move(World& theWorld, int direction) {
    if (direction == 1) {
        if (rowPlace != 0 && theWorld.world[rowPlace-1][columnPlace] == '-') {
            theWorld.world[rowPlace-1][columnPlace] = theWorld.world[rowPlace][columnPlace];
            theWorld.world[rowPlace][columnPlace] = '-';
            --rowPlace;
        }
    }
    else if (direction == 2) {
        if (columnPlace != 19 && theWorld.world[rowPlace][columnPlace+1] == '-') {
            theWorld.world[rowPlace][columnPlace+1] = theWorld.world[rowPlace][columnPlace];
            theWorld.world[rowPlace][columnPlace] = '-';
            ++columnPlace;
        }
    }
    else if (direction == 3) {
        if (rowPlace != 19 && theWorld.world[rowPlace+1][columnPlace] == '-') {
            theWorld.world[rowPlace+1][columnPlace] = theWorld.world[rowPlace][columnPlace];
            theWorld.world[rowPlace][columnPlace] = '-';
            ++rowPlace;
        }
    }
    else { //direction == 4
        if (columnPlace != 0 && theWorld.world[rowPlace][columnPlace-1] == '-') {
            theWorld.world[rowPlace][columnPlace-1] = theWorld.world[rowPlace][columnPlace];
            theWorld.world[rowPlace][columnPlace] = '-';
            --columnPlace;
        }
    }
    code = to_string(rowPlace) + to_string(columnPlace);
}
