#ifndef SONAR_H
#define SONAR_H

#include "Ranger.h"

class Sonar : public Ranger
{
public:
    Sonar();
    void printModel();
    float getMaxDist();
    float getMinDist();
    double getDist();
    int getFieldofView();
    void start();
private:
    int fieldOfView_;
    float maxDist_;
    float minDist_;
};

#endif // SONAR_H
