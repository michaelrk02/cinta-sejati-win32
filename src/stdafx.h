#ifdef _MSC_VER
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NON_CONFORMING_SWPRINTFS
#endif

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4005)
#endif
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#ifdef _MSC_VER
#pragma warning(pop)
#endif

#include <tchar.h>

#include "resource.h"

/* main dialog window */
extern HWND g_hMainDlg;

INT_PTR CALLBACK MainDlgProc(HWND, UINT, WPARAM, LPARAM);

/* application callbacks */
void UpdateAccuracy(void);
void ViewResult(void);

/* application procedures */
void SeedFromString(DWORD *pdwSeed, LPCTSTR lpszText);
void SeedFromFiletime(DWORD *pdwSeed, CONST FILETIME *pft);
