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
int e = 0;

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
        int a = 5;
        z = IntervalArithmetic::ISin(_x, e); ///////////@@@@??????????
        result = ((z * (z + point_five)) - point_five);
    }
    if(e!=0) cout << "ERROR \n";
    return result;
}

interval Equation_Interval::df(interval _x){
    interval result;
    if (id == 0){
        result = two * _x;
    } else if (id == 1){
        result = four * _x * ((_x * _x )- two_point_five);
    } else if (id == 2){
        result = (IntervalArithmetic::ISin(two * _x, e) + (point_five * IntervalArithmetic::ICos(_x, e)));
    }
    if(e!=0) cout << "ERROR \n";
    return result;
}

interval Equation_Interval::d2f(interval _x){
    interval result;
    if (id == 0){
        result = two;
    } else if (id == 1){
        result = ((twelve * _x * _x) - ten);
    } else if (id == 2){
        result = (two * IntervalArithmetic::ICos((two * _x), e)
                  - (point_five * IntervalArithmetic::ISin(_x, e)));
    }
    if(e!=0) cout << "ERROR \n";
    return result;
}

void Equation_Interval::newtonRaphson(){

    cout << "Newton Raphson INTERVAL LAUNCH! \n";
    cout << " x.a=" <<x.a<<"\n";
    cout << " x.b=" <<x.b<<"\n";
    cout << " mit=:"<<mit<<"\n";
    cout << " eps.a=:"<<eps.a<<"\n";
    cout << " eps.b=:"<<eps.b<<"\n";

    interval dfatx,d2fatx,p,v,w,xh,x1,x2;
    if(mit < 1){
        st = 1;
    }else {
        st = 3;
        it = 0;
        do{
            cout << "it=" << it << "\n";
            cout << " x.a=" <<x.a<<"\n";
            cout << " x.b=" <<x.b<<"\n";
            cout << " mit="<<mit<<"\n";
            cout << " eps.a="<<eps.a<<"\n";
            cout << " eps.b="<<eps.b<<"\n";
            it ++;
            fatx = f(x);
            cout << "fatx.a:" << fatx.a << "\n";
            cout << "fatx.b:" << fatx.b << "\n";
            dfatx = df(x);
            cout << "dfatx.a:" << dfatx.a << "\n";
            cout << "dfatx.b:" << dfatx.b << "\n";
            d2fatx = d2f(x);
            cout << "d2fatx.a:" << d2fatx.a << "\n";
            cout << "d2fatx.:" << d2fatx.b << "\n";

            p = (dfatx * dfatx) - (two * fatx * d2fatx);

            cout << "p.a=" << p.a << "\n";
            cout << "p.b=" << p.b << "\n";
            if (p < zero){
                st = 4;
            } else if(d2fatx == zero){
                st = 2;
            } else {
                xh = x;
                cout << "xh.a=" << xh.a << "\n";
                cout << "xh.b=" << xh.b << "\n";
                w = IntervalArithmetic::Abs(xh);
                cout << "abs xh.a=" << w.a << "\n";
                cout << "abs xh.b=" << w.b << "\n";

                p = IntervalArithmetic::ISqr(p,e);
                if(e!=0) cout << "ERROR \n";
                x1 = x - ((dfatx - p) / d2fatx);
                x2 = x - ((dfatx + p) / d2fatx);
                cout << "x1.a="<< x1.a << "\n";
                cout << "x1.b="<< x1.b << "\n";
                cout << "x2.a="<< x2.a << "\n";
                cout << "x2.b="<< x2.b << "\n";

                if(IntervalArithmetic::Abs(x2 - xh) > IntervalArithmetic::Abs(x1 - xh)){
                    x = x1;
                } else {
                    x = x2;
                }
                v = IntervalArithmetic::Abs(x);
                if(v < w){
                    v = w;
                }
                cout << "v.a="<< v.a << "\n";
                cout << "v.b="<< v.b << "\n";
                if(v.a== 0 || v.b == 0){
                    st = 0;
                } else if((IntervalArithmetic::Abs(x - xh) / v) <= eps){
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
    cout << " x.a=" <<x.a<<"\n";
    cout << " x.b=" <<x.b<<"\n";
    cout << " mit=:"<<mit<<"\n";
    cout << " eps.a=:"<<eps.a<<"\n";
    cout << " eps.b=:"<<eps.b<<"\n";
}
