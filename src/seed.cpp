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

void SeedFromULI(DWORD *pdwSeed, CONST ULARGE_INTEGER *puli) {
    DWORD dwSeed = *pdwSeed;

    for (UINT i = 0; i < 8; i++) {
        BYTE bAdd = (BYTE)((puli->QuadPart >> (i * 8)) & 0xFF);

        UINT uOffset = (i * 8) % 32;
        BYTE bNew = (BYTE)((((dwSeed >> uOffset) & 0xFF) + bAdd) % 0xFF);

        dwSeed = dwSeed & ~(DWORD)(0xFF << uOffset);
        dwSeed = dwSeed | (bNew << uOffset);
    }
    *pdwSeed = dwSeed;
}
