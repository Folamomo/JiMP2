//
// Created by igor on 30.03.18.
//

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
    data_=new comp [dimx*dimy];
}

algebra::Matrix::Matrix(const std::string &datastring) {

}

algebra::Matrix::Matrix(const algebra::Matrix &other) {
    dimy_=other.dimy_;
    dimx_=other.dimx_;
    data_=new comp [dimx_*dimy_];
    for (int i = 0; i < dimy_ * dimy_; ++i) {
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
    for (int i = 0; i < dimy_ * dimy_; ++i) {
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
    std::string result="[";
    for (int i = 0; i < dimy_*dimx_; ++i) {
        result+=std::to_string(data_[i].real())+", ";
    }
    result+="]";
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
    return algebra::Matrix();
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
    return algebra::Matrix();
}
