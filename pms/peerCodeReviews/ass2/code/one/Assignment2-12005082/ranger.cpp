#include "ranger.h"
#include <iostream>
using namespace std;
Ranger::Ranger()
{
    AngularResolution_ = 15;        //default of 15 degrees
}
string Ranger::getSensorType(){
    return SensorType_;
}
string Ranger::getModel(){
    return Model_;
}
double Ranger::getBaudRate(){
    return BaudRate_;
}
double Ranger::getPort(){
    return Port_;
}
double Ranger::getFieldOfView(){
    return FieldOfView_;
}
double Ranger::getAngularResolution(){
    return AngularResolution_;
}
double Ranger::getMaxDistance(){
    return MaxDistance_;
}
double Ranger::getMinDistance(){
    return MinDistance_;
}
double Ranger::getSampleSize()
{
    SampleSize_ = 1+2*floor((FieldOfView_/2)/AngularResolution_);       //formula calculate number of samples based on varying FoV and Angular Resolution
    return SampleSize_;
}

double Ranger::setBaudRate(double BaudRate){
    if (BaudRate == 38400 || BaudRate == 115200){                       //If Baud Rate is 38400 or 115200, store value

        BaudRate_ = BaudRate;
    }
    else{
        return 0;                                                       //Otherwise store default
    }
}

double Ranger::setPort(double Port){
    if (Port == 0 || Port == 1 || Port == 2){                           //If USB port is 0,1 or 2, store value

        Port_ = Port;
    }
    else{
        return 0;                                                       //Otherwise store default
    }
}
void Ranger::setFieldOfView(double FieldOfView)
{
    FieldOfView_ = FieldOfView;
}

void Ranger::setAngularResolution(double AngularResolution){
    AngularResolution_ = AngularResolution;
}

void Ranger::setSampleSize(double SampleSize)
{
    SampleSize_ = SampleSize;
}

vector<double> Ranger::RandomNumberGenerator(){                         //Random Number generator
    V1.clear();
    int rng;
    random_device Generator;
    default_random_engine Random(Generator());
    normal_distribution<double> distribution(6.0 , 5.0);                //Mean 6, std deviation of 5
    V1.clear();
    int s = getSampleSize();                                            //based on sample size
    for(rng = 0; rng < s; ++rng){
    double G = distribution(Random);

    if ( G>=MaxDistance_){                                              //clip values to remain within their max and min distances
        G = MaxDistance_;
    }
    else if (G<=MinDistance_){
        G = MinDistance_;
    }
    else{
        G;
    }
     V1.push_back(G);
}
    return V1;
}

