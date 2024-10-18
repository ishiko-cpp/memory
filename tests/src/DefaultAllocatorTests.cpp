// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "DefaultAllocatorTests.hpp"
#include "Ishiko/Memory/DefaultAllocator.hpp"

using namespace Ishiko;

namespace
{
    struct Events
    {
        size_t destructor_calls = 0;
    };

    class MockClass
    {
    public:
        MockClass() noexcept = default;
        MockClass(Events& events) noexcept;
        ~MockClass();

        void setEvents(Events& events) noexcept;

    private:
        Events* m_events = nullptr;
    };

    MockClass::MockClass(Events& events) noexcept
        : m_events(&events)
    {
    }

    MockClass::~MockClass()
    {
        ++m_events->destructor_calls;
    }

    void MockClass::setEvents(Events& events) noexcept
    {
        m_events = &events;
    }
}

DefaultAllocatorTests::DefaultAllocatorTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "DefaultAllocator tests", context)
{
    append<HeapAllocationErrorsTest>("NewObject test 1", NewObjectTest1);
    append<HeapAllocationErrorsTest>("NewObjectArray test 1", NewObjectArrayTest1);
    append<HeapAllocationErrorsTest>("NewAlignedObject test 1", NewAlignedObjectTest1);
}

void DefaultAllocatorTests::NewObjectTest1(Test& test)
{
    Error error;

    Events events;
    MockClass* ptr = NewObject<MockClass>(error, events);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_EQ(ptr, nullptr);

    DeleteObject(ptr);

    ISHIKO_TEST_FAIL_IF_NEQ(events.destructor_calls, 1);
    ISHIKO_TEST_PASS();
}

void DefaultAllocatorTests::NewObjectArrayTest1(Test& test)
{
    Error error;

    Events events;
    MockClass* ptr = NewObjectArray<MockClass>(10, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_ABORT_IF_EQ(ptr, nullptr);

    for (size_t i = 0; i < 10; ++i)
    {
        ptr[i].setEvents(events);
    }

    DeleteObjectArray(ptr);

    ISHIKO_TEST_FAIL_IF_NEQ(events.destructor_calls, 10);
    ISHIKO_TEST_PASS();
}

void DefaultAllocatorTests::NewAlignedObjectTest1(Test& test)
{
    Error error;

    Events events;
    MockClass* ptr = NewAlignedObject<MockClass>(error, events);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_EQ(ptr, nullptr);

    DeleteAlignedObject(ptr);

    ISHIKO_TEST_FAIL_IF_NEQ(events.destructor_calls, 1);
    ISHIKO_TEST_PASS();
}
