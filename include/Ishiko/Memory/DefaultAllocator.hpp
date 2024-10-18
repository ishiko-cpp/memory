// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_MEMORY_DEFAULTALLOCATOR_HPP
#define GUARD_ISHIKO_CPP_MEMORY_DEFAULTALLOCATOR_HPP

#include "MemoryErrorCategory.hpp"
#include <Ishiko/Errors.hpp>

namespace Ishiko
{
    template<typename T, typename... ArgTypes>
    T* NewObject(Error& error, ArgTypes&&... args) noexcept;

    template<typename T>
    T* NewObjectArray(size_t size, Error& error) noexcept;
}

template<typename T, typename... ArgTypes>
T* Ishiko::NewObject(Error& error, ArgTypes&&... args) noexcept
{
    T* result = new(std::nothrow) T(std::forward<ArgTypes>(args)...);
    if (result == nullptr)
    {
        Fail(MemoryErrorCategory::Value::memory_allocation_error, "Failed to allocate memory", __FILE__, __LINE__,
            error);
    }
    return result;
}

template<typename T>
T* Ishiko::NewObjectArray(size_t size, Error& error) noexcept
{
    T* result = new(std::nothrow) T[size];
    if (result == nullptr)
    {
        Fail(MemoryErrorCategory::Value::memory_allocation_error, "Failed to allocate memory", __FILE__, __LINE__,
            error);
    }
    return result;
}

#endif
