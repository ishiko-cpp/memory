// SPDX-FileCopyrightText: 2005-2025 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_MEMORY_TESTS_INPLACEBYTEBUFFERTESTS_HPP
#define GUARD_ISHIKO_CPP_MEMORY_TESTS_INPLACEBYTEBUFFERTESTS_HPP

#include <Ishiko/TestFramework/Core.hpp>

class InplaceByteBufferTests : public Ishiko::TestSequence
{
public:
    InplaceByteBufferTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void ZeroTest1(Ishiko::Test& test);
    static void WordAtTest1(Ishiko::Test& test);
    static void BigEndianWordAtTest1(Ishiko::Test& test);
    static void AsByteBufferTest1(Ishiko::Test& test);
    static void ToHexStringTest1(Ishiko::Test& test);
};

#endif
