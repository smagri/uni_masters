#include "ranger.h"

Ranger::Ranger(std::string sensorName, double minDistance, double maxDistance)
{
    sensorName_ = sensorName;
    baud_ = 38400;
    minDistance_ = minDistance;
    maxDistance_ = maxDistance;
    usbPort_ = "/dev/tty/ACM0";
}

bool Ranger::setBaud(int baud)
{
    // either 38400 or 115200
    if (baud == 38400 || baud == 115200)
    {
        baud_ = baud;
        return true;
    }
    return false;
}

int Ranger::getBaud()
{
    return baud_;
}

bool Ranger::setPort(std::string port)
{
    std::string portString = "/dev/tty/ACM";
    if (isdigit(port[0]))
    {
        portString.append(port);
        usbPort_ = portString;
        return true;
    }

    return false;

}

std::string Ranger::getPort()
{
    return usbPort_;
}

double Ranger::getNumberOfSamples()
{
    return numberOfSamples_;
}

double Ranger::getMinDistance()
{
    return minDistance_;
}

double Ranger::getMaxDistance()
{
    return maxDistance_;
}

int Ranger::getFieldOfView()
{
    return fieldOfView_;
}

std::string Ranger::getSensorName()
{
    return sensorName_;
}

std::vector<double> Ranger::generateData()
{
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::normal_distribution<double> value_distribution(6,5); // values

    for (int i=0;i<numberOfSamples_;i++)
    {
        double value = value_distribution(generator);
        if (value <= minDistance_ || value >= maxDistance_)
        {
            data_.at(i) = maxDistance_;
        }
        else
            data_.at(i) = value;
    }

    return data_;
}

std::vector<double> Ranger::getData()
{
    return data_;
}
