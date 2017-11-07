#ifndef KIRSANOV_G_V_ARRAY_H
#define KIRSANOV_G_V_ARRAY_H

#include <iostream>

#define T int

class Array {
public:
    Array(int arrsize) : size_(arrsize) {
        pdata_ = new T[arrsize];
    }

    Array() {
        size_ = 0;
        pdata_ = nullptr;
    }

    ~Array() {
        delete[] pdata_;
    }

    const T operator[](const ptrdiff_t i) const;

    T operator[](const ptrdiff_t i);

    T length() const;

private:
    std::ptrdiff_t size_{0};
    T *pdata_{nullptr};
};
T Array::length() const {
    return size_;
}

T Array::operator[](const ptrdiff_t i) {
    return pdata_[i];
}

const T Array::operator[](const int i) const {
    return pdata_[i];
}
#endif //KIRSANOV_G_V_ARRAY_H
