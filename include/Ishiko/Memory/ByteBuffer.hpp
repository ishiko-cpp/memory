// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_MEMORY_BYTEBUFFER_HPP
#define GUARD_ISHIKO_CPP_MEMORY_BYTEBUFFER_HPP

#include "BigEndianWord.hpp"
#include "Byte.hpp"
#include "Word.hpp"
#include <cstddef>

namespace Ishiko
{
    // TODO: this class is used to store raw bytes. For instance the buffer could be reallocated and the contents moved with
    // a memcpy or similar operations. In particular no alignment guarantees.
    class ByteBuffer
    {
    public:
        // TODO: size must be > 0
        ByteBuffer(size_t capacity);
        ByteBuffer(const ByteBuffer& other);
        ByteBuffer(ByteBuffer&& other) noexcept;
        ~ByteBuffer();

        ByteBuffer& operator=(const ByteBuffer& other);
        ByteBuffer& operator=(ByteBuffer&& other);

        static ByteBuffer From(const Byte* bytes, size_t count);

        void zero() noexcept;

        Byte operator[](size_t pos) const noexcept;

        const Byte* data() const noexcept;
        Byte* data() noexcept;
        size_t capacity() noexcept;

        void copyTo(Byte* buffer) const noexcept;

        Word wordAt(size_t pos) const;
        Word& wordAt(size_t pos);
        BigEndianWord bigEndianWordAt(size_t pos) const;
        BigEndianWord& bigEndianWordAt(size_t pos);

        bool operator==(const ByteBuffer& other) const noexcept;
        bool operator!=(const ByteBuffer& other) const noexcept;

    private:
        Byte* m_data{nullptr};
        size_t m_capacity{0};
    };
}

#endif
