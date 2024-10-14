// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

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
