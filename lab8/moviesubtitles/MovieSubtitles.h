//
// Created by igor on 26.04.18.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <regex>
#include <string>
#include <stdexcept>
#include <iostream>

namespace moviesubs {
    class MicroDvdSubtitles{
    public:
        void ShiftAllSubtitlesBy(int delay, int framerate,
                                 std::stringstream* in, std::stringstream* out);
    };
}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
