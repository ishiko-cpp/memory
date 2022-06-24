/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_MEMORY_BIGENDIANWORD_HPP_
#define _ISHIKO_CPP_MEMORY_BIGENDIANWORD_HPP_

#include "Byte.hpp"
#include <cstdint>
#include <stddef.h>

namespace Ishiko
{

class BigEndianWord
{
public:
    inline BigEndianWord(uint16_t word) noexcept;

    inline Byte operator[](size_t pos) const noexcept;

    inline BigEndianWord& operator=(uint16_t word) noexcept;

    inline bool operator==(const BigEndianWord& other) const noexcept;
    inline bool operator!=(const BigEndianWord& other) const noexcept;

    inline uint16_t toUint16() const noexcept;

    inline const Byte* asBytes() const noexcept;

private:
    Byte m_bytes[2];
};

BigEndianWord::BigEndianWord(uint16_t word) noexcept
{
    m_bytes[0] = *(reinterpret_cast<Byte*>(&word) + 1);
    m_bytes[1] = *reinterpret_cast<Byte*>(&word);
}

Byte BigEndianWord::operator[](size_t pos) const noexcept
{
    return m_bytes[pos];
}

BigEndianWord& BigEndianWord::operator=(uint16_t word) noexcept
{
    m_bytes[0] = *(reinterpret_cast<Byte*>(&word) + 1);
    m_bytes[1] = *reinterpret_cast<Byte*>(&word);
    return *this;
}

bool BigEndianWord::operator==(const BigEndianWord& other) const noexcept
{
    return (*reinterpret_cast<const uint16_t*>(m_bytes) == *reinterpret_cast<const uint16_t*>(other.m_bytes));
}

bool BigEndianWord::operator!=(const BigEndianWord& other) const noexcept
{
    return (*reinterpret_cast<const uint16_t*>(m_bytes) != *reinterpret_cast<const uint16_t*>(other.m_bytes));
}

uint16_t BigEndianWord::toUint16() const noexcept
{
    return ((m_bytes[0] << 8) + m_bytes[1]);
}

const Byte* BigEndianWord::asBytes() const noexcept
{
    return m_bytes;
}

}

#endif
