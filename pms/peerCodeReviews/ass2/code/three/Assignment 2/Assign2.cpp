#include "Laser.h"
#include "Radar.h"
#include "RangerFusionInterface.h"
#include "RangerFusion.h"
#include "Sonar.h"
#include "Ranger.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

int main(){

    Laser laser;
    Sonar sonar;
    Radar radar;

    vector<Ranger*> Sensors;
    RangerFusion rangers;

    //Add created Sesnor address to the Ranger object via pointers
    Sensors.push_back(&laser);
    Sensors.push_back(&sonar);
    Sensors.push_back(&radar);

    // Initalize the sensors through start() method
    for(int i = 0; i < 3; i++){
        Sensors.at(i)->start();
    }

    //Allocate the Ranger object to the RangerFusion Object to all fusion of data
    rangers.setRangers(Sensors);

    //get fused range data. Method is set to print outputs. Will loop till canceled.
    while(1){

         rangers.getFusedRangeData();
    }

    return 0;
}
