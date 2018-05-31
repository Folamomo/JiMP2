//
// Created by igor on 25.05.18.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H


template <class C, typename T>
class SequentialIdGenerator{
public:
    SequentialIdGenerator(){
        counter_=T(0);
    }
    SequentialIdGenerator(T init){
        counter_=init;
    }
    C NextValue(){
        C val (counter_);
        ++counter_;
        return val;
    }

private:
    T counter_;
};


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
