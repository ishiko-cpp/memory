// SPDX-FileCopyrightText: 2005-2025 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_MEMORY_TESTS_INPLACEOCTETBUFFERTESTS_HPP
#define GUARD_ISHIKO_CPP_MEMORY_TESTS_INPLACEOCTETBUFFERTESTS_HPP

#include <Ishiko/TestFramework/Core.hpp>

class InplaceOctetBufferTests : public Ishiko::TestSequence
{
public:
    InplaceOctetBufferTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void ZeroTest1(Ishiko::Test& test);
    static void BigEndianWordAtTest1(Ishiko::Test& test);
    static void ToHexStringTest1(Ishiko::Test& test);
};

#endif
