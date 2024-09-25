// SPDX-FileCopyrightText: 2021-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_MEMORY_TESTS_BYTEBUFFERPOOLTESTS_HPP
#define GUARD_ISHIKO_CPP_MEMORY_TESTS_BYTEBUFFERPOOLTESTS_HPP

#include <Ishiko/TestFramework/Core.hpp>

class ByteBufferPoolTests : public Ishiko::TestSequence
{
public:
    ByteBufferPoolTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void AcquireTest1(Ishiko::Test& test);
};

#endif
