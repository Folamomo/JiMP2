//
// Created by igor on 08.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <vector>
#include <functional>
#include <ostream>
#include <algorithm>
#include <experimental/optional>


namespace academia {
    class Serializable;
    class Serializer {
    public:
        Serializer(std::ostream* out);

        virtual void IntegerField(const std::string &field_name, int value)=0;
        virtual void DoubleField(const std::string &field_name, double value)=0;
        virtual void StringField(const std::string &field_name, const std::string &value)=0;
        virtual void BooleanField(const std::string &field_name, bool value)=0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value)=0;
        virtual void ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const academia::Serializable>> &value) =0;
        virtual void Header(const std::string &object_name)=0;
        virtual void Footer(const std::string &object_name)=0;

    protected:
        std::ostream *out_;
    };
    class Serializable{
    public:
        virtual void Serialize (academia::Serializer *serializer)=0;
        virtual void Serialize (academia::Serializer *serializer) const =0;

    };

    class XmlSerializer:public Serializer{
    public:
        explicit XmlSerializer(std::ostream *out);

        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;
    };

    class JsonSerializer:public Serializer{
    public:
        explicit JsonSerializer(std::ostream *out);

        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;

    private:
        void Distance();

        bool is_first_=true;

    };

    class Room:public Serializable{
    public:
        void Serialize(Serializer *serializer) override;

        void Serialize(academia::Serializer *serializer) const override;

        enum class Type{
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };
        std::string Type_to_string(Type t) const ;
        Room(int id_, const std::string &name_, Type type_);
        int id_;
        std::string name_;
        Type type_;

    };

    class Building:public Serializable{
    public:
        Building(int id_, const std::string &name_, std::initializer_list<const academia::Room> rooms);

        void Serialize(academia::Serializer *serializer) override;

        void Serialize(academia::Serializer *serializer) const override;

        int Id() const;

        std::vector<std::reference_wrapper<const Serializable>> Reference_vector_to_rooms() const;

        int id_;
        std::string name_;
        std::vector<academia::Room> rooms_;
    };

    class BuildingRepository{
    public:
        BuildingRepository(std::initializer_list<const academia::Building> buildings);
        void Add(const academia::Building new_building);
        void StoreAll(Serializer * serializer);
        std::vector<std::reference_wrapper<const Serializable>> Reference_vector_to_buildings() const;
        std::experimental::optional<Building> operator[](int id) const;
    private:
        std::vector<Building> buildings_;
    };


}

#endif //JIMP_EXERCISES_SERIALIZATION_H
