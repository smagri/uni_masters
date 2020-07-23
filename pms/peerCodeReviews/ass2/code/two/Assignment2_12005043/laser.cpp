#include "laser.h"

Laser::Laser()
{
    SensorType_ = "Laser";  //setting
    Model_ = "UTM-XXL";     //default
    Baud_ = 38400;          //values
    Port_ = 0;              //for
    FoV_ = 180;             //configurable
    MaxDis_ = 8.0;          //and
    MinDis_ = 0.2;          //fixed
    MultipleReadings_ = 1;  //parameters
    vi1 = {};               //.
}

