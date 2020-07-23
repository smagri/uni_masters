#include "sensor.h"
#include <cstdlib>
#include <time.h>

using namespace std;

Sensor::Sensor()
{
    fieldOfView_ = 180;
    baudRate_ = 38400;
    angRes_ = 0.5;
    scanTime_ = 50;
    maxDist_= 8;
    minDist_ = 0.2;
    dist_ = 0.2;
}

float Sensor::getAngRes(){
    return angRes_;
}

int Sensor::getBaudRate(){
   return baudRate_;
}

int Sensor::getFieldOfView(){
    return fieldOfView_;
}

int Sensor::getPort(){
    int random = rand()%20;
    port_ = (random/10);
    return port_;
}

float Sensor::getDist(){
    srand(time(NULL));
    float random = rand()%78;
    dist_ = (random/10)+0.2;
    return dist_;
}

int Sensor::getMaxDist(){
    return maxDist_;
}

float Sensor::getMinDist(){
    return minDist_;
}

int Sensor::getScanTime(){
    return scanTime_;
}

void Sensor::setAngRes(int i){
    switch (i){
    case 1: angRes_ = 0.5;
        break;
    case 2: angRes_ = 1;
        break;
    default: angRes_ = 0.5;
        break;
    }
}

void Sensor::setBaudRate(int i){
    switch (i){
    case 1: baudRate_ = 38400;
        break;
    case 2: baudRate_ = 115200;
        break;
    default:
        break;
    }
}

void Sensor::setScanTime(int i){
    switch (i){
    case 1: scanTime_ = 50;
        break;
    case 2: scanTime_ = 25;
        break;
    default: scanTime_ = 50;
        break;
    }
}
