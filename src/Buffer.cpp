/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#include "Buffer.hpp"
#include <cstdlib>
#include <cstring>

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

void Buffer::zero() noexcept
{
    memset(m_data, 0, m_size);
}

Byte* Buffer::data() noexcept
{
    return m_data;
}

size_t Buffer::size() noexcept
{
    return m_size;
}
