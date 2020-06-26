#include "Doodlebug.h"
using namespace std;
Doodlebug::Doodlebug(int row, int column) : Organism(row, column) {}
Doodlebug::Doodlebug() : Organism() {}

void Doodlebug::move(World& theWorld) {
    //cout << "Doodlebug moving from " << rowPlace << ' ' << columnPlace;
    int direction = rand() % 4 + 1;
    bool doodleAte = false, isDoodle = false;
    if (direction == 1) {
        //cout << " up...\n";
        if (rowPlace != 0 && theWorld.world[rowPlace-1][columnPlace] == 'o') {
            theWorld.world[rowPlace-1][columnPlace] = theWorld.world[rowPlace][columnPlace];
            theWorld.world[rowPlace][columnPlace] = '-';
            --rowPlace;
            code = to_string(rowPlace) + to_string(columnPlace);
            doodleAte = true;
        }
        else if (rowPlace != 0 && theWorld.world[rowPlace-1][columnPlace] == 'X') isDoodle = true;
    }
    else if (direction == 2) {
        //cout << " right...\n";
        if (columnPlace != 19 && theWorld.world[rowPlace][columnPlace+1] == 'o') {
            theWorld.world[rowPlace][columnPlace+1] = theWorld.world[rowPlace][columnPlace];
            theWorld.world[rowPlace][columnPlace] = '-';
            ++columnPlace;
            code = to_string(rowPlace) + to_string(columnPlace);
            doodleAte = true;
        }
        else if (columnPlace != 19 && theWorld.world[rowPlace][columnPlace+1] == 'X') isDoodle = true;
    }
    else if (direction == 3) {
        //cout << " down...\n";
        if (rowPlace != 19 && theWorld.world[rowPlace+1][columnPlace] == 'o') {
            theWorld.world[rowPlace+1][columnPlace] = theWorld.world[rowPlace][columnPlace];
            theWorld.world[rowPlace][columnPlace] = '-';
            ++rowPlace;
            code = to_string(rowPlace) + to_string(columnPlace);
            doodleAte = true;
        }
        else if (rowPlace != 19 && theWorld.world[rowPlace+1][columnPlace] == 'X') isDoodle = true;
    }
    else { //direction == 4
        //cout << " left...\n";
        if (columnPlace != 0 && theWorld.world[rowPlace][columnPlace-1] == 'o') {
            theWorld.world[rowPlace][columnPlace-1] = theWorld.world[rowPlace][columnPlace];
            theWorld.world[rowPlace][columnPlace] = '-';
            --columnPlace;
            code = to_string(rowPlace) + to_string(columnPlace);
            doodleAte = true;
            
        }
        else if (columnPlace != 0 && theWorld.world[rowPlace][columnPlace-1] == 'X') isDoodle = true;
    }
    
    if (doodleAte) {
        for (size_t i = 0; i < theWorld.ants.size(); ++i) {
            if (theWorld.ants[i].getCode() == code) {
                swap(theWorld.ants[i], theWorld.ants[theWorld.ants.size()-1]);
                theWorld.ants.pop_back();
            }
        }
    }
    else if (!isDoodle && !doodleAte) {
        Organism::move(theWorld, direction);
    }
    history[theWorld.timeStep] = doodleAte;
}

void Doodlebug::breed(World &theWorld) {
    int newDoodRow = 0, newDoodColumn = 0;
    bool hasBred = false;
    //cout << "Doodlebug ";
    //Organism::breed(theWorld);
    if (rowPlace != 0 && theWorld.world[rowPlace-1][columnPlace] == '-') { // breeding up
        newDoodRow = rowPlace - 1;
        newDoodColumn = columnPlace;
        hasBred = true;
    }
    else if (columnPlace != 19 && theWorld.world[rowPlace][columnPlace+1] == '-') { // breeding right
        newDoodRow = rowPlace;
        newDoodColumn = columnPlace + 1;
        hasBred = true;
    }
    else if (rowPlace != 19 && theWorld.world[rowPlace+1][columnPlace] == '-') { // breeding down
        newDoodRow = rowPlace + 1;
        newDoodColumn = columnPlace;
        hasBred = true;
    }
    else if (columnPlace != 0 && theWorld.world[rowPlace][columnPlace-1] == '-') { // breeding left
        newDoodRow = rowPlace;
        newDoodColumn = columnPlace - 1;
        hasBred = true;
    }
    
    
    if (hasBred) {
        Doodlebug* doodlebug = new Doodlebug(newDoodRow, newDoodColumn);
        theWorld.doodlebugs.push_back(*doodlebug);
        theWorld.world[doodlebug->rowPlace][doodlebug->columnPlace] = 'X';
    }
}
