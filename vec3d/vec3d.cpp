#include "vec3d.h"

bool Vec3d::operator==(const Vec3d &a) const {
    return (a.x == x && a.y == y && a.z == z);
}
bool Vec3d::operator!=(const Vec3d &a) const {
    return !operator==(a);
}

Vec3d& Vec3d::operator=(const Vec3d &a) {
    x = a.x;
    y = a.y;
    z = a.z;
    return *this;
}
Vec3d& Vec3d::operator+=(const Vec3d &a) {
    x += a.x;
    y += a.y;
    z += a.z;
}
Vec3d& Vec3d::operator-=(const Vec3d &a) {
    return operator+=((-1.0)*a);
}
Vec3d& Vec3d::operator*=(const double a) {
    x *= a;
    y *= a;
    z *= a;
    return *this;
}
Vec3d& Vec3d::operator/=(const double a) {
    return operator*=(1/a);
}

Vec3d& operator+(const Vec3d& a, const Vec3d& b){
    Vec3d c(a);
    c += b;
    return c;
}
Vec3d& operator-(const Vec3d& a, const Vec3d& b){
    Vec3d c(a);
    c -= b;
    return c;
}

Vec3d& operator*(const Vec3d& a, const double b);
Vec3d& operator/(const Vec3d& a, const double b);
Vec3d& operator*(const double a, const Vec3d& b);
Vec3d& operator/(const double a, const Vec3d& b);