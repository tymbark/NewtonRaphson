#ifndef EQUATION_INTERVAL_H
#define EQUATION_INTERVAL_H
#include <iostream>
#include <QString>
#include <sstream>
#include <fenv.h>
#include <limits.h>
#include <cmath>
#include <IntervalArithmetic.h>

using namespace intervalarth;

class Equation_Interval
{
public:
    Equation_Interval(int id);
    ~Equation_Interval();

    void newtonRaphson();

    interval f  (interval _x);
    interval df (interval _x);
    interval d2f(interval _x);

    interval result;
    interval x;
    interval eps;
    interval fatx;

    int mit;
    int it;
    int st;

    int id;
};


#endif // EQUATION_INTERVAL_H
