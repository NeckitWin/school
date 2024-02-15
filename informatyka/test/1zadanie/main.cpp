#include<iostream>
#include<iomanip>
using namespace std;

double f(double x)
{
    //rozpatrujemy wielomian f(x) = x^3 - 3x^2 + 2x - 6 
    return x*(x*(x-3)+2)-6; //rozbijam schematem Hornera
}

double polowienie_przedzialow(double a, double b, double epsilon)
{
    if(f(a)==0.0)return a;
    if(f(b)==0.0)return b;
    
    double srodek;
    
    while(b-a > epsilon)
    {
        srodek = (a+b)/2;
        
        if(f(srodek) == 0.0)
            return srodek;
        
        if(f(a)*f(srodek)<0) 
            b = srodek;
        else
            a = srodek;
    }
    return (a+b)/2;
}

int main()
{
    double a = -10, b = 10, epsilon = 0.00001;
    
    cout<<"Znalezione miejsce zerowe wynosi: ";
    cout<<fixed<<setprecision(5)<<polowienie_przedzialow(a, b, epsilon);

    return 0;
}