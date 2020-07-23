#ifndef RANGERFUSION_H
#define RANGERFUSION_H

#include "RangerFusionInterface.h"
#include <algorithm>
#include <set>

class RangerFusion : public RangerFusionInterface
{
public:
    RangerFusion();

    bool setFusionMethod(int fusionChoice);
    int getFusionMethod();

    void setRangers(vector<Ranger*> rangers);
    std::vector<double> getFusedRangeData();
    std::vector<std::vector<double> > getRawRangeData();

private:
    std::vector<Ranger*> rangers_; // the list of sensors
    std::vector<std::vector<double>> allTheRawData_; // all the sensors' raw data
    std::vector<double> allTheFusedData_;

    // 1. min, 2. max, 3. avg
    int fusionMethod_;


};

#endif // RANGERFUSION_H
