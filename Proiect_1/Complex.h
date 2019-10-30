#pragma once

#include <iostream>

using namespace std;

class Complex
{
    double real,img;
public:
    Complex();
    Complex(const Complex&);
    void setat_r(double);
    void setat_i(double);
    double furnizat_r() const;
    double furnizat_i() const;
    void citire();
    void afisare();

    friend Complex operator+(const Complex&);
    friend Complex operator+(const Complex&,const Complex&);
    friend Complex operator+(const Complex&,double);
    friend Complex operator+(double,const Complex&);

    friend Complex operator-(const Complex&);
    friend Complex operator-(const Complex&,const Complex&);
    friend Complex operator-(const Complex&,double);
    friend Complex operator-(double,const Complex&);

    friend Complex operator*(const Complex&,const Complex&);
    friend Complex operator*(const Complex&,double);
    friend Complex operator*(double,const Complex&);

    friend Complex operator/(const Complex&,const Complex&);
    friend Complex operator/(const Complex&,double);
    friend Complex operator/(double,const Complex&);

    friend bool operator==(const Complex&,const Complex&);
    friend bool operator==(const Complex&,double);
    friend bool operator==(double,const Complex&);

    friend bool operator!=(const Complex&,const Complex&);
    friend bool operator!=(const Complex&,double);
    friend bool operator!=(double,const Complex&);

    friend void operator +=(Complex&,const Complex&);
    friend void operator +=(Complex&,double);

    friend void operator -=(Complex&,const Complex&);
    friend void operator -=(Complex&,double);

    friend void operator *=(Complex&,const Complex&);
    friend void operator *=(Complex&,double);

    friend void operator /=(Complex&,const Complex&);
    friend void operator /=(Complex&,double);

    friend Complex operator ^(const Complex&,unsigned int);

    friend unsigned int abs(const Complex&);

    friend Complex sqrt(const Complex&);
};

