/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#include "BigEndianWordTests.hpp"
#include "BufferTests.hpp"
#include "FixedBufferTests.hpp"
#include "WordTests.hpp"
#include "Ishiko/Memory/linkoptions.hpp"
#include <Ishiko/TestFramework/Core.hpp>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("IshikoMemory");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<WordTests>();
    theTests.append<BigEndianWordTests>();
    theTests.append<BufferTests>();
    theTests.append<FixedBufferTests>();

    return theTestHarness.run();
}
