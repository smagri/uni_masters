#include "laser.h"

Laser::Laser() : Ranger("UTM-XXL", 0.2, 8)
{
    fieldOfView_ = 180;
    angularResolution_ = 15;
    data_.resize(13);
    numberOfSamples_ = 13;
}

bool Laser::setAngularResolution(int angularResolution)
{
    if (angularResolution == 15 || angularResolution == 30)
    {
        angularResolution_ = angularResolution;
        numberOfSamples_ = fieldOfView_/angularResolution_ + 1;
        data_.resize(numberOfSamples_);
        return true;
    }
    return false;
}

int Laser::getAngularResolution()
{
    return angularResolution_;
}

