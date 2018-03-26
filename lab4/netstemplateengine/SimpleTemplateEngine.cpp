//
// Created by igor on 21.03.18.
//

#include "SimpleTemplateEngine.h"
#include <vector>
#include <regex>

nets::View::View(const std::string &text) {
    text_=text;
}

std::string nets::View::Render(const std::unordered_map<std::string, std::string> &model) const {
    std::string output = text_;
    std::regex curlies ("\\{\\{\\w+\\}\\}");
    for (const auto& key : model){
        std::string replacement = key.second;
        if(std::regex_match(replacement, curlies)){
            continue;
        }
        std::regex to_replace ("\\{\\{"+key.first +"\\}\\}");
        output=std::regex_replace (output, to_replace, replacement);
    }
    output=std::regex_replace (output, curlies, "");
    return output;
}
