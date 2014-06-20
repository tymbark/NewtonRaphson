/*
 * IntervalArithmetic.cpp
 *
 *  Created on: 20-11-2012
 *      Author: Tomasz Hoffmann and Andrzej Marciniak
 * 
 *  Modified to use 128-bit precision by Sebastian Krzyszkowiak
 */


#include <iostream>
#include <string>
#include <sstream>
#include <fenv.h>
#include <limits.h>

#include "IntervalArithmetic.h"

namespace intervalarth
{

class runtime_error { // stub
public:
  runtime_error(std::string err) {
    std::cout << "Runtime error: " << err << std::endl;
  }
};
  
interval::interval(string s) {
  interval i = IntervalArithmetic::IntRead(s);
  a = i.a;
  b = i.b;
}

interval::interval(string s1, string s2) {
	interval i = IntervalArithmetic::IntRead(s1);
	a = i.a;
	i = IntervalArithmetic::IntRead(s2);
	b = i.b;
}


interval::interval(long double s) {
	// it might be better idea to use string constructor...
	a = s;
	b = s;
}


interval::interval(long double s1, long double s2) {
	// it might be better idea to use string constructor...
	a = s1;
	b = s2;
}


interval interval::operator* (interval const &i) const {
  return IntervalArithmetic::IMul(*this, i);
}

interval interval::operator/ (interval const &i) const {
  return IntervalArithmetic::IDiv(*this, i);
}

interval interval::operator+ (interval const &i) const {
  return IntervalArithmetic::IAdd(*this, i);
}

interval interval::operator- (interval const &i) const {
  return IntervalArithmetic::ISub(*this, i);
}

interval interval::operator- () const {
  return IntervalArithmetic::ISub(interval("0"), *this);
}

interval interval::operator= (string const &s) {
  interval i = IntervalArithmetic::IntRead(s);
  a = i.a;
  b = i.b;
  return *this;
}

IntervalArithmetic::IntervalArithmetic()
{
	// TODO Auto-generated constructor stub
}

IntervalArithmetic::~IntervalArithmetic()
{
	// TODO Auto-generated destructor stub
}

__float128 IntervalArithmetic::IntWidth(const interval& x)
{
	fesetround(FE_UPWARD);
	__float128 w = x.b - x.a;
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
	__float128 x1y1, x1y2, x2y1;

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
	__float128 x1y1, x1y2, x2y1, t;

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

__float128 IntervalArithmetic::DIntWidth(const interval& x)
{
	__float128 w1, w2;

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
	__float128 z;
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
		else if ((xn || xp) && (((y.a <= 0) && (y.b >= 0)) || ((y.a >= 0)
				&& (y.b <= 0))))
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
		else if (((x.a <= 0) && (x.b >= 0)) || (((x.a >= 0) && (x.b <= 0))
				&& (yn || yp)))
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
	/*mpfr_t rop;
	mpfr_init2(rop, curr_precision);
	mpfr_set_str(rop, sa.c_str(), 10, MPFR_RNDD);
	
	string le = string(mpfr_get_str(NULL, NULL, 10, 0, rop, MPFR_RNDD));
	mpfr_set_str(rop, sa.c_str(), 10, MPFR_RNDU);
	string re = string(mpfr_get_str(NULL, NULL, 10, 0, rop, MPFR_RNDU));
  
	fesetround(FE_TONEAREST);

	r.a = strtoflt128(le.c_str(), NULL);
	r.b = strtoflt128(re.c_str(), NULL);*/
  
  
  fesetround(FE_DOWNWARD);
  r.a = strtoflt128(sa.c_str(), NULL);
  fesetround(FE_UPWARD);
  r.b = strtoflt128(sa.c_str(), NULL);
	return r;
}

__float128 IntervalArithmetic::LeftRead(const string & sa)
{
	interval int_number;
	int_number = IntRead(sa);
	return int_number.a;
}

__float128 IntervalArithmetic::RightRead(const string & sa)
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
			if ((w.a != 0) && (w.b != 0)) {
				if ((abs(w.a - w1.a) / abs(w.a) < 1e-18) && (abs(w.b - w1.b)
						/ abs(w.b) < 1e-18)) {
					finished = true;
				}
			}
			else if ((w.a == 0) && (w.b != 0)) {
				if ((abs(w.a - w1.a) < 1e-18) && (abs(w.b - w1.b) / abs(w.b)
						< 1e-18)) {
					finished = true;
				}
			}
			else if (w.a != 0) {
				if ((abs(w.a - w1.a) / abs(w.a) < 1e-18) & (abs(w.b - w1.b)
						< 1e-18))
					finished = true;
				else if ((abs(w.a - w1.a) < 1e-18) & (abs(w.b - w1.b) < 1e-18))
					finished = true;
			}
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

			if ((w.a != 0) && (w.b != 0)) {
				if ((abs(w.a - w1.a) / abs(w.a) < 1e-18) && (abs(w.b - w1.b)
						/ abs(w.b) < 1e-18))
					finished = true;
			}
			else if ((w.a == 0) && (w.b != 0)) {
				if ((abs(w.a - w1.a) < 1e-18) && (abs(w.b - w1.b) / abs(w.b)
						< 1e-18))
					finished = true;
			}
			else if (w.a != 0) {
				if ((abs(w.a - w1.a) / abs(w.a) < 1e-18) & (abs(w.b - w1.b)
						< 1e-18))
					finished = true;
				else if ((abs(w.a - w1.a) < 1e-18) & (abs(w.b - w1.b) < 1e-18))
					finished = true;
			}
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
			if ((abs(w.a - w1.a) / abs(w.a) < 1e-18) && (abs(w.b - w1.b) / abs(
					w.b) < 1e-18))
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
	__float128 minx, maxx;
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
  i2 = "1.41421356237309504880168872420969807856";
  r.a = LeftRead(i2);
  i2 = "1.41421356237309504880168872420969807857";
  r.b = RightRead(i2);
	return r;
}

interval IntervalArithmetic::ISqr3()
{
	string i2;
	interval r;
  i2 = "1.73205080756887729352744634150587236694";
	r.a = LeftRead(i2);
  i2 = "1.73205080756887729352744634150587236695";
  r.b = RightRead(i2);
	return r;
}
interval IntervalArithmetic::IPi()
{
	string i2;
	interval r;
  i2 = "3.14159265358979323846264338327950288419";
	r.a = LeftRead(i2);
  i2 = "3.14159265358979323846264338327950288420";
	r.b = RightRead(i2);
	return r;
}

void IntervalArithmetic::IEndsToStrings(const interval & i, string & left,
		string & right)
{
  std::stringstream ss;
  fesetround(FE_DOWNWARD);
  ss << i.a;
  left = ss.str();
  ss.str("");
  fesetround(FE_UPWARD);
  ss << i.b;
  right = ss.str();
  fesetround(FE_TONEAREST);
}

} /* namespace interval */

int interval_test() {
  /*
   * fesetround(FE_DOWNWARD);
   * __float128 pia = strtoflt128("3.141592653589793238462643383279502", NULL);
   * fesetround(FE_UPWARD);
   * __float128 pib = strtoflt128("3.141592653589793238462643383279503", NULL);
   * 
   * fesetround(FE_DOWNWARD);
   * std::cout << pia << std::endl;
   * fesetround(FE_UPWARD);
   * std::cout << pib << std::endl;
   */  
  intervalarth::IntervalArithmetic ia;
  intervalarth::interval pi = ia.IPi();
  fesetround(FE_DOWNWARD);
  std::cout.precision(36);
  std::cout << pi.a << std::endl;
  fesetround(FE_UPWARD);
  std::cout << pi.b << std::endl;
  fesetround(FE_TONEAREST);
  
  intervalarth::interval pi2 = ia.IMul(pi, pi);
  intervalarth::interval pi4 = ia.IMul(pi2, pi2);
  intervalarth::interval pi8 = ia.IMul(pi4, pi4);
  intervalarth::interval pi16 = ia.IMul(pi8, pi8);
  intervalarth::interval pi32 = ia.IMul(pi16, pi16);
  intervalarth::interval pi64 = ia.IMul(pi32, pi32);
  
  
  fesetround(FE_DOWNWARD);
  std::cout << ia.IMul(pi64, pi64).a << std::endl;
  fesetround(FE_UPWARD);
  std::cout << ia.IMul(pi64, pi64).b << std::endl;
  fesetround(FE_TONEAREST);
  
  intervalarth::interval sqrt = ia.ISqr2();
  intervalarth::interval two;
  two.a = 1.0q;
  two.b = 1.0q;
  two = ia.IMul(sqrt, two);
  fesetround(FE_DOWNWARD);
  std::cout << ia.IMul(sqrt, two).a << std::endl;
  fesetround(FE_UPWARD);
  std::cout << ia.IMul(sqrt, two).b << std::endl;
  fesetround(FE_TONEAREST);
  
  std::string a, b;
  ia.IEndsToStrings(pi, a, b);
  std::cout << a << std::endl << b << std::endl;
  
  return 0;
}
