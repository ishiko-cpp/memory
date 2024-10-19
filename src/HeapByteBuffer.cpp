// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "HeapByteBuffer.hpp"
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace Ishiko;

HeapByteBuffer::HeapByteBuffer(size_t capacity)
{
    m_capacity = capacity;
    m_data = reinterpret_cast<Byte*>(malloc(m_capacity));
    // TODO: handle malloc error
}

HeapByteBuffer::HeapByteBuffer(const HeapByteBuffer& other)
{
    m_capacity = other.m_capacity;
    m_data = reinterpret_cast<Byte*>(malloc(m_capacity));
    // TODO: handle malloc error
    memcpy(m_data, other.m_data, other.m_capacity);
}

HeapByteBuffer::HeapByteBuffer(HeapByteBuffer&& other) noexcept
{
    std::swap(m_capacity, other.m_capacity);
    std::swap(m_data, other.m_data);
}

HeapByteBuffer& HeapByteBuffer::operator=(const HeapByteBuffer& other)
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

HeapByteBuffer& HeapByteBuffer::operator=(HeapByteBuffer&& other)
{
    std::swap(m_capacity, other.m_capacity);
    std::swap(m_data, other.m_data);
    return *this;
}

HeapByteBuffer HeapByteBuffer::From(const Byte* bytes, size_t count)
{
    HeapByteBuffer result(count);
    memcpy(result.m_data, bytes, count);
    return result;
}

HeapByteBuffer::~HeapByteBuffer()
{
    free(m_data);
}

void HeapByteBuffer::zero() noexcept
{
    memset(m_data, 0, m_capacity);
}

Byte HeapByteBuffer::operator[](size_t pos) const noexcept
{
    return m_data[pos];
}

void HeapByteBuffer::copyTo(Byte* buffer) const noexcept
{
    memcpy(buffer, m_data, m_capacity);
}

Word HeapByteBuffer::wordAt(size_t pos) const
{
    // TOOD: out of bounds check
    return *(reinterpret_cast<const Word*>(m_data + pos));
}

Word& HeapByteBuffer::wordAt(size_t pos)
{
    // TOOD: out of bounds check
    return *(reinterpret_cast<Word*>(m_data + pos));
}

BigEndianWord HeapByteBuffer::bigEndianWordAt(size_t pos) const
{
    // TOOD: out of bounds check
    return *(reinterpret_cast<const BigEndianWord*>(m_data + pos));
}

BigEndianWord& HeapByteBuffer::bigEndianWordAt(size_t pos)
{
    // TOOD: out of bounds check
    return *(reinterpret_cast<BigEndianWord*>(m_data + pos));
}

bool HeapByteBuffer::operator==(const HeapByteBuffer& other) const noexcept
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

bool HeapByteBuffer::operator!=(const HeapByteBuffer& other) const noexcept
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