/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_MEMORY_LINKOPTIONS_HPP
#define GUARD_ISHIKO_CPP_MEMORY_LINKOPTIONS_HPP

#ifdef _DEBUG
#pragma comment(lib, "IshikoMemory-d.lib")
#else
#pragma comment(lib, "IshikoMemory.lib")
#endif

#endif
