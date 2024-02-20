#include <iostream>
#include "zespolona.h"

int main() {
    Zespolona z1(2.0, -2.0);
    Zespolona z2(2.0, -2.0);
    Zespolona z(z1+z2);
    Zespolona z3(1.0, 1.0);


    std::cout << "z1 = " << z1 << std::endl;
    std::cout << "z2 = " << z2 << std::endl;
    std::cout << "z1 + z2 = " << z << std::endl;
    std::cout << "z3 = " << z3 << std::endl;
        z3+=z2;
    std::cout << "z3 += z2 = " << z3 << std::endl;


    if (z1 == z2) {
        std::cout << "z1 == z2" << std::endl;
    } else {
        std::cout << "z1 != z2" << std::endl;
    }

    return 0;
}

// "2.5 + 1.3 i"