// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "AlignedHeapByteBufferTests.hpp"
#include "Ishiko/Memory/AlignedHeapByteBuffer.hpp"
#include "Ishiko/Memory/HeapByteBuffer.hpp"

using namespace Ishiko;

AlignedHeapByteBufferTests::AlignedHeapByteBufferTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "AlignedHeapByteBuffer tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("Constructor test 2", ConstructorTest2);
    append<HeapAllocationErrorsTest>("Copy constructor test 1", CopyConstructorTest1);
    append<HeapAllocationErrorsTest>("Move constructor test 1", MoveConstructorTest1);
}

void AlignedHeapByteBufferTests::ConstructorTest1(Test& test)
{
    AlignedHeapByteBuffer<128> buffer(10);

    ISHIKO_TEST_FAIL_IF_NEQ(buffer.capacity(), 10);
    ISHIKO_TEST_FAIL_IF_NEQ(reinterpret_cast<uintptr_t>(buffer.data()) % 128, 0);
    ISHIKO_TEST_PASS();
}

void AlignedHeapByteBufferTests::ConstructorTest2(Test& test)
{
    HeapByteBuffer buffer1(10);
    memcpy(buffer1.data(), "012345678", 10);

    AlignedHeapByteBuffer<128> buffer2(buffer1);

    ISHIKO_TEST_FAIL_IF_NEQ(buffer1.capacity(), 10);
    ISHIKO_TEST_FAIL_IF_STR_NEQ((const char*)buffer1.data(), "012345678");
    ISHIKO_TEST_FAIL_IF_NEQ(buffer2.capacity(), 10);
    ISHIKO_TEST_FAIL_IF_STR_NEQ((const char*)buffer2.data(), "012345678");
    ISHIKO_TEST_FAIL_IF_NEQ(reinterpret_cast<uintptr_t>(buffer2.data()) % 128, 0);
    ISHIKO_TEST_PASS();
}

void AlignedHeapByteBufferTests::CopyConstructorTest1(Test& test)
{
    AlignedHeapByteBuffer<128> buffer1(10);
    memcpy(buffer1.data(), "012345678", 10);

    AlignedHeapByteBuffer<128> buffer2(buffer1);

    ISHIKO_TEST_FAIL_IF_NEQ(buffer1.capacity(), 10);
    ISHIKO_TEST_FAIL_IF_STR_NEQ((const char*)buffer1.data(), "012345678");
    ISHIKO_TEST_FAIL_IF_NEQ(buffer2.capacity(), 10);
    ISHIKO_TEST_FAIL_IF_STR_NEQ((const char*)buffer2.data(), "012345678");
    ISHIKO_TEST_FAIL_IF_NEQ(reinterpret_cast<uintptr_t>(buffer2.data()) % 128, 0);
    ISHIKO_TEST_PASS();
}

void AlignedHeapByteBufferTests::MoveConstructorTest1(Test& test)
{
    AlignedHeapByteBuffer<128> buffer1(10);
    memcpy(buffer1.data(), "012345678", 10);

    AlignedHeapByteBuffer<128> buffer2(std::move(buffer1));

    ISHIKO_TEST_FAIL_IF_NEQ(buffer1.capacity(), 0);
    ISHIKO_TEST_FAIL_IF_NEQ(buffer1.data(), nullptr);
    ISHIKO_TEST_FAIL_IF_NEQ(buffer2.capacity(), 10);
    ISHIKO_TEST_FAIL_IF_STR_NEQ((const char*)buffer2.data(), "012345678");
    ISHIKO_TEST_FAIL_IF_NEQ(reinterpret_cast<uintptr_t>(buffer2.data()) % 128, 0);
    ISHIKO_TEST_PASS();
}
