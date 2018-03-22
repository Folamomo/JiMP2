//
// Created by igor on 21.03.18.
//

#include "SimpleTemplateEngine.h"
#include <vector>

nets::View::View(const std::string &text) {
    text_=text;
}

std::string nets::View::Render(const std::unordered_map<std::string, std::string> &model) const {
    std::string output;
    std::vector<char> c_text(text_.c_str(), text_.c_str() + text_.size() + 1);
    for (char character : c_text){

    }
    return output;
}
