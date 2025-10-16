// SPDX-FileCopyrightText: 2005-2025 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_MEMORY_INPLACEBYTEBUFFER_HPP
#define GUARD_ISHIKO_CPP_MEMORY_INPLACEBYTEBUFFER_HPP

#include "BigEndianWord.hpp"
#include "Byte.hpp"
#include "ByteBufferRef.hpp"
#include "Word.hpp"
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <cstring>
#include <string>

namespace Ishiko
{
    // TODO: same as Buffer but fixed size and in place
    template<size_t N>
    class InplaceByteBuffer
    {
    public:
        static InplaceByteBuffer<N> From(const Byte* bytes);

        void zero() noexcept;

        Byte operator[](size_t pos) const noexcept;

        Byte* data() noexcept;
        size_t capacity() noexcept;

        void copyTo(Byte* buffer) const noexcept;

        Word wordAt(size_t pos) const;
        Word& wordAt(size_t pos);
        BigEndianWord bigEndianWordAt(size_t pos) const;
        BigEndianWord& bigEndianWordAt(size_t pos);

        bool operator==(const InplaceByteBuffer<N>& other) const noexcept;
        bool operator!=(const InplaceByteBuffer<N>& other) const noexcept;

        ByteBufferRef asByteBuffer() noexcept;

        std::string toHexString() const;

    private:
        Byte m_data[N];
    };

    template<size_t N>
    InplaceByteBuffer<N> InplaceByteBuffer<N>::From(const Byte* bytes)
    {
        InplaceByteBuffer<N> result;
        memcpy(result.m_data, bytes, N);
        return result;
    }

    template<size_t N>
    void InplaceByteBuffer<N>::zero() noexcept
    {
        memset(m_data, 0, N);
    }

    template<size_t N>
    Byte InplaceByteBuffer<N>::operator[](size_t pos) const noexcept
    {
        return m_data[pos];
    }

    template<size_t N>
    Byte* InplaceByteBuffer<N>::data() noexcept
    {
        return m_data;
    }

    template<size_t N>
    size_t InplaceByteBuffer<N>::capacity() noexcept
    {
        return N;
    }

    template<size_t N>
    void InplaceByteBuffer<N>::copyTo(Byte* buffer) const noexcept
    {
        memcpy(buffer, m_data, N);
    }

    template<size_t N>
    Word InplaceByteBuffer<N>::wordAt(size_t pos) const
    {
        // TOOD: out of bounds check
        return *(reinterpret_cast<const Word*>(m_data + pos));
    }

    template<size_t N>
    Word& InplaceByteBuffer<N>::wordAt(size_t pos)
    {
        // TOOD: out of bounds check
        return *(reinterpret_cast<Word*>(m_data + pos));
    }

    template<size_t N>
    BigEndianWord InplaceByteBuffer<N>::bigEndianWordAt(size_t pos) const
    {
        // TOOD: out of bounds check
        return *(reinterpret_cast<const BigEndianWord*>(m_data + pos));
    }

    template<size_t N>
    BigEndianWord& InplaceByteBuffer<N>::bigEndianWordAt(size_t pos)
    {
        // TOOD: out of bounds check
        return *(reinterpret_cast<BigEndianWord*>(m_data + pos));
    }

    template<size_t N>
    bool InplaceByteBuffer<N>::operator==(const InplaceByteBuffer<N>& other) const noexcept
    {
        return (memcmp(m_data, other.m_data, N) == 0);
    }

    template<size_t N>
    bool InplaceByteBuffer<N>::operator!=(const InplaceByteBuffer<N>& other) const noexcept
    {
        return (memcmp(m_data, other.m_data, N) != 0);
    }

    template<size_t N>
    ByteBufferRef InplaceByteBuffer<N>::asByteBuffer() noexcept
    {
        return ByteBufferRef(m_data, N);
    }

    template<size_t N>
    std::string InplaceByteBuffer<N>::toHexString() const
    {
        return fmt::format("{:02x}", fmt::join(m_data, ""));
    }
}

#endif
