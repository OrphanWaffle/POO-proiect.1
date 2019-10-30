#include <iostream>
#include "Complex.h"
#include <utility>
using namespace std;

class nr_ob
{
    int n;
    Complex *v;
public:
    void citire();
    void afisare(int);
    void exemple();
};

void nr_ob :: citire()
{
    cout<<"numarul de obiecte ";
    cin>>n;
    v=new Complex[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Obiectul "<<i<<endl;
        v[i].citire();
    }
}

void nr_ob :: afisare(int p)
{
    v[p].afisare();
}

pair<Complex, Complex> ecuatie_de_grad_2(Complex a,Complex b,Complex c)
{
    Complex x1,x2,delta;
    delta=(b*b)-(4*(a*c));
    x1=((-b)+(sqrt(delta)))/(2*a);
    x2=((-b)-(sqrt(delta)))/(2*a);

    cout<<"delta = "; delta.afisare();
    cout<<"sqrt(delta) = "; sqrt(delta).afisare();
    cout<<"sqrt(delta)^2 = "; (sqrt(delta)*sqrt(delta)).afisare();
    return make_pair(x1,x2);
}

void nr_ob :: exemple()
{
    cout<<"v[0] =" ; v[0].afisare();
    cout<<"v[1] =" ; v[1].afisare();
    cout<<"v[2] =" ; v[2].afisare();
    cout<<endl;

    Complex t;
    cout<<"v[0] + v[1] = "; (v[0]+v[1]).afisare(); t=v[0];
    t+=v[1];
    cout<<"v[0] += v[1] : "; t.afisare();
    cout<<"v[0] - v[1] = "; (v[0]-v[1]).afisare(); t=v[0];
    t-=v[1];
    cout<<"v[0] -= v[1] : "; t.afisare();
    cout<<"v[0] * v[1] = "; (v[0]*v[1]).afisare(); t=v[0];
    t*=v[1];
    cout<<"v[0]*=v[1] : "; t.afisare();
    cout<<"v[0] / v[1] = "; (v[0]/v[1]).afisare(); t=v[0];
    t/=v[1];
    cout<<"v[0]/=v[1] : "; t.afisare();
    cout<<endl;

    pair<Complex, Complex> solutie=ecuatie_de_grad_2(v[0],v[1],v[2]);

    cout<<"x1 = "; solutie.first.afisare();
    cout<<"x2 = "; solutie.second.afisare();
}

int main()
{
    nr_ob x;
    x.citire();
    cout<<endl;
    x.exemple();
    return 0;
}
