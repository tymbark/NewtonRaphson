#ifndef EQUATION_H
#define EQUATION_H
#include <iostream>
#include <QString>
#include <sstream>
#include <fenv.h>
#include <limits.h>
#include <cmath>
//#include <IntervalArithmetic.h>

using namespace std;

class Equation
{
public:
    Equation(int id);
    ~Equation();

    void newtonRaphson();

    long double f  (long double _x);
    long double df (long double _x);
    long double d2f(long double _x);

    long double result;
    long double x;
    long double eps;
    long double fatx;

    int mit;
    int it;
    int st;

    int id;
};

#endif // EQUATION_H
