//
// Created by igor on 10.04.18.
//

#include "StudentRepository.h"

academia::StudyYear academia::StudyYear::operator++() {
    year_++;
    return *this;
}

academia::StudyYear academia::StudyYear::operator--() {
    year_--;
    return *this;
}

bool academia::StudyYear::operator==(const academia::StudyYear &other) const{
    return year_ == other.year_;
}

bool academia::StudyYear::operator<(const academia::StudyYear &other) const {
    return year_ < other.year_;
}

std::ostream& academia::operator<<(std::ostream &out, const academia::StudyYear &me) {
    out << me.year_;
    return out;
}

std::istream &academia::operator>>(std::istream &in, academia::StudyYear &me) {
    in >> me.year_;
    return  in;
}


academia::StudyYear::StudyYear(int year) {
    year_=year;
}

academia::StudyYear::StudyYear() {
    year_=1;
}

academia::StudyYear::operator int() const {
    return year_;
}



academia::Student::Student() {}

academia::Student::Student(std::string id, std::string first_name, std::string last_name, std::string program,
                           int year) {
    id_=id;
    first_name_=first_name;
    last_name_=last_name;
    program_=program;
    year_={year};

}

std::string academia::Student::Id() {
    return id_;
}

std::ostream &academia::operator<<(std::ostream &out, const academia::Student &me) {
    out << "Student {id: „" <<me.id_<<"”, first_name: „" <<me.first_name_<< "”, last_name: „"<<me.last_name_<<
        "”, program: „"<<me.program_<<"”, year: "<<me.year_<<"}";
    return out;
}

std::string academia::Student::FirstName() const {
    return first_name_;
}

std::string academia::Student::LastName() const {
    return last_name_;
}

std::string academia::Student::Program() const {
    return program_;
}

academia::StudyYear academia::Student::Year() const {
    return year_;
}

void academia::Student::ChangeLastName(std::string new_name) {
    last_name_=new_name;
}

bool academia::Student::operator==(const academia::Student &other) const {
    return first_name_==other.first_name_&&last_name_==other.last_name_&&id_==other.id_&&program_==other.program_&&year_==other.year_;
}

int academia::StudentRepository::StudentCount() const{
    return students_.size();
}

academia::StudentRepository::StudentRepository(std::initializer_list<Student> list) {
    for (auto& person:list){
        students_.push_back(person);
    }
}

bool academia::StudentRepository::operator==(const academia::StudentRepository &other) const {
    if (this->StudentCount()==other.StudentCount()){
        for (Student student:students_) {
            if (1==0){
                return false;
            }
        }
        return true;
    }
    return false;
}

academia::Student &academia::StudentRepository::operator[](const std::string &id) {
    for(auto& student:students_){
        if (student.Id()==id){
            return student;
        }
    }
}

