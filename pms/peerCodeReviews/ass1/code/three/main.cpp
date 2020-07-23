//Dennis James Duong, 11980974.
#include "sensor.h"
#include <iostream> //cin, cout, endl
#include <string>   //string class

using namespace std;

int main()
{
    Sensor S;

    //display default parameters
    S.def_parameter();

    //allow user input for baudrate
    S.line();
    cout<<"Input Baud Rate:"<<endl;
    cout<<"a: 38400."<<endl;
    cout<<"b: 115200."<<endl;
    string input;
    cin>>input;
    S.baudrate(input);

    //allow user input for port
    S.line();
    cout<<"Choose USB Port:0,1,2."<<endl;
    cout<<"a: 0"<<endl;
    cout<<"b: 1"<<endl;
    cout<<"c: 2"<<endl;
    string portinput;
    cin >> portinput;
    S.port(portinput);

    //allow user input for angle
    S.line();
    cout<<"At 180 degrees scan, would you like to scan at:"<<endl;
    cout<<"a: 1 degree."<<endl;
    cout<<"b: 0.5 degrees."<<endl;
    string angleinput;
    cin >> angleinput;
    S.angle(angleinput);

    //allow user input for scantime
    S.line();
    cout<<"Would you like to scan at:"<<endl;
    cout<<"a: 50ms per increment."<<endl;
    cout<<"or b: 25ms per increment."<<endl;
    string stinput;
    cin >> stinput;
    S.scantime(stinput);

    //run scanner using input from angle and scantime functions.
    S.line();
    cout<<"Press any key and enter to see parameters now"<<endl;
    string checkparameters;
    cin >> checkparameters;
    S.scan(angleinput, stinput);

return 0;
}
