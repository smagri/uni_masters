#include "rangerfusion.h"
#include "ranger.h"



RangerFusion::RangerFusion()
{
    FusionType_ = 1;
}
void RangerFusion::setRangers(vector<Ranger*> rangers)
{
    sort (rangers.begin(), rangers.end(),[](Ranger*a, Ranger*b){return b->getFieldOfView() < a->getFieldOfView();}      //Rangers vector sorted based on field of view, largest to smallest
    );
    rangers_ = rangers;
}
vector<vector<double>> RangerFusion::getRawRangeData()
{
    RawData_.clear();                                                                                                   //clear vector of vector
    for(vector<Ranger*>::iterator i = rangers_.begin(); i != rangers_.end(); i++){
       vector<double> temp = (*i)->RandomNumberGenerator();

        RawData_.push_back(temp);                                                                                       //push through random number generator
    }
    return RawData_;
}

vector<double> RangerFusion::getFusedRangeData()
{
FusedData_.clear();                                                                                                     //clear vector
vector<int> fuse;                                                                                                       //vector specifies how many times the radar and sonar overlaps the laser readings
for (int o = 0; o <rangers_.size(); o++)
{
    fuse.push_back(1 + 2 * ((rangers_.at(o)->getFieldOfView()/2)/rangers_.at(o)->getAngularResolution()));
}
int a = 0;
int s = 1;
int r = 2;

int fr_ = (fuse.at(0) - fuse.at(r))/2;                                                                                 //subraction of elements in vector
int fs_ = (fuse.at(0) - fuse.at(s))/2;                                                                                 //half the range at a time

double rs_ = (RawData_.at(s)).at(0);                                                                                   //Raw data value at element location
double rr_ = (RawData_.at(r)).at(0);

double e;
for(vector<double>::iterator i = (RawData_.at(0)).begin(); i != (RawData_.at(0)).end(); i++, a++)
{
    e = *i;
    if( (a >= fs_) && (a < fs_ + fuse.at(s)) )                                                                          //if a in between data values for half the range
    {
      switch(FusionType_)
      {
        case 0: e = min((*i), rs_);                                                                                    //take minimum
          break;
        case 1: e = ((*i) + rs_)/2.0;                                                                                  //take average
          break;
        case 2: e = max((*i), rs_);                                                                                    //take maximum
          break;
      }
    }
    if( (a >= fr_) && (a < fr_ + fuse.at(r)) )                                                                          //if a in between data values for other half of range
    {
      switch(FusionType_)
      {
        case 0: e = min(e, rr_);                                                                                       //take minimum
          break;
        case 1: e = (2.0 * e + rr_)/3.0;                                                                               //take average
          break;
        case 2: e = max(e, rr_);                                                                                       //take maximum
          break;
      }
    }
    FusedData_.push_back(e);                                                                                           //push value into vector
  }

  return FusedData_;
}
int RangerFusion::getFusionType() const
{
    return FusionType_;
}

double RangerFusion::setFusionType(double FusionType)
{
    if (FusionType == 0 || FusionType == 1 || FusionType == 2){                                                          //if fusion type entered as 0,1 or 2, store value
    FusionType_ = FusionType;
}
else return 0;
}
