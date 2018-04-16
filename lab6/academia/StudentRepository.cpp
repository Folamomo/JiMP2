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

bool academia::StudyYear::operator==(academia::StudyYear &other) {
    return year_ == other.year_;
}

bool academia::StudyYear::operator<(academia::StudyYear &other) {
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

academia::StudyYear::operator int() {
    return year_;
}

academia::StudyYear::StudyYear(int year) {
    year_=year;
}

academia::StudyYear::StudyYear() {

}

academia::Student &academia::StudentRepository::operator[](const std::string &id) {
    for(auto& student:students_){
        if (student.GetId()==std::stoi(id)){
            return student;
        }
    }
}

int academia::StudentRepository::StudentCount() {
    return students_.size();
}

int academia::Student::GetId() {
    return id_;
}

std::ostream &academia::operator<<(std::ostream &out, const academia::Student &me) {
    out << "Student {id: „" <<me.id_<<"”, first_name: „" <<me.first_name_<< "”, last_name: „"<<me.last_name_<<
        "”, program: „"<<me.program_<<"”, year: "<<me.year_<<"}";
    return out;
}

academia::Student::Student() {}

