#include "laser.h"
#include "radar.h"
#include "sonar.h"
#include "ranger.h"
#include "rangerfusion.h"

int main()
{
    double Baud;            //initialising
    double Port;            //variables
    double AngularRes;      //for
    double FoV;             //user
    string FusionMethod;    //input
    int scannumber = 1;

    Ranger Rngr;            //creating
    Laser L;                //objects
    Sonar S;                //for
    Radar R;                //each
    RangerFusion RF;        //class

    vector<Ranger*> RangerSensors;    //pushing objects into vector
    RangerSensors.push_back(&L);
    RangerSensors.push_back(&S);
    RangerSensors.push_back(&R);
    RF.setRangers(RangerSensors);

    cout << "Hello World!" << endl;
    cout << "Default Parameters are:\n";
//
    cout << L.getSensorType() << " Sensor Model: " << L.getModel() << endl;
    cout << "Baud: " << L.getBaud() << endl;
    cout << "Port: /dev/ttyACM" << L.getPort() << endl;
    cout << "Field of View: " << L.getFoV() << " degrees" << endl;
    cout << "Angular Resolution: " << L.getAngularRes() << " degrees" << endl;
    cout << "Sensor Range between " << L.getMinDis() << "m and " << L.getMaxDis() << "m\n" <<endl;
//
    cout << S.getSensorType() << " Sensor Model: " << S.getModel() << endl;
    cout << "Baud: " << S.getBaud() << endl;
    cout << "Port: /dev/ttyACM" << S.getPort() << endl;
    cout << "Field of View: " << S.getFoV() << " degrees" << endl;
    cout << "Sensor Range between " << S.getMinDis() << "m and " << S.getMaxDis() << "m\n" <<endl;
//
    cout << R.getSensorType() << " Sensor Model: " << R.getModel() << endl;
    cout << "Baud: " << R.getBaud() << endl;
    cout << "Port: /dev/ttyACM" << R.getPort() << endl;
    cout << "Field of View: " << R.getFoV() << " degrees" << endl;
    cout << "Sensor Range between " << R.getMinDis() << "m and " << R.getMaxDis() << "m\n" <<endl;
//
    cout << "Setting Parameters for " << L.getSensorType() << " Sensor:\n";
    cout << "Set Baud (38400 or 115200): ";
    cin >> Baud;
    if (L.setBaud(Baud)){
        cout << "Baud set to: " << L.getBaud() << endl;
    }
    else {
        cout << "Input Error, Using Default Baud: " << L.getBaud() << endl;
    }
    cout << "Set Port (0, 1 or 2): /dev/ttyACM";
    cin >> Port;
    if (L.setPort(Port)){
        cout << "Port set to: /dev/ttyACM" << L.getPort() << endl;
    }
    else {
        cout << "Input Error, Using Default Port: /dev/ttyACM" << L.getPort() << endl;
    }
    cout << "Set Angular Resolution (15 or 30): ";
    cin >> AngularRes;
    if(L.setAngularRes(AngularRes) == 0){
        cout << "Input Error, Using Default Angular Resolution: " << L.getAngularRes() << " degrees\n" << endl;
    }
    else{
        cout << "Angular Resolution set to: " << L.getAngularRes() << " degrees\n" << endl;
    }
//
    cout << "Setting Parameters for " << S.getSensorType() << " Sensor:\n";
    cout << "Set Baud (38400 or 115200): ";
    cin >> Baud;
    if (S.setBaud(Baud)){
        cout << "Baud set to: " << S.getBaud() << endl;
    }
    else {
        cout << "Input Error, Using Default Baud: " << S.getBaud() << endl;
    }
    cout << "Set Port (0, 1 or 2): /dev/ttyACM";
    cin >> Port;
    if (S.setPort(Port)){
        cout << "Port set to: /dev/ttyACM" << S.getPort() << endl << endl;
    }
    else {
        cout << "Input Error, Using Default Port: /dev/ttyACM" << S.getPort() << endl << endl;
    }
//
    cout << "Setting Parameters for " << R.getSensorType() << " Sensor:\n";
    cout << "Set Baud (38400 or 115200): ";
    cin >> Baud;
    if (R.setBaud(Baud)){
        cout << "Baud set to: " << R.getBaud() << endl;
    }
    else {
        cout << "Input Error, Using Default Baud: " << R.getBaud() << endl;
    }
    cout << "Set Port (0, 1 or 2): /dev/ttyACM";
    cin >> Port;
    if (R.setPort(Port)){
        cout << "Port set to: /dev/ttyACM" << R.getPort() << endl;
    }
    else {
        cout << "Input Error, Using Default Port: /dev/ttyACM" << R.getPort() << endl;
    }
    cout << "Set FoV (20 or 40 degrees): ";
    cin >> FoV;
    if (R.setFoV(FoV)){
        cout << "FoV set to: " << R.getFoV() << " degrees" << endl << endl;
    }
    else {
        cout << "Input Error, Using Default FoV: " << R.getFoV() << " degrees\n" << endl;
    }
//
    cout << "Chose a Fusion Method ('Minimum', 'Maximum' or 'Average'): ";
    cin >> FusionMethod;
    if (RF.setFusionMethod(FusionMethod)){
        cout << "Fusion Method set to: " << RF.getFusionMethod() << endl << endl;
    }
    else {
        cout << "Input Error, Using Default Fusion Method: " << RF.getFusionMethod() << endl << endl;
    }
//
    while (1){      //forever printing fused vectors
    double degree = 0;  //angle of sensor reading for console display
    vector<double> y = RF.getFusedRangeData();          //assign fused vector to a vector of doubles
    cout << "\nScan Number: " << scannumber << endl;
    scannumber ++;  //counts the number of scans
    for (auto i = y.begin(); i != y.end(); i++){      //for loop to print each value of fused vector
    cout << "At " << degree << " degrees, Fused reading: " << fixed << setprecision(2) << *i << "m\n";      //prints each value in vector with corresponding angle and vector value to 2 decimal places
    degree += L.getAngularRes(); //angle increased by angular resolutions
        }
    usleep(1000);       //1ms delay for some timing
    }
    return 0;
}

