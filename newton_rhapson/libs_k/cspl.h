#include "IntervalArithmetic.h"

using namespace intervalarth;

void iclampedsplinecoeffns(int n, interval x1[], interval f1[], interval f1x0, interval f1xn, interval res[][4], int &st);
interval iclampedsplinevalue(int n, interval x1[], interval f1[], interval f1x0, interval f1xn, interval xx, int &st);
void clampedsplinecoeffns(int n, __float128 x1[], __float128 f1[], __float128 f1x0, __float128 f1xn, __float128 a[][4], int &st);
__float128 clampedsplinevalue(int n, __float128 x1[], __float128 f1[], __float128 f1x0, __float128 f1xn, __float128 xx, int &st);
void testmain();
