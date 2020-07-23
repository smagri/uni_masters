#ifndef RADAR_H
#define RADAR_H
#include "ranger.h"

class Radar: public Ranger
{
public:
    Radar();

    double getSampleSize();
    double setFieldOfView(double FieldOfView);
};

#endif // RADAR_H
