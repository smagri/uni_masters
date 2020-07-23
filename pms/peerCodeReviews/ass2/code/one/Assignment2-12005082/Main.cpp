// 12005082
// Tim Zalloua
// Assignment 2 - Programming for Mechatronic Systems

#include "laser.h"
#include "radar.h"
#include "sonar.h"
#include "ranger.h"
#include "rangerfusion.h"
#include "rangerfusioninterface.h"


using namespace std;

int main()
{
//========================================================
//        Objects, Vectors and Declarations
//========================================================

double BaudRate;
double Port;
double AngularResolution;
double FieldOfView;
int FusionType;

Laser L1;
Sonar S1;
Radar R1;
RangerFusion RawFusion;

vector<Ranger*> Sensors;
Sensors.push_back(&L1);
Sensors.push_back(&S1);
Sensors.push_back(&R1);
RawFusion.setRangers(Sensors);

//=======================================================
//          Default Parameters
//=======================================================

cout << "Default Parameters: \n"<< endl;

//============
//  Laser
//============

cout << L1.getSensorType() << "\n" << endl;                                                 //Display default sensor type
cout << "Sensor Model: " << L1.getModel() << endl;                                          //Display defaul sensor Model
cout << "Baud Rate: " << L1.getBaudRate() << endl;                                          //Display default Baud rate
cout << "USB Port: /dev/ttyACM" << L1.getPort() << endl;                                    //Display default USB port
cout << "Field of View: " << L1.getFieldOfView() << " degrees" << endl;                     //Display default FoV
cout << "Maximum Distance: " << L1.getMaxDistance() << "m" << endl;                         //Display Max distance
cout << "Minimum Distance: " << L1.getMinDistance() << "m \n" << endl;                      //Display Min distance

//============
//  Sonar
//============

cout << S1.getSensorType() << "\n" << endl;
cout << "Sensor Model: " << S1.getModel() << endl;
cout << "Baud Rate: " << S1.getBaudRate() << endl;
cout << "USB Port: /dev/ttyACM" << S1.getPort() << endl;
cout << "Field of View: " << S1.getFieldOfView() << " degrees" << endl;
cout << "Maximum Distance: " << S1.getMaxDistance() << "m" << endl;
cout << "Minimum Distance: " << S1.getMinDistance() << "m \n" << endl;

//============
//  Radar
//============

cout << R1.getSensorType() << "\n" << endl;
cout << "Sensor Model: " << R1.getModel() << endl;
cout << "Baud Rate: " << R1.getBaudRate() << endl;
cout << "USB Port: /dev/ttyACM" << R1.getPort() << endl;
cout << "Field of View: " << R1.getFieldOfView() << " degrees" << endl;
cout << "Maximum Distance: " << R1.getMaxDistance() << "m" << endl;
cout << "Minimum Distance: " << R1.getMinDistance() << "m" << endl;

//=======================================================
//          Setting Parameters
//=======================================================

//============
//  Laser
//============

cout << "Set Parameters for " << L1.getSensorType() << ": \n" << endl;
cout << "Set Baud Rate (Enter 38400 or 115200): " << endl;
cin >> BaudRate;                                                                                                //input Baud rate
if (L1.setBaudRate(BaudRate)){
    cout << "Baud Rate set to: " << L1.getBaudRate() << endl;
}
else{
    cout << "Unrecognised Input, Default Baud Rate of " << L1.getBaudRate() << " selected \n" << endl;
}
cout << "Set USB Port (Enter 0, 1 or 2): " << endl;
cin >> Port;                                                                                                    //input USB port
if (L1.setPort(Port)){
    cout << "USB Port set to /dev/ttyACM" << L1.getPort() << endl;
}
else{
    cout << "Unrecognised Input, Default USB port of /dev/ttyACM" << L1.getPort() << " selected \n" << endl;
}
cout << "Set Angular Resolution (Enter 15 or 30): " << endl;
cin >> AngularResolution;                                                                                       //input anglular resolution
if(L1.setAngularResolution(AngularResolution)){
    cout << "Angular Resolution set to: " << L1.getAngularResolution() << " degrees " << endl;
}
else {
    cout << "Unrecognised Input, Default value of " << L1.getAngularResolution() << " degrees selected \n" << endl;
}

//============
//  Radar
//============

cout << "Set Parameters for " << R1.getSensorType() << ": \n" << endl;
cout << "Set Baud Rate (Enter 38400 or 115200): " << endl;
cin >> BaudRate;
if (R1.setBaudRate(BaudRate)){
    cout << "Baud Rate set to: " << R1.getBaudRate() << endl;
}
else{
    cout << "Unrecognised Input, Default Baud Rate of " << R1.getBaudRate() << " selected \n" << endl;
}
cout << "Set USB Port (Enter 0, 1 or 2): " << endl;
cin >> Port;
if (R1.setPort(Port)){
    cout << "USB Port set to /dev/ttyACM" << R1.getPort() << endl;
}
else{
    cout << "Unrecognised Input, Default USB port of /dev/ttyACM" << R1.getPort() << " selected \n" << endl;
}
cout << "Set Field Of View (Enter 20 or 40): " << endl;
cin >> FieldOfView;
if (R1.setFieldOfView(FieldOfView)){
    cout << "Field Of View set to " << R1.getFieldOfView() << " degrees" << endl;
}
else{
    cout << "Unrecognised Input, Default Field Of View of " << R1.getFieldOfView() << " degrees selected \n" << endl;
}


//============
//  Sonar
//============

cout << "Set Parameters for " << S1.getSensorType() << ": \n" << endl;
cout << "Set Baud Rate (Enter 38400 or 115200): " << endl;
cin >> BaudRate;
if (S1.setBaudRate(BaudRate)){
    cout << "Baud Rate set to: " << S1.getBaudRate() << endl;
}
else{
    cout << "Unrecognised Input, Default Baud Rate of " << S1.getBaudRate() << " selected \n" << endl;
}
cout << "Set USB Port (Enter 0, 1 or 2): " << endl;
cin >> Port;
if (S1.setPort(Port)){
    cout << "USB Port set to /dev/ttyACM" << S1.getPort() << endl;
}
else{
    cout << "Unrecognised Input, Default USB port of /dev/ttyACM" << S1.getPort() << " selected \n" << endl;
}

//=======================================================
//          Setting Fusion Type
//=======================================================
//selection of fusion type will alter the type of fusion that is undertaken in the getFusedRangeData function

cout << "Select Fusion Type: " << endl;
cout << "Enter 0: Minimum" << endl;
cout << "Enter 1: Average" << endl;
cout << "Enter 2: Maximum" << endl;
cin >> FusionType;
if (RawFusion.setFusionType(FusionType)){
    cout << "Fusion Type " << RawFusion.getFusionType() << " selected \n" << endl;
}
else{
    cout << "Unrecognised Input, Default Fusion Type of " << RawFusion.getFusionType() << " selected \n" << endl;
}


//=======================================================
//          Print Raw Data
//=======================================================
//Option to print a sample of sensor readings for all 3 sensors

//int increment = 0;
//int sample = 1;
//vector<vector<double>> RawData_ = RawFusion.getRawRangeData();
//cout << "Printing Raw data: \n " << endl;
//usleep(500000);
//for(vector<vector<double>>:: iterator it = RawData_.begin(); it < RawData_.end(); it++){
//    vector<double> t = RawData_[increment];
//    cout<< Sensors.at(increment)->getSensorType() << endl;
//    for(vector<double>:: iterator a = t.begin(); a < t.end(); a++){
//    cout << "Sample " << sample << ": " << (*a) << endl;
//    sample++;}
//    increment++;
//}

//=======================================================
//          Print Fused Data
//=======================================================
//continuously prints fused data with small delay for visibility
int sequence = 1;
cout << "Printing Fused Data: " << endl;
usleep(100000);
while(1){
RawFusion.getRawRangeData();                            //call rawdata function to cycle raw data, without this data values dont regenerate
vector<double> f = RawFusion.getFusedRangeData();
cout << "Sequence Number: " << sequence << endl;
for(auto i = f.begin(); i != f.end(); i++)
{
    cout << fixed << setprecision(2) << *i << endl;
}
sequence++;
cout<<endl;
usleep(200000);                                         //delay loop of sequences to properly view data fusion
}


}


