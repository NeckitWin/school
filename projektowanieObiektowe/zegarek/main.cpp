#include "Czas.h"

int main() {
    Czas czas1(200);
    Czas czas2(2, 45);
    Czas suma = czas1 + czas2;
    Czas roznica = czas1 - czas2;

    std::cout << "Czas 1: " << czas1 << std::endl;
    std::cout << "Czas 2: " << czas2 << std::endl;
    std::cout << "Suma między czasami: " << suma << std::endl;
    std::cout << "Różnica między czasami: " << roznica << std::endl;

    if (czas1 > czas2) {
        std::cout << "Czas 1 jest większy od Czas 2" << std::endl;
    } else {
        std::cout << "Czas 1 jest mniejszy od Czas 2" << std::endl;
    }

    return 0;
}