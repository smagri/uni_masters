#ifndef RANGER_H
#define RANGER_H

#include <string>
#include <vector>
#include <random>
#include <chrono>

class Ranger
{
public:


    bool setBaud(int baud);
    int getBaud();

    bool setPort(std::string port);
    std::string getPort();

    // Getters for fixed parameters
    double getNumberOfSamples();
    double getMinDistance();
    double getMaxDistance();
    int getFieldOfView();
    std::string getSensorName();
    std::vector<double> generateData();
    std::vector<double> getData();

protected:
    Ranger(std::string sensorName, double minDistance, double maxDistance);

    int fieldOfView_;
    double numberOfSamples_;
    std::vector<double> data_;
    std::string usbPort_;

    std::string sensorName_;
    int baud_;
    double maxDistance_;
    double minDistance_;
};

#endif // RANGER_H
