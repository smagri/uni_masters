#include "Ranger.h"

using namespace std;


Ranger::Ranger()
{
    sampleNum_ = 10;

}

void Ranger::start(){

}

double Ranger::getDist(){

}

int Ranger::getFieldofView(){

}

void Ranger::setFieldOfView(){

}

float Ranger::getMaxDist(){

}

float Ranger::getMinDist(){

}

void Ranger::setAngularRes(){

}

int Ranger::getAngularRes(){

}


int Ranger::getUsbConnection(){
    return usbConnection_;
}

int Ranger::getBaudRate(){
    return baudRate_;
}

int Ranger::getSampleNum(){
    return sampleNum_;
}

void Ranger::setBaudRate(){

    int i = 1;

    cout << "Set Baud Rate 1. 38400 2. 115200" << endl;
    cin >> i;

    switch(i){
    case 1:
        baudRate_ = 38400;
        break;
    case 2:
        baudRate_ = 115200;
        break;
    default:
        break;
    }
}

