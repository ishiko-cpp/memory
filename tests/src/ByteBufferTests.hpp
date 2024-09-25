// SPDX-FileCopyrightText: 2021-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_MEMORY_TESTS_BYTEBUFFERTESTS_HPP
#define GUARD_ISHIKO_CPP_MEMORY_TESTS_BYTEBUFFERTESTS_HPP

#include <Ishiko/TestFramework/Core.hpp>

class ByteBufferTests : public Ishiko::TestSequence
{
public:
    ByteBufferTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void CopyConstructorTest1(Ishiko::Test& test);
    static void MoveConstructorTest1(Ishiko::Test& test);
    static void CopyAssignmentOperatorTest1(Ishiko::Test& test);
    static void MoveAssignmentOperatorTest1(Ishiko::Test& test);
    static void ZeroTest1(Ishiko::Test& test);
    static void WordAtTest1(Ishiko::Test& test);
    static void BigEndianWordAtTest1(Ishiko::Test& test);
};

#endif
