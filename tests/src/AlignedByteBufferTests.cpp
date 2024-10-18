// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "AlignedByteBufferTests.hpp"
#include "Ishiko/Memory/AlignedByteBuffer.hpp"

using namespace Ishiko;

AlignedByteBufferTests::AlignedByteBufferTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "AlignedByteBuffer tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void AlignedByteBufferTests::ConstructorTest1(Test& test)
{
    AlignedByteBuffer<128> buffer(10);

    ISHIKO_TEST_FAIL_IF_NEQ(buffer.capacity(), 10);
    ISHIKO_TEST_PASS();
}
