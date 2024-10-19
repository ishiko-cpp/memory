// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "AlignedByteBufferTests.hpp"
#include "BigEndianWordTests.hpp"
#include "ByteBufferPoolTests.hpp"
#include "ByteBufferTests.hpp"
#include "DefaultAllocatorTests.hpp"
#include "FixedByteBufferTests.hpp"
#include "WordTests.hpp"
#include "Ishiko/Memory/linkoptions.hpp"
#include <Ishiko/TestFramework/Core.hpp>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("IshikoMemory");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<DefaultAllocatorTests>();
    theTests.append<WordTests>();
    theTests.append<BigEndianWordTests>();
    theTests.append<ByteBufferTests>();
    theTests.append<AlignedByteBufferTests>();
    theTests.append<ByteBufferPoolTests>();
    theTests.append<FixedBufferTests>();

    return theTestHarness.run();
}
