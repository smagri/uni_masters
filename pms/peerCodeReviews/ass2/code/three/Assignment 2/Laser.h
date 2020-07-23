#ifndef LASER_H
#define LASER_H

#include "Ranger.h"
#include <vector>

class Laser : public Ranger
{
public:
    Laser();
    void printModel();
    int getAngularRes();
    void setAngularRes();
    float getMaxDist();
    float getMinDist();
    int getFieldofView();
    double getDist();
    void start();
    vector<double> getContDist(int sample);

private:
    int fieldOfView_;
    float maxDist_;
    float minDist_;
    int AngularRes_;
    int dist_;
};

#endif // LASER_H
