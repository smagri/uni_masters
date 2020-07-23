#ifndef RANGER_H
#define RANGER_H
#include <string>
#include <random>
#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>                  //for set precision
#include <unistd.h>                 //for usleep

using namespace std;

class Ranger
{
public:

//=======================================================
//          Getters
//=======================================================
    Ranger();
    string getSensorType();
    string getModel();
    double getBaudRate();
    double getPort();
    double getFieldOfView();
    double getAngularResolution();
    double getMaxDistance();
    double getMinDistance();
    virtual double getSampleSize();
//=======================================================
//          Setters
//=======================================================
    double setBaudRate(double BaudRate);
    double setPort (double Port);
    void setFieldOfView(double FieldOfView);
    void setAngularResolution(double AngularResolution);
    virtual void setSampleSize(double SampleSize);
//=======================================================
//          Vectors
//=======================================================
    vector<double> RandomNumberGenerator();
    vector<double> V1;

protected:
    string SensorType_;
    string Model_;
    double BaudRate_;
    double Port_;
    double FieldOfView_;
    double AngularResolution_;
    double MaxDistance_;
    double MinDistance_;
    double SampleSize_;

};

#endif // RANGER_H
