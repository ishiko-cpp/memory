/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_MEMORY_TESTS_FIXEDBYTEBUFFERTESTS_HPP
#define GUARD_ISHIKO_CPP_MEMORY_TESTS_FIXEDBYTEBUFFERTESTS_HPP

#include <Ishiko/TestFramework/Core.hpp>

class FixedBufferTests : public Ishiko::TestSequence
{
public:
    FixedBufferTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void ZeroTest1(Ishiko::Test& test);
    static void WordAtTest1(Ishiko::Test& test);
    static void BigEndianWordAtTest1(Ishiko::Test& test);
};

#endif
