// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_MEMORY_ALIGNEDHEAPBYTEBUFFER_HPP
#define GUARD_ISHIKO_CPP_MEMORY_ALIGNEDHEAPBYTEBUFFER_HPP

#include "ByteBuffer.hpp"
#include "DefaultAllocator.hpp"
#include <cstring>

namespace Ishiko
{
    // TODO: this class is used to store raw bytes. For instance the buffer could be reallocated and the contents moved with
    // a memcpy or similar operations.
    template<size_t alignment>
    class AlignedHeapByteBuffer : private ByteBuffer
    {
    public:
        // TODO: size must be > 0
        AlignedHeapByteBuffer(size_t capacity);
        AlignedHeapByteBuffer(const ByteBuffer& other);
        AlignedHeapByteBuffer(const AlignedHeapByteBuffer& other);
        AlignedHeapByteBuffer(AlignedHeapByteBuffer&& other) noexcept;
        ~AlignedHeapByteBuffer() noexcept;

        using ByteBuffer::data;
        using ByteBuffer::capacity;
    };
}

template<size_t alignment>
Ishiko::AlignedHeapByteBuffer<alignment>::AlignedHeapByteBuffer(size_t capacity)
{
    // TODO: handle errors
    Error error;

    m_capacity = capacity;
    m_data = NewAlignedObjectArray<Byte>(alignment, capacity, error);
}

template<size_t alignment>
Ishiko::AlignedHeapByteBuffer<alignment>::AlignedHeapByteBuffer(const ByteBuffer& other)
{
    // TODO: handle errors
    Error error;

    m_capacity = other.capacity();
    m_data = NewAlignedObjectArray<Byte>(alignment, m_capacity, error);
    memcpy(m_data, other.data(), other.capacity());
}

template<size_t alignment>
Ishiko::AlignedHeapByteBuffer<alignment>::AlignedHeapByteBuffer(const AlignedHeapByteBuffer& other)
{
    // TODO: handle errors
    Error error;

    m_capacity = other.m_capacity;
    m_data = NewAlignedObjectArray<Byte>(alignment, m_capacity, error);
    memcpy(m_data, other.m_data, other.m_capacity);
}

template<size_t alignment>
Ishiko::AlignedHeapByteBuffer<alignment>::AlignedHeapByteBuffer(AlignedHeapByteBuffer&& other) noexcept
{
    m_capacity = other.m_capacity;
    m_data = other.m_data;
    other.m_capacity = 0;
    other.m_data = nullptr;
}

template<size_t alignment>
Ishiko::AlignedHeapByteBuffer<alignment>::~AlignedHeapByteBuffer() noexcept
{
    DeleteAlignedObjectArray(m_capacity, m_data);
    // Set m_data to null to suppress deletion in the base constructor
    m_data = nullptr;
}

#endif
