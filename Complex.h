#include <iostream>
#include <cmath>

template<typename T>

class Complex {

private:
    T real;
    T imag;

public:
    Complex() : real(0), imag(0) {}

    Complex(T r, T i) : real(r), imag(i) {}

    T getReal() const {
        return real;
    }

    T getImag() const {
        return imag;
    }

    void setReal(T r) {
        real = r;
    }

    void setImag(T i) {
        imag = i;
    }

    Complex<T> operator+(const Complex<T> &other) const {
        return Complex<T>(real + other.real, imag + other.imag);
    }

    Complex<T> operator-(const Complex<T> &other) const {
        return Complex<T>(real - other.real, imag - other.imag);
    }

    Complex<T> operator*(const Complex<T> &other) const {
        return Complex<T>(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    Complex<T> operator/(const Complex<T> &other) const {
        T denominator = other.real * other.real + other.imag * other.imag;

        if (denominator == 0) {
            throw std::runtime_error("Division by zero");
        }

        return Complex<T>((real * other.real + imag * other.imag) / denominator,
                          (imag * other.real - real * other.imag) / denominator);
    }

    bool operator==(const Complex<T> &other) const {
        return (real == other.real) && (imag == other.imag);
    }

    bool operator==(T num) const {
        return (real == num) && (imag == 0);
    }

    Complex<T> pow(int n) const {
        T r = std::pow(std::sqrt(real * real + imag * imag), n);
        T phi = std::atan2(imag, real);
        return Complex<T>(r * std::cos(n * phi), r * std::sin(n * phi));
    }

    T abs() const {
        return std::sqrt(real * real + imag * imag);
    }

    friend std::ostream &operator<<(std::ostream &os, const Complex<T> &c) {
        os << "(" << c.real << ", " << c.imag << "i)";
        return os;
    }
};