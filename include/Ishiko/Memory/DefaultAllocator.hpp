// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_MEMORY_DEFAULTALLOCATOR_HPP
#define GUARD_ISHIKO_CPP_MEMORY_DEFAULTALLOCATOR_HPP

#include "MemoryErrorCategory.hpp"
#include <Ishiko/BasePlatform.hpp>
#include <Ishiko/Errors.hpp>

namespace Ishiko
{
    template<typename T, typename... ArgTypes>
    T* NewObject(Error& error, ArgTypes&&... args) noexcept;

    template<typename T>
    void DeleteObject(T* ptr) noexcept;

    template<typename T>
    T* NewObjectArray(size_t size, Error& error) noexcept;

    template<typename T>
    void DeleteObjectArray(T* ptr) noexcept;

    template<typename T, typename... ArgTypes>
    T* NewAlignedObject(size_t alignment, Error& error, ArgTypes&&... args) noexcept;

    template<typename T>
    void DeleteAlignedObject(T* ptr) noexcept;

    template<typename T>
    T* NewAlignedObjectArray(size_t alignment, size_t size, Error& error) noexcept;

    template<typename T>
    void DeleteAlignedObjectArray(size_t size, T* ptr) noexcept;
}

template<typename T, typename... ArgTypes>
T* Ishiko::NewObject(Error& error, ArgTypes&&... args) noexcept
{
    static_assert(noexcept(T(std::forward<ArgTypes>(args)...)));

    T* result = new(std::nothrow) T(std::forward<ArgTypes>(args)...);
    if (result == nullptr)
    {
        Fail(MemoryErrorCategory::Value::memory_allocation_error, "Failed to allocate memory", __FILE__, __LINE__,
            error);
    }
    return result;
}

template<typename T>
void Ishiko::DeleteObject(T* ptr) noexcept
{
    delete ptr;
}

template<typename T>
T* Ishiko::NewObjectArray(size_t size, Error& error) noexcept
{
    static_assert(noexcept(T()));

    T* result = new(std::nothrow) T[size];
    if (result == nullptr)
    {
        Fail(MemoryErrorCategory::Value::memory_allocation_error, "Failed to allocate memory", __FILE__, __LINE__,
            error);
    }
    return result;
}

template<typename T>
void Ishiko::DeleteObjectArray(T* ptr) noexcept
{
    delete[] ptr;
}

template<typename T, typename... ArgTypes>
T* Ishiko::NewAlignedObject(size_t alignment, Error& error, ArgTypes&&... args) noexcept
{
    static_assert(noexcept(T(std::forward<ArgTypes>(args)...)));

#if ISHIKO_COMPILER == ISHIKO_COMPILER_GCC
    void* allocated_memory = aligned_alloc(alignment, sizeof(T));
#elif ISHIKO_COMPILER == ISHIKO_COMPILER_MSVC
    void* allocated_memory = _aligned_malloc(sizeof(T), alignment);
#else
#error Unsupported or unrecognized compiler
#endif

    if (allocated_memory == nullptr)
    {
        Fail(MemoryErrorCategory::Value::memory_allocation_error, "Failed to allocate memory", __FILE__, __LINE__,
            error);
    }

    return new(allocated_memory) T(std::forward<ArgTypes>(args)...);
}

template<typename T>
void Ishiko::DeleteAlignedObject(T* ptr) noexcept
{
    if (ptr)
    {
        ptr->~T();
#if ISHIKO_COMPILER == ISHIKO_COMPILER_GCC
        free(ptr);
#elif ISHIKO_COMPILER == ISHIKO_COMPILER_MSVC
        _aligned_free(ptr);
#else
#error Unsupported or unrecognized compiler
#endif
    }
}

template<typename T>
T* Ishiko::NewAlignedObjectArray(size_t alignment, size_t size, Error& error) noexcept
{
    static_assert(noexcept(T()));

    size_t allocation_size = (size * sizeof(T));
    if (allocation_size == 0)
    {
        allocation_size = sizeof(T);
    }

#if ISHIKO_COMPILER == ISHIKO_COMPILER_GCC
    T* allocated_memory = (T*)aligned_alloc(alignment, allocation_size);
#elif ISHIKO_COMPILER == ISHIKO_COMPILER_MSVC
    T* allocated_memory = (T*)_aligned_malloc(allocation_size, alignment);
#else
#error Unsupported or unrecognized compiler
#endif

    if (allocated_memory == nullptr)
    {
        Fail(MemoryErrorCategory::Value::memory_allocation_error, "Failed to allocate memory", __FILE__, __LINE__,
            error);
    }

    for (size_t i = 0; i < size; ++i)
    {
        new(allocated_memory + i) T();
    }

    return allocated_memory;
}


template<typename T>
void Ishiko::DeleteAlignedObjectArray(size_t size, T* ptr) noexcept
{
    if (ptr)
    {
        for (size_t i = 0; i < size; ++i)
        {
            ptr[i].~T();
        }
#if ISHIKO_COMPILER == ISHIKO_COMPILER_GCC
        free(ptr);
#elif ISHIKO_COMPILER == ISHIKO_COMPILER_MSVC
        _aligned_free(ptr);
#else
#error Unsupported or unrecognized compiler
#endif
    }
}

#endif
