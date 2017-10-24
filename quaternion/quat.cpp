#include "quat.h"
#include <iostream>
#include <cmath>

double eps = 1e-8;

double matrMult(double lu, double ru, double lua, double lda){
    return lu * lua + ru * lda;
}

bool Quat::operator==(const Quat &a) {
    return fabs(lu - a.lu) < eps &&
           fabs(ld - a.ld) < eps &&
           fabs(ru - a.ru) < eps &&
           fabs(rd - a.rd) < eps;
}

bool Quat::operator!=(const Quat &a) {
    return !operator==(a);
}

Quat &Quat::operator*=(const double a) {
    lu *= a;
    ld *= a;
    ru *= a;
    rd *= a;
    return *this;
}

Quat& Quat::operator*=(const Quat &a) {
    double templu = lu;
    double tempru = ru;
    double templd = ld;
    double temprd = rd;
    lu = matrMult(templu, tempru, a.lu, a.ld);
    ld = matrMult(templd, temprd, a.lu, a.ld);
    ru = matrMult(templu, tempru, a.ru, a.rd);
    rd = matrMult(templd, temprd, a.ru, a.rd);
    return *this;
}

Quat &Quat::operator-() {
    Quat t = *this;
    t *= -1;
    return t;
}

Quat &Quat::operator=(const Quat &a) {
    lu = a.lu;
    ld = a.ld;
    rd = a.rd;
    ru = a.ru;
}

Quat &Quat::operator+=(const Quat &a) {
    lu += a.lu;
    ld += a.rd;
    ru += a.ru;
    rd += a.rd;
    return *this;
}

Quat &Quat::operator-=(Quat &a) {
    return operator+=(-a);
}

std::ostream &Quat::writeTo(std::ostream &ost) const {
    ost << lu << " " << ru << '\n'
        << ld << " " << rd;
    return ost;
}

std::istream &Quat::readFrom(std::istream &ist) {
    double lun{0.0};
    double run{0.0};
    double ldn{0.0};
    double rdn{0.0};
    if (ist >> lun >> run >> ldn >> rdn) {
        lu = lun;
        ru = run;
        ld = ldn;
        rd = rdn;
    } else
        ist.setstate(std::ios_base::failbit);
    return ist;
}