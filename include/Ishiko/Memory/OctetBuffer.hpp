// SPDX-FileCopyrightText: 2005-2025 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_MEMORY_OCTETBUFFER_HPP
#define GUARD_ISHIKO_CPP_MEMORY_OCTETBUFFER_HPP

#include "Byte.hpp"

namespace Ishiko
{
    // TODO: this class is used to store raw octet. For instance the buffer could be reallocated and the contents moved with
    // a memcpy or similar operations. In particular no alignment guarantees.
    class OctetBuffer
    {
    protected:
        OctetBuffer() noexcept = default;
        OctetBuffer(const OctetBuffer& other) noexcept = default;
        ~OctetBuffer() noexcept = default;

        Octet* m_data = nullptr;
        size_t m_capacity = 0;
    };
}

#endif
