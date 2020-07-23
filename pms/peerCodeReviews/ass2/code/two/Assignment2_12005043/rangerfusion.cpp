#include "rangerfusion.h"
#include <iostream>

RangerFusion::RangerFusion()
{
    FusionMethod_ = "Minimum";
    Output = {};
    maxsize_ = 0;
    vf = {};
}
void RangerFusion::setRangers(vector<Ranger*> RangerSensors){   //setter for vector of ranger classes to used to in get fused data function
    RangerSensors_ = RangerSensors;
}


vector<double> RangerFusion::getFusedRangeData(){   //returns a vector of fused data using vectors in any order and of variable size

    vf.clear(); //clears vector when ever function is called

    vector<double> Data0 = RangerSensors_[0]->RNG();        //unloads vector of vector of double into vectors of doubles
    vector<double> Data1 = RangerSensors_[1]->RNG();        //order is not important
    vector<double> Data2 = RangerSensors_[2]->RNG();        //add more or remove if there are more or less sensors

    /*      //individual sensor readings used to check fusion is working
            //this prints the vectors that are going to be fused
            //this is purely for testing and debugging purposes to see if vectors are fused correctly
        cout<< endl;
        vector<double> v = Data0;
        int f =1;
        int g =4;
        int h =7;
        for (auto i = v.begin(); i != v.end(); i++){
            cout << f << ". " << *i << endl;
            f++;
        }
        cout<<endl;
        vector<double> w = Data1;
        for (auto i = w.begin(); i != w.end(); i++){
            cout << g << ". " << *i << endl;
            g++;
        }
        cout<< endl;
        vector<double> x = Data2;
        for (auto i = x.begin(); i != x.end(); i++){
            cout << h << ". " << *i << endl;
            h++;
        }
        cout<< "\nFusion" <<endl;
        */

    double D0 = Data0.size();   //sets a variable to the size of each vector
    double D1 = Data1.size();
    double D2 = Data2.size();
    if (D0>=D1 && D0>=D2){      //determines which vector has the most values
        maxsize_ = D0;          //and sets that value to variable max size
    }
    else if(D1>=D0 && D1>=D2){
        maxsize_ = D1;
    }
    else if (D2>=D0 && D2>=D1){
        maxsize_ = D2;
    }

    int a = 0;  //int a,b and c are used to pull out values from vectors
    int b = 0;
    int c = 0;
    double A = 0;   //doubles A,B and C are used to store the variable from each vector to be used when fusing
    double B = 0;
    double C = 0;
    int D0min = ((maxsize_ - D0)/2);        //Dmins calculate the offset of each veactor with respect to the biggest vector so that the values line up for fusion
    int D0max = (((maxsize_ - D0)/2)+D0);   //Dmaxs calculate the end of the applicable vector so that the vectors are not looking for values after all of its values have been used
    int D1min = ((maxsize_ - D1)/2);
    int D1max = (((maxsize_ - D1)/2)+D1);
    int D2min = ((maxsize_ - D2)/2);
    int D2max = (((maxsize_ - D2)/2)+D2);
    int A_range = 0;    //variables that are used to check if the vector values are overlapping or not, used to determine which vectors need to be fused and when
    int B_range = 0;
    int C_range = 0;
    double average = 0; //initialising variable for averaging calc

    for (int x = 0; x<maxsize_; x++){   //this for loop fills the vector which is limited by the size of the biggest vector input
        if ((x>=D0min) && (x<D0max)){   //checking if each sesnor is in range at that point and assigning a value to A,B and C when conditions are met and incrementing a, b and c to look at the next values in the vectors
            A = Data0.at(a);
            A_range = 1;
            a++;
        }
        if (x>=D0max){  //if the number of loop exceeds the Dmax(offset of vector+ size of vector) set the range variable to say that the vector should not be used to fuse
            A_range = 0;
        }
        if ((x>=D1min) && (x<D1max)){
            B = Data1.at(b);
            B_range = 1;
            b++;
        }
        if (x>=D1max){
            B_range = 0;
        }
        if ((x>=D2min) && (x<D2max)){
            C = Data2.at(c);
            C_range = 1;
            c++;
        }
        if (x>=D2max){
            C_range = 0;
        }
    if (FusionMethod_ == "Minimum"){ //minimum fusion.
        if (A_range == 1 && B_range == 1 && C_range == 1){  //each if statement checks which vectors are overlapping to determine which values need to be compared
            if (A<=B && A<=C){      //now checks the minimum and pushes it back into the vf vector which will be the final fuesed vector
                vf.push_back(A);
            }
            else if (B<=A && B<=C){
                vf.push_back(B);
            }
            else if (C<=A && C<=B){
                vf.push_back(C);
            }
        }
        else if (A_range == 1 && B_range == 1 && C_range == 0){//same as above for a different case
            if (A<=B){
                vf.push_back(A);
            }
            else{
                vf.push_back(B);
            }
        }
        else if (A_range == 1 && C_range == 1 && B_range == 0){//same as above for a different case
            if (A<=C){
                vf.push_back(A);
            }
            else{
                vf.push_back(C);
            }
        }
        else if (B_range == 1 && C_range == 1 && A_range == 0){//same as above for a different case
            if (B<=C){
                vf.push_back(B);
            }
            else{
                vf.push_back(C);
            }
        }
        else if (A_range == 1 && B_range == 0 && C_range == 0){//same as above for a different case
            vf.push_back(A);
        }
        else if (A_range == 0 && B_range == 1 && C_range == 0){//same as above for a different case
            vf.push_back(B);
        }
        else if (A_range == 0 && B_range == 0 && C_range == 1){//same as above for a different case
            vf.push_back(C);
        }
    }
    if (FusionMethod_ == "Maximum"){    //maximum fusion
        if (A_range == 1 && B_range == 1 && C_range == 1){//each if statement checks which vectors are overlapping to determine which values need to be compared
            if (A>=B && A>=C){          //now checks the maximum and pushes it back into the vf vector which will be the final fuesed vector
                vf.push_back(A);
            }
            else if (B>=A && B>=C){
                vf.push_back(B);
            }
            else if (C>=A && C>=B){
                vf.push_back(C);
            }
        }
        else if (A_range == 1 && B_range == 1 && C_range == 0){//same as above for a different case
            if (A>=B){
                vf.push_back(A);
            }
            else{
                vf.push_back(B);
            }
        }
        else if (A_range == 1 && C_range == 1 && B_range == 0){//same as above for a different case
            if (A>=C){
                vf.push_back(A);
            }
            else{
                vf.push_back(C);
            }
        }
        else if (B_range == 1 && C_range == 1 && A_range == 0){//same as above for a different case
            if (B>=C){
                vf.push_back(B);
            }
            else{
                vf.push_back(C);
            }
        }
        else if (A_range == 1 && B_range == 0 && C_range == 0){//same as above for a different case
            vf.push_back(A);
        }
        else if (A_range == 0 && B_range == 1 && C_range == 0){//same as above for a different case
            vf.push_back(B);
        }
        else if (A_range == 0 && B_range == 0 && C_range == 1){//same as above for a different case
            vf.push_back(C);
        }
    }
    if (FusionMethod_ == "Average"){//average fusion
        if (A_range == 1 && B_range == 1 && C_range == 1){//each if statement checks which vectors are overlapping to determine which values need to be compared
            average = (A+B+C)/3;        //calculates the average for this scenario and pushes value back into fused vector
            vf.push_back(average);
        }
        else if (A_range == 1 && B_range == 1 && C_range == 0){//same as above for a different case
            average = (A+B)/2;
            vf.push_back(average);
        }
        else if (A_range == 1 && C_range == 1 && B_range == 0){//same as above for a different case
            average = (A+C)/2;
            vf.push_back(average);
        }
        else if (B_range == 1 && C_range == 1 && A_range == 0){//same as above for a different case
            average = (B+C)/2;
            vf.push_back(average);
        }
        else if (A_range == 1 && B_range == 0 && C_range == 0){//same as above for a different case
            vf.push_back(A);
        }
        else if (A_range == 0 && B_range == 1 && C_range == 0){//same as above for a different case
            vf.push_back(B);
        }
        else if (A_range == 0 && B_range == 0 && C_range == 1){//same as above for a different case
            vf.push_back(C);
        }
    }
    }
    return vf;  //returns fused vector
}

vector<vector<double> > RangerFusion::getRawRangeData(){    //filling a vector of vectors of doubles with vectors of doubles that come from the sensors
    Output.clear(); //clears Output vector each time function is called
    vector<Ranger*>::iterator it;   //iterator for for loop to cycle through the sensors
    for(it = RangerSensors_.begin(); it < RangerSensors_.end(); it++){
        vector<double> temp = (*it)->RNG(); //assigns vector from each sensor to a temporary vector of doubles
        Output.push_back(temp); //temp values put into a vector of vectors of doubles
    }
    return Output;  //returns vector of vectors of doubles
}

string RangerFusion::getFusionMethod (){ //getter for fusion method
    return FusionMethod_;
}

bool RangerFusion::setFusionMethod (string FusionMethod){       //settter for user input choosing the method of fusion
    if (FusionMethod == "Minimum" || FusionMethod == "Maximum" || FusionMethod == "Average"){
        FusionMethod_ = FusionMethod;
    }
}

