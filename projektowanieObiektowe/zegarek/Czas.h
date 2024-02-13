#ifndef CZAS_H
#define CZAS_H

#include <iostream>
#include <string>

class Czas {
private:
    int minuty;
    
public:
    Czas (int minuty = 0);
    Czas (int godziny, int minuty);

    std::string ToString() const;

    Czas operator+(const Czas& inny) const;
    Czas operator-(const Czas& inny) const;
    bool operator>(const Czas& inny) const;

    friend std::ostream& operator<<(std::ostream& out, const Czas& czas);
};

#endif