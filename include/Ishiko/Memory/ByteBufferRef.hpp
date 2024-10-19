// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_MEMORY_BYTEBUFFERREF_HPP
#define GUARD_ISHIKO_CPP_MEMORY_BYTEBUFFERREF_HPP

#include "ByteBuffer.hpp"

namespace Ishiko
{
    class ByteBufferRef : public ByteBuffer
    {
    public:
        inline ByteBufferRef(Byte* data, size_t capacity) noexcept;
    };
}

Ishiko::ByteBufferRef::ByteBufferRef(Byte* data, size_t capacity) noexcept
{
    m_data = data;
    m_capacity = capacity;
}

#endif
