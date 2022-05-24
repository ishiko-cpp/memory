/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#include "BufferTests.hpp"
#include "Ishiko/Memory/Buffer.hpp"

using namespace Ishiko;

BufferTests::BufferTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "Buffer tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("zero test 1", ZeroTest1);
}

void BufferTests::ConstructorTest1(Test& test)
{
    Buffer buffer(10);

    ISHIKO_TEST_FAIL_IF_NEQ(buffer.size(), 10);
    ISHIKO_TEST_PASS();
}

void BufferTests::ZeroTest1(Test& test)
{
    Buffer buffer(10);

    buffer.zero();

    ISHIKO_TEST_ABORT_IF_NEQ(buffer.size(), 10);
    
    for (size_t i = 0; i < buffer.size(); ++i)
    {
        ISHIKO_TEST_FAIL_IF_NEQ(buffer.data()[i], 0);
    }

    ISHIKO_TEST_PASS();
}
