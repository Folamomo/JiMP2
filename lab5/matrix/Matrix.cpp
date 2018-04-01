//
// Created by igor on 30.03.18.
//

#include <sstream>
#include "Matrix.h"


using comp=std::complex<double>;

algebra::Matrix::Matrix() {
    dimx_=0;
    dimy_=0;
    data_= nullptr;
}

algebra::Matrix::Matrix(size_t dimx, size_t dimy) {
    dimx_=dimx;
    dimy_=dimy;
    data_=new comp [dimx_*dimy_];
}

algebra::Matrix::Matrix(const std::string &datastring) {

}

algebra::Matrix::Matrix(const algebra::Matrix &other) {
    dimy_=other.dimy_;
    dimx_=other.dimx_;
    data_=new comp [dimx_*dimy_];
    for (int i = 0; i < dimx_ * dimy_; ++i) {
        data_[i]=other.data_[i];
    }
}

algebra::Matrix &algebra::Matrix::operator=(const algebra::Matrix &other) {
    if (this == &other) {
        return *this;
    }
    delete[] data_;
    dimy_=other.dimy_;
    dimx_=other.dimx_;
    data_=new comp [dimx_*dimy_];
    for (int i = 0; i < dimx_ * dimy_; ++i) {
        data_[i]=other.data_[i];
    }
}

algebra::Matrix::Matrix(const std::initializer_list<std::vector<std::complex<double>>> &elements) {
    dimy_=elements.size();
    dimx_=elements.begin()->size();
    data_=new comp [dimx_*dimy_];
    int i=0;
    for(auto row:elements){
        for (auto value:row){
            data_[i]=value;
            i++;
        }
    }
}

algebra::Matrix::~Matrix() {
    delete [] data_;
}

std::complex<double> algebra::Matrix::at(size_t x, size_t y) const {
    return data_[y*dimx_+x];
}

std::pair<size_t, size_t> algebra::Matrix::Size() const {
    return std::make_pair(dimx_, dimy_);
}

void algebra::Matrix::set(std::complex<double> value, size_t x, size_t y) {
    data_[y*dimx_+x]=value;
}

std::string algebra::Matrix::Print() const{
    std::ostringstream result;
    result<<"[";
    for (int i = 0; i < dimy_*dimx_; ++i) {
        result<<data_[i].real()<<"i"<<data_[i].imag();
        if (i!=dimy_*dimx_-1) {
            if ((i + 1) % dimx_ == 0)
                result << "; ";
            else
                result << ", ";
        }
    }
    result << "]";
    return result.str();
}

algebra::Matrix algebra::Matrix::Add(const algebra::Matrix &other) const{
    if (this->Size()!=other.Size()){
        return Matrix();
    }
    Matrix sum (dimx_, dimy_);
    for (int i = 0; i < dimx_*dimy_; ++i) {
        sum.data_[i]=data_[i]+other.data_[i];
    }
    return sum;
}

algebra::Matrix algebra::Matrix::Sub(const algebra::Matrix &other) const {
    if (this->Size()!=other.Size()){
        return Matrix();
    }
    Matrix sum (dimx_, dimy_);
    for (int i = 0; i < dimx_*dimy_; ++i) {
        sum.data_[i]=data_[i]-other.data_[i];
    }
    return sum;
}

algebra::Matrix algebra::Matrix::Mul(const algebra::Matrix &other) const {
    if (dimx_!=other.dimy_) {
        return algebra::Matrix();
    }
    Matrix result=Matrix(other.dimx_, dimy_);
    for (int j = 0; j < dimy_; ++j) {
        for (int i = 0; i < other.dimx_; ++i) {
            comp sum = 0.0;
            for (int k = 0; k < dimx_; ++k) {
                sum+=this->at(k, j)*other.at(i, k);
            }
            result.set(sum, i, j);
        }
    }
    return result;
}

algebra::Matrix algebra::Matrix::Mul(std::complex<double> &factor) const {
    Matrix result (dimx_, dimy_);
    for (int i = 0; i < dimx_*dimy_; ++i) {
        result.data_[i]=data_[i]*factor;
    }
    return result;
}

algebra::Matrix algebra::Matrix::Div(const algebra::Matrix &other) const {
    return algebra::Matrix();
}

algebra::Matrix algebra::Matrix::Div(std::complex<double> &factor) const {
    Matrix result (dimx_, dimy_);
    for (int i = 0; i < dimx_*dimy_; ++i) {
        result.data_[i]=data_[i]/factor;
    }
    return result;
}

algebra::Matrix algebra::Matrix::Pow(int exponent) const {
    if (dimx_!=dimy_){
            return Matrix();
    }
    if (exponent==0){
        Matrix newmatrix=Matrix(dimx_, dimy_);
        for (int i = 0; i < dimx_; ++i) {
            for (int j = 0; j < dimy_; ++j){
                if (i==j)
                    newmatrix.set(std::complex<double>(1.0), i, j);
                else
                    newmatrix.set(std::complex<double>(0.0), i, j);
            }
        }
        return newmatrix;
    }
    if (exponent>0){
        Matrix newmatrix (*this);
        for (int i = 1; i < exponent; ++i) {
            newmatrix = newmatrix.Mul(*this);
        }
        return newmatrix;
    }
    return Matrix();
}
