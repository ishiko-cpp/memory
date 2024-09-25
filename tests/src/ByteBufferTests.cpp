// SPDX-FileCopyrightText: 2021-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "ByteBufferTests.hpp"
#include "Ishiko/Memory/ByteBuffer.hpp"

using namespace Ishiko;

ByteBufferTests::ByteBufferTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "ByteBuffer tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("Copy constructor test 1", CopyConstructorTest1);
    append<HeapAllocationErrorsTest>("Move constructor test 1", MoveConstructorTest1);
    append<HeapAllocationErrorsTest>("Copy assignment test 1", CopyAssignmentOperatorTest1);
    append<HeapAllocationErrorsTest>("Move assignment test 1", MoveAssignmentOperatorTest1);
    append<HeapAllocationErrorsTest>("zero test 1", ZeroTest1);
    append<HeapAllocationErrorsTest>("wordAt test 1", WordAtTest1);
    append<HeapAllocationErrorsTest>("bigEndianWordAt test 1", BigEndianWordAtTest1);
}

void ByteBufferTests::ConstructorTest1(Test& test)
{
    ByteBuffer buffer{10};

    ISHIKO_TEST_FAIL_IF_NEQ(buffer.capacity(), 10);
    ISHIKO_TEST_PASS();
}

void ByteBufferTests::CopyConstructorTest1(Test& test)
{
    ByteBuffer buffer1{10};
    memcpy(buffer1.data(), "012345678", 10);

    ByteBuffer buffer2{buffer1};

    ISHIKO_TEST_FAIL_IF_NEQ(buffer1.capacity(), 10);
    ISHIKO_TEST_FAIL_IF_STR_NEQ((const char*)buffer1.data(), "012345678");
    ISHIKO_TEST_FAIL_IF_NEQ(buffer2.capacity(), 10);
    ISHIKO_TEST_FAIL_IF_STR_NEQ((const char*)buffer2.data(), "012345678");
    ISHIKO_TEST_PASS();
}

void ByteBufferTests::MoveConstructorTest1(Test& test)
{
    ByteBuffer buffer1{10};
    memcpy(buffer1.data(), "012345678", 10);

    ByteBuffer buffer2{std::move(buffer1)};

    ISHIKO_TEST_FAIL_IF_NEQ(buffer1.capacity(), 0);
    ISHIKO_TEST_FAIL_IF_NEQ(buffer1.data(), nullptr);
    ISHIKO_TEST_FAIL_IF_NEQ(buffer2.capacity(), 10);
    ISHIKO_TEST_FAIL_IF_STR_NEQ((const char*)buffer2.data(), "012345678");
    ISHIKO_TEST_PASS();
}

void ByteBufferTests::CopyAssignmentOperatorTest1(Test& test)
{
    ByteBuffer buffer1{10};
    memcpy(buffer1.data(), "012345678", 10);

    ByteBuffer buffer2{5};
    buffer2 = buffer1;

    ISHIKO_TEST_FAIL_IF_NEQ(buffer1.capacity(), 10);
    ISHIKO_TEST_FAIL_IF_STR_NEQ((const char*)buffer1.data(), "012345678");
    ISHIKO_TEST_FAIL_IF_NEQ(buffer2.capacity(), 10);
    ISHIKO_TEST_FAIL_IF_STR_NEQ((const char*)buffer2.data(), "012345678");
    ISHIKO_TEST_PASS();
}

void ByteBufferTests::MoveAssignmentOperatorTest1(Test& test)
{
    ByteBuffer buffer1{10};
    memcpy(buffer1.data(), "012345678", 10);

    ByteBuffer buffer2{5};
    buffer2 = std::move(buffer1);

    ISHIKO_TEST_FAIL_IF_NEQ(buffer1.capacity(), 5);
    ISHIKO_TEST_FAIL_IF_NEQ(buffer2.capacity(), 10);
    ISHIKO_TEST_FAIL_IF_STR_NEQ((const char*)buffer2.data(), "012345678");
    ISHIKO_TEST_PASS();
}

void ByteBufferTests::ZeroTest1(Test& test)
{
    ByteBuffer buffer{10};

    buffer.zero();

    ISHIKO_TEST_ABORT_IF_NEQ(buffer.capacity(), 10);
    
    for (size_t i = 0; i < buffer.capacity(); ++i)
    {
        ISHIKO_TEST_FAIL_IF_NEQ(buffer.data()[i], 0);
    }

    ISHIKO_TEST_PASS();
}

void ByteBufferTests::WordAtTest1(Test& test)
{
    ByteBuffer buffer{10};
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

void ByteBufferTests::BigEndianWordAtTest1(Test& test)
{
    ByteBuffer buffer{10};
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
