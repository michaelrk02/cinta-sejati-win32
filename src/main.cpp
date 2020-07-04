#if _MSC_VER >= 1400
#pragma comment(linker, "\"/MANIFESTDEPENDENCY:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif

#include "stdafx.h"

#include <stdio.h>

HWND g_hMainDlg;

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpszCmdLine, int nShowCmd) {
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpszCmdLine);
    UNREFERENCED_PARAMETER(nShowCmd);

    HMODULE hComctl = LoadLibrary(_T("comctl32.dll"));
    if (hComctl != NULL) {
        MSG msg;
        ZeroMemory(&msg, sizeof(MSG));

        g_hMainDlg = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAIN), NULL, MainDlgProc);
        if (g_hMainDlg != NULL) {
            ShowWindow(g_hMainDlg, nShowCmd);
            UpdateAccuracy();

            while (GetMessage(&msg, NULL, 0, 0)) {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
            DestroyWindow(g_hMainDlg);
        } else {
            MessageBox(NULL, _T("Failed to create dialog box!"), _T("Error"), MB_ICONERROR);
        }

        FreeLibrary(hComctl);

        return msg.wParam;
    } else {
        MessageBox(NULL, _T("Unable to load comctl32.dll"), _T("Error"), MB_ICONERROR);
    }
    return 1;
}
