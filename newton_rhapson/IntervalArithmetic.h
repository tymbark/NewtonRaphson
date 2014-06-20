/*
 * IntervalArithmetic.h
 *
 *  Created on: 20-11-2012
 *      Author: Tomasz Hoffmann and Andrzej Marciniak
 *
 *  Before you start use module, please install libraries:
 *      - .boost ( http://www.boost.org/ )
 *      - GNU MPFR ( http://www.mpfr.org/ )
 */

#ifndef INTERVALARITHMETIC_H_
#define INTERVALARITHMETIC_H_
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <fenv.h>
#include <stdlib.h>
#include <stdint.h>
#include <cmath>
#include <mpfr.h>
#include <boost/lexical_cast.hpp>

#include <iomanip>
#include <fstream>
#include <float.h>


using namespace std;

namespace intervalarth
{

    class interval
    {
    public:
            long double a, b;

            interval();
            interval(const long double &x, const long double &y);

            interval operator +(const interval& x);
            interval operator -(const interval& x);
            interval operator *(const interval& x);
            interval operator ^(const int &x);
            interval operator /(const interval& x);
            bool operator >(const interval& x);
            bool operator <(const interval& x);
            bool operator ==(const interval& x);
            bool operator !=(const interval &x);
            bool operator >=(const interval& x);
            bool operator <=(const interval& x);
    };


    //set precision
    const int curr_precision = 80;

    // store the original rounding mode
    const int originalRounding = fegetround();
    const char DecimalSeparator = '.';

    const int DMODE = 1;
    const int PMODE = 2;

    class IntervalArithmetic
    {
    private:
            static int mode;
    public:
            IntervalArithmetic();
            virtual ~IntervalArithmetic();
            static long double IntWidth(const interval& x);
            static interval IAdd(const interval& x, const interval& y);
            static interval ISub(const interval& x, const interval& y);
            static interval IMul(const interval& x, const interval& y);
            static interval IDiv(const interval& x, const interval& y);
            static long double DIntWidth(const interval& x);
            static interval Abs(const interval& x);
            static interval Projection(const interval& x);
            static interval Opposite(const interval& x);
            static interval Inverse(const interval& x);
            static interval DIAdd(const interval& x, const interval& y);
            static interval DISub(const interval& x, const interval& y);
            static interval DIMul(const interval& x, const interval& y);
            static interval DIDiv(const interval& x, const interval& y);
            static interval IntRead(const string& sa);
            static long double LeftRead(const string& sa);
            static long double RightRead(const string& sa);
            static interval ISin(const interval& x, int& st);
            static interval ICos(const interval& x, int& st);
            static interval IExp(const interval& x, int& st);
            static interval ISqr(const interval& x, int& st);
            static interval DISin(const interval& x, int& st);
            static interval DICos(const interval& x, int& st);
            static interval DIExp(const interval& x, int& st);
            static interval DISqr(const interval& x, int& st);
            static interval ISqr2();
            static interval ISqr3();
            static interval IPi();
            static void IEndsToStrings(const interval& i, string& left, string& right);
            static void SetArthMode(int m);
            static int GetArthMode();
    };

} /* namespace interval */
#endif /* INTERVALARITHMETIC_H_ */
