#ifndef RANGERFUSION_H
#define RANGERFUSION_H
#include "rangerfusioninterface.h"
#include "ranger.h"

class RangerFusion: public RangerFusionInterface
{
public:
    RangerFusion();
    void setRangers(vector<Ranger*> RangerSensors);
    vector<double> getFusedRangeData();
    vector<vector<double> > getRawRangeData();
    string getFusionMethod();
    bool setFusionMethod(string FusionMethod);
    vector<double> vf;


private:
    string FusionMethod_;
    vector<vector<double>> Output;
    vector<Ranger*> RangerSensors_;
    double maxsize_;

};

#endif // RANGERFUSION_H
