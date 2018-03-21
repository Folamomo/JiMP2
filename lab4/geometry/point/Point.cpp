//
// Created by igor on 20.03.18.
//


#include <cmath>
#include <iostream>
#include "Point.h"

namespace geometry {

    using ::std::ostream;
    using ::std::cout;
    using ::std::endl;
    using ::std::pow;
    using ::std::sqrt;


    Point::Point() : x_(0), y_(0) {
    }

    Point::Point(double x, double y) {
        x_ = x;
        y_ = y;
    }

    Point::~Point() {

    }

    double Point::Distance(const Point &other) const {
        return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2));
    }

    void Point::ToString(ostream *out) const {
        (*out) << "(" << GetX() << ";" << GetY() << ")";
    }

    double Point::GetX() const {
        return x_;
    }

    double Point::GetY() const {
        return y_;
    }

    void Point::SetX(double x) {
        x_=x;
    }

    void Point::SetY(double y) {
        y_=y;
    }

}