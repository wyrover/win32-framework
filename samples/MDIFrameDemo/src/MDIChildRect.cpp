//////////////////////////////////////////////
// MDIChildRect.cpp
//  Definitions for the CViewRect and CMDIChildRect class

#include "stdafx.h"
#include "MDIChildRect.h"
#include "resource.h"


////////////////////////
// CViewRect definitions
LRESULT CViewRect::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_CREATE:
        SetTimer(1, 250, NULL) ;
        break;

    case WM_CLOSE:
        KillTimer(1);
        break;

    case WM_TIMER: {          // Display a random rectangle
        int nRed, nGreen, nBlue;
        int xLeft, xRight, yTop, yBottom;
        xLeft   = rand() % m_cxClientMax;
        xRight  = rand() % m_cxClientMax;
        yTop    = rand() % m_cyClientMax;
        yBottom = rand() % m_cyClientMax;
        nRed    = rand() & 255;
        nGreen  = rand() & 255;
        nBlue   = rand() & 255;
        CClientDC dcRect(this);
        dcRect.CreateSolidBrush(RGB(nRed, nGreen, nBlue));
        int Left   = (xLeft < xRight) ? xLeft : xRight;
        int Top    = (yTop < yBottom) ? yTop  : yBottom;
        int Right  = (xLeft > xRight) ? xLeft : xRight;
        int Bottom = (yTop > yBottom) ? yTop  : yBottom;
        dcRect.Rectangle(Left, Top, Right, Bottom);
    }
    break;

    case WM_SIZE:             // If not minimized, save the window size
        if (wParam != SIZE_MINIMIZED) {
            m_cxClientMax = LOWORD(lParam) ;

            if (m_cxClientMax < 1) m_cxClientMax = 1;

            m_cyClientMax = HIWORD(lParam) ;

            if (m_cyClientMax < 1) m_cyClientMax = 1;
        }

        break ;        // WM_SIZE must be processed by DefMDIChildProc
    }

    return WndProcDefault(uMsg, wParam, lParam);
}

////////////////////////////
// CMDIChildRect definitions
CMDIChildRect::CMDIChildRect()
{
    HINSTANCE hResource = GetApp()->GetResourceHandle();
    HMENU hChildMenu = LoadMenu(hResource, _T("MdiMenuRect"));
    SetHandles(hChildMenu, NULL);
    SetView(m_RectView);
}

CMDIChildRect::~CMDIChildRect()
{
}

void CMDIChildRect::OnInitialUpdate()
{
    SetWindowText(_T("Rectangle Window"));
    SetIconLarge(IDI_RECT);
    SetIconSmall(IDI_RECT);
}

