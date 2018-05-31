//
// Created by igor on 26.05.18.
//

#include "TeacherHash.h"
#include <functional>

academia::TeacherId::TeacherId(int id_) : id_(id_) {}

academia::TeacherId::operator int() const{
    return id_;
}

bool academia::TeacherId::operator!=(const academia::TeacherId &other) const {
    return id_!= other.id_;
}

bool academia::TeacherId::operator==(const academia::TeacherId &other) const {
    return id_== other.id_;
}

academia::Teacher::Teacher(const academia::TeacherId &id_, const std::string &name_,
                           const std::string &department_) : id_(id_), name_(name_), department_(department_) {}

const academia::TeacherId &academia::Teacher::Id() const {
    return id_;
}

const std::string &academia::Teacher::Name() const {
    return name_;
}

const std::string &academia::Teacher::Department() const {
    return department_;
}

bool academia::Teacher::operator!=(const academia::Teacher &other) const {
    return id_!=other.id_ or name_!=other.name_ or department_!=other.department_;
}

bool academia::Teacher::operator==(const academia::Teacher &other) const {
    return id_==other.id_ and name_==other.name_ and department_==other.department_;
}

size_t academia::TeacherHash::operator()(const academia::Teacher &to_hash) const{
    size_t hash = std::hash<int>()((int)to_hash.Id());
    hash+=hash<<2+std::hash<std::string>()(to_hash.Name());
    hash+=hash<<2+std::hash<std::string>()(to_hash.Department());
    return hash;
}
