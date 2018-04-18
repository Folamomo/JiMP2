//
// Created by igor on 17.04.18.
//

#include "Comparable.h"
#include <string>

bool academia::StudentComparator::operator()(const academia::Student &left, const academia::Student &right) {
    return this->IsLess(left, right);

}

bool academia::ByFirstNameAscending::IsLess(const academia::Student &left, const academia::Student &right) {
    return left.FirstName()<right.FirstName();
}

bool academia::ByFirstNameDescending::IsLess(const academia::Student &left, const academia::Student &right) {
    return left.FirstName()>right.FirstName();
}

bool academia::ByLastNameAscending::IsLess(const academia::Student &left, const academia::Student &right) {
    return left.LastName()<right.LastName();
}

bool academia::ByLastNameDescending::IsLess(const academia::Student &left, const academia::Student &right) {
    return left.LastName()>right.LastName();
}

bool academia::ByProgramAscendingEmptyLast::IsLess(const academia::Student &left, const academia::Student &right) {
    if (left.Program()=="")
        return false;
    if (right.Program()=="")
        return true;
    return left.Program()<right.Program();
}

bool academia::ByProgramAscendingEmptyFirst::IsLess(const academia::Student &left, const academia::Student &right) {
    return left.Program()<right.Program();
}
