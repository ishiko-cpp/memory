// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "AlignedByteBufferTests.hpp"
#include "Ishiko/Memory/AlignedByteBuffer.hpp"

using namespace Ishiko;

AlignedByteBufferTests::AlignedByteBufferTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "AlignedByteBuffer tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("Copy constructor test 1", CopyConstructorTest1);
}

void AlignedByteBufferTests::ConstructorTest1(Test& test)
{
    AlignedByteBuffer<128> buffer(10);

    ISHIKO_TEST_FAIL_IF_NEQ(buffer.capacity(), 10);
    ISHIKO_TEST_FAIL_IF_NEQ(reinterpret_cast<uintptr_t>(buffer.data()) % 128, 0);
    ISHIKO_TEST_PASS();
}

void AlignedByteBufferTests::CopyConstructorTest1(Test& test)
{
    AlignedByteBuffer<128> buffer1(10);
    memcpy(buffer1.data(), "012345678", 10);

    AlignedByteBuffer<128> buffer2(buffer1);

    ISHIKO_TEST_FAIL_IF_NEQ(buffer1.capacity(), 10);
    ISHIKO_TEST_FAIL_IF_STR_NEQ((const char*)buffer1.data(), "012345678");
    ISHIKO_TEST_FAIL_IF_NEQ(buffer2.capacity(), 10);
    ISHIKO_TEST_FAIL_IF_STR_NEQ((const char*)buffer2.data(), "012345678");
    ISHIKO_TEST_PASS();
}
