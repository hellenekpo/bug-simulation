#include<iostream>
#include<string>
#include<fstream>
#include <vector>
#include <stdlib.h>

#include "World.h"
#include "Ant.h"
#include "Doodlebug.h"

using namespace std;


int main() {
    World hellen(5, 100);
    cout << "Welcome to the Bug Simulation!\nThe population of "
    << "Ants and Doodlebugs are currently coexisting in harmony.\n";
    hellen.printWorld();
    cout << "Doodlebug: 'Err...'\n"
    << "Oh no! The Doodlebugs realized they can add Ants to their diet!\n"
    << "They start preying on Ants and the population changes between timesteps!\n"
    << "Press the 'Enter' key to watch how the population changes between "
    << "timesteps!\n";
    while (cin.get() == '\n') {
        hellen.timeStepWorld();
        if (!hellen.timeStepWorld()) {
            cout << "This is how the ecosystem has changed:\n";
            hellen.printWorld();
            break;
        }
        hellen.printWorld();
    }
}
