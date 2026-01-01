// SPDX-FileCopyrightText: 2005-2025 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_MEMORY_INPLACEOCTETBUFFER_HPP
#define GUARD_ISHIKO_CPP_MEMORY_INPLACEOCTETBUFFER_HPP

#include "Octet.hpp"

namespace Ishiko
{
    // TODO: same as Buffer but fixed size and in place
    template<size_t N>
    class InplaceOctetBuffer
    {
    public:
        static InplaceOctetBuffer<N> From(const Octet* octets);

        void zero() noexcept;

        Octet operator[](size_t pos) const noexcept;

        Octet* data() noexcept;
        size_t capacity() noexcept;

        void copyTo(Octet* buffer) const noexcept;

        BigEndianWord bigEndianWordAt(size_t pos) const;
        BigEndianWord& bigEndianWordAt(size_t pos);

        bool operator==(const InplaceOctetBuffer<N>& other) const noexcept;
        bool operator!=(const InplaceOctetBuffer<N>& other) const noexcept;

        std::string toHexString() const;

    private:
        Octet m_data[N];
    };

    template<size_t N>
    InplaceOctetBuffer<N> InplaceOctetBuffer<N>::From(const Octet* octets)
    {
        InplaceOctetBuffer<N> result;
        memcpy(result.m_data, octets, N);
        return result;
    }

    template<size_t N>
    void InplaceOctetBuffer<N>::zero() noexcept
    {
        memset(m_data, 0, N);
    }

    template<size_t N>
    Octet InplaceOctetBuffer<N>::operator[](size_t pos) const noexcept
    {
        return m_data[pos];
    }

    template<size_t N>
    Octet* InplaceOctetBuffer<N>::data() noexcept
    {
        return m_data;
    }

    template<size_t N>
    size_t InplaceOctetBuffer<N>::capacity() noexcept
    {
        return N;
    }

    template<size_t N>
    void InplaceOctetBuffer<N>::copyTo(Octet* buffer) const noexcept
    {
        memcpy(buffer, m_data, N);
    }

    template<size_t N>
    BigEndianWord InplaceOctetBuffer<N>::bigEndianWordAt(size_t pos) const
    {
        // TOOD: out of bounds check
        return *(reinterpret_cast<const BigEndianWord*>(m_data + pos));
    }

    template<size_t N>
    BigEndianWord& InplaceOctetBuffer<N>::bigEndianWordAt(size_t pos)
    {
        // TOOD: out of bounds check
        return *(reinterpret_cast<BigEndianWord*>(m_data + pos));
    }
    
    template<size_t N>
    bool InplaceOctetBuffer<N>::operator==(const InplaceOctetBuffer<N>& other) const noexcept
    {
        return (memcmp(m_data, other.m_data, N) == 0);
    }

    template<size_t N>
    bool InplaceOctetBuffer<N>::operator!=(const InplaceOctetBuffer<N>& other) const noexcept
    {
        return (memcmp(m_data, other.m_data, N) != 0);
    }

    template<size_t N>
    std::string InplaceOctetBuffer<N>::toHexString() const
    {
        return fmt::format("{:02x}", fmt::join(m_data, ""));
    }
}

#endif
