#ifndef LASER_H
#define LASER_H

#include "ranger.h"

class Laser : public Ranger
{
public:
    Laser();
    bool setAngularResolution(int angularResolution);
    int getAngularResolution();

private:
    int angularResolution_;
};

#endif // LASER_H
