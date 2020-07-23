//Dennis James Duong, 11980974.
#include "sensor.h" //includes the header file for the Sensor class
#include <iostream> //cin, cout, endl
#include <string>   //string class
#include <unistd.h> //usleep()
#include <random>   //default_random_engine, random_device, uniform_real_distribution
#include <iomanip>  //setprecision
using namespace std;

Sensor::Sensor()
{
    def_baudrate = 38400;
    def_port = 0;
    def_angle = 1;
    def_scantime = 50;
}
void Sensor::line()				//creates a line break for neatness and clarity
{
    cout<<" "<<endl;
}
void Sensor::def_parameter() 	//prints the parameters as they are in default sensor mode.
{
    line();
    cout<<"The following are default parameters:"<<endl;
    cout<<"Sensor Model: UTM-XXL."<<endl;
    cout<<"Sensor Baud Rate: "<<def_baudrate<<"."<<endl;
    cout<<"Sensor Port: "<<def_port<<"."<<endl;
    cout<<"Sensor Field of View: 180 Degrees."<<endl;
    cout<<"Sensor Angular Resolution: "<<def_angle<<"."<<endl;
    cout<<"Sensor Scanning Time: "<<def_scantime<<"."<<endl;
    cout<<"Sensor Distance Detection Range: 0.2 - 8.0 metres."<<endl;
}
void Sensor::baudrate(string baudinput)    		//function for giving user control over baud rate
{
    if(baudinput.length()!=1){		//checks that the string is limited to 1 character; if more than 1, set parameter to default.
        cout<<"Input not sane. Sensor Baud Rate using default value of: "<<def_baudrate<<"."<<endl;
    }else {g = baudinput[0];		//takes the 0 element of the string and assigns it to character variable g to be used in the switch case statement.
        switch (g){
        case 'a':
            cout<<"Sensor Baud Rate: 38400"<<endl;
            break;
        case 'b':
            cout<<"Sensor Baud Rate: 115200"<<endl;
            break;
        default:
            cout<<"Input not sane. Sensor Baud Rate using default value of: "<<def_baudrate<<"."<<endl;
           break;
    }}

}

void Sensor::port(string portinput)				//function for giving user control over usb port usage.
{

    if(portinput.length()!=1){		//checks that the string is limited to 1 character; if more than 1, set parameter to default.
        cout<<"Input not sane. Sensor Port using default value of: "<<def_port<<endl;
    }else {g = portinput[0];		//takes the 0 element of the string and assigns it to character variable g to be used in the switch case statement.
    if (g=='a'){
            cout<<"Sensor Port: 0."<<endl;
            }
        else if(g=='b'){
            cout<<"Sensor Port: 1."<<endl;
            }
        else if(g=='c'){
            cout<<"Sensor Port: 2."<<endl;
            }
        else {
           cout<<"Input not sane. Sensor Port using default value of: "<<def_port<<endl;}
           }
    }
double Sensor::angle(string angleinput)			//function for giving user control over angular resolution of the scanner
{

    if(angleinput.length()!=1){		//checks that the string is limited to 1 character; if more than 1, set parameter to default.
        cout<<"Input not sane. Sensor Angular Resolution using default value of: "<<def_angle<<" degree"<<endl;
        h = 'a';
    }else {h = angleinput[0];		//takes the 0 element of the string and assigns it to character variable h to be used in the switch case statement.
        switch (h){
        case 'a':
            cout<<"Sensor Angular Resolution: 1 degree."<<endl;
            break;
        case 'b':
            cout<<"Sensor Angular Resolution: 0.5 degrees."<<endl;
            break;
        default:
           cout<<"Input not sane. Sensor Angular Resolution using default value of: "<<def_angle<<" degree"<<endl;
           h = 'a';
           break;}
        }
}

double Sensor::scantime(string stinput)
{
    if(stinput.length()!=1){		//checks that the string is limited to 1 character; if more than 1, set parameter to default.
        cout<<"Input not sane. Sensor Scantime using default value of: "<<def_scantime<<"ms"<<endl;
        i = 'a';
    }else {i = stinput[0];		//takes the 0 element of the string and assigns it to character variable g to be used in the switch case statement.
    switch (i){
        case 'a':
            cout<<"Sensor Scantime: 50ms."<<endl;
            break;
        case 'b':
            cout<<"Sensor Scantime: 25ms."<<endl;
            break;
        default:
           cout<<"Input not sane. Sensor Scantime using default value of: "<<def_scantime<<"ms"<<endl;
           i = 'a';
           break;}
    }
}

double Sensor::scan(string angleinput, string stinput)
{
    //if(scaninput.length()!=1){		//checks that the string is limited to 1 character; if more than 1, set parameter to default.
        //g = 'a';
    //}else {j = scaninput[0];}		//takes the 0 element of the string and assigns it to character variable g to be used in the switch case statement.
    cout<<"Degree Choice was "<<h<<endl;
    cout<<"Scan Choice was "<<i<<endl;
    char A[h][i];
    A['a']['a'] = 'a';
    A['a']['b'] = 'b';
    A['b']['a'] = 'c';
    A['b']['b'] = 'd';
    cout<<"Case choice is "<<A[h][i]<<endl;  			//for debugging and showing the chosen case
    random_device rd;									//true random number generator that allows for uniformally distributed numbers.
    default_random_engine generator(rd());				//generates the random number and assigns it to rd
    uniform_real_distribution<double> dist(0.2,8.0);	//distributes the random number within the range given
    switch(A[h][i]){
    case 'a':
        cout<<"Display distance measured at 1 degree increments every 50ms"<<endl;
        cout<<"Press any key and enter to scan now."<<endl;
        cin>>x;
        for(int d = 0;d<181;d++)    					//generate 180 instances delayed by 50 ms each
        {   int *angle_ptr = &d;						//pointer used to show the incrementing variable as the current angle.
            cout<<"At "<<*angle_ptr<<" degrees, the distance is "<<fixed << setprecision(2)<<dist(rd) <<endl;
            usleep(50000);}								//usleep is in microseconds; 50milliseconds = 50000 microseconds.
        break;
    case 'b':
        cout<<"Display distance measured at 1 degree increments every 25ms"<<endl;
        cout<<"Press any key and enter to scan now."<<endl;
        cin>>x;
        for(int d = 0;d<181;d++)    					//generate 180 instances delayed by 25 ms each
        {   int *angle_ptr = &d;
            cout<<"At "<<*angle_ptr<<" degrees, the distance is "<<fixed << setprecision(2)<<dist(rd) <<endl;
			usleep(25000);}
        break;
    case 'c':
        cout<<"Display distance measured at 0.5 degree increments every 50ms"<<endl;
        cout<<"Press any key and enter to scan now."<<endl;
        cin>>x;
        while(1){
        for(double d = 0;d<180.5;d+=0.5)  				//generate 360 instances delayed by 50 ms each
        {double *angle_ptr = &d;
            cout<<"At "<<*angle_ptr<<" degrees, the distance is "<<fixed << setprecision(2)<<dist(rd) <<endl;
			usleep(50000);}}
        break;
    case 'd':
        cout<<"Display distance measured at 0.5 degree increments every 25ms"<<endl;
        cout<<"Press any key and enter to scan now."<<endl;
        cin>>x;
        for(double d = 0;d<180.5;d+=0.5) 				//generate 360 instances delayed by 25 ms each.
        {double *angle_ptr = &d;
            cout<<"At "<<*angle_ptr<<" degrees, the distance is "<<fixed << setprecision(2)<<dist(rd) <<endl;
			usleep(25000);}
        break;
    }

}
