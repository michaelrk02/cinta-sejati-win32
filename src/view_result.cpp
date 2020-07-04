#include "stdafx.h"

#include <commctrl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void ViewResult(void) {
    DWORD dwRandomSeed = 0;

    HWND hAccurate = GetDlgItem(g_hMainDlg, IDC_ACCURATE);
    BOOL fAccurate = (SendMessage(hAccurate, BM_GETCHECK, 0, 0) == BST_CHECKED);

    DWORD dwSeed1 = 0;
    HWND hName1 = GetDlgItem(g_hMainDlg, IDC_NAME1);
    UINT cchName1 = GetWindowTextLength(hName1);
    LPTSTR lpszName1 = new TCHAR[cchName1 + 1];
    GetWindowText(hName1, lpszName1, cchName1 + 1);
    _tcslwr(lpszName1);
    SeedFromString(&dwSeed1, lpszName1);
    SeedFromString(&dwRandomSeed, lpszName1);
    delete lpszName1;

    DWORD dwSeed2 = 0;
    HWND hName2 = GetDlgItem(g_hMainDlg, IDC_NAME2);
    UINT cchName2 = GetWindowTextLength(hName2);
    LPTSTR lpszName2 = new TCHAR[cchName2 + 1];
    GetWindowText(hName2, lpszName2, cchName2 + 1);
    _tcslwr(lpszName2);
    SeedFromString(&dwSeed2, lpszName2);
    SeedFromString(&dwRandomSeed, lpszName2);
    delete lpszName2;

    if (fAccurate) {
        HWND hBDate1 = GetDlgItem(g_hMainDlg, IDC_BDATE1);
        SYSTEMTIME st1;
        SendMessage(hBDate1, DTM_GETSYSTEMTIME, 0, (LPARAM)&st1);
        ZeroMemory(&st1.wHour, sizeof(WORD) * 4);
        FILETIME ft1;
        SystemTimeToFileTime(&st1, &ft1);
        ft1.dwLowDateTime = ft1.dwLowDateTime ^ dwSeed1;
        ft1.dwHighDateTime = ~dwSeed1;
        SeedFromFiletime(&dwRandomSeed, &ft1);

        HWND hBDate2 = GetDlgItem(g_hMainDlg, IDC_BDATE2);
        SYSTEMTIME st2;
        SendMessage(hBDate2, DTM_GETSYSTEMTIME, 0, (LPARAM)&st2);
        ZeroMemory(&st2.wHour, sizeof(WORD) * 4);
        FILETIME ft2;
        SystemTimeToFileTime(&st2, &ft2);
        ft2.dwLowDateTime = ft2.dwLowDateTime ^ dwSeed2;
        ft2.dwHighDateTime = ~dwSeed2;
        SeedFromFiletime(&dwRandomSeed, &ft2);
    }

    srand(dwRandomSeed);
    int nResult = rand() % 101;
    TCHAR szMsg[20];
    _stprintf(szMsg, _T("Kecocokan: %d%%"), nResult);
    MessageBox(NULL, szMsg, _T("Hasil"), MB_ICONINFORMATION);
}
