#include "Doodlebug.h"
using namespace std;

void Doodlebug::breed(World &theWorld) {
    cout << "Yes\n";
}

void Doodlebug::move(World& theWorld) {
    cout << "Doodlebug moving from " << rowPlace << ' ' << columnPlace;
    int direction = rand() % 4 + 1;
    bool doodleAte = false, isDoodle = false;
    if (direction == 1) {
        cout << " up...\n";
        if (rowPlace != 0 && theWorld.world[rowPlace-1][columnPlace] == 'o') {
            theWorld.world[rowPlace-1][columnPlace] = theWorld.world[rowPlace][columnPlace];
            theWorld.world[rowPlace][columnPlace] = '-';
            --rowPlace;
            code = to_string(rowPlace) + to_string(columnPlace);
            doodleAte = true;
        }
        else if (theWorld.world[rowPlace-1][columnPlace] == 'X') isDoodle = true;
    }
    else if (direction == 2) {
        cout << " right...\n";
        if (columnPlace != 19 && theWorld.world[rowPlace][columnPlace+1] == 'o') {
            theWorld.world[rowPlace][columnPlace+1] = theWorld.world[rowPlace][columnPlace];
            theWorld.world[rowPlace][columnPlace] = '-';
            ++columnPlace;
            code = to_string(rowPlace) + to_string(columnPlace);
            doodleAte = true;
        }
        else if (theWorld.world[rowPlace][columnPlace+1] == 'X') isDoodle = true;
    }
    else if (direction == 3) {
        cout << " down...\n";
        if (rowPlace != 19 && theWorld.world[rowPlace+1][columnPlace] == 'o') {
            theWorld.world[rowPlace+1][columnPlace] = theWorld.world[rowPlace][columnPlace];
            theWorld.world[rowPlace][columnPlace] = '-';
            ++rowPlace;
            code = to_string(rowPlace) + to_string(columnPlace);
            doodleAte = true;
        }
        else if (theWorld.world[rowPlace+1][columnPlace] == 'X') isDoodle = true;
    }
    else { //direction == 4
        cout << " left...\n";
        if (columnPlace != 0 && theWorld.world[rowPlace][columnPlace-1] == 'o') {
            theWorld.world[rowPlace][columnPlace-1] = theWorld.world[rowPlace][columnPlace];
            theWorld.world[rowPlace][columnPlace] = '-';
            --columnPlace;
            code = to_string(rowPlace) + to_string(columnPlace);
            doodleAte = true;
            
        }
        else if (theWorld.world[rowPlace][columnPlace-1] == 'X') isDoodle = true;
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
