// SPDX-FileCopyrightText: 2021-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "ByteBufferPoolTests.hpp"
#include "Ishiko/Memory/ByteBufferPool.hpp"

using namespace Ishiko;

ByteBufferPoolTests::ByteBufferPoolTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "ByteBufferPool tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void ByteBufferPoolTests::ConstructorTest1(Test& test)
{
    ByteBufferPool buffer_pool;
    
    ISHIKO_TEST_PASS();
}
