/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#include "FixedBufferTests.hpp"
#include "Ishiko/Memory/FixedBuffer.hpp"

using namespace Ishiko;

FixedBufferTests::FixedBufferTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "FixedBuffer tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("zero test 1", ZeroTest1);
    append<HeapAllocationErrorsTest>("wordAt test 1", WordAtTest1);
}

void FixedBufferTests::ConstructorTest1(Test& test)
{
    FixedBuffer<10> buffer;

    ISHIKO_TEST_FAIL_IF_NEQ(buffer.capacity(), 10);
    ISHIKO_TEST_PASS();
}

void FixedBufferTests::ZeroTest1(Test& test)
{
    FixedBuffer<10> buffer;

    buffer.zero();

    ISHIKO_TEST_ABORT_IF_NEQ(buffer.capacity(), 10);

    for (size_t i = 0; i < buffer.capacity(); ++i)
    {
        ISHIKO_TEST_FAIL_IF_NEQ(buffer.data()[i], 0);
    }

    ISHIKO_TEST_PASS();
}

void FixedBufferTests::WordAtTest1(Test& test)
{
    FixedBuffer<10> buffer;
    buffer.zero();

    buffer.wordAt(0) = 128;
    buffer.wordAt(2) = 255;

    ISHIKO_TEST_FAIL_IF_NEQ(buffer.wordAt(0), 128);
    ISHIKO_TEST_FAIL_IF_NEQ(buffer.wordAt(2), 255);
    ISHIKO_TEST_PASS();
}
