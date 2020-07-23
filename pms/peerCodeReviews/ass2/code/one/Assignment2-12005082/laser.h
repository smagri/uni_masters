#ifndef LASER_H
#define LASER_H
#include "ranger.h"

class Laser: public Ranger
{
public:
    Laser();
    double setAngularResolution(double AngularResolution);
};

#endif // LASER_H
