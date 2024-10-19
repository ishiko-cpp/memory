// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_MEMORY_STACKBYTEBUFFER_HPP
#define GUARD_ISHIKO_CPP_MEMORY_STACKBYTEBUFFER_HPP

#include "BigEndianWord.hpp"
#include "Byte.hpp"
#include "Word.hpp"
#include <cstring>

namespace Ishiko
{
    // TODO: same as Buffer but fixed size and on the stack
    template<size_t N>
    class StackByteBuffer
    {
    public:
        static StackByteBuffer<N> From(const Byte* bytes);

        void zero() noexcept;

        Byte operator[](size_t pos) const noexcept;

        Byte* data() noexcept;
        size_t capacity() noexcept;

        void copyTo(Byte* buffer) const noexcept;

        Word wordAt(size_t pos) const;
        Word& wordAt(size_t pos);
        BigEndianWord bigEndianWordAt(size_t pos) const;
        BigEndianWord& bigEndianWordAt(size_t pos);

        bool operator==(const StackByteBuffer<N>& other) const noexcept;
        bool operator!=(const StackByteBuffer<N>& other) const noexcept;

    private:
        Byte m_data[N];
    };

    template<size_t N>
    StackByteBuffer<N> StackByteBuffer<N>::From(const Byte* bytes)
    {
        FixedByteBuffer<N> result;
        memcpy(result.m_data, bytes, N);
        return result;
    }

    template<size_t N>
    void StackByteBuffer<N>::zero() noexcept
    {
        memset(m_data, 0, N);
    }

    template<size_t N>
    Byte StackByteBuffer<N>::operator[](size_t pos) const noexcept
    {
        return m_data[pos];
    }

    template<size_t N>
    Byte* StackByteBuffer<N>::data() noexcept
    {
        return m_data;
    }

    template<size_t N>
    size_t StackByteBuffer<N>::capacity() noexcept
    {
        return N;
    }

    template<size_t N>
    void StackByteBuffer<N>::copyTo(Byte* buffer) const noexcept
    {
        memcpy(buffer, m_data, N);
    }

    template<size_t N>
    Word StackByteBuffer<N>::wordAt(size_t pos) const
    {
        // TOOD: out of bounds check
        return *(reinterpret_cast<const Word*>(m_data + pos));
    }

    template<size_t N>
    Word& StackByteBuffer<N>::wordAt(size_t pos)
    {
        // TOOD: out of bounds check
        return *(reinterpret_cast<Word*>(m_data + pos));
    }

    template<size_t N>
    BigEndianWord StackByteBuffer<N>::bigEndianWordAt(size_t pos) const
    {
        // TOOD: out of bounds check
        return *(reinterpret_cast<const BigEndianWord*>(m_data + pos));
    }

    template<size_t N>
    BigEndianWord& StackByteBuffer<N>::bigEndianWordAt(size_t pos)
    {
        // TOOD: out of bounds check
        return *(reinterpret_cast<BigEndianWord*>(m_data + pos));
    }

    template<size_t N>
    bool StackByteBuffer<N>::operator==(const StackByteBuffer<N>& other) const noexcept
    {
        return (memcmp(m_data, other.m_data, N) == 0);
    }

    template<size_t N>
    bool StackByteBuffer<N>::operator!=(const StackByteBuffer<N>& other) const noexcept
    {
        return (memcmp(m_data, other.m_data, N) != 0);
    }
}

#endif
