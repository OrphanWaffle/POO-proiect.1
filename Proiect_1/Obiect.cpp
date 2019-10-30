#include "Complex.h"
#include<math.h>
Complex::Complex(){ real=0; img=0; }
Complex::Complex(const Complex& c){ real=c.real; img=c.img; }

void Complex::setat_r(double a){ real=a; }
double Complex::furnizat_r() const{ return real; }
void Complex::setat_i(double a){ img=a; }
double Complex::furnizat_i() const{ return img; }

void Complex::citire()
{
    cout<<"Partea reala: "; cin>>real;
    cout<<"Partea imaginara: "; cin>>img;
}

void Complex::afisare()
{
    if(real==0 && img==0){cout<< 0 <<endl; return;}
    if(real==0){cout<<img<<"*i"<<endl; return;}
    if(img==0){cout<<real<<endl; return;}
    if(img<0){cout<<real<<img<<"*i"<<endl; return;}
    cout<<real<<"+"<<img<<"*i"<<endl;
}
//---------------------------------------------------
Complex operator+(const Complex& a){return a;}
Complex operator+(const Complex& a,const Complex& b)
{
    Complex c;
    c.real=a.real+b.real;
    c.img=a.img+b.img;
    return c;
}
Complex operator+(const Complex& a,double b)
{
    Complex c;
    c.real=a.real+b;
    c.img=a.img;
    return c;
}
Complex operator+(double a,const Complex& b)
{
    Complex c;
    c.real=a+b.real;
    c.img=b.img;
    return c;
}
//----------------------------------
Complex operator-(const Complex& a)
{
    Complex c;
    c.real=(-1)*a.real;
    c.img=(-1)*a.img;
    return c;
}
Complex operator-(const Complex& a,const Complex& b)
{
    Complex c;
    c.real=a.real-b.real;
    c.img=a.img-b.img;
    return c;
}
Complex operator-(const Complex& a,double b)
{
    Complex c;
    c.real=a.real-b;
    c.img=a.img;
    return c;
}
Complex operator-(double a,const Complex& b)
{
    Complex c;
    c.real=a-b.real;
    c.img=(-1)*b.img;
    return c;
}
//--------------------------------------------------------
Complex operator*(const Complex& a,const Complex& b)
{
    Complex c;
    c.real=a.real*b.real-a.img*b.img;
    c.img=a.real*b.img+a.img*b.real;
    return c;
}
Complex operator*(const Complex& a,double b)
{
    Complex c;
    c.real=a.real*b;
    c.img=a.img*b;
    return c;
}
Complex operator*(double a,const Complex& b)
{
    Complex c;
    c.real=a*b.real;
    c.img=a*b.img;
    return c;
}
//-------------------------------
Complex operator/(const Complex& a,const Complex& b)
{
    Complex c,x;
    x.real=b.real;
    x.img=(-1)*b.img;
    c.real=(a*x).real/(pow(b.real,2)+pow(b.img,2));
    c.img=(a*x).img/(pow(b.real,2)+pow(b.img,2));
    return c;
}
Complex operator/(const Complex& a,double b)
{
    Complex c;
    c.real=a.real/b;
    c.img=a.img/b;
    return c;
}
Complex operator/(double a,const Complex& b)
{
    Complex c,x;
    x.real=b.real;
    x.img=(-1)*b.img;
    c.real=(a*x).real/(pow(b.real,2)+pow(b.img,2));
    c.img=(a*x).img/(pow(b.real,2)+pow(b.img,2));
    return c;
}
//------------------------------------------------------
bool operator==(const Complex& a,const Complex& b)
{
    if(a.real==b.real && a.img==b.img) return true;
    else return false;
}
bool operator==(const Complex& a,double b)
{
    if(a.real==b && a.img==0) return true;
    else return false;
}
bool operator==(double a,const Complex& b)
{
   if(a==b.real && 0==b.img) return true;
    else return false;
}
//---------------------------------------------
bool operator!=(const Complex& a,const Complex& b)
{
    if(a.real!=b.real || a.img!=b.img) return true;
    else return false;
}
bool operator!=(const Complex& a,double b)
{
    if(a.real!=b || a.img!=0) return true;
    else return false;
}
bool operator!=(double a,const Complex& b)
{
    if(a!=b.real || 0!=b.img) return true;
    else return false;
}
//----------------------------------------------------
void operator +=(Complex& a,const Complex& b)
{
    a=(a+b);
}
void operator +=(Complex& a,double b)
{
    a=(a+b);
}
//----------------------------------------------------
void operator -=(Complex& a,const Complex& b)
{
    a=(a-b);
}
void operator -=(Complex& a,double b)
{
    a=(a-b);
}
//----------------------------------------------------
void operator *=(Complex& a,const Complex& b)
{
    a=(a*b);
}
void operator *=(Complex& a,double b)
{
    a=(a*b);
}
//----------------------------------------------------
void operator /=(Complex& a,const Complex& b)
{
    a=(a/b);
}
void operator /=(Complex& a,double b)
{
    a=(a/b);
}
//--------------------------------------------------------
Complex operator ^(const Complex& a,unsigned int b)
{
    Complex c;
    c=a;
    for(unsigned int i=1;i<b;i++) c*=a;
    if(b==0)
    {
        c.setat_r(1);
        c.setat_i(0);
    }
    return c;
}
//-----------------------------------------
unsigned int abs(const Complex& a)
{
    return sqrt(pow(a.real,2)+pow(a.img,2));
}
//----------------------------
Complex sqrt(const Complex& a)
{
    Complex c;
    double x=pow(a.real*a.real+a.img*a.img,0.25f);
    c.real=x*cos(0.5f*atan2(a.img,a.real));
    c.img=x*sin(0.5f*atan2(a.img,a.real));
    return c;
}
