//
// Created by igor on 21.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>

namespace nets {
    class View {
    public:

        View(const std::string &text);

        std::string Render(const std::unordered_map <std::string, std::string> &model) const;
        
    private:
        std::string text_;
    };
}

#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
