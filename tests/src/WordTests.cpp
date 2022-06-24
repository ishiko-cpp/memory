/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#include "WordTests.hpp"
#include "Ishiko/Memory/Word.hpp"

using namespace Ishiko;

WordTests::WordTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "Word tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void WordTests::ConstructorTest1(Test& test)
{
    Word word(0);

    ISHIKO_TEST_FAIL_IF_NEQ(word.toUint16(), 0);
    ISHIKO_TEST_PASS();
}
