//
// Created by igor on 20.03.18.
//

#include "Square.h"

namespace geometry {
    Square::Square(const Point &a, const Point &b, const Point &c, const Point &d) {
        double bok = a.Distance(b);
        if (bok == b.Distance(c)&& bok == c.Distance(d)&& bok == d.Distance(a)&&a.Distance(c) == b.Distance(d)){
            a_= a;
            b_= b;
            c_= c;
            d_= d;
        } else {
            a_= Point();
            b_= Point();
            c_= Point();
            d_= Point();
        }

    }

    double Square::Circumference() const {
        return a_.Distance(b_)*4;
    }

    double Square::Area() const {
        return a_.Distance(b_)*a_.Distance(b_);
    }
}