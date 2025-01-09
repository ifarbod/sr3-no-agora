// Copyright (c) 2023-2025 iFarbod. All Rights Reserved.
//
// SPDX-License-Identifier: MIT

// compile with:
// clang++ -shared -O3 -o sr3-dx11_no_agora.asi dllmain.cpp

#include <windows.h>

#include <iostream>

void patch_game()
{
    // Get the base address of the current module
    HMODULE hModule = GetModuleHandle(nullptr);
    if (hModule == nullptr)
    {
        std::cerr << "Failed to get module handle." << std::endl;
        return;
    }

    // Calculate the target address
    unsigned char* address = reinterpret_cast<unsigned char*>(hModule) + 0x7D8EE0;

    // Change the memory protection to allow writing
    DWORD oldProtect;
    if (!VirtualProtect(address, sizeof(unsigned char), PAGE_EXECUTE_READWRITE, &oldProtect))
    {
        std::cerr << "Failed to change memory protection." << std::endl;
        return;
    }

    // Set the memory value
    *address = 0xC3;

    // Restore the original memory protection
    if (!VirtualProtect(address, sizeof(unsigned char), oldProtect, &oldProtect))
    {
        std::cerr << "Failed to restore memory protection." << std::endl;
        return;
    }

    std::cout << "Memory address 0xBD8EE0 set to 0xC3" << std::endl;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            patch_game();
            break;
        case DLL_PROCESS_DETACH:
            break;
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
            break;
    }
    return TRUE;
}
