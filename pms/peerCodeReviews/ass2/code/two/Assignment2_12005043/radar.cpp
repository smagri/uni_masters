#include "radar.h"

Radar::Radar()
{
    SensorType_ = "Radar";  //Setting
    Model_ = "RAD-001";     //default
    Baud_ = 38400;          //values
    Port_ = 1;              //for
    FoV_ = 20;              //configurable
    MaxDis_ = 16.0;         //and
    MinDis_ = 0.2;          //fixed
    MultipleReadings_ = 0;  //parameters
    vi1 = {};               //.
}
bool Radar::setFoV (double FoV){    //setter for field of view of radar sensor
    if (FoV == 20 || FoV == 40)     //this is specific to radar
        FoV_ = FoV;                 //overrides default value in constructor
}                                   //returns true/false if input from main meets one of the conditions
