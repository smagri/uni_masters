#include "ranger.h"

Ranger::Ranger()
{
    AngularRes_ = 15;
}
//Getters
string Ranger::getSensorType (){    //gets value specified in constructor of derived class
    return SensorType_;
}
string Ranger::getModel (){         //gets value specified in constructor of derived class
    return Model_;
}
double Ranger::getBaud (){         //gets value specified in constructor of derived class
    return Baud_;
}
double Ranger::getPort (){         //gets value specified in constructor of derived class
    return Port_;
}
double Ranger::getFoV (){         //gets value specified in constructor of derived class
    return FoV_;
}
double Ranger::getAngularRes (){  //gets value specified in constructor of derived class
    return AngularRes_;
}
double Ranger::getMaxDis (){      //gets value specified in constructor of derived class
    return MaxDis_;
}
double Ranger::getMinDis (){      //gets value specified in constructor of derived class
    return MinDis_;
}
double Ranger::AngularRes_ = 0;   //initialising a value for the static variable

//Setters
bool Ranger::setBaud (double Baud){         //accepts a double and returns true if conditions are met, false otherwise
    if (Baud == 38400 || Baud == 115200)    //if conditions are met, the value in the constructor of the derived class if changed
        Baud_ = Baud;

}
bool Ranger::setPort (double Port){             //accepts a double and returns true if conditions are met, false otherwise
    if (Port == 0 || Port == 1 || Port == 2)    //if conditions are met, the value in the constructor of the derived class if changed
        Port_ = Port;
}

double Ranger::setAngularRes (double AngularRes){         //accepts a double
    if (AngularRes == 15 || AngularRes == 30){            //if conditions are met, the value in the constructor of the derived class if changed
        AngularRes_ = AngularRes;
    }
    else {
        return 0;                                         //returns 0, which acts as a flag to show that the input is invalid
    }
}

int Ranger::getSampleSize (){
    return (1+2*floor((FoV_/2)/AngularRes_));       //uses the static variable of angular resolution to calculate, depending on the field of view of any sensor, the amount of readings that particular sensor will have in it's field of view
}

//RNG
vector<double> Ranger::RNG (){  //returns a vector of doubles
    int it; //declares type of variable used in for loops below

    random_device Random;                               //generates a random
    default_random_engine generator(Random());          //number with a standard deviation
    normal_distribution<double> distribution(6.0, 5.0); //and mean
    vi1.clear();                            //clears vector that is to be filled below
    int n = getSampleSize();                //calls get sample size function and assigns value to variable n, used to limit the size of vector created for each derived class

    if (MultipleReadings_ == 1){            //checks variable for multiple readings, a value of 1 represents if the sensor can take multiple different readings eg.laser, this value is in the constructor of derived classes
    for (it = 0; it < n; ++it){             //limits number of values put into vector based on variable n which is mentioned above
        double Ds = distribution(generator);//assigns a new random number each time the for loop is iterated

        if ((Ds<=MaxDis_) && (Ds>=MinDis_)){//ifrandom number is between maximum and minimum range of sensor this is the number pushhed back into the vector
            Ds;
        }
        else if(Ds>MaxDis_){                //if random number is bigger than max range of sensor the variable Ds that is pushed back is set to the maximum range of the sensor(this is clipping)
            Ds = MaxDis_;
        }
        else if (Ds<MinDis_){               //if random number is smaller than min range of sensor the variable Ds that is pushed back is set to the minimum range of the sensor(this is clipping)
            Ds = MinDis_;
        }
        vi1.push_back(Ds);                  //each time the for loop iterates a new value is put into the vector that has is within the sensors range or clipped to its max or min range which is determined immediately above
    }
    }
    else if (MultipleReadings_  == 0){      //checks variable for multiple readings, a value of 0 represents if the sensor can take only one different readings eg.sonar and radar, this value is in the constructor of derived classes
        double Ds = distribution(generator);//the following for loop is the same as above with the difference of the random value is assigned to variable Ds outside the for loop so that
        for (it = 0; it < n; ++it){         //a vector is generated pushing back the same random value the amount of times that its field of view overlaps with a sensor that has an angular resolution so that this vector can be fusedwith others within its field of view

            if ((Ds<=MaxDis_) && (Ds>=MinDis_)){
                Ds;
            }
            else if(Ds>MaxDis_){
                Ds = MaxDis_;
            }
            else if (Ds<MinDis_){
                Ds = MinDis_;
            }
            vi1.push_back(Ds);
        }
    }
    return vi1; //returns vector
}
