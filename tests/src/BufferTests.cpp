/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#include "BufferTests.hpp"
#include "Ishiko/Memory/Buffer.hpp"

using namespace Ishiko;

BufferTests::BufferTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "Buffer tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void BufferTests::ConstructorTest1(Test& test)
{
    Buffer buffer;

    ISHIKO_TEST_PASS();
}
