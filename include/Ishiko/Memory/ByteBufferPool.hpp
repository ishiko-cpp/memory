// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_MEMORY_BYTEBUFFERPOOL_HPP
#define GUARD_ISHIKO_CPP_MEMORY_BYTEBUFFERPOOL_HPP

#include "ByteBuffer.hpp"
#include <Ishiko/Errors.hpp>
#include <memory>

namespace Ishiko
{
    // TODO: a buffer pool, at the moment this is just a dummy that simply allocates and deallocates all the time.
    // TODO: The point is to start using it in other projects and switch when I have some time to implement.
    // The size of the returned buffers is set by the pool so it also serves as some sort of policy object that
    // determines how big a buffer is returned. Probably I should allow this to be overriden in the acquire call
    // but for now it seems convenient for the use I make of it in the Ishiko networking classes.
    class ByteBufferPool
    {
    public:
        class Deleter
        {
        public:
            Deleter(ByteBufferPool& pool);

            void operator()(ByteBuffer* buffer) const
            {
                m_pool.release(buffer);
            };

        private:
            ByteBufferPool& m_pool;
        };

        ByteBufferPool(size_t default_buffer_capacity);

        std::unique_ptr<ByteBuffer, Deleter> acquire(Error& error) noexcept;
        void release(ByteBuffer* buffer) noexcept;

    private:
        size_t m_default_buffer_capacity;
    };
}

#endif
