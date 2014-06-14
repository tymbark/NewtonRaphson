#include "equation.h"

using namespace std;


Equation::Equation(int _id){
    id = _id;
    cout << "new equation\n";
}

Equation::~Equation(){
}

long double Equation::f(long double x){
    long double result;
    long double z;
    if (id == 1){
        z = x*x;
        result = ((z * (z - 5)) + 4);
    }
    if (id == 2){
        z = sin(x);
        result = ((z * (z + 0.5)) - 0.5);
    }
    return result;
}

long double Equation::df(long double x){
    long double result;
    if (id == 1){
        result = 4 * x * ((x * x )- 2.5);
    }
    if (id == 2){
        result = (sin(2 * x) + (0.5 * cos(x)));
    }
    return result;
}

long double Equation::d2f(long double x){
    long double result;
    if (id == 1){
        result = ((12 * x * x) - 10);
    }
    if (id == 2){
        result = (2 * cos(2 * x)) - (0.5 * sin(x));
    }
    return result;
}

long double Equation::newtonRaphson(long double x,
                                   long double eps,
                                   long double fatx,
                                   int mit,
                                   int it,
                                   int st){

    long double dfatx,d2fatx,p,v,w,xh,x1,x2;
    if(mit < 1){
        st = 1;
    }else {
        st = 3;
        it = 0;
        while((it == mit) || (st != 3)){
            it ++;
            fatx = f(x);
            dfatx = df(x);
            d2fatx = d2f(x);
            p = dfatx * (dfatx -2) * fatx * d2fatx;
            if (p < 0){
                st = 4;
            } else if(d2fatx == 0){
                st = 2;
            } else {
                xh = x;
                w = abs(xh);
                p = sqrt(p);
                x1 = x - (dfatx - p) / d2fatx;
                x2 = x - (dfatx + p) / d2fatx;
                if(abs(x2 - xh) > abs(x1 - xh)){
                    x = x1;
                } else {
                    x = x2;
                }
                v = abs(x);
                if(v < w){
                    v = w;
                }
                if(v == 0){
                    st = 0;
                } else if((abs(x - xh) / v) <= eps){
                    st = 0;
                }
            }
        }
    }
    if((st == 0) || (st == 3)){
        //NewtonRaphson = x;
        fatx = f(x);
    }
    long double result;
    return result;
}


