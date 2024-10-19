// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "StackByteBufferTests.hpp"
#include "Ishiko/Memory/StackByteBuffer.hpp"

using namespace Ishiko;

StackByteBufferTests::StackByteBufferTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "StackByteBuffer tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("zero test 1", ZeroTest1);
    append<HeapAllocationErrorsTest>("wordAt test 1", WordAtTest1);
    append<HeapAllocationErrorsTest>("bigEndianWordAt test 1", BigEndianWordAtTest1);
}

void StackByteBufferTests::ConstructorTest1(Test& test)
{
    StackByteBuffer<10> buffer;

    ISHIKO_TEST_FAIL_IF_NEQ(buffer.capacity(), 10);
    ISHIKO_TEST_PASS();
}

void StackByteBufferTests::ZeroTest1(Test& test)
{
    StackByteBuffer<10> buffer;

    buffer.zero();

    ISHIKO_TEST_ABORT_IF_NEQ(buffer.capacity(), 10);

    for (size_t i = 0; i < buffer.capacity(); ++i)
    {
        ISHIKO_TEST_FAIL_IF_NEQ(buffer.data()[i], 0);
    }

    ISHIKO_TEST_PASS();
}

void StackByteBufferTests::WordAtTest1(Test& test)
{
    StackByteBuffer<10> buffer;
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

void StackByteBufferTests::BigEndianWordAtTest1(Test& test)
{
    StackByteBuffer<10> buffer;
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
