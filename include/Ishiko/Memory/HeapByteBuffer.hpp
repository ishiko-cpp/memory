// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_MEMORY_HEAPBYTEBUFFER_HPP
#define GUARD_ISHIKO_CPP_MEMORY_HEAPBYTEBUFFER_HPP

#include "Byte.hpp"
#include "ByteBuffer.hpp"
#include <cstddef>
#include <string>

namespace Ishiko
{
    // TODO: this class is used to store raw bytes. For instance the buffer could be reallocated and the contents moved with
    // a memcpy or similar operations. In particular no alignment guarantees.
    class HeapByteBuffer : public ByteBuffer
    {
    public:
        // TODO: size must be > 0
        HeapByteBuffer(size_t capacity);
        HeapByteBuffer(const HeapByteBuffer& other);
        HeapByteBuffer(HeapByteBuffer&& other) noexcept;
        ~HeapByteBuffer();

        HeapByteBuffer& operator=(const HeapByteBuffer& other);
        HeapByteBuffer& operator=(HeapByteBuffer&& other);

        static HeapByteBuffer From(const Byte* bytes, size_t count);

        std::string toHexString() const;
    };
}

#endif
