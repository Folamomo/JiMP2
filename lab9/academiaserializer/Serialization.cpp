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
    *(out_)<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
}

void academia::XmlSerializer::DoubleField(const std::string &field_name, double value) {
    *(out_)<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
}

void academia::XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
    *(out_)<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
}

void academia::XmlSerializer::BooleanField(const std::string &field_name, bool value) {
    *(out_)<<"<"<<field_name<<">";
    if (value)
        *out_<<"true";
    else
        *out_<<"false";
    *(out_)<<"<\\"<<field_name<<">";
}

void academia::XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
    *(out_)<<"<"<<field_name<<">";
    XmlSerializer sub_serializer(out_);
    value.Serialize(&sub_serializer);
    *(out_)<<"<\\"<<field_name<<">";
}

void academia::XmlSerializer::ArrayField(const std::string &field_name,
                                         const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
    *(out_)<<"<"<<field_name<<">";
    for (auto i : value) {
        XmlSerializer sub_serializer(out_);
        i.get().Serialize(&sub_serializer);
    }
    *(out_)<<"<\\"<<field_name<<">";
}

void academia::XmlSerializer::Header(const std::string &object_name) {
    *(out_)<<"<"<<object_name<<">";
}

void academia::XmlSerializer::Footer(const std::string &object_name) {
    *(out_)<<"<\\"<<object_name<<">";
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
    serializer->Header("room");
    serializer->IntegerField("id", id_);
    serializer->StringField("name", name_);
    serializer->StringField("type", this->Type_to_string(type_));
    serializer->Footer("room");

}

void academia::Room::Serialize(academia::Serializer *serializer) const {
    serializer->Header("room");
    serializer->IntegerField("id", id_);
    serializer->StringField("name", name_);
    serializer->StringField("type", this->Type_to_string(type_));
    serializer->Footer("room");
}


void academia::Building::Serialize(academia::Serializer *serializer) {
    serializer->Header("building");
    serializer->IntegerField("id", id_);
    serializer->StringField("name", name_);
    serializer->ArrayField("rooms", this->Reference_vector_to_rooms());
    serializer->Footer("building");
}

void academia::Building::Serialize(academia::Serializer *serializer) const {
    serializer->Header("building");
    serializer->IntegerField("id", id_);
    serializer->StringField("name", name_);
    serializer->ArrayField("rooms", this->Reference_vector_to_rooms());
    serializer->Footer("building");
}

academia::Building::Building(int id_, const std::string &name_,
                             std::initializer_list<const academia::Room> rooms):id_(id_), name_(name_) {
    for (auto &room:rooms){
        rooms_.emplace_back(room);
    }
}

std::vector<std::reference_wrapper<const academia::Serializable>> academia::Building::Reference_vector_to_rooms() const{
    std::vector<std::reference_wrapper<const academia::Serializable>> result;
    for (auto &room:rooms_) {
        result.emplace_back(std::cref(room));
    }
    return result;
}

int academia::Building::Id() const {
    return id_;
}

academia::BuildingRepository::BuildingRepository(std::initializer_list<const academia::Building> buildings) {
    for (auto &building:buildings){
        buildings_.emplace_back(building);
    }
}

void academia::BuildingRepository::Add(const academia::Building new_building) {
    buildings_.emplace_back(new_building);
}

void academia::BuildingRepository::StoreAll(academia::Serializer *serializer) {
    serializer->Header("building_repository");
    serializer->ArrayField("buildings", this->Reference_vector_to_buildings());
    serializer->Footer("building_repository");
}

std::vector<std::reference_wrapper<const academia::Serializable>>
academia::BuildingRepository::Reference_vector_to_buildings() const {
    std::vector<std::reference_wrapper<const academia::Serializable>> result;
    for (auto &building:buildings_) {
        result.emplace_back(std::cref(building));
    }
    return result;
}

std::experimental::optional<academia::Building> academia::BuildingRepository::operator[](int id) const{
    for (auto building:buildings_){
        if(building.Id()==id){
            return building;
        }
    }
}
