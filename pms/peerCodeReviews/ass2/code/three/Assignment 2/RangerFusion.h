#ifndef RANGERFUSION_H
#define RANGERFUSION_H
#include "RangerFusionInterface.h"

#include <vector>

class Ranger;

class RangerFusion : public RangerFusionInterface
{
public:
    RangerFusion();
    vector<double> getFusedRangeData();
    void setRangers(vector<Ranger*> rangers);
    vector<vector<double> > getRawRangeData();
private:
    int functionMethod_;
    vector<Ranger*> rangers_;
    vector<double> data_;
};

#endif // RANGERFUSION_H
