// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_MEMORY_ALIGNEDBYTEBUFFER_HPP
#define GUARD_ISHIKO_CPP_MEMORY_ALIGNEDBYTEBUFFER_HPP

#include "ByteBuffer.hpp"
#include "DefaultAllocator.hpp"
#include <cstring>

namespace Ishiko
{
    // TODO: this class is used to store raw bytes. For instance the buffer could be reallocated and the contents moved with
    // a memcpy or similar operations.
    template<size_t alignment>
    class AlignedByteBuffer : private ByteBuffer
    {
    public:
        // TODO: size must be > 0
        AlignedByteBuffer(size_t capacity);
        AlignedByteBuffer(const ByteBuffer& other);
        AlignedByteBuffer(const AlignedByteBuffer& other);
        AlignedByteBuffer(AlignedByteBuffer&& other) noexcept;
        ~AlignedByteBuffer() noexcept;

        using ByteBuffer::data;
        using ByteBuffer::capacity;
    };
}

template<size_t alignment>
Ishiko::AlignedByteBuffer<alignment>::AlignedByteBuffer(size_t capacity)
{
    // TODO: handle errors
    Error error;

    m_capacity = capacity;
    m_data = NewAlignedObjectArray<Byte>(alignment, capacity, error);
}

template<size_t alignment>
Ishiko::AlignedByteBuffer<alignment>::AlignedByteBuffer(const ByteBuffer& other)
{
    // TODO: handle errors
    Error error;

    m_capacity = other.capacity();
    m_data = NewAlignedObjectArray<Byte>(alignment, m_capacity, error);
    memcpy(m_data, other.data(), other.capacity());
}

template<size_t alignment>
Ishiko::AlignedByteBuffer<alignment>::AlignedByteBuffer(const AlignedByteBuffer& other)
{
    // TODO: handle errors
    Error error;

    m_capacity = other.m_capacity;
    m_data = NewAlignedObjectArray<Byte>(alignment, m_capacity, error);
    memcpy(m_data, other.m_data, other.m_capacity);
}

template<size_t alignment>
Ishiko::AlignedByteBuffer<alignment>::AlignedByteBuffer(AlignedByteBuffer&& other) noexcept
{
    m_capacity = other.m_capacity;
    m_data = other.m_data;
    other.m_capacity = 0;
    other.m_data = nullptr;
}

template<size_t alignment>
Ishiko::AlignedByteBuffer<alignment>::~AlignedByteBuffer() noexcept
{
    DeleteAlignedObjectArray(m_capacity, m_data);
    // Set m_data to null to suppress deletion in the base constructor
    m_data = nullptr;
}

#endif
