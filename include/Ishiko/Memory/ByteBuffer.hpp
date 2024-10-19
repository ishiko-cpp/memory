// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_MEMORY_BYTEBUFFER_HPP
#define GUARD_ISHIKO_CPP_MEMORY_BYTEBUFFER_HPP

#include "BigEndianWord.hpp"
#include "Byte.hpp"
#include "Word.hpp"
#include <cstddef>
#include <cstring>

namespace Ishiko
{
    // TODO: this class is used to store raw bytes. For instance the buffer could be reallocated and the contents moved with
    // a memcpy or similar operations. In particular no alignment guarantees.
    class ByteBuffer
    {
    public:
        /*
        // TODO: size must be > 0
        ByteBuffer(ByteBuffer&& other) noexcept;

        ByteBuffer& operator=(const ByteBuffer& other);
        ByteBuffer& operator=(ByteBuffer&& other);*/

        inline void zero() noexcept;

        inline Byte operator[](size_t pos) const noexcept;

        inline const Byte* data() const noexcept;
        inline Byte* data() noexcept;
        inline size_t capacity() const noexcept;

        inline void copyTo(Byte* buffer) const noexcept;

        inline Word wordAt(size_t pos) const;
        inline Word& wordAt(size_t pos);
        inline BigEndianWord bigEndianWordAt(size_t pos) const;
        inline BigEndianWord& bigEndianWordAt(size_t pos);

        /*
        bool operator==(const ByteBuffer& other) const noexcept;
        bool operator!=(const ByteBuffer& other) const noexcept;
        */
    protected:
        ByteBuffer() noexcept = default;
        ByteBuffer(const ByteBuffer& other) noexcept = default;
        ~ByteBuffer() noexcept = default;

        Byte* m_data = nullptr;
        size_t m_capacity = 0;
    };
}

void Ishiko::ByteBuffer::zero() noexcept
{
    memset(m_data, 0, m_capacity);
}

Ishiko::Byte Ishiko::ByteBuffer::operator[](size_t pos) const noexcept
{
    return m_data[pos];
}

const Ishiko::Byte* Ishiko::ByteBuffer::data() const noexcept
{
    return m_data;
}

Ishiko::Byte* Ishiko::ByteBuffer::data() noexcept
{
    return m_data;
}

size_t Ishiko::ByteBuffer::capacity() const noexcept
{
    return m_capacity;
}

void Ishiko::ByteBuffer::copyTo(Byte* buffer) const noexcept
{
    memcpy(buffer, m_data, m_capacity);
}

Ishiko::Word Ishiko::ByteBuffer::wordAt(size_t pos) const
{
    // TOOD: out of bounds check
    return *(reinterpret_cast<const Word*>(m_data + pos));
}

Ishiko::Word& Ishiko::ByteBuffer::wordAt(size_t pos)
{
    // TOOD: out of bounds check
    return *(reinterpret_cast<Word*>(m_data + pos));
}

Ishiko::BigEndianWord Ishiko::ByteBuffer::bigEndianWordAt(size_t pos) const
{
    // TOOD: out of bounds check
    return *(reinterpret_cast<const BigEndianWord*>(m_data + pos));
}

Ishiko::BigEndianWord& Ishiko::ByteBuffer::bigEndianWordAt(size_t pos)
{
    // TOOD: out of bounds check
    return *(reinterpret_cast<BigEndianWord*>(m_data + pos));
}

#endif
