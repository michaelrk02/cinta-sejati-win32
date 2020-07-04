#include "stdafx.h"

#include <commctrl.h>
#include <string.h>

void SeedFromString(DWORD *pdwSeed, LPCTSTR lpszText) {
    DWORD dwSeed = *pdwSeed;
    UINT cchText = _tcslen(lpszText);
    for (UINT i = 0; i < cchText; i++) {
        TCHAR ch = lpszText[i];
        if ((ch >= _T('a')) && (ch <= _T('z'))) {
            BYTE bAdd = (BYTE)(((DWORD)ch - _T('a') + i + 1) % 0xFF);

            UINT uOffset = (i * 8) % 32;
            BYTE bNew = (BYTE)((((dwSeed >> uOffset) & 0xFF) + bAdd) % 0xFF);

            dwSeed = dwSeed & ~(DWORD)(0xFF << uOffset);
            dwSeed = dwSeed | (bNew << uOffset);
        }
    }
    *pdwSeed = dwSeed;
}

void SeedFromFiletime(DWORD *pdwSeed, CONST FILETIME *pft) {
    DWORD dwSeed = *pdwSeed;
    ULARGE_INTEGER uli;
    uli.LowPart = pft->dwLowDateTime;
    uli.HighPart = pft->dwHighDateTime;

    for (UINT i = 0; i < 8; i++) {
        BYTE bAdd = (BYTE)((uli.QuadPart >> (i * 8)) & 0xFF);

        UINT uOffset = (i * 8) % 32;
        BYTE bNew = (BYTE)((((dwSeed >> uOffset) & 0xFF) + bAdd) % 0xFF);

        dwSeed = dwSeed & ~(DWORD)(0xFF << uOffset);
        dwSeed = dwSeed | (bNew << uOffset);
    }
    *pdwSeed = dwSeed;
}
