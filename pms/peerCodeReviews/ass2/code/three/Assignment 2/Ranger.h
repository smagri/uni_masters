#ifndef RANGER_H
#define RANGER_H

#include "RangerFusionInterface.h"

#include <vector>
#include <iostream>

using std::vector;

class Laser;
class Radar;
class Sonar;

class Ranger
{
public:
    Ranger();
    virtual int getFieldofView();
    virtual void setFieldOfView();
    virtual float getMaxDist();
    virtual float getMinDist();
    virtual void setAngularRes();
    virtual int getAngularRes();
    virtual double getDist();
    int getSampleNum();
    int getUsbConnection();
    int getBaudRate();
    void setBaudRate();

    virtual void start();


    private:
    int numberOfSamples_;
    int usbConnection_;
    int baudRate_;
    int sampleNum_;
    vector<Ranger*> rangers_;
    int functionMethod_;
};

#endif // RANGER_H
