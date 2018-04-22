//
// Created by igor on 21.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include <utility>
#include <string>
#include <vector>
#include <memory>

namespace utility {
    class IterableIterator {
    public:

        virtual std::pair<int, std::string> Dereference() const =0;

        virtual IterableIterator &Next() =0;

        virtual bool NotEquals(const std::unique_ptr<IterableIterator> &other) const =0;

        virtual ~IterableIterator() = default;

        std::vector<int>::const_iterator left_;
        std::vector<std::string>::const_iterator right_;
    };

    class ZipperIterator : public IterableIterator {
    public:
        explicit ZipperIterator(std::vector<int>::const_iterator left,
                                std::vector<std::string>::const_iterator right,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end);

        explicit ZipperIterator(std::vector<int>::const_iterator left,
                                std::vector<std::string>::const_iterator right);

        std::pair<int, std::string> Dereference() const override;

        IterableIterator &Next() override;

        bool NotEquals(const std::unique_ptr<IterableIterator> &other) const override;


    };


    class IterableIteratorWrapper{
    public:
        explicit IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator);
        bool operator!=(const IterableIteratorWrapper &other) const;
        std::pair<int, std::string> operator*() const;
        IterableIteratorWrapper &operator++();
    private:
        std::unique_ptr<IterableIterator> iterator_;
    };

    class Iterable{
    public:
        virtual std::unique_ptr<IterableIterator> ConstBegin() const =0;
        virtual std::unique_ptr<IterableIterator> ConstEnd() const =0;
        IterableIteratorWrapper cbegin() const;
        IterableIteratorWrapper cend() const;
        IterableIteratorWrapper begin() const;
        IterableIteratorWrapper end() const;
        std::vector<int> vi_;
        std::vector<std::string> vs_;
    };

    class Zipper: public Iterable {
    public:

        Zipper(std::vector<int> vi, std::vector<std::string> vs);
        std::unique_ptr<IterableIterator> ConstBegin() const override;

        std::unique_ptr<IterableIterator> ConstEnd() const override;
    };

    class Enumerate: public Iterable {
    public:

        explicit Enumerate(std::vector<std::string> vs);
        std::unique_ptr<IterableIterator> ConstBegin() const override;

        std::unique_ptr<IterableIterator> ConstEnd() const override;
    };

    class Product: public Iterable {
    public:

        Product(std::vector<int> vi, std::vector<std::string> vs);
        std::unique_ptr<IterableIterator> ConstBegin() const override;

        std::unique_ptr<IterableIterator> ConstEnd() const override;
    };
}


#endif //JIMP_EXERCISES_ITERABLE_H
