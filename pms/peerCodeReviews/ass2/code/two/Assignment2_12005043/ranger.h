#ifndef RANGER_H
#define RANGER_H
#include <string>       //strings
#include <random>       //random number generation
#include <iostream>
#include <vector>       //vectors
#include <math.h>       //math operations
#include <iomanip>
#include <unistd.h>


using namespace std;

class Ranger
{
public:
    Ranger();

    //Getters
    string getSensorType();     //gets sensor type from derived class
    string getModel();          //gets sensor model from derived class
    double getBaud ();          //gets default or set baud from derived class
    double getPort ();          //gets default or set port from derived class
    double getFoV ();           //gets feild of view from derived class
    double getAngularRes ();    //gets angular resolution from derived class
    double getMaxDis ();        //gets maximum distance from derived class
    double getMinDis ();        //gets minimum distance from derived class
    int getSampleSize ();       //gets sample size from derived class

    //Setters
    bool setBaud (double Baud);                 //sets baud according to user input, returns false for invalid input
    bool setPort (double Port);                 //sets port according to user input, returns false for invalid input
    bool setFoV (double FoV);                   //sets field of view according to user input, returns false for invalid input
    double setAngularRes (double AngularRes);   //sets angular resolution according to user input, returns 0 for invalid input
    vector<double> vi1;                         //declaring vector vi1 type to be a vector of doubles

    //RNG
    vector<double> RNG ();      //generates a vector of random numbers,

protected:
    string SensorType_;     //
    string Model_;          //
    double Baud_;           //
    double Port_;           //
    double FoV_;            //
    double MaxDis_;         //
    double MinDis_;         //
    int MultipleReadings_;  //

private:
    static double AngularRes_;  //static variable allows this same variable value to be accessed by all derived classes(used in get sample size function)

};

#endif // RANGER_H
