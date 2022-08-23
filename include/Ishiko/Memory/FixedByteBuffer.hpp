/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_MEMORY_FIXEDBYTEBUFFER_HPP
#define GUARD_ISHIKO_CPP_MEMORY_FIXEDBYTEBUFFER_HPP

#include "BigEndianWord.hpp"
#include "Byte.hpp"
#include "Word.hpp"
#include <cstring>

namespace Ishiko
{

// TODO: same as Buffer but fixed size and on the stack
template<size_t N>
class FixedBuffer
{
public:
    static FixedBuffer<N> From(const Byte* bytes);

    void zero() noexcept;

    Byte operator[](size_t pos) const noexcept;

    Byte* data() noexcept;
    size_t capacity() noexcept;

    void copyTo(Byte* buffer) const noexcept;

    Word wordAt(size_t pos) const;
    Word& wordAt(size_t pos);
    BigEndianWord bigEndianWordAt(size_t pos) const;
    BigEndianWord& bigEndianWordAt(size_t pos);

    bool operator==(const FixedBuffer<N>& other) const noexcept;
    bool operator!=(const FixedBuffer<N>& other) const noexcept;

private:
    Byte m_data[N];
};

template<size_t N>
FixedBuffer<N> FixedBuffer<N>::From(const Byte* bytes)
{
    FixedBuffer<N> result;
    memcpy(result.m_data, bytes, N);
    return result;
}

template<size_t N>
void FixedBuffer<N>::zero() noexcept
{
    memset(m_data, 0, N);
}

template<size_t N>
Byte FixedBuffer<N>::operator[](size_t pos) const noexcept
{
    return m_data[pos];
}

template<size_t N>
Byte* FixedBuffer<N>::data() noexcept
{
    return m_data;
}

template<size_t N>
size_t FixedBuffer<N>::capacity() noexcept
{
    return N;
}

template<size_t N>
void FixedBuffer<N>::copyTo(Byte* buffer) const noexcept
{
    memcpy(buffer, m_data, N);
}

template<size_t N>
Word FixedBuffer<N>::wordAt(size_t pos) const
{
    // TOOD: out of bounds check
    return *(reinterpret_cast<const Word*>(m_data + pos));
}

template<size_t N>
Word& FixedBuffer<N>::wordAt(size_t pos)
{
    // TOOD: out of bounds check
    return *(reinterpret_cast<Word*>(m_data + pos));
}

template<size_t N>
BigEndianWord FixedBuffer<N>::bigEndianWordAt(size_t pos) const
{
    // TOOD: out of bounds check
    return *(reinterpret_cast<const BigEndianWord*>(m_data + pos));
}

template<size_t N>
BigEndianWord& FixedBuffer<N>::bigEndianWordAt(size_t pos)
{
    // TOOD: out of bounds check
    return *(reinterpret_cast<BigEndianWord*>(m_data + pos));
}

template<size_t N>
bool FixedBuffer<N>::operator==(const FixedBuffer<N>& other) const noexcept
{
    return (memcmp(m_data, other.m_data, N) == 0);
}

template<size_t N>
bool FixedBuffer<N>::operator!=(const FixedBuffer<N>& other) const noexcept
{
    return (memcmp(m_data, other.m_data, N) != 0);
}

}

#endif
