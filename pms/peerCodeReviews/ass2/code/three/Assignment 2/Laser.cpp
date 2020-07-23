#include "Laser.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

Laser::Laser()
{
    maxDist_ = 8.0;
    minDist_ = 0.2;
    AngularRes_ = 15;
    fieldOfView_ = 180;
}

void Laser::printModel(){
    std::cout << "Laser Model UTM-XXL" << std::endl;
}

void Laser::start(){
    Laser::printModel();
    cout << "Port: " << "/dev/ttyACM0" << endl;
    cout << "Min Distance: " << Laser::getMinDist() << "m" << endl;
    cout << "Max Distance: " << Laser::getMaxDist() << "m" << endl;
    cout << "Field of View: " << Laser::getFieldofView() << " degrees" << endl;
    cout << "" << endl;
    Laser::setAngularRes();
    Laser::setFieldOfView();
}

int Laser::getFieldofView(){
    return fieldOfView_;
}

float Laser::getMaxDist(){
    return maxDist_;
}

float Laser::getMinDist(){
    return minDist_;
}

int Laser::getAngularRes(){
    return AngularRes_;
}

void Laser::setAngularRes(){
    int i = 0;
    std::cout << "Set Angular Resolution: 1. 15 deg 2. 30 deg" << std::endl;
    std::cin >> i;

    switch(i){
    case 1:
        AngularRes_ = 15;
        break;
    case 2:
        AngularRes_ = 30;
        break;
    default:
        break;
    }
}

double Laser::getDist(){
    //Random number generator
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::normal_distribution<double> normal(5.0,6.0);
    double random = normal(generator);
    if(random > maxDist_){
        return maxDist_;
    }else if(random < minDist_){
        return minDist_;
    }else{
        return random;
    }
}

vector<double> Laser::getContDist(int sample){
    vector<double> contDist;
    while(sample > 0){
        contDist.push_back(Laser::getDist());
        sample--;
    }
    return contDist;
}


