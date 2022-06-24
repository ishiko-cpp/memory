/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_MEMORY_BUFFER_HPP_
#define _ISHIKO_CPP_MEMORY_BUFFER_HPP_

#include "Byte.hpp"
#include "Word.hpp"
#include <cstddef>

namespace Ishiko
{

// TODO: this class is used to store raw bytes. For instance the buffer could be reallocatd and the contents moved with
// a memcpy or similar operations.
class Buffer
{
public:
    // TODO: size must be > 0
    Buffer(size_t capacity);
    ~Buffer();

    void zero() noexcept;

    Byte* data() noexcept;
    size_t capacity() noexcept;

    Word& wordAt(size_t pos);

private:
    Byte* m_data;
    size_t m_capacity;
};

}

#endif
