#ifndef RADAR_H
#define RADAR_H
#include "ranger.h"

class Radar: public Ranger  //derived class Radar of base class Ranger
{
public:
    Radar();
    bool setFoV (double FoV);   //bool function accepts a double which will come from user input in the main

};

#endif // RADAR_H
