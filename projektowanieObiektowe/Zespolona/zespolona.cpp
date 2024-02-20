#include <iostream>
#include "zespolona.h"

Zespolona::Zespolona(double re, double im) : re(re), im(im) {}

std::ostream& operator<<(std::ostream& out, const Zespolona& z) {
    out << z.re;
    if (z.im >= 0) {
        out << " + ";
    } else {
        out << " - ";
    }
    out << std::abs(z.im) << " i";
    return out;
}

Zespolona Zespolona::operator+(const Zespolona& z) const {
    return Zespolona(re + z.re, im + z.im);
}

Zespolona& Zespolona::operator+=(const Zespolona& z) {
    re += z.re;
    im += z.im;
    return *this;
}

bool Zespolona::operator==(const Zespolona& z) const {
    return re == z.re && im == z.im;
}