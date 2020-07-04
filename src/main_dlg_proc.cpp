#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>

INT_PTR CALLBACK MainDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    if (uMsg == WM_COMMAND) {
        if (LOWORD(wParam) == IDC_RESULT) {
            if (HIWORD(wParam) == BN_CLICKED) {
                ViewResult();
                return (INT_PTR)TRUE;
            }
        }
        if (LOWORD(wParam) == IDC_ACCURATE) {
            if (HIWORD(wParam) == BN_CLICKED) {
                UpdateAccuracy();
                return (INT_PTR)TRUE;
            }
        }
    }

    if (uMsg == WM_CLOSE) {
        PostQuitMessage(EXIT_SUCCESS);
        return (INT_PTR)TRUE;
    }

    return (INT_PTR)FALSE;
}
