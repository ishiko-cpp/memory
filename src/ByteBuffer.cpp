/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#include "ByteBuffer.hpp"
#include <cstdlib>
#include <cstring>

using namespace Ishiko;

ByteBuffer::ByteBuffer(size_t capacity)
    : m_capacity(capacity)
{
    m_data = reinterpret_cast<Byte*>(malloc(m_capacity));
    // TODO: handle malloc error
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

size_t ByteBuffer::capacity() noexcept
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
