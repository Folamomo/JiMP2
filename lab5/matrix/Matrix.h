//
// Created by igor on 30.03.18.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <complex>
#include <initializer_list>
#include <vector>

namespace algebra {
    class Matrix {
    public:
        Matrix();
        Matrix(size_t dimx, size_t dimy);
        Matrix(const std::initializer_list<std::vector<std::complex<double>>> &elements);
        explicit Matrix (const std::string &datastring);
        Matrix(const Matrix &other);
        Matrix &operator=(const Matrix &other);
        ~Matrix();

        std::complex<double> at(size_t x, size_t y) const;
        std::pair<size_t ,size_t > Size () const;
        void set (std::complex<double> value, size_t x, size_t y);

        Matrix Add(const Matrix &other) const;
        Matrix Sub(const Matrix &other) const;
        Matrix Mul(const Matrix &other) const;
        Matrix Mul(std::complex<double> &factor) const;
        Matrix Div(const Matrix &other) const;
        Matrix Div(std::complex<double> &factor) const;
        Matrix Pow(int exponent) const;

        std::string Print() const;

    private:
        size_t dimx_;
        size_t dimy_;
        std::complex<double> *data_;
    };
}



#endif //JIMP_EXERCISES_MATRIX_H
