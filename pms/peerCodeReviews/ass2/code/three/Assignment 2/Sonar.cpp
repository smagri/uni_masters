#include "Sonar.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

Sonar::Sonar()
{
    maxDist_ = 4.0;
    minDist_ = 0.2;
    fieldOfView_ = 90;
}

void Sonar::printModel(){
    std::cout << "Sonar Model SONX-001" << std::endl;
}

void Sonar::start(){
    Sonar::printModel();
    cout << "Port: " << "/dev/ttyACM2" << endl;
    cout << "Min Distance: " << Sonar::getMinDist() << "m" << endl;
    cout << "Max Distance: " << Sonar::getMaxDist() << "m" << endl;
    cout << "Field of View: " << Sonar::getFieldofView() << " degrees" << endl;
    cout << "" << endl;

}

float Sonar::getMaxDist(){
    return maxDist_;
}

float Sonar::getMinDist(){
    return minDist_;
}

int Sonar::getFieldofView(){
    return fieldOfView_;
}

double Sonar::getDist(){
    //Random number generator
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::normal_distribution<double> normal(6.0,5.0);
    double random = normal(generator);
    if(random >= maxDist_){
        return maxDist_;
    }else if(random <= minDist_){
        return minDist_;
    }else{
        return random;
    }
}