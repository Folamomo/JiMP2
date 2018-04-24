//
// Created by igor on 24.04.18.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>
#include <stdexcept>
#include <regex>

namespace academia {
    class Pesel {
    public:
        Pesel(const std::string &input);
        void validatePesel(const std::string &input);

    private:
        std::string data_;
    };
    class AcademiaDataValidationError:public std::runtime_error{
    public:
        AcademiaDataValidationError (const std::string &message);
    };

    class InvalidPeselChecksum : public AcademiaDataValidationError {
    public:
        InvalidPeselChecksum(const std::string &message);
    };
    class InvalidPeselLength : public AcademiaDataValidationError {
    public:
        InvalidPeselLength(const std::string &message);
    };
    class InvalidPeselCharacter : public AcademiaDataValidationError{
    public:
        InvalidPeselCharacter(const std::string &message);
    };

}

#endif //JIMP_EXERCISES_PESEL_H
