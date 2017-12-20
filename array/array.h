#ifndef KIRSANOV_G_V_ARRAY_H
#define KIRSANOV_G_V_ARRAY_H

#include <iostream>


template <typename T>
class Array {
public:
    explicit Array(int arrsize) : size_(arrsize)
    {
        pdata_ = new T[size_];
    }
    Array()
    {
        size_ = 0;
        pdata_ = nullptr;
    }
    ~Array()
    {
        delete[] pdata_;
    }
    Array(const Array<T>& ex):size_(ex.size_)
    {
        pdata_ = new T[size_];
        for (ptrdiff_t i = 0; i < size_; i += 1){
            pdata_[i] = ex[i];
        }
    }
    Array(const int size, const T data):size_(size)
    {
        pdata_ = new T[size_];
        for (ptrdiff_t i = 0; i < size_; i+=1){
            pdata_[i] = data;
        }
    }
    T& operator[](const ptrdiff_t i) const;
    T& operator[](const ptrdiff_t i);
    Array<T>& operator=(const Array<T> rhs);
    void resize(int newsize);
    void push_back(const T& rhs);
    void pop_back();
    const ptrdiff_t length() const;
    std::ostream &writeTo(std::ostream &ost) const;
private:
    std::ptrdiff_t size_{0};
    T *pdata_{nullptr};
};

template <typename T>
inline std::ostream &operator<<(std::ostream &ost, Array<T> &rhs) {
    return rhs.writeTo(ost);
}

template <typename T>
std::ostream& Array<T>::writeTo(std::ostream &ost) const
{
    for (ptrdiff_t i = 0; i < size_; i += 1) {
        ost << pdata_[i] << " \n"[i == size_ - 1];
    }
    return ost;
}

template <typename T>
const ptrdiff_t Array<T>::length() const
{
    return size_;
}

template <typename T>
T& Array<T>::operator[](const ptrdiff_t i) const
{
    return pdata_[i];
}

template <typename T>
T& Array<T>::operator[](const ptrdiff_t i)
{
    return pdata_[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> rhs)
{
    size_ = rhs.size_;
    pdata_ = new T[size_];
    for (ptrdiff_t i = 0; i < size_; i += 1) {
        pdata_[i] = rhs[i];
    }
    return *this;
}

template <typename T>
void Array<T>::push_back(const T &rhs)
{
    this->resize(++size_);
    pdata_[size_ - 1] = rhs;
}

template <typename T>
void Array<T>::pop_back()
{
    this->resize(--size_);
}

template<typename T>
void Array<T>::resize(int newsize)
{
    Array res = *this;
    delete[] pdata_;
    size_ = newsize;
    pdata_= new T[size_];
    int len = std::min(res.size_, size_);
    for (ptrdiff_t i = 0; i < len; i+=1){
        pdata_[i] = res.pdata_[i];
    }
    for (ptrdiff_t i = len; i < size_; i += 1){
        pdata_[i] = 0;
    }
    return;
}

template <typename T>
void CopyTo(Array<T>& CopyTo, const Array<T>& CopyFrom)
{
    if (CopyFrom.length() > CopyTo.length()) {
        CopyTo.resize(CopyFrom.length());
    }
    CopyTo = CopyFrom;
}
#endif //KIRSANOV_G_V_ARRAY_H