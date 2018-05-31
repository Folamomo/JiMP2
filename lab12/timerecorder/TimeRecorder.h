//
// Created by igor on 25.05.18.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <vector>
#include <chrono>

namespace profiling{
    template <class T>
    auto TimeRecorder(T to_measure){
        auto start = std::chrono::high_resolution_clock::now();
        auto value = to_measure();
        auto end = std::chrono::high_resolution_clock::now();
        double duration = std::chrono::duration<double, std::milli> (end - start).count();
        return std::make_pair(value, duration);
    };
}


#endif //JIMP_EXERCISES_TIMERECORDER_H
