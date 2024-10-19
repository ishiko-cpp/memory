// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "ByteBuffer.hpp"
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace Ishiko;

ByteBuffer::ByteBuffer(size_t capacity)
    : m_capacity(capacity)
{
    m_data = reinterpret_cast<Byte*>(malloc(m_capacity));
    // TODO: handle malloc error
}

ByteBuffer::ByteBuffer(const ByteBuffer& other)
    : m_capacity(other.m_capacity)
{
    m_data = reinterpret_cast<Byte*>(malloc(m_capacity));
    // TODO: handle malloc error
    memcpy(m_data, other.m_data, other.m_capacity);
}

ByteBuffer::ByteBuffer(ByteBuffer&& other) noexcept
{
    std::swap(m_capacity, other.m_capacity);
    std::swap(m_data, other.m_data);
}

ByteBuffer& ByteBuffer::operator=(const ByteBuffer& other)
{
    if (this != &other)
    {
        Byte* temp = reinterpret_cast<Byte*>(malloc(other.m_capacity));
        if (temp)
        {
            free(m_data);
            m_capacity = other.m_capacity;
            m_data = temp;
            memcpy(m_data, other.m_data, other.m_capacity);
        }
        else
        {
            // TODO: handle malloc error
        }
    }
    return *this;
}

ByteBuffer& ByteBuffer::operator=(ByteBuffer&& other)
{
    std::swap(m_capacity, other.m_capacity);
    std::swap(m_data, other.m_data);
    return *this;
}

ByteBuffer ByteBuffer::From(const Byte* bytes, size_t count)
{
    ByteBuffer result(count);
    memcpy(result.m_data, bytes, count);
    return result;
}

ByteBuffer::~ByteBuffer()
{
    free(m_data);
}

void ByteBuffer::zero() noexcept
{
    memset(m_data, 0, m_capacity);
}

Byte ByteBuffer::operator[](size_t pos) const noexcept
{
    return m_data[pos];
}

const Byte* ByteBuffer::data() const noexcept
{
    return m_data;
}

Byte* ByteBuffer::data() noexcept
{
    return m_data;
}

size_t ByteBuffer::capacity() const noexcept
{
    return m_capacity;
}

void ByteBuffer::copyTo(Byte* buffer) const noexcept
{
    memcpy(buffer, m_data, m_capacity);
}

Word ByteBuffer::wordAt(size_t pos) const
{
    // TOOD: out of bounds check
    return *(reinterpret_cast<const Word*>(m_data + pos));
}

Word& ByteBuffer::wordAt(size_t pos)
{
    // TOOD: out of bounds check
    return *(reinterpret_cast<Word*>(m_data + pos));
}

BigEndianWord ByteBuffer::bigEndianWordAt(size_t pos) const
{
    // TOOD: out of bounds check
    return *(reinterpret_cast<const BigEndianWord*>(m_data + pos));
}

BigEndianWord& ByteBuffer::bigEndianWordAt(size_t pos)
{
    // TOOD: out of bounds check
    return *(reinterpret_cast<BigEndianWord*>(m_data + pos));
}

bool ByteBuffer::operator==(const ByteBuffer& other) const noexcept
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

bool ByteBuffer::operator!=(const ByteBuffer& other) const noexcept
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

ByteBuffer::ByteBuffer()
{
}
