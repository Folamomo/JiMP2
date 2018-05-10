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
    this->Distance();
    *(out_)<<"\""<<field_name<<"\": "<<value;
}

void academia::JsonSerializer::DoubleField(const std::string &field_name, double value) {
    this->Distance();
    *(out_)<<"\""<<field_name<<"\": "<<value;
}

void academia::JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
    this->Distance();
    *(out_)<<"\""<<field_name<<"\": \""<<value<<"\"";
}

void academia::JsonSerializer::BooleanField(const std::string &field_name, bool value) {
    this->Distance();
    *(out_)<<"\""<<field_name<<"\": \"";
    if (value)
        *out_<<"true";
    else
        *out_<<"false";
    *(out_)<<"\"";
}

void academia::JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
    this->Distance();
    *(out_)<<"\""<<field_name<<"\": \"";
    JsonSerializer sub_serializer(out_);
    value.Serialize(&sub_serializer);
}

void academia::JsonSerializer::ArrayField(const std::string &field_name,
                                          const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
    this->Distance();
    *(out_)<<"\""<<field_name<<"\": [";
    if (!value.empty()){
        JsonSerializer sub_serializer(out_);
        value[0].get().Serialize(&sub_serializer);
    }
    for (int i=1;i<value.size();++i){
        JsonSerializer sub_serializer(out_);
        *(out_)<<", ";
        value[i].get().Serialize(&sub_serializer);
    }
    *(out_)<<"]";
}

void academia::JsonSerializer::Header(const std::string &object_name) {
    *(out_)<<"{";
    is_first_= true;
}

void academia::JsonSerializer::Footer(const std::string &object_name) {
    *(out_)<<"}";
}

void academia::JsonSerializer::Distance() {
    if(is_first_){
        is_first_= false;
    } else {
        *out_<<", ";
    }
}

academia::Room::Room(int id_, const std::string &name_, academia::Room::Type type_) : id_(id_), name_(name_),
                                                                                      type_(type_) {}

std::string academia::Room::Type_to_string(academia::Room::Type t) const{
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

void academia::Room::Serialize(academia::Serializer *serializer) {
    serializer->Header("Room");
    serializer->IntegerField("id", id_);
    serializer->StringField("name", name_);
    serializer->StringField("type", this->Type_to_string(type_));
    serializer->Footer("Room");

}

void academia::Room::Serialize(academia::Serializer *serializer) const {
    serializer->Header("Room");
    serializer->IntegerField("id", id_);
    serializer->StringField("name", name_);
    serializer->StringField("type", this->Type_to_string(type_));
    serializer->Footer("Room");
}

void academia::Building::Serialize(academia::Serializer *serializer) {
    serializer->Header("Building");
    serializer->IntegerField("id", id_);
    serializer->StringField("name", name_);
    serializer->ArrayField("rooms", rooms_);
    serializer->Footer("Building");
}

academia::Building::Building(int id_, const std::string &name_,
                             const std::vector<std::reference_wrapper<const academia::Serializable>> &rooms_) : id_(id_),
                                                                                                        name_(name_),
                                                                                                        rooms_(rooms_) {}

void academia::Building::Serialize(academia::Serializer *serializer) const {
    serializer->Header("Building");
    serializer->IntegerField("id", id_);
    serializer->StringField("name", name_);
    serializer->ArrayField("rooms", rooms_);
    serializer->Footer("Building");
}
