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
        bool operator==(const StudyYear &other)const;
        bool operator<(const StudyYear &other)const;
        operator int()const ;
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
        Student(std::string id, std::string first_name, std::string last_name, std::string program, int year);

        std::string Id();
        std::string FirstName()const;
        std::string LastName()const;
        std::string Program()const;
        academia::StudyYear Year()const;

        void ChangeLastName(std::string new_name);

        bool operator == (const academia::Student &other)const;
        friend std::ostream & operator << (std::ostream &out, const Student &me);
    private:
        std::string id_;
        std::string first_name_;
        std::string last_name_;
        std::string program_;
        StudyYear year_;
    };

    std::ostream & operator << (std::ostream &out, const Student &me);

    class StudentRepository{
    public:
        StudentRepository(std::initializer_list<Student>list);
        bool operator == (const academia::StudentRepository &other)const;
        Student & operator [](const std::string &id);
        int StudentCount() const;
    private:
        std::vector<Student> students_;
    };
}


#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
