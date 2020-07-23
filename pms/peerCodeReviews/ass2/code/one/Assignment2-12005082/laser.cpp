#include "laser.h"

Laser::Laser()
{
    //Defaults
    SensorType_ = "Laser";
    Model_ = "UTM-XXL";
    BaudRate_ = 38400;
    Port_ = 0;
    FieldOfView_ = 180;
    AngularResolution_ = 15;
    MaxDistance_ = 8.0;
    MinDistance_ = 0.2;
    V1 = {};
}
double Laser::setAngularResolution(double AngularResolution)            //If Angular resolution is 15 or 30, store value
{
    if (AngularResolution == 15 || AngularResolution == 30){

        AngularResolution_ = AngularResolution;
    }
    else return 0;                                                      //Otherwise return default

}
