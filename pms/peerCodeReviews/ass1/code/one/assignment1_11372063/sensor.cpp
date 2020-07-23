#include "sensor.h"


sensor::sensor()
{
    baud = 38400;
    port = 0;
    max_acce = 10;
}

// ********************setter****************

void sensor::set_baud(int input)
{
    baud = input;
}

void sensor::set_port(int input)
{
    port = input;
}

void sensor::set_max_acce(int input)
{
    max_acce = input;
}

void sensor::set_model(std::string input)
{
    model = input;
}

void sensor::set_sampling_time(int input)
{
    sampling_time = input;
}

void sensor::set_sampling_reso(int input)
{
    sampling_reso = input;
}

//*************************** getter********************

int sensor::get_baud()
{
    return baud;
}

int sensor::get_port()
{
    return port;
}

std::string sensor::get_model()
{
    return model;
}

int sensor::get_max_acce()
{
    return max_acce;
}

int sensor::get_sampling_time()
{
    return sampling_time;
}

int sensor::get_sampling_reso()
{
    return sampling_reso;
}



double sensor::get_data_x()
{
    double resolution = (double)rand()/RAND_MAX * (2*sampling_reso) - sampling_reso;
    double random = resolution/sampling_reso * max_acce;

    return random;
}

double sensor::get_data_y()
{
    double resolution = (double)rand()/RAND_MAX * (2*sampling_reso) - sampling_reso;
    double random = resolution/sampling_reso * max_acce;

    return random;
}

double sensor::get_data_z()
{
    double resolution = (double)rand()/RAND_MAX * sampling_reso - sampling_reso;
    double random = resolution/sampling_reso * max_acce;

    return random;
}
