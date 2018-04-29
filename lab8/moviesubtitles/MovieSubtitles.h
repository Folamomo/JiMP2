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

    class NegativeFrameAfterShift:public std::exception{

    };

    class SubtitleEndBeforeStart:public std::exception{
    public:
        SubtitleEndBeforeStart(const std::string &line_content, int line_number);
        int LineAt() const;
        const char* what () const noexcept override;
    private:
        std::string message_;
        int line_number_;
    };
    class InvalidSubtitleLineFormat:public std::exception{

    };
}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
