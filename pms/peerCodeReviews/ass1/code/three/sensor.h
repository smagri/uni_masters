//Dennis James Duong, 11980974.
#ifndef SENSOR_H
#define SENSOR_H
#include <string>
using namespace std;
class Sensor    //create Sensor class
{
public:
    Sensor();
    void def_parameter();   //displays default parameters
    void baudrate(string baudinput);
    void port(string portinput);
    double angle(string angleinput);
    double scantime(string stinput);
    double scan(string angleinput, string stinput);
    void line();

private:
	//keeps these variables private so that the default parameters cannot be changed in the main or sensor.cpp
    double def_baudrate;
    int def_port;
    double def_angle;
    double def_scantime;

    char g;     //initialise g input as a character. this is for general cin>> use in the baud rate and usb selection.
    char h;     //h is a character input that will be used in a two bit array for correctly outputting the distance according to user input for speed and resolution.
    char i;     //as above
    char j;     //used only to cease automatic line printing from random number generator, so that parameters may be read.
    char x;     //used to initiate scan after parameters are viewed.
};

#endif // SENSOR_H
