#ifndef RANGERFUSION_H
#define RANGERFUSION_H
#include <vector>
#include <algorithm>                //for min and max
#include "rangerfusioninterface.h"


class RangerFusion: public RangerFusionInterface
{
public:
    RangerFusion();
//=======================================================
//          Setters
//=======================================================
    void setRangers(vector<Ranger*> rangers);
//=======================================================
//          Getters
//=======================================================
    vector<double> getFusedRangeData();
    vector<vector<double>> getRawRangeData();
    int getFusionType() const;
    double setFusionType(double FusionType);

private:
    int FusionType_;
    vector<vector<double>> RawData_;
    vector<double> FusedData_;
    vector<Ranger*> rangers_;
};

#endif // RANGERFUSION_H
