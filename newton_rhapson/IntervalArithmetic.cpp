/*
 * IntervalArithmetic.cpp
 *
 *  Created on: 20-11-2012
 *      Author: Tomasz Hoffmann and Andrzej Marciniak
 */

#include "IntervalArithmetic.h"
#include <iostream>

namespace intervalarth
{

int intervalarth::IntervalArithmetic::mode;

IntervalArithmetic::IntervalArithmetic()
{
        // TODO Auto-generated constructor stub
}

IntervalArithmetic::~IntervalArithmetic()
{
        // TODO Auto-generated destructor stub
}

long double IntervalArithmetic::IntWidth(const interval& x)
{
        fesetround(FE_UPWARD);
        long double w = x.b - x.a;
        fesetround(FE_TONEAREST);
        return w;
}

interval IntervalArithmetic::IAdd(const interval& x, const interval& y)
{
        interval r;
        fesetround(FE_DOWNWARD);
        r.a = x.a + y.a;
        fesetround(FE_UPWARD);
        r.b = x.b + y.b;
        fesetround(FE_TONEAREST);
        return r;
}

interval IntervalArithmetic::ISub(const interval& x, const interval& y)
{
        interval r;
        fesetround(FE_DOWNWARD);
        r.a = x.a - y.b;
        fesetround(FE_UPWARD);
        r.b = x.b - y.a;
        fesetround(FE_TONEAREST);
        return r;
}

interval IntervalArithmetic::IMul(const interval& x, const interval& y)
{
        interval r;
        long double x1y1, x1y2, x2y1;

        fesetround(FE_DOWNWARD);
        x1y1 = x.a * y.a;
        x1y2 = x.a * y.b;
        x2y1 = x.b * y.a;
        r.a = x.b * y.b;
        if (x2y1 < r.a)
                r.a = x2y1;
        if (x1y2 < r.a)
                r.a = x1y2;
        if (x1y1 < r.a)
                r.a = x1y1;

        fesetround(FE_UPWARD);
        x1y1 = x.a * y.a;
        x1y2 = x.a * y.b;
        x2y1 = x.b * y.a;

        r.b = x.b * y.b;
        if (x2y1 > r.b)
                r.b = x2y1;
        if (x1y2 > r.b)
                r.b = x1y2;
        if (x1y1 > r.b)
                r.b = x1y1;
        fesetround(FE_TONEAREST);
        return r;
}

interval IntervalArithmetic::IDiv(const interval& x, const interval& y)
{
        interval r;
        long double x1y1, x1y2, x2y1, t;

        if ((y.a <= 0) && (y.b >= 0))
        {
                throw runtime_error("Division by an interval containing 0.");
        }
        else
        {
                fesetround(FE_DOWNWARD);
                x1y1 = x.a / y.a;
                x1y2 = x.a / y.b;
                x2y1 = x.b / y.a;
                r.a = x.b / y.b;
                t = r.a;
                if (x2y1 < t)
                        r.a = x2y1;
                if (x1y2 < t)
                        r.a = x1y2;
                if (x1y1 < t)
                        r.a = x1y1;

                fesetround(FE_UPWARD);
                x1y1 = x.a / y.a;
                x1y2 = x.a / y.b;
                x2y1 = x.b / y.a;

                r.b = x.b / y.b;
                t = r.b;
                if (x2y1 > t)
                        r.b = x2y1;
                if (x1y2 > t)
                        r.b = x1y2;
                if (x1y1 > t)
                        r.b = x1y1;

        }
        fesetround(FE_TONEAREST);
        return r;
}

long double IntervalArithmetic::DIntWidth(const interval& x)
{
        long double w1, w2;

        fesetround(FE_UPWARD);
        w1 = x.b - x.a;
        if (w1 < 0)
                w1 = -w1;
        fesetround(FE_DOWNWARD);
        w2 = x.b - x.a;
        if (w2 < 0)
                w2 = -w2;
        fesetround(FE_TONEAREST);
        if (w1 > w2)
                return w1;
        else
                return w2;
}

interval IntervalArithmetic::Abs(const interval& x)
{
    interval r;

    if(x.a < 0 && x.b >= 0)
    {
        r.a = 0;
        r.b = x.b;
    }
    else if(x.a >= 0 && x.b >= 0)
    {
        return x;
    }
    else if(x.a < 0 && x.b < 0)
    {
        r.a = std::abs(x.b);
        r.b = std::abs(x.a);
    }

    return r;
}

interval IntervalArithmetic::Projection(const interval& x)
{
        interval r;
        r = x;
        if (x.a > x.b)
        {
                r.a = x.b;
                r.b = x.a;
        }
        return r;
}

interval IntervalArithmetic::Opposite(const interval& x)
{
        interval r;
        r.a = -x.a;
        r.b = -x.b;
        return r;
}

interval IntervalArithmetic::Inverse(const interval& x)
{
        interval z1, z2;

        fesetround(FE_DOWNWARD);
        z1.a = 1 / x.a;
        z2.b = 1 / x.b;
        fesetround(FE_UPWARD);
        z1.b = 1 / x.b;
        z2.a = 1 / x.a;
        fesetround(FE_TONEAREST);
        if (DIntWidth(z1) >= DIntWidth(z2))
                return z1;
        else
                return z2;
}

interval IntervalArithmetic::DIAdd(const interval& x, const interval& y)
{
        interval z1, z2;
        if ((x.a <= x.b) && (y.a <= y.b))
        {
                return IAdd(x, y);
        }
        else
        {
                fesetround(FE_DOWNWARD);
                z1.a = x.a + y.a;
                z2.b = x.b + y.b;
                fesetround(FE_UPWARD);
                z1.b = x.b + y.b;
                z2.a = x.a + y.a;
                fesetround(FE_TONEAREST);
                if (DIntWidth(z1) >= DIntWidth(z2))
                        return z1;
                else
                        return z2;
        }
}

interval IntervalArithmetic::DISub(const interval& x, const interval& y)
{
        interval z1, z2;
        if ((x.a <= x.b) && (y.a <= y.b))
        {
                return ISub(x, y);
        }
        else
        {
                fesetround(FE_DOWNWARD);
                z1.a = x.a - y.b;
                z2.b = x.b - y.a;
                fesetround(FE_UPWARD);
                z1.b = x.b - y.a;
                z2.a = x.a - y.b;
                fesetround(FE_TONEAREST);
                if (DIntWidth(z1) >= DIntWidth(z2))
                        return z1;
                else
                        return z2;
        }
}

interval IntervalArithmetic::DIMul(const interval& x, const interval& y)
{
        interval z1, z2, r;
        long double z;
        bool xn, xp, yn, yp, zero;

        if ((x.a <= x.b) && (y.a <= y.b))
                r = IMul(x, y);
        else
        {
                xn = (x.a < 0) and (x.b < 0);
                xp = (x.a > 0) and (x.b > 0);
                yn = (y.a < 0) and (y.b < 0);
                yp = (y.a > 0) and (y.b > 0);
                zero = false;
                // A, B in H-T
                if ((xn || xp) && (yn || yp))
                        if (xp && yp)
                        {
                                fesetround(FE_DOWNWARD);
                                z1.a = x.a * y.a;
                                z2.b = x.b * y.b;
                                fesetround(FE_UPWARD);
                                z1.b = x.b * y.b;
                                z2.a = x.a * y.a;
                        }
                        else if (xp && yn)
                        {
                                fesetround(FE_DOWNWARD);
                                z1.a = x.b * y.a;
                                z2.b = x.a * y.b;
                                fesetround(FE_UPWARD);
                                z1.b = x.a * y.b;
                                z2.a = x.b * y.a;
                        }
                        else if (xn && yp)
                        {
                                fesetround(FE_DOWNWARD);
                                z1.a = x.a * y.b;
                                z2.b = x.b * y.a;
                                fesetround(FE_UPWARD);
                                z1.b = x.b * y.a;
                                z2.a = x.a * y.b;
                        }
                        else
                        {
                                fesetround(FE_DOWNWARD);
                                z1.a = x.b * y.b;
                                z2.b = x.a * y.a;
                                fesetround(FE_UPWARD);
                                z1.b = x.a * y.a;
                                z2.a = x.b * y.b;
                        }
                // A in H-T, B in T
                else if ((xn || xp)
                                && (((y.a <= 0) && (y.b >= 0)) || ((y.a >= 0) && (y.b <= 0))))
                        if (xp && (y.a <= y.b))
                        {
                                fesetround(FE_DOWNWARD);
                                z1.a = x.b * y.a;
                                z2.b = x.b * y.b;
                                fesetround(FE_UPWARD);
                                z1.b = x.b * y.b;
                                z2.a = x.b * y.a;
                        }
                        else if (xp && (y.a > y.b))
                        {
                                fesetround(FE_DOWNWARD);
                                z1.a = x.a * y.a;
                                z2.b = x.a * y.b;
                                fesetround(FE_UPWARD);
                                z1.b = x.a * y.b;
                                z2.a = x.a * y.a;
                        }
                        else if (xn && (y.a <= y.b))
                        {
                                fesetround(FE_DOWNWARD);
                                z1.a = x.a * y.b;
                                z2.b = x.a * y.a;
                                fesetround(FE_UPWARD);
                                z1.b = x.a * y.a;
                                z2.a = x.a * y.b;
                        }
                        else
                        {
                                fesetround(FE_DOWNWARD);
                                z1.a = x.b * y.b;
                                z2.b = x.b * y.a;
                                fesetround(FE_UPWARD);
                                z1.b = x.b * y.a;
                                z2.a = x.b * y.b;
                        }
                // A in T, B in H-T
                else if ((((x.a <= 0) && (x.b >= 0)) || ((x.a >= 0) && (x.b <= 0)))
                                && (yn || yp))
                        if ((x.a <= x.b) && yp)
                        {
                                fesetround(FE_DOWNWARD);
                                z1.a = x.a * y.b;
                                z2.b = x.b * y.b;
                                fesetround(FE_UPWARD);
                                z1.b = x.b * y.b;
                                z2.a = x.a * y.b;
                        }
                        else if ((x.a <= 0) && yn)
                        {
                                fesetround(FE_DOWNWARD);
                                z1.a = x.b * y.a;
                                z2.b = x.a * y.a;
                                fesetround(FE_UPWARD);
                                z1.b = x.a * y.a;
                                z2.a = x.b * y.a;
                        }
                        else if ((x.a > x.b) && yp)
                        {
                                fesetround(FE_DOWNWARD);
                                z1.a = x.a * y.a;
                                z2.b = x.b * y.a;
                                fesetround(FE_UPWARD);
                                z1.b = x.b * y.a;
                                z2.a = x.a * y.a;
                        }
                        else
                        {
                                fesetround(FE_DOWNWARD);
                                z1.a = x.b * y.b;
                                z2.b = x.a * y.b;
                                fesetround(FE_UPWARD);
                                z1.b = x.a * y.b;
                                z2.a = x.b * y.b;
                        }
                // A, B in Z-
                else if ((x.a >= 0) && (x.b <= 0) && (y.a >= 0) && (y.b <= 0))
                {
                        fesetround(FE_DOWNWARD);
                        z1.a = x.a * y.a;
                        z = x.b * y.b;
                        if (z1.a < z)
                                z1.a = z;
                        z2.b = x.a * y.b;
                        z = x.b * y.a;
                        if (z < z2.b)
                                z2.b = z;
                        fesetround(FE_UPWARD);
                        z1.b = x.a * y.b;
                        z = x.b * y.a;
                        if (z < z1.b)
                                z1.b = z;
                        z2.a = x.a * y.a;
                        z = x.b * y.b;
                        if (z2.a < z)
                                z2.a = z;
                }
                // A in Z and B in Z- or A in Z- and B in Z
                else
                        zero = true;
                if (zero)
                {
                        r.a = 0;
                        r.b = 0;
                }
                else if (DIntWidth(z1) >= DIntWidth(z2))
                        r = z1;
                else
                        r = z2;
        }

        fesetround(FE_TONEAREST);
        return r;
}

interval IntervalArithmetic::DIDiv(const interval& x, const interval& y)
{

        interval z1, z2, r;
        bool xn, xp, yn, yp, zero;

        if ((x.a <= x.b) && (y.a <= y.b))
                r = IDiv(x, y);
        else
        {
                xn = (x.a < 0) && (x.b < 0);
                xp = (x.a > 0) && (x.b > 0);
                yn = (y.a < 0) && (y.b < 0);
                yp = (y.a > 0) && (y.b > 0);
                zero = false;
                // A, B in H-T
                if ((xn || xp) && (yn || yp))
                        if (xp && yp)
                        {
                                fesetround(FE_DOWNWARD);
                                z1.a = x.a / y.b;
                                z2.b = x.b / y.a;
                                fesetround(FE_UPWARD);
                                z1.b = x.b / y.a;
                                z2.a = x.a / y.b;
                        }
                        else if (xp && yn)
                        {
                                fesetround(FE_DOWNWARD);
                                z1.a = x.b / y.b;
                                z2.b = x.a / y.a;
                                fesetround(FE_UPWARD);
                                z1.b = x.a / y.a;
                                z2.a = x.b / y.b;
                        }
                        else if (xn && yp)
                        {
                                fesetround(FE_DOWNWARD);
                                z1.a = x.a / y.a;
                                z2.b = x.b / y.b;
                                fesetround(FE_UPWARD);
                                z1.b = x.b / y.b;
                                z2.a = x.a / y.a;
                        }
                        else
                        {
                                fesetround(FE_DOWNWARD);
                                z1.a = x.b / y.a;
                                z2.b = x.a / y.b;
                                fesetround(FE_UPWARD);
                                z1.b = x.a / y.b;
                                z2.a = x.b / y.a;
                        }
                // A in T, B in H-T
                else if (((x.a <= 0) && (x.b >= 0))
                                || (((x.a >= 0) && (x.b <= 0)) && (yn || yp)))
                        if ((x.a <= x.b) && yp)
                        {
                                fesetround(FE_DOWNWARD);
                                z1.a = x.a / y.a;
                                z2.b = x.b / y.a;
                                fesetround(FE_UPWARD);
                                z1.b = x.b / y.a;
                                z2.a = x.a / y.a;
                        }
                        else if ((x.a <= x.b) && yn)
                        {
                                fesetround(FE_DOWNWARD);
                                z1.a = x.b / y.b;
                                z2.b = x.a / y.b;
                                fesetround(FE_UPWARD);
                                z1.b = x.a / y.b;
                                z2.a = x.b / y.b;
                        }
                        else if ((x.a > x.b) && yp)
                        {
                                fesetround(FE_DOWNWARD);
                                z1.a = x.a / y.b;
                                z2.b = x.b / y.b;
                                fesetround(FE_UPWARD);
                                z1.b = x.b / y.b;
                                z2.a = x.a / y.b;
                        }
                        else
                        {
                                fesetround(FE_DOWNWARD);
                                z1.a = x.b / y.a;
                                z2.b = x.a / y.a;
                                fesetround(FE_UPWARD);
                                z1.b = x.a / y.a;
                                z2.a = x.b / y.a;
                        }
                else
                        zero = true;
                if (zero)
                        throw runtime_error("Division by an interval containing 0.");
                else if (DIntWidth(z1) >= DIntWidth(z2))
                        r = z1;
                else
                        r = z2;
                fesetround(FE_TONEAREST);
        }
        return r;
}

interval IntervalArithmetic::IntRead(const string & sa)
{
        interval r;
        mpfr_t rop;
        mpfr_init2(rop, 80);
        //mpfr_
        mpfr_set_str(rop, sa.c_str(), 10, MPFR_RNDD);

        long double le = mpfr_get_ld(rop, MPFR_RNDD);
        mpfr_set_str(rop, sa.c_str(), 10, MPFR_RNDU);
        long double re = mpfr_get_ld(rop, MPFR_RNDU);
        fesetround(FE_TONEAREST);

        r.a = le;
        r.b = re;
        return r;
}

long double IntervalArithmetic::LeftRead(const string & sa)
{
        interval int_number;
        int_number = IntRead(sa);
        return int_number.a;
}

long double IntervalArithmetic::RightRead(const string & sa)
{
        interval int_number;
        int_number = IntRead(sa);
        return int_number.b;
}

interval IntervalArithmetic::ISin(const interval& x, int & st)
{
        bool is_even, finished;
        int k;
        interval d, s, w, w1, x2;
        if (x.a > x.b)
                st = 1;
        else
        {
                s = x;
                w = x;
                x2 = IMul(x, x);
                k = 1;
                is_even = true;
                finished = false;
                st = 0;

                do
                {
                        d.a = (k + 1) * (k + 2);
                        d.b = d.a;
                        s = IMul(s, IDiv(x2, d));
                        if (is_even)
                                w1 = ISub(w, s);
                        else
                                w1 = IAdd(w, s);
                        if ((w.a != 0) && (w.b != 0))
                                if ((abs(w.a - w1.a) / abs(w.a) < 1e-18)
                                                && (abs(w.b - w1.b) / abs(w.b) < 1e-18))
                                        finished = true;
                                else
                                        ;
                        else if ((w.a == 0) && (w.b != 0))
                                if ((abs(w.a - w1.a) < 1e-18)
                                                && (abs(w.b - w1.b) / abs(w.b) < 1e-18))
                                        finished = true;
                                else
                                        ;

                        else if (w.a != 0)
                                if ((abs(w.a - w1.a) / abs(w.a) < 1e-18)
                                                & (abs(w.b - w1.b) < 1e-18))
                                        finished = true;
                                else if ((abs(w.a - w1.a) < 1e-18) & (abs(w.b - w1.b) < 1e-18))
                                        finished = true;

                        if (finished)
                        {
                                if (w1.b > 1)
                                {
                                        w1.b = 1;
                                        if (w1.a > 1)
                                                w1.a = 1;
                                }
                                if (w1.a < -1)
                                {
                                        w1.a = -1;
                                        if (w1.b < -1)
                                                w1.b = -1;
                                }
                                return w1;
                        }
                        else
                        {
                                w = w1;
                                k = k + 2;
                                is_even = !is_even;
                        }
                } while (!(finished || (k > INT_MAX / 2)));
        }
        if (!finished)
                st = 2;

        interval r;
        r.a = 0;
        r.b = 0;
        return r;
}
interval IntervalArithmetic::ICos(const interval& x, int & st)
{
        bool is_even, finished;
        int k;
        interval d, c, w, w1, x2;
        if (x.a > x.b)
                st = 1;
        else
        {
                c.a = 1;
                c.b = 1;
                w = c;
                x2 = IMul(x, x);
                k = 1;
                is_even = true;
                finished = false;
                st = 0;

                do
                {
                        d.a = k * (k + 1);
                        d.b = d.a;
                        c = IMul(c, IDiv(x2, d));
                        if (is_even)
                                w1 = ISub(w, c);
                        else
                                w1 = IAdd(w, c);

                        if ((w.a != 0) && (w.b != 0))
                                if ((abs(w.a - w1.a) / abs(w.a) < 1e-18)
                                                && (abs(w.b - w1.b) / abs(w.b) < 1e-18))
                                        finished = true;
                                else
                                        ;
                        else if ((w.a == 0) && (w.b != 0))
                                if ((abs(w.a - w1.a) < 1e-18)
                                                && (abs(w.b - w1.b) / abs(w.b) < 1e-18))
                                        finished = true;
                                else
                                        ;

                        else if (w.a != 0)
                                if ((abs(w.a - w1.a) / abs(w.a) < 1e-18)
                                                & (abs(w.b - w1.b) < 1e-18))
                                        finished = true;
                                else if ((abs(w.a - w1.a) < 1e-18) & (abs(w.b - w1.b) < 1e-18))
                                        finished = true;

                        if (finished)
                        {
                                if (w1.b > 1)
                                {
                                        w1.b = 1;
                                        if (w1.a > 1)
                                                w1.a = 1;
                                }
                                if (w1.a < -1)
                                {
                                        w1.a = -1;
                                        if (w1.b < -1)
                                                w1.b = -1;
                                }
                                return w1;
                        }
                        else
                        {
                                w = w1;
                                k = k + 2;
                                is_even = !is_even;
                        }
                } while (!(finished || (k > INT_MAX / 2)));
        }
        if (!finished)
                st = 2;

        interval r;
        r.a = 0;
        r.b = 0;
        return r;
}
interval IntervalArithmetic::IExp(const interval& x, int & st)
{
        bool finished;
        int k;
        interval d, e, w, w1;
        if (x.a > x.b)
                st = 1;
        else
        {
                e.a = 1;
                e.b = 1;
                w = e;
                k = 1;
                finished = false;
                st = 0;
                do
                {
                        d.a = k;
                        d.b = k;
                        e = IMul(e, IDiv(x, d));
                        w1 = IAdd(w, e);
                        if ((abs(w.a - w1.a) / abs(w.a) < 1e-18)
                                        && (abs(w.b - w1.b) / abs(w.b) < 1e-18))
                        {
                                finished = true;
                                return w1;
                        }
                        else
                        {
                                w = w1;
                                k = k + 1;
                        }
                } while (!(finished || (k > INT_MAX / 2)));
                if (!finished)
                        st = 2;
        }
        interval r;
        r.a = 0;
        r.b = 0;
        return r;
}

interval IntervalArithmetic::ISqr(const interval& x, int & st)
{
        long double minx, maxx;
        interval r;
        r.a = 0;
        r.b = 0;
        if (x.a > x.b)
                st = 1;
        else
        {
                st = 0;
                if ((x.a <= 0) && (x.b >= 0))
                        minx = 0;
                else if (x.a > 0)
                        minx = x.a;
                else
                        minx = x.b;
                if (abs(x.a) > abs(x.b))
                        maxx = abs(x.a);
                else
                        maxx = abs(x.b);
                fesetround(FE_DOWNWARD);
                r.a = minx * minx;
                fesetround(FE_UPWARD);
                r.b = maxx * maxx;
                fesetround(FE_TONEAREST);
        }
        return r;
}

interval IntervalArithmetic::DISin(const interval& x, int & st)
{
        bool is_even, finished;
        int k;
        interval d, s, w, w1, x2;
        if (x.a > x.b)
                st = 1;
        else
        {
                s = x;
                w = x;
                x2 = DIMul(x, x);
                k = 1;
                is_even = true;
                finished = false;
                st = 0;

                do
                {
                        d.a = (k + 1) * (k + 2);
                        d.b = d.a;
                        s = DIMul(s, DIDiv(x2, d));
                        if (is_even)
                                w1 = DISub(w, s);
                        else
                                w1 = DIAdd(w, s);
                        if ((w.a != 0) && (w.b != 0))
                                if ((abs(w.a - w1.a) / abs(w.a) < 1e-18)
                                                && (abs(w.b - w1.b) / abs(w.b) < 1e-18))
                                        finished = true;
                                else
                                        ;
                        else if ((w.a == 0) && (w.b != 0))
                                if ((abs(w.a - w1.a) < 1e-18)
                                                && (abs(w.b - w1.b) / abs(w.b) < 1e-18))
                                        finished = true;
                                else
                                        ;

                        else if (w.a != 0)
                                if ((abs(w.a - w1.a) / abs(w.a) < 1e-18)
                                                & (abs(w.b - w1.b) < 1e-18))
                                        finished = true;
                                else if ((abs(w.a - w1.a) < 1e-18) & (abs(w.b - w1.b) < 1e-18))
                                        finished = true;

                        if (finished)
                        {
                                if (w1.b > 1)
                                {
                                        w1.b = 1;
                                        if (w1.a > 1)
                                                w1.a = 1;
                                }
                                if (w1.a < -1)
                                {
                                        w1.a = -1;
                                        if (w1.b < -1)
                                                w1.b = -1;
                                }
                                return w1;
                        }
                        else
                        {
                                w = w1;
                                k = k + 2;
                                is_even = !is_even;
                        }
                } while (!(finished || (k > INT_MAX / 2)));
        }
        if (!finished)
                st = 2;

        interval r;
        r.a = 0;
        r.b = 0;
        return r;
}

interval IntervalArithmetic::DICos(const interval& x, int & st)
{
        bool is_even, finished;
        int k;
        interval d, c, w, w1, x2;
        if (x.a > x.b)
                st = 1;
        else
        {
                c.a = 1;
                c.b = 1;
                w = c;
                x2 = DIMul(x, x);
                k = 1;
                is_even = true;
                finished = false;
                st = 0;

                do
                {
                        d.a = k * (k + 1);
                        d.b = d.a;
                        c = DIMul(c, DIDiv(x2, d));
                        if (is_even)
                                w1 = DISub(w, c);
                        else
                                w1 = DIAdd(w, c);

                        if ((w.a != 0) && (w.b != 0))
                                if ((abs(w.a - w1.a) / abs(w.a) < 1e-18)
                                                && (abs(w.b - w1.b) / abs(w.b) < 1e-18))
                                        finished = true;
                                else
                                        ;
                        else if ((w.a == 0) && (w.b != 0))
                                if ((abs(w.a - w1.a) < 1e-18)
                                                && (abs(w.b - w1.b) / abs(w.b) < 1e-18))
                                        finished = true;
                                else
                                        ;

                        else if (w.a != 0)
                                if ((abs(w.a - w1.a) / abs(w.a) < 1e-18)
                                                & (abs(w.b - w1.b) < 1e-18))
                                        finished = true;
                                else if ((abs(w.a - w1.a) < 1e-18) & (abs(w.b - w1.b) < 1e-18))
                                        finished = true;

                        if (finished)
                        {
                                if (w1.b > 1)
                                {
                                        w1.b = 1;
                                        if (w1.a > 1)
                                                w1.a = 1;
                                }
                                if (w1.a < -1)
                                {
                                        w1.a = -1;
                                        if (w1.b < -1)
                                                w1.b = -1;
                                }
                                return w1;
                        }
                        else
                        {
                                w = w1;
                                k = k + 2;
                                is_even = !is_even;
                        }
                } while (!(finished || (k > INT_MAX / 2)));
        }
        if (!finished)
                st = 2;

        interval r;
        r.a = 0;
        r.b = 0;
        return r;
}

interval IntervalArithmetic::DIExp(const interval& x, int & st)
{
        bool finished;
        int k;
        interval d, e, w, w1;
        if (x.a > x.b)
                st = 1;
        else
        {
                e.a = 1;
                e.b = 1;
                w = e;
                k = 1;
                finished = false;
                st = 0;
                do
                {
                        d.a = k;
                        d.b = k;
                        e = IMul(e, DIDiv(x, d));
                        w1 = DIAdd(w, e);
                        if ((abs(w.a - w1.a) / abs(w.a) < 1e-18)
                                        && (abs(w.b - w1.b) / abs(w.b) < 1e-18))
                        {
                                finished = true;
                                return w1;
                        }
                        else
                        {
                                w = w1;
                                k = k + 1;
                        }
                } while (!(finished || (k > INT_MAX / 2)));
                if (!finished)
                        st = 2;
        }
        interval r;
        r.a = 0;
        r.b = 0;
        return r;
}

interval IntervalArithmetic::DISqr(const interval& x, int & st)
{
        long double minx, maxx;
        interval r;
        r.a = 0;
        r.b = 0;
        if (x.a > x.b)
                st = 1;
        else
        {
                st = 0;
                if ((x.a <= 0) && (x.b >= 0))
                        minx = 0;
                else if (x.a > 0)
                        minx = x.a;
                else
                        minx = x.b;
                if (abs(x.a) > abs(x.b))
                        maxx = abs(x.a);
                else
                        maxx = abs(x.b);
                fesetround(FE_DOWNWARD);
                r.a = minx * minx;
                fesetround(FE_UPWARD);
                r.b = maxx * maxx;
                fesetround(FE_TONEAREST);
        }
        return r;
}

interval IntervalArithmetic::ISqr2()
{
        string i2;
        interval r;
        i2 = "1.414213562373095048";
        r.a = LeftRead(i2);
        i2 = "1.414213562373095049";
        r.b = RightRead(i2);
        return r;
}

interval IntervalArithmetic::ISqr3()
{
        string i2;
        interval r;
        i2 = "1.732050807568877293";
        r.a = LeftRead(i2);
        i2 = "1.732050807568877294";
        r.b = RightRead(i2);
        return r;
}
interval IntervalArithmetic::IPi()
{
        string i2;
        interval r;
        i2 = "3.141592653589793238";
        r.a = LeftRead(i2);
        i2 = "3.141592653589793239";
        r.b = RightRead(i2);
        return r;
}

void IntervalArithmetic::IEndsToStrings(const interval & i, string & left,
                string & right)
{
        mpfr_t rop;
        mpfr_exp_t exponent;
        mpfr_init2(rop, 80);
        char* str = NULL;
        char *buffer = new char(80 + 3);
        mpfr_set_ld(rop, i.a, MPFR_RNDD);

        mpfr_get_str(buffer, &exponent, 10, 17, rop, MPFR_RNDD);
        str = buffer;

        stringstream ss;
        int prec = std::numeric_limits<long double>::digits10;
        ss.setf(std::ios_base::scientific);
        bool minus = (str[0] == '-');
        int splitpoint = minus ? 1 : 0;
        string sign = minus ? "-" : "";

        ss << std::setprecision(prec) << sign << str[splitpoint] << "."
                        << &str[splitpoint + 1] << "E" << exponent - 1;
        left = ss.str();
        ss.str(std::string());

        mpfr_set_ld(rop, i.b, MPFR_RNDU);
        mpfr_get_str(buffer, &exponent, 10, 17, rop, MPFR_RNDU);
        str = buffer;
        splitpoint = (str[0] == '-') ? 1 : 0;
        ss << std::setprecision(prec) << sign << str[splitpoint] << "."
                        << &str[splitpoint + 1] << "E" << exponent - 1;
        right = ss.str();
        ss.clear();
}

void IntervalArithmetic::SetArthMode(int m)
{
        mode = m;
}

int IntervalArithmetic::GetArthMode()
{
        return mode;
}

interval::interval()
{
}

interval::interval(const long double &x, const long double &y)
{
    a = x;
    b = y;
}

interval interval::operator +(const interval& x)
{
    return IntervalArithmetic::IAdd(*this, x);
}

interval interval::operator -(const interval& x)
{
    return IntervalArithmetic::ISub(*this, x);
}

interval interval::operator *(const interval& x)
{
    return IntervalArithmetic::IMul(*this, x);
}

interval interval::operator ^(const int &x)
{
    int z = x;
    return IntervalArithmetic::ISqr(*this,z);
}

interval interval::operator /(const interval& x)
{
    return IntervalArithmetic::IDiv(*this, x);
}

bool interval::operator >(const interval &x)
{

    return ((this->a) > x.b);
}

bool interval::operator <(const interval &x)
{
    return ((this->b) < x.a);
}

bool interval::operator ==(const interval &x)
{
    return (((this->b) == x.a) && ((this->a) == x.b));
}

bool interval::operator !=(const interval &x)
{
    return (((this->b) < x.a) || ((this->a) > x.b));
}

bool interval::operator >=(const interval &x)
{
    return ((this->a) >= x.b);
}

bool interval::operator <=(const interval &x)
{
    return ((this->b) <= x.a);
}


} /* namespace interval */

/*******************************/
/* INTERVAL CLASS DEFINITIONS  */
/*******************************/

