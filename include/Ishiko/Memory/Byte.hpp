/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_MEMORY_BYTE_HPP
#define GUARD_ISHIKO_CPP_MEMORY_BYTE_HPP

// TODO: check this works both when byte is defined and not
namespace Ishiko
{

// We defined our own Byte type because std::byte was only added in C++17. However users are encouraged to use
// std::byte instead of this typedef if they can.
#ifdef __cpp_lib_byte
    typedef std::byte Byte;
#else
    typedef unsigned char Byte;
#endif
}

#endif
