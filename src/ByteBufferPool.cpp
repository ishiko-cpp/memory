// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "ByteBufferPool.hpp"
#include "HeapByteBuffer.hpp"

using namespace Ishiko;

ByteBufferPool::Deleter::Deleter(ByteBufferPool& pool)
    : m_pool(pool)
{
}

ByteBufferPool::ByteBufferPool(size_t default_buffer_capacity)
    : m_default_buffer_capacity{default_buffer_capacity}
{
}

std::unique_ptr<ByteBuffer, ByteBufferPool::Deleter> ByteBufferPool::acquire(Error& error) noexcept
{
    // TODO: this can't throw, fix and set error
    return std::unique_ptr<ByteBuffer, ByteBufferPool::Deleter>(
        new HeapByteBuffer{m_default_buffer_capacity}, Deleter{*this});
}

void ByteBufferPool::release(ByteBuffer* buffer) noexcept
{
    delete static_cast<HeapByteBuffer*>(buffer);
}
