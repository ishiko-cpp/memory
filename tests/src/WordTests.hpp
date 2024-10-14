// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_MEMORY_TESTS_WORDTESTS_HPP
#define GUARD_ISHIKO_CPP_MEMORY_TESTS_WORDTESTS_HPP

#include <Ishiko/TestFramework/Core.hpp>

class WordTests : public Ishiko::TestSequence
{
public:
    WordTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void ConstructorTest2(Ishiko::Test& test);
};

#endif
