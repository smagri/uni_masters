#ifndef RADAR_H
#define RADAR_H

#include "ranger.h"

class Radar : public Ranger
{
public:
    Radar();
    bool setFieldOfView(int fieldOfView);
};

#endif // RADAR_H
