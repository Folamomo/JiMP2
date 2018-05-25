//
// Created by igor on 22.05.18.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

namespace factoryMethod {

    class MyType{
    public:
        MyType()= default;
        std:: string SayHello();
    };

template <class myclass> myclass Create(){
    return myclass();
}

}

#endif //JIMP_EXERCISES_FACTORYMETHOD_H
