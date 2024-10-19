// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_MEMORY_HEAPBYTEBUFFER_HPP
#define GUARD_ISHIKO_CPP_MEMORY_HEAPBYTEBUFFER_HPP

#include "BigEndianWord.hpp"
#include "Byte.hpp"
#include "ByteBuffer.hpp"
#include "Word.hpp"
#include <cstddef>

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

        void copyTo(Byte* buffer) const noexcept;

        Word wordAt(size_t pos) const;
        Word& wordAt(size_t pos);
        BigEndianWord bigEndianWordAt(size_t pos) const;
        BigEndianWord& bigEndianWordAt(size_t pos);

        bool operator==(const HeapByteBuffer& other) const noexcept;
        bool operator!=(const HeapByteBuffer& other) const noexcept;
    };
}

#endif
