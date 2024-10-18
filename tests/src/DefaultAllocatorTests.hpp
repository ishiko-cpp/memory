// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_MEMORY_TESTS_DEFAULTALLOCATORTESTS_HPP
#define GUARD_ISHIKO_CPP_MEMORY_TESTS_DEFAULTALLOCATORTESTS_HPP

#include <Ishiko/TestFramework/Core.hpp>

class DefaultAllocatorTests : public Ishiko::TestSequence
{
public:
    DefaultAllocatorTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void NewObjectTest1(Ishiko::Test& test);
    static void NewObjectArrayTest1(Ishiko::Test& test);
    static void NewObjectArrayTest2(Ishiko::Test& test);
    static void NewObjectArrayTest3(Ishiko::Test& test);
    static void NewAlignedObjectTest1(Ishiko::Test& test);
    static void NewAlignedObjectArrayTest1(Ishiko::Test& test);
    static void NewAlignedObjectArrayTest2(Ishiko::Test& test);
    static void NewAlignedObjectArrayTest3(Ishiko::Test& test);
};

#endif
