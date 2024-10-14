// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "MemoryErrorCategory.hpp"

using namespace Ishiko;

const MemoryErrorCategory& MemoryErrorCategory::Get() noexcept
{
    static MemoryErrorCategory the_category;
    return the_category;
}

const char* MemoryErrorCategory::name() const noexcept
{
    return "Ishiko::MemoryErrorCategory";
}

const char* MemoryErrorCategory::message(int ev, char* buffer, size_t len) const noexcept
{
    switch (static_cast<Value>(ev))
    {
    case Value::generic_error:
        return "generic error";

    case Value::memory_allocation_error:
        return "memory allocation error";

    default:
        return "unknown value";
    }
}

void Ishiko::Fail(MemoryErrorCategory::Value value, const std::string& message, const char* file, int line,
    Error& error) noexcept
{
    error.fail(MemoryErrorCategory::Get(), static_cast<int>(value), message, file, line);
}
