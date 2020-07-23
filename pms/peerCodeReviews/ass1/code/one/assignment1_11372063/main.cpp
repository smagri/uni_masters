#include <cstdio>
#include "sensor.h"
#include <cmath>

int main()
{
    int baud_;
    int port_;
    int max_acce_;

    printf("Assignment 1 - 3 Axis accelerometer sensor\n\n");

    // Initialises the sensor
    sensor sensor1;

    // Queries the fixed sensor parameters
    sensor1.set_sampling_time(100);
    sensor1.set_sampling_reso(pow(2,12));
    sensor1.set_model("HWE-XXL");

    // Sets sensor parameters as specified by user
    printf("Enter baud (19200 or 38400): ");
    scanf("%d",&baud_);
    if(baud_ == 19200 || baud_ == 38400)
    {
        sensor1.set_baud(baud_);
    }
    else
    {
        printf("Invalid, use default value 38400\n\n");
    }

    printf("Enter USB port you prefer connect to (0 ,1 or 2): ");
    scanf("%d",&port_);
    if(port_ == 0 || port_ == 1 || port_ == 2)
    {
        sensor1.set_port(port_);
    }
    else
    {
        printf("Invalid, use default value 0\n\n");
    }

    printf("Enter Max acceleration (10m/s^2 ,20m/s^2 or 50m/s^2): ");
    scanf("%d",&max_acce_);
    if(max_acce_ == 10 || max_acce_ == 20 || max_acce_ == 50)
    {
        sensor1.set_max_acce(max_acce_);
    }
    else
    {
        printf("Invalid, use default value 10\n\n");
    }


    // show senosr information
    printf("Sensor information\n\n");
    printf("Model: %s\n",sensor1.get_model().c_str());
    printf("Baud: %d\n",sensor1.get_baud());
    printf("USB port: dev/ttyUSB %d\n",sensor1.get_port());
    printf("Sampling time: %d\n",sensor1.get_sampling_time());
    printf("Max acceleration: %d\n",sensor1.get_max_acce());
    printf("Sampling resolution: %d\n",sensor1.get_sampling_reso());


    // Continuously queries and displays data from the sensor
    printf("\nSensor Data\n\n");
    usleep(1000000);

    int seq = 1;

    while(1)
    {
        printf("***  %d  ***\n",seq);
        printf(" [x] = %lf m/s^2\n",sensor1.get_data_x());
        printf(" [y] = %lf m/s^2\n",sensor1.get_data_y());
        printf(" [z] = %lf m/s^2\n\n",sensor1.get_data_z());
        seq ++;
        sleep(1/sensor1.get_sampling_time());

    }


    return 0;
}
