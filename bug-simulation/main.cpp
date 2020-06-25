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
    World hellen(5, 200);
    hellen.printWorld();
    hellen.timeStepWorld();
    hellen.printWorld();
}
