/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_MEMORY_TESTS_BUFFERTESTS_HPP_
#define _ISHIKO_CPP_MEMORY_TESTS_BUFFERTESTS_HPP_

#include <Ishiko/TestFramework/Core.hpp>

class BufferTests : public Ishiko::TestSequence
{
public:
    BufferTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void ZeroTest1(Ishiko::Test& test);
};

#endif
