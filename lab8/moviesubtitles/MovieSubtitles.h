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

    class SubtitleLine{
        virtual bool ExtractOneLine(std::stringstream* in)=0;
        virtual void InsertOneLine(std::stringstream* out)=0;
        int start_time_;
        int end_time_;
        std::string text_;
        int linenumber_;
    };

    class MovieSubtitles{
    public:
        void ShiftAllSubtitlesBy(int delay, int framerate,
                                 std::stringstream* in, std::stringstream* out);
        std::regex any_line_regex_;
        std::regex correct_line_regex_;
    };

    class MicroDvdSubtitles:public MovieSubtitles{
    public:
        MicroDvdSubtitles();
        void ShiftAllSubtitlesBy(int delay, int framerate,
                                 std::stringstream* in, std::stringstream* out);
    };



    //Errors

    class SubtitleException : public std::invalid_argument{
        SubtitleException
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

    class OutOfOrderFrames:public std::exception{

    };

    class MissingTimeSpecification{};
}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
