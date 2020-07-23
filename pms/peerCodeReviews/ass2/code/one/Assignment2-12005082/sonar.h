#ifndef SONAR_H
#define SONAR_H
#include "ranger.h"


class Sonar: public Ranger
{
public:
    Sonar();
    double getSampleSize();
};

#endif // SONAR_H
