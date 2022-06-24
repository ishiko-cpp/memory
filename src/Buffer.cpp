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

Byte Buffer::operator[](size_t pos) const noexcept
{
    return m_data[pos];
}

Byte* Buffer::data() noexcept
{
    return m_data;
}

size_t Buffer::capacity() noexcept
{
    return m_capacity;
}

void Buffer::copyTo(Byte* buffer) const noexcept
{
    memcpy(buffer, m_data, m_capacity);
}

Word Buffer::wordAt(size_t pos) const
{
    // TOOD: out of bounds check
    return *(reinterpret_cast<const Word*>(m_data + pos));
}

Word& Buffer::wordAt(size_t pos)
{
    // TOOD: out of bounds check
    return *(reinterpret_cast<Word*>(m_data + pos));
}

BigEndianWord Buffer::bigEndianWordAt(size_t pos) const
{
    // TOOD: out of bounds check
    return *(reinterpret_cast<const BigEndianWord*>(m_data + pos));
}

BigEndianWord& Buffer::bigEndianWordAt(size_t pos)
{
    // TOOD: out of bounds check
    return *(reinterpret_cast<BigEndianWord*>(m_data + pos));
}

bool Buffer::operator==(const Buffer& other) const noexcept
{
    if (m_capacity != other.m_capacity)
    {
        return false;
    }
    else
    {
        return (memcmp(m_data, other.m_data, m_capacity) == 0);
    }
}

bool Buffer::operator!=(const Buffer& other) const noexcept
{
    if (m_capacity != other.m_capacity)
    {
        return true;
    }
    else
    {
        return (memcmp(m_data, other.m_data, m_capacity) != 0);
    }
}
