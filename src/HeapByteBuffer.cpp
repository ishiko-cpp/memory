// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "HeapByteBuffer.hpp"
#include <fmt/format.h>
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

std::string HeapByteBuffer::toHexString() const
{
    return fmt::format("{:02x}", fmt::join(m_data, (m_data + m_capacity), ""));
}
