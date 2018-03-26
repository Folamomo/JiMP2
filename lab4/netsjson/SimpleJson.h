//
// Created by igor on 26.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>

namespace nets {
    class JsonValue {
    public:
        JsonValue();
        JsonValue(int wartosc);
        JsonValue(double wartosc);
        JsonValue(const std::string &wartosc);
        JsonValue(bool wartosc);
        JsonValue(const std::vector<JsonValue> &wartosc);
        JsonValue(const std::map<std::string, nets::JsonValue> &wartosc);

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;

        std::string ToString() const;

        ~JsonValue();

        std::string datatype;

        int int_;
        double double_;
        std::string str_;
        bool bool_;
        std::vector<JsonValue> vector_;
        std::map<std::string, JsonValue> map_;
    };
}


#endif //JIMP_EXERCISES_SIMPLEJSON_H
