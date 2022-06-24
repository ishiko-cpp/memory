/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#include "BigEndianWordTests.hpp"
#include "Ishiko/Memory/BigEndianWord.hpp"

using namespace Ishiko;

BigEndianWordTests::BigEndianWordTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "BigEndianWord tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void BigEndianWordTests::ConstructorTest1(Test& test)
{
    BigEndianWord word(0);

    ISHIKO_TEST_FAIL_IF_NEQ(word.toUint16(), 0);
    ISHIKO_TEST_PASS();
}
