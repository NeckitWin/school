#include "Czas.h"

Czas::Czas(int minuty) : minuty(minuty) {}

Czas::Czas(int godziny, int minuty) : minuty(godziny * 60 + minuty) {}

std::string Czas::ToString() const {
    int godziny = minuty / 60;
    int pozostale_minuty = minuty % 60;
    return std::to_string(godziny) + ":" + (pozostale_minuty < 10 ? "0" : "") + std::to_string(pozostale_minuty);
}

Czas Czas::operator+(const Czas& inny) const {
    return Czas(minuty + inny.minuty);
}

Czas Czas::operator-(const Czas& inny) const {
    int result_minutes = minuty - inny.minuty;
    if (result_minutes < 0) {
        result_minutes = 0;
    }
    return Czas(result_minutes);
}

bool Czas::operator>(const Czas& inny) const {
    return minuty > inny.minuty;
}

std::ostream& operator<<(std::ostream& out, const Czas& czas) {
    out << czas.ToString();
    return out;
}