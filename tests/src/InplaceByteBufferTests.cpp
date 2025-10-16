// SPDX-FileCopyrightText: 2005-2025 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "InplaceByteBufferTests.hpp"
#include "Ishiko/Memory/InplaceByteBuffer.hpp"

using namespace Ishiko;

InplaceByteBufferTests::InplaceByteBufferTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "InplaceByteBuffer tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("zero test 1", ZeroTest1);
    append<HeapAllocationErrorsTest>("wordAt test 1", WordAtTest1);
    append<HeapAllocationErrorsTest>("bigEndianWordAt test 1", BigEndianWordAtTest1);
    append<HeapAllocationErrorsTest>("asByteBuffer test 1", AsByteBufferTest1);
    append<HeapAllocationErrorsTest>("toHexStringTest1 test 1", ToHexStringTest1);
}

void InplaceByteBufferTests::ConstructorTest1(Test& test)
{
    InplaceByteBuffer<10> buffer;

    ISHIKO_TEST_FAIL_IF_NEQ(buffer.capacity(), 10);
    ISHIKO_TEST_PASS();
}

void InplaceByteBufferTests::ZeroTest1(Test& test)
{
    InplaceByteBuffer<10> buffer;

    buffer.zero();

    ISHIKO_TEST_ABORT_IF_NEQ(buffer.capacity(), 10);

    for (size_t i = 0; i < buffer.capacity(); ++i)
    {
        ISHIKO_TEST_FAIL_IF_NEQ(buffer.data()[i], 0);
    }

    ISHIKO_TEST_PASS();
}

void InplaceByteBufferTests::WordAtTest1(Test& test)
{
    InplaceByteBuffer<10> buffer;
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

void InplaceByteBufferTests::BigEndianWordAtTest1(Test& test)
{
    InplaceByteBuffer<10> buffer;
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

void InplaceByteBufferTests::AsByteBufferTest1(Test& test)
{
    InplaceByteBuffer<10> buffer;
    ByteBufferRef byte_buffer = buffer.asByteBuffer();

    ISHIKO_TEST_FAIL_IF_NEQ(byte_buffer.data(), buffer.data());
    ISHIKO_TEST_FAIL_IF_NEQ(byte_buffer.capacity(), buffer.capacity());
    ISHIKO_TEST_PASS();
}

void InplaceByteBufferTests::ToHexStringTest1(Test& test)
{
    InplaceByteBuffer<10> buffer = InplaceByteBuffer<10>::From((Byte*)"0123456z\x0\x1");

    ISHIKO_TEST_FAIL_IF_NEQ(buffer.toHexString(), "303132333435367a0001");
    ISHIKO_TEST_PASS();
}
