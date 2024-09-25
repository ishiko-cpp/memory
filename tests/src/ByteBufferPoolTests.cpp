// SPDX-FileCopyrightText: 2021-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "ByteBufferPoolTests.hpp"
#include "Ishiko/Memory/ByteBufferPool.hpp"

using namespace Ishiko;

ByteBufferPoolTests::ByteBufferPoolTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "ByteBufferPool tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("acquire test 1", AcquireTest1);
}

void ByteBufferPoolTests::ConstructorTest1(Test& test)
{
    ByteBufferPool buffer_pool{1024};
    
    ISHIKO_TEST_PASS();
}

void ByteBufferPoolTests::AcquireTest1(Test& test)
{
    ByteBufferPool buffer_pool{1024};

    Error error;
    std::unique_ptr<ByteBuffer, ByteBufferPool::Deleter> buffer = buffer_pool.acquire(error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(buffer->capacity(), 1024);
    ISHIKO_TEST_PASS();
}
