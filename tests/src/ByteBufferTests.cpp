/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#include "ByteBufferTests.hpp"
#include "Ishiko/Memory/ByteBuffer.hpp"

using namespace Ishiko;

BufferTests::BufferTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "Buffer tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("zero test 1", ZeroTest1);
    append<HeapAllocationErrorsTest>("wordAt test 1", WordAtTest1);
    append<HeapAllocationErrorsTest>("bigEndianWordAt test 1", BigEndianWordAtTest1);
}

void BufferTests::ConstructorTest1(Test& test)
{
    ByteBuffer buffer(10);

    ISHIKO_TEST_FAIL_IF_NEQ(buffer.capacity(), 10);
    ISHIKO_TEST_PASS();
}

void BufferTests::ZeroTest1(Test& test)
{
    ByteBuffer buffer(10);

    buffer.zero();

    ISHIKO_TEST_ABORT_IF_NEQ(buffer.capacity(), 10);
    
    for (size_t i = 0; i < buffer.capacity(); ++i)
    {
        ISHIKO_TEST_FAIL_IF_NEQ(buffer.data()[i], 0);
    }

    ISHIKO_TEST_PASS();
}

void BufferTests::WordAtTest1(Test& test)
{
    ByteBuffer buffer(10);
    buffer.zero();

    buffer.wordAt(0) = 128;
    buffer.wordAt(2) = 255;

    ISHIKO_TEST_FAIL_IF_NEQ(buffer.wordAt(0), 128);
    ISHIKO_TEST_FAIL_IF_NEQ(buffer[0], 128);
    ISHIKO_TEST_FAIL_IF_NEQ(buffer[1], 0);
    ISHIKO_TEST_FAIL_IF_NEQ(buffer.wordAt(2), 255);
    ISHIKO_TEST_FAIL_IF_NEQ(buffer[2], 255);
    ISHIKO_TEST_FAIL_IF_NEQ(buffer[3], 0);
    ISHIKO_TEST_PASS();
}

void BufferTests::BigEndianWordAtTest1(Test& test)
{
    ByteBuffer buffer(10);
    buffer.zero();

    buffer.bigEndianWordAt(0) = 128;
    buffer.bigEndianWordAt(2) = 255;

    ISHIKO_TEST_FAIL_IF_NEQ(buffer.bigEndianWordAt(0), 128);
    ISHIKO_TEST_FAIL_IF_NEQ(buffer[0], 0);
    ISHIKO_TEST_FAIL_IF_NEQ(buffer[1], 128);
    ISHIKO_TEST_FAIL_IF_NEQ(buffer.bigEndianWordAt(2), 255);
    ISHIKO_TEST_FAIL_IF_NEQ(buffer[2], 0);
    ISHIKO_TEST_FAIL_IF_NEQ(buffer[3], 255);
    ISHIKO_TEST_PASS();
}
