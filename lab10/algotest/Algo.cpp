//
// Created by igor on 15.05.18.
//

#include "Algo.h"
#include <numeric>
#include <utility>

std::set<std::string> algo::Keys(const std::map<std::string, int> &m) {
    std::set<std::string> result;
    std::transform(m.begin(),m.end(),std::inserter(result, result.begin()), [](const auto &p){ return p.first;});
    return result;
}

std::vector<int> algo::Values(const std::map<std::string, int> &m) {
    std::vector<int> result;
    std::transform(m.begin(),m.end(),std::inserter(result, result.begin()), [](const auto &p){ return p.second;});
    return result;
}

std::vector<int> algo::DivisableBy(const std::vector<int> &m, int divisor) {
    std::vector<int> result;
    std::copy_if(m.begin(),m.end(),std::back_inserter(result), [](const auto &p, int divisor){ return p%divisor==0;});
    return result;
}

void algo::SortInPlace(std::vector<int> *v) {
    std::sort(v->begin(),v->end());
}

std::vector<int> algo::Sort(const std::vector<int> &v) {
    std::vector<int> result;
    std::copy(v.begin(),v.end() , std::back_inserter(result));
    std::sort(result.begin(),result.end());
    return result;
}

void algo::SortByFirstInPlace(std::vector<std::pair<int, int>> *v) {
    std::sort(v->begin(),v->end(),[](const auto &l, const auto &r){return l.first<r.first;});
}

void algo::SortBySecondInPlace(std::vector<std::pair<int, int>> *v) {
    std::sort(v->begin(),v->end(),[](const auto &l, const auto &r){return l.second<r.second;});
}

void algo::SortByThirdInPlace(std::vector<std::tuple<int, int, int>> *v) {
    std::sort(v->begin(),v->end(),[](const auto &l, const auto &r){return std::get<3>&l < std::get<3>&r;});
}

std::vector<std::string> algo::MapToString(const std::vector<double> &v) {
    std::vector<std::string> result;
    std::transform(v.begin(),v.end(),std::inserter(result, result.begin()), [](double p){ return std::to_string(p);});
    return result;
}

std::string algo::Join(const std::string &joiner, const std::vector<double> &v) {
    return "";
}

int algo::Sum(const std::vector<int> &v) {
    int result=0;
    std::accumulate(v.begin(),v.end(), result);
    return result;
}

int algo::Product(const std::vector<int> &v) {
    int result=0;
    std::accumulate(v.begin(),v.end(), result,[](int x, int y){return x*y;});
    return result;
}

bool algo::Contains(const std::vector<int> &v, int element) {
    return v.end()!=std::find(v.begin(), v.end(), element);
}

bool algo::ContainsKey(const std::map<std::string, int> &v, const std::string &key) {
    return 0!=v.count(key);
}

bool algo::ContainsValue(const std::map<std::string, int> &v, int value) {

}

std::vector<std::string> algo::RemoveDuplicates(const std::vector<std::string> &v) {
    return std::vector<std::string>();
}

void algo::RemoveDuplicatesInPlace(std::vector<std::string> *v) {

}

void algo::InitializeWith(int initial_value, std::vector<int> *v) {
    std::cge(v.begin(), n_elements, std::back_inserter(*out));
}

std::vector<int> algo::InitializedVectorOfLength(int length, int initial_value) {
    return std::vector<int>();
}

void algo::CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {
    std::copy_n(v.begin(), n_elements, std::back_inserter(*out));
}

int algo::HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length) {
    return 0;
}
