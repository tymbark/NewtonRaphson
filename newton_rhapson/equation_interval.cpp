#include "equation_interval.h"

using namespace intervalarth;

interval zero(0,0);
interval two(2,2);
interval four(4,4);
interval five(5,5);
interval ten(10,10);
interval twelve(12,12);
interval point_five(0.5,0.5);
interval two_point_five(2.5,2.5);

Equation_Interval::Equation_Interval(int _id){
    id = _id;
    cout << "new equation\n";
}

Equation_Interval::~Equation_Interval(){
}

interval Equation_Interval::f(interval _x){
    interval z;
    if (id == 0){
        z = _x *_x;
        result = z - two;
    } else if (id == 1){
        z = _x *_x;
        result = ((z * (z - five)) + four);
    } else if (id == 2){
        z = IntervalArithmetic::ISin(_x, 1); ///////////@@@@??????????
        result = ((z * (z + point_five)) - point_five);
    }
    return result;
}

interval Equation_Interval::df(interval _x){
    interval result;
    if (id == 0){
        result = two * _x;
    } else if (id == 1){
        result = four * _x * ((_x * _x )- two_point_five);
    } else if (id == 2){
        result = (sin(two * _x) + (point_five * cos(_x)));
    }
    return result;
}

interval Equation_Interval::d2f(interval _x){
    interval result;
    if (id == 0){
        result = two;
    } else if (id == 1){
        result = ((twelve * _x * _x) - ten);
    } else if (id == 2){
        result = (two * cos(two * _x)) - (point_five * sin(_x));
    }
    return result;
}

void Equation_Interval::newtonRaphson(){

    cout << "Newton Raphson LAUNCH! \n";
    //cout << " x" <<x<<"\n";
    //cout << " mit:"<<mit<<"\n";
    //cout << " eps:"<<eps<<"\n";

    interval dfatx,d2fatx,p,v,w,xh,x1,x2;
    if(mit < 1){
        st = 1;
    }else {
        st = 3;
        it = 0;
        do{
            it ++;
            fatx = f(x);
            //cout << "fatx:" << fatx << "\n";
            dfatx = df(x);
            //cout << "dfatx:" << dfatx << "\n";
            d2fatx = d2f(x);
            //cout << "d2fatx:" << d2fatx << "\n";
            p = (dfatx * dfatx) - (two * fatx * d2fatx);
            //cout << "p:" << p << "\n";
            if (p < zero){
                st = 4;
            } else if(d2fatx == zero){
                st = 2;
            } else {
                xh = x;
                cout << "xh:" << xh << "\n";
                w = IntervalArithmetic::Abs(xh);
                cout << "abs xh:" << w << "\n";

                p = sqrt(p);
                x1 = x - ((dfatx - p) / d2fatx);
                x2 = x - ((dfatx + p) / d2fatx);
                if(abs(x2 - xh) > abs(x1 - xh)){
                    x = x1;
                } else {
                    x = x2;
                }
                v = abs(x);
                if(v < w){
                    v = w;
                }
                if(v == zero){
                    st = 0;
                } else if((abs(x - xh) / v) <= eps){
                    st = 0;
                }
            }
        }while((it != mit) && (st == 3));
    }
    if((st == 0) || (st == 3)){
        cout << "LOL \n";
        fatx = f(x);
        result = x;
    }
    cout << "Newton Raphson FINISHED! \n";
    //cout << " x:" << x <<"\n";
    //cout << " result:" << result <<"\n";
    //cout << " it:"<< it <<"\n";
    //cout << " st:"<< st <<"\n";
    //cout << " fatx:"<< fatx <<"\n";
}

