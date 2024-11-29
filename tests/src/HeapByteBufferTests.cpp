// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "HeapByteBufferTests.hpp"
#include "Ishiko/Memory/HeapByteBuffer.hpp"

using namespace Ishiko;

HeapByteBufferTests::HeapByteBufferTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "HeapByteBuffer tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("Copy constructor test 1", CopyConstructorTest1);
    append<HeapAllocationErrorsTest>("Move constructor test 1", MoveConstructorTest1);
    append<HeapAllocationErrorsTest>("Copy assignment test 1", CopyAssignmentOperatorTest1);
    append<HeapAllocationErrorsTest>("Move assignment test 1", MoveAssignmentOperatorTest1);
    append<HeapAllocationErrorsTest>("zero test 1", ZeroTest1);
    append<HeapAllocationErrorsTest>("wordAt test 1", WordAtTest1);
    append<HeapAllocationErrorsTest>("bigEndianWordAt test 1", BigEndianWordAtTest1);
    append<HeapAllocationErrorsTest>("toHexStringTest1 test 1", ToHexStringTest1);
}

void HeapByteBufferTests::ConstructorTest1(Test& test)
{
    HeapByteBuffer buffer{10};

    ISHIKO_TEST_FAIL_IF_NEQ(buffer.capacity(), 10);
    ISHIKO_TEST_PASS();
}

void HeapByteBufferTests::CopyConstructorTest1(Test& test)
{
    HeapByteBuffer buffer1{10};
    memcpy(buffer1.data(), "012345678", 10);

    HeapByteBuffer buffer2{buffer1};

    ISHIKO_TEST_FAIL_IF_NEQ(buffer1.capacity(), 10);
    ISHIKO_TEST_FAIL_IF_STR_NEQ((const char*)buffer1.data(), "012345678");
    ISHIKO_TEST_FAIL_IF_NEQ(buffer2.capacity(), 10);
    ISHIKO_TEST_FAIL_IF_STR_NEQ((const char*)buffer2.data(), "012345678");
    ISHIKO_TEST_PASS();
}

void HeapByteBufferTests::MoveConstructorTest1(Test& test)
{
    HeapByteBuffer buffer1{10};
    memcpy(buffer1.data(), "012345678", 10);

    HeapByteBuffer buffer2{std::move(buffer1)};

    ISHIKO_TEST_FAIL_IF_NEQ(buffer1.capacity(), 0);
    ISHIKO_TEST_FAIL_IF_NEQ(buffer1.data(), nullptr);
    ISHIKO_TEST_FAIL_IF_NEQ(buffer2.capacity(), 10);
    ISHIKO_TEST_FAIL_IF_STR_NEQ((const char*)buffer2.data(), "012345678");
    ISHIKO_TEST_PASS();
}

void HeapByteBufferTests::CopyAssignmentOperatorTest1(Test& test)
{
    HeapByteBuffer buffer1{10};
    memcpy(buffer1.data(), "012345678", 10);

    HeapByteBuffer buffer2{5};
    buffer2 = buffer1;

    ISHIKO_TEST_FAIL_IF_NEQ(buffer1.capacity(), 10);
    ISHIKO_TEST_FAIL_IF_STR_NEQ((const char*)buffer1.data(), "012345678");
    ISHIKO_TEST_FAIL_IF_NEQ(buffer2.capacity(), 10);
    ISHIKO_TEST_FAIL_IF_STR_NEQ((const char*)buffer2.data(), "012345678");
    ISHIKO_TEST_PASS();
}

void HeapByteBufferTests::MoveAssignmentOperatorTest1(Test& test)
{
    HeapByteBuffer buffer1{10};
    memcpy(buffer1.data(), "012345678", 10);

    HeapByteBuffer buffer2{5};
    buffer2 = std::move(buffer1);

    ISHIKO_TEST_FAIL_IF_NEQ(buffer1.capacity(), 5);
    ISHIKO_TEST_FAIL_IF_NEQ(buffer2.capacity(), 10);
    ISHIKO_TEST_FAIL_IF_STR_NEQ((const char*)buffer2.data(), "012345678");
    ISHIKO_TEST_PASS();
}

void HeapByteBufferTests::ZeroTest1(Test& test)
{
    HeapByteBuffer buffer{10};

    buffer.zero();

    ISHIKO_TEST_ABORT_IF_NEQ(buffer.capacity(), 10);
    
    for (size_t i = 0; i < buffer.capacity(); ++i)
    {
        ISHIKO_TEST_FAIL_IF_NEQ(buffer.data()[i], 0);
    }

    ISHIKO_TEST_PASS();
}

void HeapByteBufferTests::WordAtTest1(Test& test)
{
    HeapByteBuffer buffer{10};
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

void HeapByteBufferTests::BigEndianWordAtTest1(Test& test)
{
    HeapByteBuffer buffer{10};
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

void HeapByteBufferTests::ToHexStringTest1(Test& test)
{
    HeapByteBuffer buffer = HeapByteBuffer::From((Byte*)"0123456z\x0\x1", 10);

    ISHIKO_TEST_FAIL_IF_NEQ(buffer.toHexString(), "303132333435367a0001");
    ISHIKO_TEST_PASS();
}
