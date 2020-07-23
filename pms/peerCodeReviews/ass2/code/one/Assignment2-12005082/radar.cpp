#include "radar.h"

Radar::Radar()
{
    //Defaults
    SensorType_ = "Radar";
    Model_ = "RAD-001";
    BaudRate_ = 38400;
    Port_ = 0;
    FieldOfView_ = 20;
    MaxDistance_ = 16.0;
    MinDistance_ = 0.2;
    SampleSize_ = 1;
    V1 = {};
}
double Radar::getSampleSize()
{
    setSampleSize(1);
    return SampleSize_;
}
double Radar::setFieldOfView(double FieldOfView){           //If Fov is 20 or 40, store value
    if (FieldOfView == 20 || FieldOfView == 40){
        FieldOfView_ = FieldOfView;
    }
    else{
        return 0;                                           //otherwise store default
    }
}

