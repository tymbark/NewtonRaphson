#include <cstdlib>
#include "IntervalArithmetic.h"

using namespace intervalarth;

void iclampedsplinecoeffns(int n, interval x[], interval f[], interval f1x0, interval f1xn, interval a[][4], int &st){
  int i,k;
  interval u,v,y,z,xi;
  interval d[n+1], b[n+1], c[n+1];  
  
  if (n<1) {
    st=1;
  } else {
    st=0;
    i=-1;
    do {
      i=i+1;
      for (k=i+1; k<=n; k++) {
        if (x[i]==x[k]) {
          st=2;
        }
      }
    } while (!((i==n-1) || (st==2)));
  }
  if (st==0) {
    b[0]=interval("1");
    u=x[1]-x[0];
    d[0]=interval("6")*((f[1]-f[0])/u-f1x0)/u;
    c[n]=interval("1");
    u=x[n]-x[n-1];
    d[n]=interval("6")*(f1xn-(f[n]-f[n-1])/u)/u;
    for (i=1; i<n; i++) {
      z=x[i];
      y=x[i+1]-z;
      z=z-x[i-1];
      u=f[i];
      b[i]=y/(y+z);
      c[i]=interval("1")-b[i];
      d[i]=interval("6")*((f[i+1]-u)/y-(u-f[i-1])/z)/(y+z);
    }
    u=interval("2");
    i=-1;
    y=d[0]/u;
    d[0]=y;
    do {
      i=i+1;
      z=b[i]/u;
      b[i]=z;
      u=interval("2")-z*c[i+1];
      y=(d[i+1]-y*c[i+1])/u;
      d[i+1]=y;
    } while (i!=(n-1));
    u=d[n];
    for (i=n-1; i>=0; i--) {
      u=d[i]-u*b[i];
      d[i]=u;
    }
    for (i=0; i<n; i++) {
      u=f[i];
      xi=x[i];
      z=x[i+1]-xi;
      y=d[i];
      v=(f[i+1]-u)/z-(interval("2")*y+d[i+1])*z/interval("6");
      z=(d[i+1]-y)/(interval("6")*z);
      y=y/interval("2");
			a[i][0]=((-z*xi+y)*xi-v)*xi+u;
      u=interval("3")*z*xi;
			a[i][1]=(u-interval("2")*y)*xi+v;
			a[i][2]=y-u;
			a[i][3]=z;
    }
  }
}

interval iclampedsplinevalue(int n, interval x[], interval f[], interval f1x0, interval f1xn, interval xx, int &st) {
  int i,k;
  interval u,y,z;
  bool found;
  interval a[4];
  interval d[n+1], b[n+1], c[n+1];  
  
  if (n<1) {
    st=1;
  } else if ((xx<x[0]) || (xx>x[n])) {
    st=3;
  } else {
    st=0;
    i=-1;
    do {
      i=i+1;
      for (k=i+1; k<=n; k++) {
        if (x[i]==x[k]) {
          st=2;
        }
      }
    } while (!((i==n-1) || (st==2)));
  }
  if (st==0) {
    b[0]=interval("1");
    u=x[1]-x[0];
    d[0]=interval("6")*((f[1]-f[0])/u-f1x0)/u;
    c[n]=interval("1");
    u=x[n]-x[n-1];
    d[n]=interval("6")*(f1xn-(f[n]-f[n-1])/u)/u;
    for (i=1; i<n; i++) {
      z=x[i];
      y=x[i+1]-z;
      z=z-x[i-1];
      u=f[i];
      b[i]=y/(y+z);
      c[i]=interval("1")-b[i];
      d[i]=interval("6")*((f[i+1]-u)/y-(u-f[i-1])/z)/(y+z);
    }
    u=interval("2");
    i=-1;
    y=d[0]/u;
    d[0]=y;
    do {
      i=i+1;
      z=b[i]/u;
      b[i]=z;
      u=interval("2")-z*c[i+1];
      y=(d[i+1]-y*c[i+1])/u;
      d[i+1]=y;
    } while (i!=n-1);
    u=d[n];
    for (i=n-1; i>=0; i--) {
      u=d[i]-u*b[i];
      d[i]=u;
    }
    found=false;
    i=-1;
    do {
      i=i+1;
      if ((xx>=x[i]) && (xx<=x[i+1])) {
        found=true;
      }
    } while (!found);
    y=x[i+1]-x[i];
    z=d[i+1];
    u=d[i];
    a[0]=f[i];
    a[1]=(f[i+1]-f[i])/y-(interval("2")*u+z)*y/interval("6");
    a[2]=u/interval("2");
    a[3]=(z-u)/(interval("6")*y);
    y=a[3];
    z=xx-x[i];
    for (i=2; i>=0; i--) {
      y=y*z+a[i];
    }
    return y;
  }
	return interval("0");
}


void clampedsplinecoeffns(int n, __float128 x[], __float128 f[], __float128 f1x0, __float128 f1xn, __float128 a[][4], int &st) {
  int i,k;
  __float128 u,v,y,z,xi;
  __float128 d[n+1], b[n+1], c[n+1];
    
  if (n<1) {
    st=1;
  } else {
    st=0;
    i=-1;
    do {
      i=i+1;
      for (k=i+1; k<=n; k++) {
        if (x[i]==x[k]) {
          st=2;
        }
      }
    } while (!((i==n-1) || (st==2)));
  }
  if (st==0) {
    b[0]=1;
    u=x[1]-x[0];
    d[0]=6*((f[1]-f[0])/u-f1x0)/u;
    c[n]=1;
    u=x[n]-x[n-1];
    d[n]=6*(f1xn-(f[n]-f[n-1])/u)/u;
    for (i=1; i<n; i++) {
      z=x[i];
      y=x[i+1]-z;
      z=z-x[i-1];
      u=f[i];
      b[i]=y/(y+z);
      c[i]=1-b[i];
      d[i]=6*((f[i+1]-u)/y-(u-f[i-1])/z)/(y+z);
    }
    u=2;
    i=-1;
    y=d[0]/u;
    d[0]=y;
    do {
      i=i+1;
      z=b[i]/u;
      b[i]=z;
      u=2-z*c[i+1];
      y=(d[i+1]-y*c[i+1])/u;
      d[i+1]=y;
    } while (i!=(n-1));
    u=d[n];
    for (i=n-1; i>=0; i--) {
      u=d[i]-u*b[i];
      d[i]=u;
    }
    for (i=0; i<n; i++) {
      u=f[i];
      xi=x[i];
      z=x[i+1]-xi;
      y=d[i];
      v=(f[i+1]-u)/z-(2*y+d[i+1])*z/6;
      z=(d[i+1]-y)/(6*z);
      y=y/2;
			a[i][0]=((-z*xi+y)*xi-v)*xi+u;
      u=3*z*xi;
			a[i][1]=(u-2*y)*xi+v;
			a[i][2]=y-u;
			a[i][3]=z;
    }
  }
}

__float128 clampedsplinevalue(int n, __float128 x[], __float128 f[], __float128 f1x0, __float128 f1xn, __float128 xx, int &st) {
  int i,k;
  __float128 u,y,z;
  bool found;
  __float128 a[4];
  __float128 d[n+1], b[n+1], c[n+1];
    
  
  if (n<1) {
    st=1;
  } else if ((xx<x[0]) || (xx>x[n])) {
    st=3;
  } else {
    st=0;
    i=-1;
    do {
      i=i+1;
      for (k=i+1; k<=n; k++) {
        if (x[i]==x[k]) {
          st=2;
        }
      }
    } while (!((i==n-1) || (st==2)));
  }
  if (st==0) {
    b[0]=1;
    u=x[1]-x[0];
    d[0]=6*((f[1]-f[0])/u-f1x0)/u;
    c[n]=1;
    u=x[n]-x[n-1];
    d[n]=6*(f1xn-(f[n]-f[n-1])/u)/u;
    for (i=1; i<n; i++) {
      z=x[i];
      y=x[i+1]-z;
      z=z-x[i-1];
      u=f[i];
      b[i]=y/(y+z);
      c[i]=1-b[i];
      d[i]=6*((f[i+1]-u)/y-(u-f[i-1])/z)/(y+z);
    }
    u=2;
    i=-1;
    y=d[0]/u;
    d[0]=y;
    do {
      i=i+1;
      z=b[i]/u;
      b[i]=z;
      u=2-z*c[i+1];
      y=(d[i+1]-y*c[i+1])/u;
      d[i+1]=y;
    } while (i!=n-1);
    u=d[n];
    for (i=n-1; i>=0; i--) {
      u=d[i]-u*b[i];
      d[i]=u;
    }
    found=false;
    i=-1;
    do {
      i=i+1;
      if ((xx>=x[i]) && (xx<=x[i+1])) {
        found=true;
      }
    } while (!found);
    y=x[i+1]-x[i];
    z=d[i+1];
    u=d[i];
    a[0]=f[i];
    a[1]=(f[i+1]-f[i])/y-(2*u+z)*y/6;
    a[2]=u/2;
    a[3]=(z-u)/(6*y);
    y=a[3];
    z=xx-x[i];
    for (i=2; i>=0; i--) {
      y=y*z+a[i];
    }
    return y;
  }
	return 0.0q;
}

int testmain() {
  interval* x = new interval[7];
  interval* f = new interval[7];
  *(x) = "17.0";
  *(x+1) = "20.0";
  *(x+2) = "23.0";
  *(x+3) = "24.0";
  *(x+4) = "25.0";
  *(x+5) = "27.0";
  *(x+6) = "27.7";
  *(f) = "4.5";
  *(f+1) = "7.0";
  *(f+2) = "6.1";
  *(f+3) = "5.6";
  *(f+4) = "5.8";
  *(f+5) = "5.2";
  *(f+6) = "4.1";
  int st;
	interval aaaa[7][4];
	iclampedsplinecoeffns(6, x, f, interval("3.0"), interval("-4.0"),aaaa, st);
  std::cout << st << std::endl;
  std::cout << iclampedsplinevalue(6, x, f, interval("3.0"), interval("-4.0"), interval("23.5"), st) << std::endl;
  std::cout << st << std::endl;
  delete[] x;
  delete[] f;

  __float128* x1 = new __float128[7];
  __float128* f1 = new __float128[7];
  *(x1) = 17.0q;
  *(x1+1) = 20.0q;
  *(x1+2) = 23.0q;
  *(x1+3) = 24.0q;
  *(x1+4) = 25.0q;
  *(x1+5) = 27.0q;
  *(x1+6) = 27.7q;
  *(f1) = 4.5q;
  *(f1+1) = 7.0q;
  *(f1+2) = 6.1q;
  *(f1+3) = 5.6q;
  *(f1+4) = 5.8q;
  *(f1+5) = 5.2q;
  *(f1+6) = 4.1q;
	__float128 aaa[7][4];
	clampedsplinecoeffns(6, x1, f1, 3.0q, -4.0q, aaa, st);
  std::cout << st << std::endl;
  std::cout << clampedsplinevalue(6, x1, f1, 3.0q, -4.0q, 23.5q, st) << std::endl;
  std::cout << st << std::endl;
  delete[] x1;
  delete[] f1;
  return 0;
}
