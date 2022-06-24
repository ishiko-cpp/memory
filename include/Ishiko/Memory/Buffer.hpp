/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_MEMORY_BUFFER_HPP_
#define _ISHIKO_CPP_MEMORY_BUFFER_HPP_

#include "BigEndianWord.hpp"
#include "Byte.hpp"
#include "Word.hpp"
#include <cstddef>

namespace Ishiko
{

// TODO: this class is used to store raw bytes. For instance the buffer could be reallocated and the contents moved with
// a memcpy or similar operations.
class Buffer
{
public:
    // TODO: size must be > 0
    Buffer(size_t capacity);
    static Buffer From(const Byte* bytes, size_t count);
    ~Buffer();

    void zero() noexcept;

    Byte operator[](size_t pos) const noexcept;

    Byte* data() noexcept;
    size_t capacity() noexcept;

    void copyTo(Byte* buffer) const noexcept;

    Word wordAt(size_t pos) const;
    Word& wordAt(size_t pos);
    BigEndianWord bigEndianWordAt(size_t pos) const;
    BigEndianWord& bigEndianWordAt(size_t pos);

    bool operator==(const Buffer& other) const noexcept;
    bool operator!=(const Buffer& other) const noexcept;

private:
    Byte* m_data;
    size_t m_capacity;
};

}

#endif
