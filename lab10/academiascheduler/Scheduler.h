//
// Created by igor on 18.05.18.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H


#include <vector>
#include <map>
#include <set>
#include <exception>

namespace academia{
    class SchedulingItem {
    public:
        SchedulingItem(int course_id_, int teacher_id_, int room_id_, int time_slot_, int year_);

        int CourseId() const;
        int TeacherId() const;
        int RoomId() const;
        int TimeSlot() const;

        int Year() const;

    private:
        int course_id_;
        int teacher_id_;
        int room_id_;
        int time_slot_;
        int year_;
    };
    class Schedule{
    public:
        Schedule OfTeacher(int teacher_id) const ;
        Schedule OfRoom(int room_id) const ;
        Schedule OfYear(int year) const ;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const ;
        void InsertScheduleItem(const SchedulingItem &item);
        size_t Size() const;
        SchedulingItem operator[](size_t index) const ;

        std::vector<SchedulingItem> data_;
    };

    class Scheduler {
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year,
                                    int n_time_slots)= 0;

    };
    class NoViableSolutionFound :public std::exception{

    };
}


#endif //JIMP_EXERCISES_SCHEDULER_H
