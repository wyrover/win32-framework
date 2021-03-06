//////////////////////////////////////////////////////
// MainWnd.h
//  Declaration of the CMainWindow class

#ifndef MAINWND_H
#define MAINWND_H


#include "TestWnd.h"
#include "MyDialog.h"

typedef Shared_Ptr<CTestWindow> TestWindowPtr;

class CMainWindow : public CWnd
{
public:
    CMainWindow();
    virtual ~CMainWindow();
    virtual HWND Create(CWnd* pParent = 0);
    virtual void CreateTestWindows(int nWindows);
    virtual void OnAllWindowsCreated();
    virtual void PerformanceTest();
    virtual void SendText(LPCTSTR str);
    virtual void SetTestMessages(int nTestMessages)
    {
        m_nTestMessages = nTestMessages;
    }

protected:
    virtual void OnCreate();
    virtual void OnInitialUpdate();
    virtual void OnSize();
    virtual LRESULT WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
    enum Constants {
        WM_WINDOWCREATED     = WM_USER + 1, // the message sent when window is created
        WM_TESTMESSAGE       = WM_USER + 2  // the test message
    };

    std::vector<TestWindowPtr> m_pCTestWindows; // A vector CTestWindow smart pointers
//  HWND  m_hEdit;          // Handle to the edit window
    CEdit m_Edit;           // Handle to the edit window
    CFont m_Font;           // A font for the edit window
    int m_nTestMessages;    // Number of test messages to be sent
    int m_nTestWindows;     // Number of test windows to create
};


#endif  //MAINWND_H
