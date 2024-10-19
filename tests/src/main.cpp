// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "AlignedHeapByteBufferTests.hpp"
#include "BigEndianWordTests.hpp"
#include "ByteBufferPoolTests.hpp"
#include "DefaultAllocatorTests.hpp"
#include "HeapByteBufferTests.hpp"
#include "StackByteBufferTests.hpp"
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
    theTests.append<HeapByteBufferTests>();
    theTests.append<AlignedHeapByteBufferTests>();
    theTests.append<ByteBufferPoolTests>();
    theTests.append<StackByteBufferTests>();

    return theTestHarness.run();
}
