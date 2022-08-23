/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_MEMORY_TESTS_BIGENDIANWORDTESTS_HPP
#define GUARD_ISHIKO_CPP_MEMORY_TESTS_BIGENDIANWORDTESTS_HPP

#include <Ishiko/TestFramework/Core.hpp>

class BigEndianWordTests : public Ishiko::TestSequence
{
public:
    BigEndianWordTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void ConstructorTest2(Ishiko::Test& test);
};

#endif
