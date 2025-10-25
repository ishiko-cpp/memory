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
        void zero() noexcept;

        Octet* data() noexcept;
        size_t capacity() noexcept;

    private:
        Octet m_data[N];
    };

    template<size_t N>
    void InplaceOctetBuffer<N>::zero() noexcept
    {
        memset(m_data, 0, N);
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
}

#endif
