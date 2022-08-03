#include <windows.h>
#include <stdio.h>
#include <tchar.h> 
#include <iostream>
#include <math.h>
#include <Psapi.h>
#include <string.h>
#include <time.h>
#include <fstream>
#include <algorithm>
#include <signal.h>
#include <cstdlib>
#include <map> 
#include <shellapi.h>

class Scanner {
private:
    inline MODULEINFO GetModuleInfo(LPCSTR szModule) {
        MODULEINFO modinfo = { 0 };
        HMODULE hModule = GetModuleHandleA(szModule);
        if (hModule == 0) return modinfo;
        GetModuleInformation(GetCurrentProcess(), hModule, &modinfo, sizeof(MODULEINFO));
        return modinfo;
    }
    BOOL Match(const BYTE* pData, const BYTE* bMask, const char* szMask);

public:
    DWORD FindPattern_(char* bMask, char* szMask);
    DWORD FindPattern(DWORD Mod, DWORD Size, char* bMask, char* szMask);
};

extern Scanner Scan;