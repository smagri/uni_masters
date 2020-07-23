#include "rangerfusion.h"
#include "ranger.h"
#include <iostream>

RangerFusionInterface:: RangerFusionInterface()
{
}

RangerFusion::RangerFusion()
{
    fusionMethod_ = 1;
}

bool RangerFusion::setFusionMethod(int fusionChoice)
{
    switch (fusionChoice)
    {
        case 1: // min
            fusionMethod_ = fusionChoice;
            return true;

        case 2: // max
            fusionMethod_ = fusionChoice;
            return true;

        case 3: // avg
            fusionMethod_ = fusionChoice;
            return true;

        default:
            return false;
    }
}

int RangerFusion::getFusionMethod()
{
    return fusionMethod_;
}

void RangerFusion::setRangers(vector<Ranger*> rangers)
{
    rangers_ = rangers;
}

std::vector<double> RangerFusion::getFusedRangeData()
{
    std::vector<int> fovArray(rangers_.size()); // contains a list of the FOV of current sensors
    std::vector<int> leftLimits(rangers_.size()); // list of left boundary angles
    std::vector<int> rightLimits(rangers_.size()); // list of right boundary angles
    std::vector<int> angles; // list of angles of the largest FOV
    std::vector<double> tempData; // temp data for processing

    // run through every sensor, pull the FOV, check if that FOV is inside another FOV

    for (int i=0; i< rangers_.size(); i++)
    {
        fovArray.at(i) = rangers_.at(i)->getFieldOfView();
        leftLimits.at(i) = 90 - fovArray.at(i)/2;
        rightLimits.at(i) = 90 + fovArray.at(i)/2;
    }

    // find the max fov and set that as the number of samples of allTheFusedData
    auto maxIT = std::max_element(fovArray.begin(), fovArray.end());
    int idx = std::distance(fovArray.begin(), maxIT);
    // idx is the index of the sensor with the biggest FOV

    // make the vectors the right size for all the data
    int maxNumberOfSamples = rangers_.at(idx)->getNumberOfSamples();
    angles.resize(maxNumberOfSamples);
    tempData.resize(maxNumberOfSamples);
    allTheFusedData_.resize(maxNumberOfSamples);

    // fill up angles with the all the angles of largest FOV
    for(int j=0; j<maxNumberOfSamples; j++)
    {
        if (maxNumberOfSamples!=1)
        {
            tempData.at(j) = allTheRawData_[idx][j];
            angles.at(j) = fovArray.at(idx)/(maxNumberOfSamples-1)*j;
        }
        else
        {
            tempData.at(j) = allTheRawData_[idx][j];
            angles.at(j) = 90;
        }
    }

    for (int k = 0; k < allTheRawData_.size(); k++) // run through each sensor
    {
        if (k == idx) // skip sensor if same
        {
            continue;
        }
        // run through each sensor data, check angles

        for (int a=0; a < angles.size(); a++)
        {
            if (angles.at(a) >= leftLimits.at(k) && angles.at(a) <= rightLimits.at(k)) // check if inside boundary
            {
                auto result = std::minmax({allTheRawData_[k][0],tempData[a]}); // check for min/max

                if (fusionMethod_ == 1) // min
                {
                    tempData.at(a) = result.first;
                }
                if (fusionMethod_ == 2) // max
                {
                    tempData.at(a) = result.second;
                }

                if (fusionMethod_ == 3) // avg
                {
                    // HOW DO I DO THIS AAAAAHHHH
                    double number = (tempData[a] + allTheRawData_[k][0]) / 2 ; // probably the wrong average

                    tempData.at(a) = number;
                }
            }
        }
    }
    allTheFusedData_ = tempData;

    return allTheFusedData_;
}

vector<vector<double> > RangerFusion::getRawRangeData()
{
    vector<vector<double>> lotsOfRaw;
    vector<double> rawSensorData;
    int numberOfSensors = rangers_.size();

    for (int i = 0; i < numberOfSensors; i++)
    {
        rawSensorData = rangers_.at(i)->getData(); // gets data from each sensor
        lotsOfRaw.push_back(rawSensorData); // pushes the data from the sensor into the list of sensor datas
    }

    allTheRawData_ = lotsOfRaw;

    return allTheRawData_;
}
