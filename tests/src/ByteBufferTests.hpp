/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_MEMORY_TESTS_BYTEBUFFERTESTS_HPP
#define GUARD_ISHIKO_CPP_MEMORY_TESTS_BYTEBUFFERTESTS_HPP

#include <Ishiko/TestFramework/Core.hpp>

class BufferTests : public Ishiko::TestSequence
{
public:
    BufferTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

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
