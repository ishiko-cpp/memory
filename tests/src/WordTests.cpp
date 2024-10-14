// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "WordTests.hpp"
#include "Ishiko/Memory/Word.hpp"

using namespace Ishiko;

WordTests::WordTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "Word tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("Constructor test 2", ConstructorTest2);
}

void WordTests::ConstructorTest1(Test& test)
{
    Word word(0);

    ISHIKO_TEST_FAIL_IF_NEQ(word[0], 0);
    ISHIKO_TEST_FAIL_IF_NEQ(word[1], 0);
    ISHIKO_TEST_FAIL_IF_NEQ(word.toUint16(), 0);
    ISHIKO_TEST_PASS();
}

void WordTests::ConstructorTest2(Test& test)
{
    Word word(255);

    ISHIKO_TEST_FAIL_IF_NEQ(word[0], 255);
    ISHIKO_TEST_FAIL_IF_NEQ(word[1], 0);
    ISHIKO_TEST_FAIL_IF_NEQ(word.toUint16(), 255);
    ISHIKO_TEST_PASS();
}
