//
// Created by igor on 08.05.18.
//

#include "Serialization.h"

academia::Serializer::Serializer(std::ostream *out) {
    out_=out;
}

academia::XmlSerializer::XmlSerializer(std::ostream *out) : Serializer(out) {

}

void academia::XmlSerializer::IntegerField(const std::string &field_name, int value) {

}

void academia::XmlSerializer::DoubleField(const std::string &field_name, double value) {

}

void academia::XmlSerializer::StringField(const std::string &field_name, const std::string &value) {

}

void academia::XmlSerializer::BooleanField(const std::string &field_name, bool value) {

}

void academia::XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {

}

void academia::XmlSerializer::ArrayField(const std::string &field_name,
                                         const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {

}

void academia::XmlSerializer::Header(const std::string &object_name) {

}

void academia::XmlSerializer::Footer(const std::string &object_name) {

}

academia::JsonSerializer::JsonSerializer(std::ostream *out) : Serializer(out) {

}

void academia::JsonSerializer::IntegerField(const std::string &field_name, int value) {
    *(out_)<<"\""<<field_name<<"\": "<<value<<", ";
}

void academia::JsonSerializer::DoubleField(const std::string &field_name, double value) {
    *(out_)<<"\""<<field_name<<"\": "<<value<<", ";
}

void academia::JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
    *(out_)<<"\""<<field_name<<"\": \""<<value<<"\", ";
}

void academia::JsonSerializer::BooleanField(const std::string &field_name, bool value) {
    *(out_)<<"\""<<field_name<<"\": \"";
    if (value)
        *out_<<"true";
    else
        *out_<<"true";
    *(out_)<<"\", ";
}

void academia::JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
    //Serializer *subserializer =std::make_unique<JsonSerializer>(JsonSerializer(out_));
    //*(out_)<<value.Serialize(subserializer);
}

void academia::JsonSerializer::ArrayField(const std::string &field_name,
                                          const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {

}

void academia::JsonSerializer::Header(const std::string &object_name) {
    *(out_)<<"{";
}

void academia::JsonSerializer::Footer(const std::string &object_name) {
    out_->seekp(out_->tellp()-2);
    *(out_)<<"}";
    out_->put('');
}

academia::Room::Room(int id_, const std::string &name_, academia::Room::Type type_) : id_(id_), name_(name_),
                                                                                      type_(type_) {}

void academia::Room::Serialize(academia::Serializer *serializer) {
    serializer->Header("Room");
    serializer->IntegerField("id", id_);
    serializer->StringField("name", name_);
    serializer->StringField("type", this->Type_to_string(type_));
    serializer->Footer("Room");

}

std::string academia::Room::Type_to_string(academia::Room::Type t) {
    switch (t){
        case Type (0):
            return "COMPUTER_LAB";
        case Type (1):
            return "LECTURE_HALL";
        case Type (2):
            return "CLASSROOM";
    }
    return std::__cxx11::string();
}

void academia::Building::Serialize(academia::Serializer *serializer) {

}

academia::Building::Building(int id_, const std::string &name_,
                             const std::vector<std::reference_wrapper<const academia::Room>> &rooms_) : id_(id_),
                                                                                                        name_(name_),
                                                                                                        rooms_(rooms_) {}
