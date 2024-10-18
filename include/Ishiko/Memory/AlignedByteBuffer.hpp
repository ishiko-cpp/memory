// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_MEMORY_ALIGNEDBYTEBUFFER_HPP
#define GUARD_ISHIKO_CPP_MEMORY_ALIGNEDBYTEBUFFER_HPP

#include "ByteBuffer.hpp"

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
        ~AlignedByteBuffer() noexcept;

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
Ishiko::AlignedByteBuffer<alignment>::~AlignedByteBuffer() noexcept
{
    DeleteAlignedObjectArray(m_capacity, m_data);
    // Set m_data to null to suppress deletion in the base constructor
    m_data = nullptr;
}

#endif
