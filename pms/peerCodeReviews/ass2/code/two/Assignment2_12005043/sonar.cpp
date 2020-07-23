#include "sonar.h"

Sonar::Sonar()
{
    SensorType_ = "Sonar";  //default
    Model_ = "SONX-001";    //values
    Baud_ = 38400;          //for
    Port_ = 2;              //configurable
    FoV_ = 90;              //and
    MaxDis_ = 4.0;          //fixed
    MinDis_ = 0.2;          //parameters
    MultipleReadings_ = 0;  //in
    vi1 = {};               //constructor
}

