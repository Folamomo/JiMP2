//
// Created by igor on 26.03.18.
//

#include <vector>
#include <map>
#include <experimental/optional>
#include "SimpleJson.h"

nets::JsonValue::JsonValue() {
    datatype="null";
}

nets::JsonValue::JsonValue(int wartosc) {
    int_=wartosc;
    datatype="int";
}

nets::JsonValue::JsonValue(double wartosc) {
    double_=wartosc;
    datatype="double";
}

nets::JsonValue::JsonValue(const std::string &wartosc) {
    datatype="string";
    str_=wartosc;
}

nets::JsonValue::JsonValue(bool wartosc) {
    datatype="bool";
    bool_=wartosc;
}

nets::JsonValue::JsonValue(const std::vector<nets::JsonValue> &wartosc) {
    datatype="array";
}

nets::JsonValue::JsonValue(const std::map<std::string, nets::JsonValue> &wartosc) {
    datatype="map";
}

std::experimental::optional<nets::JsonValue> nets::JsonValue::ValueByName(const std::string &name) const {
    return std::experimental::optional<nets::JsonValue>();
}

std::string nets::JsonValue::ToString() const {
    if (datatype=="int"){
        return std::to_string(int_);
    } else if (datatype=="double"){
        return std::to_string(double_);
    }else if (datatype=="bool"){
        return bool_ ? "true" : "false";
    }else if (datatype=="null"){
        return "";
    }else if (datatype=="string"){
        return "\""+str_+"\"";
    }else if (datatype==""){
        return std::to_string(0);
    }else if (datatype==""){
        return std::to_string(0);
    }else if (datatype==""){
        return std::to_string(0);
    } else
    return std::__cxx11::string();

}

nets::JsonValue::~JsonValue() {

}


