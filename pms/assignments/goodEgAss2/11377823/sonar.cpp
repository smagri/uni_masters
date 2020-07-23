#include "sonar.h"

Sonar::Sonar() : Ranger("SONX-001", 0.2, 4)
{
    fieldOfView_ = 90;
    data_.resize(1);
    numberOfSamples_ = 1;
}
