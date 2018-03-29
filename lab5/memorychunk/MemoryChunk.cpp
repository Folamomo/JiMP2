//
// Created by igor on 27.03.18.
//

#include <algorithm>

#include "MemoryChunk.h"

memorychunk::MemoryChunk::MemoryChunk(const memorychunk::MemoryChunk &other) {
    chunksize_=other.chunksize_;
    memorychunk_=new int8_t [chunksize_];
    for (size_t i = 0; i < chunksize_; i+= sizeof(int8_t)) {
        *(this->MemoryAt(i))=*(other.MemoryAt(i));
    }
}

memorychunk::MemoryChunk::MemoryChunk(memorychunk::MemoryChunk &&other) : memorychunk_{nullptr}, chunksize_{0} {
        std::swap(memorychunk_,other.memorychunk_);
        std::swap(chunksize_,other.chunksize_);
}

memorychunk::MemoryChunk &memorychunk::MemoryChunk::operator=(const memorychunk::MemoryChunk &other) {
    if(this==&other){
        return *this;
    }
    delete [] memorychunk_;
    chunksize_ = other.chunksize_;
    memorychunk_=new int8_t [chunksize_];
    for (size_t i = 0; i < chunksize_; i+= sizeof(int8_t)) {
        *(this->MemoryAt(i))=*(other.MemoryAt(i));
    }
}

memorychunk::MemoryChunk &memorychunk::MemoryChunk::operator=(memorychunk::MemoryChunk &&other) {
    //jeśli ktoś wpadł na pomsył x = move(x);
    if (this == &other) {
        return other;
    }

    delete[] memorychunk_;
    memorychunk_ = nullptr;
    std::swap(memorychunk_,other.memorychunk_);
    chunksize_=other.chunksize_;
}

memorychunk::MemoryChunk::~MemoryChunk() {
    delete  [] memorychunk_ ;
}

memorychunk::MemoryChunk::MemoryChunk(size_t sz) {
    chunksize_ = sz;
    memorychunk_ = new  int8_t [chunksize_];
}

int8_t *memorychunk::MemoryChunk::MemoryAt(size_t offset) const {
    return (memorychunk_+offset);
}

size_t memorychunk::MemoryChunk::ChunkSize() const {
    return chunksize_;
}
