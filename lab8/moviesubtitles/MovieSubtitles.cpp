//
// Created by igor on 26.04.18.
//

#include "MovieSubtitles.h"

void moviesubs::MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int framerate,
                                                        std::stringstream* in, std::stringstream* out) {
    std::regex sub_line_regex(R"(\{(-?\d+)\}\{(-?\d+)\}(.+))");
    if (framerate < 0){
        throw std::invalid_argument("Negative framerate");
    }
    int shift_by=(delay*framerate)/1000;
    int line_index=1;
    char line_buffer[1000];
    while(in->getline(line_buffer, 1000)) {
        std::cmatch sub_line;
        if (std::regex_match(line_buffer, sub_line, sub_line_regex)){
            int start_frame = std::stoi(sub_line[1])+shift_by;
            int end_frame = std::stoi(sub_line[2])+shift_by;
            if (start_frame<end_frame){
                //TODO: throw(SubtitleEndBeforeStart);
            }
            if (start_frame < 0){
                //TODO: throw(NegativeFrameAfterShift);
            }
            (*out)<<"{"<<start_frame<<"}{"<<end_frame<<"}"<<sub_line[3]<<"\n";
        } else{
            //TODO: throw(InvalidSubtitleLineFormat);
        }
        ++line_index;
    }
}
