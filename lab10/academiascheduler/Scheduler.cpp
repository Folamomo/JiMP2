//
// Created by igor on 18.05.18.
//

#include "Scheduler.h"
#include <algorithm>

academia::SchedulingItem::SchedulingItem(int course_id_, int teacher_id_, int room_id_, int time_slot_, int year_)
        : course_id_(course_id_), teacher_id_(teacher_id_), room_id_(room_id_), time_slot_(time_slot_), year_(year_) {}

int academia::SchedulingItem::CourseId() const {
    return course_id_;
}

int academia::SchedulingItem::TeacherId() const {
    return teacher_id_;
}

int academia::SchedulingItem::RoomId() const {
    return room_id_;
}

int academia::SchedulingItem::TimeSlot() const {
    return time_slot_;
}

int academia::SchedulingItem::Year() const {
    return year_;
}

academia::Schedule academia::Schedule::OfTeacher(int teacher_id) const {
    Schedule result;
    std::copy_if(data_.begin(), data_.end(), std::back_inserter(result.data_),
                 [teacher_id](const SchedulingItem &p){ return teacher_id==p.TeacherId();});
    return result;
}

academia::Schedule academia::Schedule::OfRoom(int room_id) const {
    Schedule result;
    std::copy_if(data_.begin(), data_.end(), std::back_inserter(result.data_),
                 [room_id](const SchedulingItem &p){ return room_id==p.RoomId();});
    return result;
}

academia::Schedule academia::Schedule::OfYear(int year) const {
    Schedule result;
    std::copy_if(data_.begin(), data_.end(), std::back_inserter(result.data_),
                 [year](const SchedulingItem &p){ return year==p.Year();});
    return result;
}

std::vector<int> academia::Schedule::AvailableTimeSlots(int n_time_slots) const {
    bool used[n_time_slots];
    for (int i=0; i<n_time_slots; ++i){
        used[i]= false;
    }
    for (const SchedulingItem& item:data_){
        used[item.TimeSlot()-1]= true;
    }
    std::vector<int> result;
    for(int i=0; i<n_time_slots; ++i){
        if (!used[i])
            result.emplace_back(i+1);
    }
    return result;
}

void academia::Schedule::InsertScheduleItem(const academia::SchedulingItem &item) {
    data_.emplace_back(item);
}

size_t academia::Schedule::Size() const {
    return data_.size();
}

academia::SchedulingItem academia::Schedule::operator[](size_t index) const{
    return data_[index];
}

academia::Schedule academia::GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                                 int n_time_slots) {
    Schedule schedule;
        for (const auto &single_teacher:teacher_courses_assignment){
            for(int course:single_teacher.second){
                int year = this->FindYearWithCourse(courses_of_year, course);
                std::pair<int, int> room_and_time = FindRoomAndSlot(schedule, single_teacher.first, rooms, n_time_slots, year);
                schedule.InsertScheduleItem(SchedulingItem(course, single_teacher.first, room_and_time.first,
                                                           room_and_time.second, year));
            }
        }
    return schedule;
}


int academia::GreedyScheduler::FindYearWithCourse(const std::map<int, std::set<int>> &courses_of_year, int course) {
    for(const auto& single_year_courses:courses_of_year){
        if (std::count(single_year_courses.second.begin(), single_year_courses.second.end(), course)){
            return single_year_courses.first;
        }
    }
    throw NoViableSolutionFound();
}

std::pair<int, int> academia::GreedyScheduler::FindRoomAndSlot(const academia::Schedule &schedule, int teacher,
                                                  const std::vector<int> &rooms, int n_time_slots, int year) const {
    std::vector<int> teacher_free_slots;
    teacher_free_slots = schedule.OfTeacher(teacher).AvailableTimeSlots(n_time_slots);
    std::vector<int> year_free_slots;
    year_free_slots = schedule.OfYear(year).AvailableTimeSlots(n_time_slots);
    std::vector<int> both_free_slots;
    std::set_intersection(teacher_free_slots.begin(), teacher_free_slots.end(),
                          year_free_slots.begin(), year_free_slots.end(),
                          std::back_inserter(both_free_slots));

    for (int room:rooms) {
        std::vector<int> room_free_slots;
        room_free_slots = schedule.OfRoom(room).AvailableTimeSlots(n_time_slots);

        std::vector<int> all_free_slots;
        std::set_intersection(both_free_slots.begin(), both_free_slots.end(),
                              room_free_slots.begin(), room_free_slots.end(),
                              std::back_inserter(all_free_slots));
        if(!all_free_slots.empty()){
            return std::make_pair(room, all_free_slots[0]);
        }
    }
    throw NoViableSolutionFound();
}


academia::NoViableSolutionFound::NoViableSolutionFound() {
    message_="Can't find viable solution";
}


const char *academia::NoViableSolutionFound::what() {
    return message_.c_str();
}
