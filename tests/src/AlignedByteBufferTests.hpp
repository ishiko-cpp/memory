// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_MEMORY_TESTS_ALIGNEDBYTEBUFFERTESTS_HPP
#define GUARD_ISHIKO_CPP_MEMORY_TESTS_ALIGNEDBYTEBUFFERTESTS_HPP

#include <Ishiko/TestFramework/Core.hpp>

class AlignedByteBufferTests : public Ishiko::TestSequence
{
public:
    AlignedByteBufferTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void CopyConstructorTest1(Ishiko::Test& test);
};

#endif
