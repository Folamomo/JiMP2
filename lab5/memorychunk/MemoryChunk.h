//
// Created by igor on 27.03.18.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H

#include <cstdint>
#include <algorithm>

namespace memorychunk {
    class MemoryChunk {
    public:
        //Rule of five://
        //1. konstruktor kopiujący
        MemoryChunk(const MemoryChunk &other);
        //2. konstruktor przenoszący
        MemoryChunk(MemoryChunk &&other);
        //3. operator przypisania kopiujący
        MemoryChunk &operator=(const MemoryChunk &other);
        //4. operator przypisania przenoszący
        MemoryChunk &operator=(MemoryChunk &&other);
        //5. Destruktor
        ~MemoryChunk();

        MemoryChunk(size_t sz=0);

        int8_t *MemoryAt(size_t offset) const;
        size_t ChunkSize() const;
    private:
        int8_t  *memorychunk_;
        size_t chunksize_;
    };
}

#endif //JIMP_EXERCISES_MEMORYCHUNK_H
