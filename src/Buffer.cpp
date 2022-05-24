/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#include "Buffer.hpp"
#include <cstdlib>

using namespace Ishiko;

Buffer::Buffer(size_t size)
    : m_size(size)
{
    m_data = reinterpret_cast<Byte*>(malloc(size));
    // TODO: handle malloc error
}

Buffer::~Buffer()
{
    free(m_data);
}

Byte* Buffer::data() noexcept
{
    return m_data;
}

size_t Buffer::size() noexcept
{
    return m_size;
}
