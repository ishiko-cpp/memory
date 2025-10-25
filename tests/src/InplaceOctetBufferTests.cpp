// SPDX-FileCopyrightText: 2005-2025 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "InplaceOctetBufferTests.hpp"
#include "Ishiko/Memory/InplaceOctetBuffer.hpp"

using namespace Ishiko;

InplaceOctetBufferTests::InplaceOctetBufferTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "InplaceOctetBuffer tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("zero test 1", ZeroTest1);
}

void InplaceOctetBufferTests::ConstructorTest1(Test& test)
{
    InplaceOctetBuffer<10> buffer;

    ISHIKO_TEST_FAIL_IF_NEQ(buffer.capacity(), 10);
    ISHIKO_TEST_PASS();
}

void InplaceOctetBufferTests::ZeroTest1(Test& test)
{
    InplaceOctetBuffer<10> buffer;

    buffer.zero();

    ISHIKO_TEST_ABORT_IF_NEQ(buffer.capacity(), 10);

    for (size_t i = 0; i < buffer.capacity(); ++i)
    {
        ISHIKO_TEST_FAIL_IF_NEQ(buffer.data()[i], 0);
    }

    ISHIKO_TEST_PASS();
}
