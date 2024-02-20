#include <iostream>
#ifndef ZESPOLONA_H
#define ZESPOLONA_H

class Zespolona {
    private:
        double re;
        double im;

    public:
        Zespolona(double re = 0, double im = 0);

        friend std::ostream& operator<<(std::ostream& out, const Zespolona& z);

        Zespolona operator+(const Zespolona& z) const;
        Zespolona& operator+=(const Zespolona& z);

        bool operator==(const Zespolona& z) const;
};

#endif