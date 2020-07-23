#ifndef RADAR_H
#define RADAR_H

#include "Ranger.h"

class Radar : public Ranger
{
public:
    Radar();
    void printModel();
    float getMaxDist();
    float getMinDist();
    void setFieldOfView();
    double getDist();
    void start();
private:
    int fieldOfView_;
    float maxDist_;
    float minDist_;
};

#endif // RADAR_H
