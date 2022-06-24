/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#include "Buffer.hpp"
#include <cstdlib>
#include <cstring>

using namespace Ishiko;

Buffer::Buffer(size_t capacity)
    : m_capacity(capacity)
{
    m_data = reinterpret_cast<Byte*>(malloc(capacity));
    // TODO: handle malloc error
}

Buffer::~Buffer()
{
    free(m_data);
}

void Buffer::zero() noexcept
{
    memset(m_data, 0, m_capacity);
}

Byte* Buffer::data() noexcept
{
    return m_data;
}

size_t Buffer::capacity() noexcept
{
    return m_capacity;
}

Word& Buffer::wordAt(size_t pos)
{
    // TOOD: out of bounds check
    return *(reinterpret_cast<Word*>(m_data + pos));
}
