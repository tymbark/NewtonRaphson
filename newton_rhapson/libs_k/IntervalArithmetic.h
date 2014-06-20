/*
 * IntervalArithmetic.h
 *
 *  Created on: 20-11-2012
 *      Author: Tomasz Hoffmann and Andrzej Marciniak
 *
 *  Modified to use 128-bit precision by Sebastian Krzyszkowiak
 */

#ifndef INTERVALARITHMETIC_H_
#define INTERVALARITHMETIC_H_

using namespace std;

#include <iostream>

extern "C" {
  #include <quadmath.h>
}

namespace intervalarth
{

class interval
{
public:
	__float128 a, b;
  interval() {}
  
  interval(string a);
	interval(string, string);
	interval(long double a);
	interval(long double, long double);

  inline bool operator< (interval const &i) const {
    return (a < i.b);
  }
  inline bool operator> (interval const &i) const {
    return (b > i.a);
  }
  inline bool operator<= (interval const &i) const {
    return (a <= i.b);
  }
  inline bool operator>= (interval const &i) const {
    return (b >= i.a);
  }
  inline bool operator== (interval const &i) const {
    return ((b == i.b) && (a == i.a));
  }
  interval operator* (interval const &i) const;
  interval operator/ (interval const &i) const;
  interval operator+ (interval const &i) const;
  interval operator- (interval const &i) const;
  interval operator= (string const &s);
  interval operator- () const;
};

class IntervalArithmetic
{
public:
	IntervalArithmetic();
	virtual ~IntervalArithmetic();
  static __float128 IntWidth(const interval& x);
	static interval IAdd(const interval& x, const interval& y);
	static interval ISub(const interval& x, const interval& y);
  static interval IMul(const interval& x, const interval& y);
  static interval IDiv(const interval& x, const interval& y);
  static __float128 DIntWidth(const interval& x);
  static interval Projection(const interval& x);
  static interval Opposite(const interval& x);
  static interval Inverse(const interval& x);
  static interval DIAdd(const interval& x, const interval& y);
  static interval DISub(const interval& x, const interval& y);
  static interval DIMul(const interval& x, const interval& y);
  static interval DIDiv(const interval& x, const interval& y);
  static interval IntRead(const std::string& sa);
  static __float128 LeftRead(const std::string& sa);
  static __float128 RightRead(const std::string& sa);
  static interval ISin(const interval& x, int& st);
  static interval ICos(const interval& x, int& st);
  static interval IExp(const interval& x, int& st);
  static interval ISqr(const interval& x, int& st);
  static interval ISqr2();
  static interval ISqr3();
  static interval IPi();
  static void IEndsToStrings(const interval& i, std::string& left, std::string& right);
};

} /* namespace interval */

namespace std {
  inline __float128 abs(__float128 x) { return fabsq(x); }
  inline __float128 sqrt(__float128 x) { return sqrtq(x); }
  inline __float128 pow(__float128 x, __float128 y) { return powq(x,y); }
  inline ostream& operator<< (std::ostream& stream, const __float128& f) {
    char* y = new char[100];
    quadmath_snprintf(y, 100, "%.36Qg", f);
    stream << y;
    delete[] y;
    return stream;
  }
  inline ostream& operator<< (std::ostream& stream, const intervalarth::interval& i) {
    string left, right;
    intervalarth::IntervalArithmetic::IEndsToStrings(i, left, right);
    stream << "[" << left << ", "<<right<<"]";
    return stream;
  }
}


#endif /* INTERVALARITHMETIC_H_ */

