//
// Created by igor on 26.05.18.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <string>

namespace academia {
    class TeacherId{
    public:
        explicit TeacherId(int id_);
        operator int () const;
        bool operator != (const TeacherId & other) const;
        bool operator == (const TeacherId & other) const;
    private:
        int id_;
    };

    class Teacher{
    public:
        Teacher(const TeacherId &id_, const std::string &name_, const std::string &department_);

        const TeacherId &Id() const;
        const std::string &Name() const;
        const std::string &Department() const;

        bool operator != (const Teacher& other) const;
        bool operator == (const Teacher& other) const;
    private:
        TeacherId id_;
        std::string name_;
        std::string department_;
    };
    class TeacherHash{
    public:
        size_t operator()(const Teacher & to_hash) const;
    };
}

#endif //JIMP_EXERCISES_TEACHERHASH_H
