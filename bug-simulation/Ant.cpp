#include "Ant.h"

using namespace std;

void Ant::move(World& theWorld) {
    cout << "Ant moving...\n";
    int direction = rand() % 4 + 1;
    Organism::move(theWorld, direction);
}

void Ant::breed(World &theWorld) {
    cout << "Ant breeding...\n";
}

