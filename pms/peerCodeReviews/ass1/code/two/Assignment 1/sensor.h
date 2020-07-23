#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
public:
    Sensor();
    int getBaudRate();
    float getAngRes();
    int getScanTime();
    int getMaxDist();
    float getMinDist();
    float getDist();
    int getPort();
    int getFieldOfView();

    void setBaudRate(int i);
    void setAngRes(int i);
    void setScanTime(int i);

protected:
    int fieldOfView_;
    int port_;
    int baudRate_;
    float angRes_;
    int scanTime_;
    int maxDist_;
    float minDist_;
    float dist_;
};

#endif // SENSOR_H
