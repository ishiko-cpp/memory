/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_MEMORY_WORD_HPP_
#define _ISHIKO_CPP_MEMORY_WORD_HPP_

#include "Byte.hpp"
#include <cstdint>

namespace Ishiko
{

class Word
{
public:
    inline Word(uint16_t word) noexcept;

    inline Byte operator[](size_t pos) const noexcept;

    inline Word& operator=(uint16_t word) noexcept;

    inline bool operator==(const Word& other) const noexcept;
    inline bool operator!=(const Word& other) const noexcept;

    inline uint16_t toUint16() const noexcept;

private:
    Byte m_bytes[2];
};

Word::Word(uint16_t word) noexcept
{
    *(reinterpret_cast<uint16_t*>(m_bytes)) = word;
}

Byte Word::operator[](size_t pos) const noexcept
{
    return m_bytes[pos];
}

Word& Word::operator=(uint16_t word) noexcept
{
    *(reinterpret_cast<uint16_t*>(m_bytes)) = word;
    return *this;
}

bool Word::operator==(const Word& other) const noexcept
{
    return (toUint16() == other.toUint16());
}

bool Word::operator!=(const Word& other) const noexcept
{
    return (toUint16() != other.toUint16());
}

uint16_t Word::toUint16() const noexcept
{
    return *(reinterpret_cast<const uint16_t*>(m_bytes));
}

}

#endif
