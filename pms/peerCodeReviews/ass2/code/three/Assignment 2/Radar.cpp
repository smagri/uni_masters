#include "Radar.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

Radar::Radar()
{
    maxDist_ = 16.0;
    minDist_ = 0.2;
    fieldOfView_ = 20;
}

void Radar::printModel(){
    std::cout << "Radar Model RAD-001" << std::endl;
}

void Radar::start(){
    Radar::printModel();
    cout << "Port: " << "/dev/ttyACM1" << endl;
    cout << "Min Distance: " << Radar::getMinDist() << "m" << endl;
    cout << "Max Distance: " << Radar::getMaxDist() << "m" << endl;
    cout << "" << endl;

    Radar::setFieldOfView();
}

float Radar::getMaxDist(){
    return maxDist_;
}

float Radar::getMinDist(){
    return minDist_;
}

void Radar::setFieldOfView(){
    int i = 0;
    std::cout << "Select Field of View: 1. 20 deg 2. 40 deg" << std::endl;
    std::cin >> i;

    switch(i){
    case 1:
        fieldOfView_ = 20;
        break;
    case 2:
        fieldOfView_ = 40;
        break;
    default:
        break;
    }
}
    double Radar::getDist(){
        //Random number generator
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator(seed);
        std::normal_distribution<double> normal(6.0,5.0);
        double random = normal(generator);
        if(random > maxDist_){
            return maxDist_;
        }else if(random < minDist_){
            return minDist_;
        }else{
            return random;
        }
    }

