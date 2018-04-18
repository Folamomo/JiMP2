//
// Created by igor on 17.04.18.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <vector>
#include <memory>
#include <random>

namespace arrays {
    class ArrayFill{
    public:
        virtual int Value(int index) const =0;
    };
    void FillArray(size_t size, const ArrayFill& filler, std::vector<int> *v);

    class UniformFill:public ArrayFill{
    public:
        UniformFill(int number=0);
        int Value(int index) const override;
    private:
        int number_;
    };

    class IncrementalFill:public ArrayFill{
    public:
        IncrementalFill(int start=0, int increment=1);
        int Value(int index) const override;
    private:
        int start_;
        int increment_;
    };
    class SquaredFill:public ArrayFill{
    public:
        SquaredFill(int factor =1, int offset=0);
        int Value(int index) const override;
    private:
        int factor_;
        int offset_;
    };
    class RandomFill:public ArrayFill{
    public:
        RandomFill(std::unique_ptr<std::default_random_engine>, std::unique_ptr<std::uniform_int_distribution<int>>);

        int Value(int index) const override;

    private:
        std::unique_ptr<std::default_random_engine> engine_;
        std::unique_ptr<std::uniform_int_distribution<int>> dist_;
    };
}

#endif //JIMP_EXERCISES_ARRAYFILL_H
