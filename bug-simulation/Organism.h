#ifndef ORGANISM_H
#define ORGANISM_H
#include <string>

class World;




class Organism {
    friend class World;
public:
    Organism();
    Organism(int rowPlace, int columnPlace);
    virtual void move(World& theWorld, int direction);
    virtual void breed(World& theWorld);
    const std::string& getCode() const;
protected:
    int rowPlace, columnPlace;
    std::string code;
};

#endif
