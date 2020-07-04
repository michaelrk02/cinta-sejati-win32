#include "stdafx.h"

void UpdateAccuracy(void) {
    HWND hAccurate = GetDlgItem(g_hMainDlg, IDC_ACCURATE);
    HWND hAdditional = GetDlgItem(g_hMainDlg, IDC_ADDITIONAL);
    HWND hBDate1 = GetDlgItem(g_hMainDlg, IDC_BDATE1);
    HWND hBDate2 = GetDlgItem(g_hMainDlg, IDC_BDATE2);

    LRESULT lCheckState = SendMessage(hAccurate, BM_GETCHECK, 0, 0);
    if (lCheckState == BST_CHECKED) {
        EnableWindow(hAdditional, TRUE);
        EnableWindow(hBDate1, TRUE);
        EnableWindow(hBDate2, TRUE);
    } else {
        EnableWindow(hAdditional, FALSE);
        EnableWindow(hBDate1, FALSE);
        EnableWindow(hBDate2, FALSE);
    }
}
