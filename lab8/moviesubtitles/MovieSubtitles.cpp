//
// Created by igor on 26.04.18.
//

#include "MovieSubtitles.h"

int str_to_ms(const char* hour, const char* minute, const char* second, const char* milisecond){
    return std::stoi(hour)*3600000+std::stoi(minute)*60000+std::stoi(second)*1000+std::stoi(milisecond);
}

const char* ms_to_string(int time_in_ms){
    std::stringstream out;
    out<<time_in_ms/36000000<<(time_in_ms/3600000)%10<<":"<<(time_in_ms/600000)%6<<(time_in_ms/60000)%10<<":"
       <<(time_in_ms/10000)%6<<(time_in_ms/1000)%10<<","<<(time_in_ms/100)%10<<(time_in_ms/10)%10<<(time_in_ms)%10;
    return out.str().c_str();
}

void moviesubs::MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int framerate,
                                                        std::stringstream* in, std::stringstream* out) {

    if (framerate < 0){
        throw std::invalid_argument("Negative framerate");
    }

    int shift_by=(delay*framerate)/1000;

    std::regex sub_line_regex(R"(\{(-?\d+)\}\{(-?\d+)\}(.+))");
    int line_index=1;

    char line_buffer[1000];

    while(in->getline(line_buffer, 1000)) {
        std::cmatch sub_line;
        if (std::regex_match(line_buffer, sub_line, sub_line_regex)){
            int start_frame = std::stoi(sub_line[1])+shift_by;
            int end_frame = std::stoi(sub_line[2])+shift_by;
            if (start_frame>end_frame){
                throw(SubtitleEndBeforeStart(sub_line[0], line_index));
            }
            if (start_frame < 0){
                throw(NegativeFrameAfterShift(sub_line[0], line_index));
            }
            (*out)<<"{"<<start_frame<<"}{"<<end_frame<<"}"<<sub_line[3]<<"\n";
        } else{
            throw(InvalidSubtitleLineFormat(std::string(line_buffer), line_index));
        }
        ++line_index;
    }
}


moviesubs::SubtitleException::SubtitleException(const std::string &line_content, int line_number): std::invalid_argument{"SubtitleException"}{
    std::stringstream out_stream;
    line_number_=line_number;
    out_stream<<"At line "<<line_number_<<": "<<line_content;
    message_=out_stream.str();
}

int moviesubs::SubtitleException::LineAt() const {
    return line_number_;
}

const char *moviesubs::SubtitleException::what() const noexcept {
    return message_.c_str();
}

moviesubs::NegativeFrameAfterShift::NegativeFrameAfterShift(const std::string &line_content, int line_number)
        : SubtitleException(line_content, line_number) {

}

moviesubs::SubtitleEndBeforeStart::SubtitleEndBeforeStart(const std::string &line_content, int line_number)
        : SubtitleException(line_content, line_number) {

}

moviesubs::InvalidSubtitleLineFormat::InvalidSubtitleLineFormat(const std::string &line_content, int line_number)
        : SubtitleException(line_content, line_number) {

}

moviesubs::OutOfOrderFrames::OutOfOrderFrames(const std::string &line_content, int line_number) : SubtitleException(
        line_content, line_number) {

}

moviesubs::MissingTimeSpecification::MissingTimeSpecification(const std::string &line_content, int line_number)
        : InvalidSubtitleLineFormat(line_content, line_number) {

}

void moviesubs::SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream *in,
                                                     std::stringstream *out) {
    if (framerate < 0){
        throw std::invalid_argument("Negative framerate");
    }

    int shift_by=delay;

    std::regex line_index_regex (R"(\d+)");
    std::regex timings (R"((\d+):([0-5]\d):([0-5]\d),(\d{3}) --> (\d+):([0-5]\d):([0-5]\d),(\d{3}))");

    int line_index=1;
    int internal_index = 0;

    std::string line;

    while(std::getline(*in, line)) {

        const char* line_buffer = line.c_str();
        std::cmatch sub_line;

        if (internal_index==0){
            if (std::regex_match(line_buffer, sub_line, line_index_regex)){
                if (std::stoi(sub_line[0])==line_index){
                    *(out)<<sub_line[0]<<"\n";
                    ++internal_index;
                }
                else throw (OutOfOrderFrames(line_buffer, line_index));
            } else throw (InvalidSubtitleLineFormat(line_buffer, line_index));

        }else if (internal_index==1){
            if (std::regex_match(line_buffer, sub_line, timings)){
                int start_time = str_to_ms(sub_line[1].first, sub_line[2].first, sub_line[3].first, sub_line[4].first)+shift_by;
                int end_time = str_to_ms(sub_line[5].first, sub_line[6].first, sub_line[7].first, sub_line[8].first)+shift_by;
                if (start_time>end_time)
                    throw SubtitleEndBeforeStart(line_buffer, line_index);
                if (start_time<0)
                    throw NegativeFrameAfterShift(line_buffer, line_index);
                *(out)<<ms_to_string(start_time)<<" --> "<<ms_to_string(end_time)<<"\n";
                ++internal_index;
            } else throw MissingTimeSpecification(line_buffer, line_index);
        } else if (line==""){
            *(out)<<"\n";
            internal_index=0;
            ++line_index;
        } else {
            *(out)<<line_buffer<<"\n";
            internal_index++;
        }

    }



}
