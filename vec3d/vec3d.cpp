#include "vec3d.h"
#include <iostream>
#include <cmath>

double eps = 1e-8;

bool Vec3d::operator==(const Vec3d &a) const {
    return fabs(a.x - x) < eps &&
           fabs(a.y - y) < eps &&
           fabs(a.z - z) < eps;
}

bool Vec3d::operator!=(const Vec3d &a) const {
    return !operator==(a);
}

double Vec3d::length() const {
    return sqrt(x * x + y * y + z * z);
}

Vec3d &Vec3d::normalize() {
    double len = this->length();
    x /= len;
    y /= len;
    z /= len;
    return *this;
}

Vec3d &Vec3d::operator=(const Vec3d &a) {
    x = a.x;
    y = a.y;
    z = a.z;
    return *this;
}

Vec3d &Vec3d::operator+=(const Vec3d &a) {
    x += a.x;
    y += a.y;
    z += a.z;
}

Vec3d &Vec3d::operator-=(const Vec3d &a) {
    return operator+=((-1.0) * a);
}

Vec3d &Vec3d::operator*=(const double a) {
    x *= a;
    y *= a;
    z *= a;
    return *this;
}

Vec3d &Vec3d::operator/=(const double a) {
    return operator*=(1 / a);
}

Vec3d operator+(const Vec3d &a, const Vec3d &b) {
    Vec3d c(a);
    c += b;
    return c;
}

Vec3d operator-(const Vec3d &a, const Vec3d &b) {
    Vec3d c(a);
    c -= b;
    return c;
}

Vec3d operator*(const Vec3d &a, const double b) {
    Vec3d c(a.x * b, a.y * b, a.z * b);
    return c;
}

Vec3d operator/(const Vec3d &a, const double b) {
    Vec3d c(a.x / b, a.y / b, a.z / b);
    return c;
}

Vec3d operator*(const double a, const Vec3d &b) {
    Vec3d c(b.x * a, b.y * a, b.z * a);
    return c;
}

Vec3d operator/(const double a, const Vec3d &b) {
    Vec3d c(b.x / a, b.y / a, b.z / a);
    return c;
}

std::ostream &Vec3d::writeTo(std::ostream &ost) const {
    ost << x << " " << y << " " << z << std::endl;
    return ost;
}

std::istream &Vec3d::readFrom(std::istream &ist) {
    double xn{0.0};
    double yn{0.0};
    double zn{0.0};
    if (ist >> xn >> yn >> zn) {
        x = xn;
        y = yn;
        z = zn;
    } else
        ist.setstate(std::ios_base::failbit);
    return ist;
}