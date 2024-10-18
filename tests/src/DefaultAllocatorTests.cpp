// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "DefaultAllocatorTests.hpp"
#include "Ishiko/Memory/DefaultAllocator.hpp"

using namespace Ishiko;

DefaultAllocatorTests::DefaultAllocatorTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "DefaultAllocator tests", context)
{
    append<HeapAllocationErrorsTest>("NewObject test 1", NewObjectTest1);
    append<HeapAllocationErrorsTest>("NewObjectArray test 1", NewObjectArrayTest1);
}

void DefaultAllocatorTests::NewObjectTest1(Test& test)
{
    Error error;

    int* pointer = NewObject<int>(error, 5);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(*pointer, 5);

    delete pointer;

    ISHIKO_TEST_PASS();
}

void DefaultAllocatorTests::NewObjectArrayTest1(Test& test)
{
    Error error;

    int* pointer = NewObjectArray<int>(10, error);

    ISHIKO_TEST_FAIL_IF(error);

    delete[] pointer;

    ISHIKO_TEST_PASS();
}
