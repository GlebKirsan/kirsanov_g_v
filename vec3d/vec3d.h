#ifndef KIRSANOV_G_V_VEC3D_H
#define KIRSANOV_G_V_VEC3D_H

#include <iosfwd>

struct Vec3d{
public:
    Vec3d() = default;
    Vec3d(const double x, const double y, const double z): x(x), y(y), z(z){}
    Vec3d(const Vec3d& a) = default;
    ~Vec3d() = default;
    Vec3d normalize();
    double length() const;
    bool operator==(const Vec3d& a)const;
    bool operator!=(const Vec3d& a)const;
    Vec3d&operator=(const Vec3d& a);
    Vec3d&operator+=(const Vec3d& a);
    Vec3d&operator-=(const Vec3d& a);
    Vec3d&operator*=(const double a);
    Vec3d&operator/=(const double a);
    Vec3d&operator*=(const Vec3d& a);
    Vec3d&operator/=(const Vec3d& a);
    std::istream& readFrom(std::istream& ist);
    std::ostream& writeTo(std::ostream& ost)const;
private:
    double  x{0.0},
            y{0.0},
            z{0.0};
};

Vec3d& operator+(const Vec3d& a, const Vec3d& b);
Vec3d& operator-(const Vec3d& a, const Vec3d& b);

Vec3d& operator*(const Vec3d& a, const double b);
Vec3d& operator/(const Vec3d& a, const double b);
Vec3d& operator*(const double a, const Vec3d& b);
Vec3d& operator/(const double a, const Vec3d& b);

inline std::istream& operator>>(std::istream& ist, Vec3d a){
    return a.readFrom(ist);
}
inline std::ostream& operator<<(std::ostream& ost, Vec3d a){
    return a.writeTo(ost);
}
#endif
