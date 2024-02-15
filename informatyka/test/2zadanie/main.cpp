#include <iostream>

using namespace std;

double x = 40;

double newSqrt(double x){
    double halfx = x/2;

    while ((halfx*halfx-x)>0.0001){
        halfx = 0.5*(halfx + x / halfx);
    }

    // Ищем квадратный корень из числа x
    // закончить цикл когда (половина умножить на половину отнять x)
    // приравниваем половину к 1/2 (половина + x / половину) 
    // возвращаем половину

    return halfx;
}

int main() {
    if (x < 0){
        cout << "Niemożliwe" << endl;
    }else{
        cout << newSqrt(x) << endl;   
    }
}