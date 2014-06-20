#include "equation_interval.h"

using namespace intervalarth;

Equation_Interval::Equation_Interval(int _id){
    id = _id;
    cout << "new equation\n";
}

Equation_Interval::~Equation_Interval(){
}
/*
interval Equation_Interval::f(interval _x){
    interval z;
    if (id == 0){
        z = _x *_x;
        result = z - 2;
    } else if (id == 1){
        z = _x *_x;
        result = ((z * (z - 5)) + 4);
    } else if (id == 2){
        z = sin(_x);
        result = ((z * (z + 0.5)) - 0.5);
    }
    return result;
}

interval Equation_Interval::df(interval _x){
    interval result;
    if (id == 0){
        result = 2 * _x;
    } else if (id == 1){
        result = 4 * _x * ((_x * _x )- 2.5);
    } else if (id == 2){
        result = (sin(2 * _x) + (0.5 * cos(_x)));
    }
    return result;
}

interval Equation_Interval::d2f(interval _x){
    interval result;
    if (id == 0){
        result = 2;
    } else if (id == 1){
        result = ((12 * _x * _x) - 10);
    } else if (id == 2){
        result = (2 * cos(2 * _x)) - (0.5 * sin(_x));
    }
    return result;
}

void Equation_Interval::newtonRaphson(){

    cout << "Newton Raphson LAUNCH! \n";
    cout << " x" <<x<<"\n";
    cout << " mit:"<<mit<<"\n";
    cout << " eps:"<<eps<<"\n";

    interval dfatx,d2fatx,p,v,w,xh,x1,x2;
    if(mit < 1){
        st = 1;
    }else {
        st = 3;
        it = 0;
        do{
            it ++;
            fatx = f(x);
            cout << "fatx:" << fatx << "\n";
            dfatx = df(x);
            cout << "dfatx:" << dfatx << "\n";
            d2fatx = d2f(x);
            cout << "d2fatx:" << d2fatx << "\n";
            p = (dfatx * dfatx) - (2 * fatx * d2fatx);
            cout << "p:" << p << "\n";
            if (p < 0){
                st = 4;
            } else if(d2fatx == 0){
                st = 2;
            } else {
                xh = x;
                cout << "xh:" << xh << "\n";
                w = abs(xh);
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
                if(v == 0){
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
    cout << " x:" << x <<"\n";
    cout << " result:" << result <<"\n";
    cout << " it:"<< it <<"\n";
    cout << " st:"<< st <<"\n";
    cout << " fatx:"<< fatx <<"\n";
}*/

