#ifndef SENSOR_H
#define SENSOR_H
#include <cstdio>
#include <string>
#include <stdlib.h>
#include <unistd.h> //for sleep()
#include <iostream>
#include <random>

class sensor
{
private:
    std::string model;
    int baud;
    int port;
    int sampling_time;
    int max_acce;
    int sampling_reso;

public:
    sensor();

    //setter
    void set_baud(int input);
    void set_port(int input);
    void set_max_acce(int input);

    void set_sampling_time(int input);
    void set_model(std::string input);
    void set_sampling_reso(int input);

    //getter
    int get_baud();
    int get_port();
    std::string get_model();
    int get_sampling_time();
    int get_max_acce();
    int get_sampling_reso();

    double get_data_x();
    double get_data_y();
    double get_data_z();


};

#endif // SENSOR_H
