#include "sonar.h"

Sonar::Sonar()
{
    //Defaults
    SensorType_ = "Sonar";
    Model_ = "SONX-001";
    BaudRate_ = 38400;
    Port_ = 0;
    FieldOfView_ = 90;
    MaxDistance_ = 4.0;
    MinDistance_ = 0.2;
    SampleSize_ = 1;
    V1 = {};
 }
double Sonar::getSampleSize()
{
    setSampleSize(1);
    return SampleSize_;
}

