//
// Created by igor on 10.04.18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <ostream>
#include <istream>
#include <vector>

namespace academia{
    class StudyYear{
    public:
        StudyYear();
        StudyYear(int year);
        StudyYear operator ++();
        StudyYear operator --();
        bool operator==(StudyYear &other);
        bool operator<(StudyYear &other);
        operator int();
        friend std::ostream& operator << (std::ostream &out, const StudyYear &me);
        friend std::istream& operator >> (std::istream &in, StudyYear &me);

    private:
        int year_;
    };

    std::ostream& operator << (std::ostream &out, const StudyYear &me);
    std::istream& operator >> (std::istream &in, StudyYear &me);

    class Student{
    public:
        Student();
        Student(std::initializer_list);
        int GetId();
        friend  std::ostream & operator << (std::ostream &out, const Student &me);
    private:
        int id_;
        std::string first_name_;
        std::string last_name_;
        std::string program_;
        StudyYear year_;
    };

    std::ostream & operator << (std::ostream &out, const Student &me);

    class StudentRepository{
    public:
        Student & operator [](const std::string &id);
        int StudentCount();
    private:
        std::vector<Student> students_;
    };
}


#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
