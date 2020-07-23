// Get minimum value of overlapping FOV's.
// for (int m=0; m<rangers_.size(); m++){
//   rangers_.at(i).rawRangeData();
// }

// fovl = rangers_.at(0).fov;
// fovr = rangers_.at(1).fov;
// fovs = rangers_.at(2).fov;

// // Determine overlapping FOV range.
//
// minFOV = getMinimum(fovl, fovr, fovs);
// overlapMinFOV = 90 - minFOV/2;
// overlapMaxFOV = 90 + minFOV/2;

// foreach ranger_.at(i); should be some loop in i asnd then foreach j
// valueInFOVRange(ranger.at(0).rawRangeData(j));
//
// Where valueInFOVrange tests if  range value between overlapMinFOV
// and  overlapMaxFOV.  If  so flag that this is so.
//
// If value not in FOV range make
// into any min/max/average values???
//
// value1 = valueInFOVrange(ranger.at(1).rawRangeData(j));
// value2 = valueInFOVrange(ranger.at(2).rawRangeData(j));
// value3 = valueInFOVrange(ranger.at(3).rawRangeData(j));

// For value1, value2, value3, where inOverlappingFOVflag = 1
// (ie flag is set). Perform fusion according to that chosen by the
// user(min/max/average).
//
// Use getFusionMethod() return value = string (ie min/max/average);
//
// use c++ functions  to determine the min/max/average of those values.
//


// ***********************************************************************************

// vector<double> readRangerRawData;

// for (int j=0; j<rangers_.size(); j++){
//   rangers_.at(j)->readRanger(readRangerRawData,60,10);

//   // vector copy, save raw ranger data vector of doubles
//   //rawRangeData_.at(j) = readRangerRawData;

//   // itterate the raw data vector backwards.
//   //
//   // However, could use rbegin() and rend() vector methods, it works
//   // accross all containers.
//   //
//   // Containers and itterators, it acts like a pointer.
//   vector<double>::iterator it;
//   vector<double>::iterator itbegin = readRangerRawData.begin();
//   vector<double>::iterator itend = readRangerRawData.end()-1;

//   for(vector<double>::iterator it=itend; it>=itbegin; --it){
//     // pops last element in vector off the list
//     cout<<"dbg: readRangerRawData(" <<  (it-itbegin) << ")=" << *it<<endl;
//     readRangerRawData.pop_back();
//   }
// }
// vector<double> readRangerRawData;

// for (int j=0; j<rangers_.size(); j++){
//   rangers_.at(j)->readRanger(readRangerRawData,60,10);

//   // vector copy, save raw ranger data vector of doubles
//   //rawRangeData_.at(j) = readRangerRawData;

//   // itterate the raw data vector backwards.
//   //
//   // However, could use rbegin() and rend() vector methods, it works
//   // accross all containers.
//   //
//   // Containers and itterators, it acts like a pointer.
//   vector<double>::iterator it;
//   vector<double>::iterator itbegin = readRangerRawData.begin();
//   vector<double>::iterator itend = readRangerRawData.end()-1;

//   for(vector<double>::iterator it=itend; it>=itbegin; --it){
//     // pops last element in vector off the list
//     cout<<"dbg: readRangerRawData(" <<  (it-itbegin) << ")=" << *it<<endl;
//     readRangerRawData.pop_back();
//   }
// }
