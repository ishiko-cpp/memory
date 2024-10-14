// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_MEMORY_MEMORYERRORCATEGORY_HPP
#define GUARD_ISHIKO_CPP_MEMORY_MEMORYERRORCATEGORY_HPP

#include <Ishiko/Errors.hpp>

namespace Ishiko
{
    class MemoryErrorCategory : public ErrorCategory
    {
    public:
        enum class Value
        {
            generic_error = -1,
            memory_allocation_error = -2
        };

        static const MemoryErrorCategory& Get() noexcept;

        const char* name() const noexcept override;
        const char* message(int ev, char* buffer, size_t len) const noexcept override;

    private:
        MemoryErrorCategory() noexcept = default;
    };

    void Fail(MemoryErrorCategory::Value value, const std::string& message, const char* file, int line,
        Error& error) noexcept;
}

#endif
