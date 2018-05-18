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
