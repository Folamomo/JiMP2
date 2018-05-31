//
// Created by igor on 22.05.18.
//

#ifndef JIMP_EXERCISES_TEMPLATES_H
#define JIMP_EXERCISES_TEMPLATES_H

#include <vector>
#include <algorithm>
#include <numeric>

namespace mytemplates {

    template<typename T>auto Value(const T& p){
        return *(p);
    }

    template <class T>
    class Repository{
    public:
        Repository(std::vector <T> data){
            objects_=data;
        }
        size_t Size(){
            return objects_.size();
        }

        T operator [](size_t index){
            return objects_[index];
        }

        long NextId(){
            return ++last_id_;
        }

        std::vector<T> MyFindBy (bool (*Query)(T)){
            std::vector<T> result;
            std::copy_if(objects_.begin(),objects_.end(),std::back_inserter(result), [Query](const T& o){ return Query(o);});
            return result;
        }
    private:
        long last_id_;
        std::vector<T> objects_;
    };

    template <typename T> T Mean(std::vector<T> data){
        T sum = std::accumulate(data.begin(), data.end(), 0);
        return sum/data.size();
    }
    template <typename ToSave, typename Out>
    class Logger {
        public:
        Logger( Out &out):out_(out){}
        void Debug(ToSave tosave){
            out_<<tosave;
        }
        void Info(ToSave tosave){
            out_<<tosave;
        }
        void Warning(ToSave tosave){
            out_<<tosave;
        }
        void Error(ToSave tosave){
            out_<<tosave;
        }
    private:
         Out &out_;
    };

}

#endif //JIMP_EXERCISES_TEMPLATES_H
