/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_MEMORY_TESTS_WORDTESTS_HPP_
#define _ISHIKO_CPP_MEMORY_TESTS_WORDTESTS_HPP_

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
