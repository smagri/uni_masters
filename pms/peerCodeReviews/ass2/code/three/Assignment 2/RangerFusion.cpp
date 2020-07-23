#include "RangerFusion.h"

#include <vector>
#include <iostream>
#include "Ranger.h"

class Laser;
class Sonar;
class Radar;

using namespace std;

RangerFusion::RangerFusion()
{
    //C1 fusion method set on creation
    cout << "Select fusion method: 1. Min 2. Max 3. Average" << endl;
    cin >> functionMethod_;

}

void RangerFusion::setRangers(vector<Ranger*> rangers){
    //clear last set rangers vector
    rangers_.clear();
    //add new rangers data
    rangers.swap(rangers_);
}

vector<double> RangerFusion::getFusedRangeData(){

    data_.clear();

    data_.push_back(rangers_.at(0)->getDist());
    data_.push_back(rangers_.at(1)->getDist());
    data_.push_back(rangers_.at(2)->getDist());

    int count = data_.size();

    //Applying Bubblesort from lowest to highest.
   for(int i = 0; i < (count - 1); i++){
            for(int d = 0; d < count - i - 1; d++){
                if(data_.at(d) > data_.at(d+1)){
                    int swap = data_.at(d);
                    data_.at(d) = data_.at(d+1);
                    data_.at(d+1) = swap;
                }
        }
   }

   //Switch Statement uses functionMethod to select how the data is processed.
    switch(functionMethod_){
    case 1:
    {
        //Min method. Prints the Min Reading
        cout << data_.at(0) << "m (Min Reading)" << endl;
        break;
    }
    case 2:
    {
        //max method. Prints the Max Reading
        cout << data_.at(2) << "m (Max Reading)" << endl;
        break;
    }
    case 3:
    {
        //Creates an average value and prints the answer
        double avg = data_.at(0);
        int count = data_.size();
        cout << avg << endl;
        for(int i = 1; i < (count - 1); i++){
            double avg = (avg + data_.at(i));
        }
        \
        avg = avg/3;

        cout << avg << "m (Average Reading)" << endl;

        break;
    }
    default:
        break;
    }

    return data_;

}

vector<vector<double> > RangerFusion::getRawRangeData(){
    vector<double> dataLaser;
    vector<double> dataSonar;
    vector<double> dataRadar;
    vector<vector<double>> data;

    dataLaser.push_back(rangers_.at(0)->getDist());
    dataSonar.push_back(rangers_.at(0)->getDist());
    dataRadar.push_back(rangers_.at(0)->getDist());

    data.push_back(dataLaser);
    data.push_back(dataSonar);
    data.push_back(dataRadar);

    return data;

}
