#include "radar.h"

Radar::Radar() : Ranger("RAD-001", 0.2, 16)
{
    fieldOfView_ = 20;
    data_.resize(1);
    numberOfSamples_ = 1;
}

bool Radar::setFieldOfView(int fieldOfView)
{
    // 20 or 40
    if (fieldOfView == 20 || fieldOfView == 40)
    {
        fieldOfView_ = fieldOfView;
        return true;
    }
    return false;
}

