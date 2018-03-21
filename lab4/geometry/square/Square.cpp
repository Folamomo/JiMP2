//
// Created by igor on 20.03.18.
//

#include "Square.h"

namespace geometry {
    Square::Square(const Point &a, const Point &b, const Point &c, const Point &d) {
        std::cout<<a.Distance(b)<<"\t" << b.Distance(d)<<"\t" <<c.Distance(d)<<"\t"<<d.Distance(a)<<"\t"<<a.Distance(c)<<"\t"<<b.Distance(d)<<"\t";
        if (a.Distance(b) == b.Distance(d)&&
            a.Distance(b) == c.Distance(a)&&
            a.Distance(b) == d.Distance(c)&&
            a.Distance(d) == b.Distance(c)){
            a_= a;
            b_= b;
            c_= c;
            d_= d;
            std::cout<<"Kwadrat"<<std::endl;
        } else {
            a_= Point();
            b_= Point();
            c_= Point();
            d_= Point();
            std::cout<<"Nie kwadrat"<<std::endl;
        }

    }

    double Square::Circumference() const {
        return a_.Distance(b_)*4;
    }

    double Square::Area() const {
        return a_.Distance(b_)*a_.Distance(b_);
    }
}