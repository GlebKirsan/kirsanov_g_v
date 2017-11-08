#ifndef KIRSANOV_G_V_VEC3DT_H
#define KIRSANOV_G_V_VEC3DT_H

#include <iostream>
#include <cmath>

double epsD = 1e-14;
float epsF = 1e-7;

template<typename T>
struct Vec3dT {
    Vec3dT() = default;

    Vec3dT(const T &x, const T &y, const T &z) : x(x), y(y), z(z) {

    }

    ~Vec3dT() = default;

    Vec3dT(const Vec3dT &copy) = default;

    Vec3dT &operator=(const Vec3dT &rhs) = default;

    bool operator==(const Vec3dT &rhs);

    bool operator!=(const Vec3dT &rhs);

    Vec3dT &operator+=(const Vec3dT &rhs);

    Vec3dT &operator-=(const Vec3dT &rhs);

    Vec3dT &operator/=(const Vec3dT &rhs);

    Vec3dT &operator*=(const Vec3dT &rhs);

    std::ostream &writeTo(std::ostream &ost) const;

    std::istream &readFrom(std::istream &ist);

    T x{T()},
            y{T()},
            z{T()};
};

template<typename T>
Vec3dT<T> &Vec3dT<T>::operator+=(const Vec3dT<T> &rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}

template<typename T>
Vec3dT<T> &Vec3dT<T>::operator-=(const Vec3dT<T> &rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}

template<typename T>
Vec3dT<T> &Vec3dT<T>::operator/=(const Vec3dT<T> &rhs) {
    x /= rhs.x;
    y /= rhs.y;
    z /= rhs.z;
    return *this;
}

template<typename T>
Vec3dT<T> &Vec3dT<T>::operator*=(const Vec3dT<T> &rhs) {
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
    return *this;
}


template<typename T>
Vec3dT<T> operator+(const Vec3dT<T> &lhs, const Vec3dT<T> &rhs) {
    Vec3dT<T> c = lhs;
    c += rhs;
    return c;
}

template<typename T>
Vec3dT<T> operator-(const Vec3dT<T> &lhs, const Vec3dT<T> &rhs) {
    Vec3dT<T> c = lhs;
    c -= rhs;
    return c;
}

template<typename T>
Vec3dT<T> operator/(const Vec3dT<T> &lhs, const Vec3dT<T> &rhs) {
    Vec3dT<T> c = lhs;
    c /= rhs;
    return c;
}

template<typename T>
Vec3dT<T> operator*(const Vec3dT<T> &lhs, const Vec3dT<T> &rhs) {
    Vec3dT<T> c = lhs;
    c *= rhs;
    return c;
}


bool Compare(const Vec3dT<double> &lhs, const Vec3dT<double> &rhs) {
    return std::abs(lhs.x - rhs.x) < epsD &&
           std::abs(lhs.y - rhs.y) < epsD &&
           std::abs(lhs.z - rhs.z) < epsD;
}

bool Compare(const Vec3dT<float> &lhs, const Vec3dT<float> &rhs) {
    return std::abs(lhs.x - rhs.x) < epsF &&
           std::abs(lhs.y - rhs.y) < epsF &&
           std::abs(lhs.z - rhs.z) < epsF;
}

template<typename T>
bool Compare(const Vec3dT<T> &lhs, const Vec3dT<T> &rhs) {
    return lhs.x == rhs.x &&
           lhs.y == rhs.y &&
           lhs.z == rhs.z;
}

template<typename T>
bool Vec3dT<T>::operator==(const Vec3dT<T> &rhs) {
    return Compare(*this, rhs);
}

template<typename T>
bool Vec3dT<T>::operator!=(const Vec3dT<T> &rhs) {
    return !operator==(rhs);
}

template<typename T>
inline std::ostream &operator<<(std::ostream &ost, const Vec3dT<T> rhs) {
    return rhs.writeTo(ost);
}

template<typename T>
inline std::istream &operator>>(std::istream &ist, Vec3dT<T> &rhs) {
    return rhs.readFrom(ist);
}

template<typename T>
std::ostream &Vec3dT<T>::writeTo(std::ostream &ost) const {
    ost << x << " " << y << " " << z << std::endl;
    return ost;
}

template<typename T>
std::istream &Vec3dT<T>::readFrom(std::istream &ist) {
    T xn{T()},
            yn{T()},
            zn{T()};
    if (ist >> xn >> yn >> zn) {
        x = xn;
        y = yn;
        z = zn;
    } else
        ist.setstate(std::ios_base::failbit);
    return ist;
}

#endif //KIRSANOV_G_V_VEC3DT_H
