//
// Created by igor on 24.04.18.
//

#include "Pesel.h"

academia::AcademiaDataValidationError::AcademiaDataValidationError(const std::string &message)
        : std::runtime_error(message) {}

academia::InvalidPeselChecksum::InvalidPeselChecksum(const std::string &message)
        : AcademiaDataValidationError(message) {}

academia::InvalidPeselLength::InvalidPeselLength(const std::string &message)
        : AcademiaDataValidationError(message) {}

academia::InvalidPeselCharacter::InvalidPeselCharacter(const std::string &message)
        : AcademiaDataValidationError(message) {}

academia::Pesel::Pesel(const std::string &input) {
    validatePesel(input);
    data_=input;
}

void academia::Pesel::validatePesel(const std::string &input) {
    if (input.length()!=11) {
        throw InvalidPeselLength(input);
    }
    std::smatch s;
    std::regex pattern (R"(\d{11})");
    if (!std::regex_match(input, s, pattern)){
        throw InvalidPeselCharacter(input);
    }
    int digits [11];
    for (int i=0; i<11; i++){
        digits[i]=input[i]-'0';
    }
    int checksum=(9*digits[0] + 7*digits[1] + 3*digits[2] + 1*digits[3] + 9*digits[4] + 7*digits[5] + 3*digits[6]
    + 1*digits[7] + 9*digits[8] + 7*digits[9])%10;
    if(checksum!=digits[10]){
        throw InvalidPeselChecksum("Invalid PESEL("+input+ ") checksum: "+std::to_string(digits[10]));
    }

}
