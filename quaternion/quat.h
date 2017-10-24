#ifndef KIRSANOV_G_V_QUAT_H
#define KIRSANOV_G_V_QUAT_H

#include <iostream>

struct Quat {
    Quat() = default;

    Quat(const double lu, const double ru, const double ld, const double rd) :
            lu(lu), ru(ru), rd(rd), ld(ld) {

    }

    ~Quat() = default;

    Quat(const Quat &a) = default;

    bool operator==(const Quat &a);

    bool operator!=(const Quat &a);

    Quat &operator=(const Quat &a);

    Quat &operator+=(const Quat &a);

    Quat &operator-=(Quat &a);

    Quat &operator-();

    Quat &operator*=(const Quat &a);

    Quat &operator+=(const double a);

    Quat &operator-=(const double a);

    Quat &operator*=(const double a);

    std::ostream &writeTo(std::ostream &ost) const;

    std::istream &readFrom(std::istream &ist);

    double lu{0.0},
            ru{0.0},
            ld{0.0},
            rd{0.0};
};

std::ostream &operator<<(std::ostream &ost, const Quat &a) {
    return a.writeTo(ost);
}

std::istream &operator>>(std::istream &ist, Quat &a) {
    return a.readFrom(ist);
}

#endif //KIRSANOV_G_V_QUAT_H