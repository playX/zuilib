// App.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
//#include "resource.h"
class CFrameWindowWnd : public WindowImplBase
{
public:
    CFrameWindowWnd() {  };
	CDuiString GetSkinFolder() {return _T(""); };
	CDuiString GetSkinFile() {return _T("t.xml"); };
    LPCTSTR GetWindowClassName() const { return _T("UIMainFrame"); };
    UINT GetClassStyle() const { return UI_CLASSSTYLE_FRAME | CS_DBLCLKS; };


    void Notify(TNotifyUI& msg)
    {
		if (_tcsicmp(msg.sType, _T("click")) == 0) OnClick(msg);
    }
};


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
    CPaintManagerUI::SetInstance(hInstance);
    CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());

    HRESULT Hr = ::CoInitialize(NULL);
    if( FAILED(Hr) ) return 0;

    CFrameWindowWnd* pFrame = new CFrameWindowWnd();
    if( pFrame == NULL ) return 0;
    pFrame->Create(NULL, _T("这是一个最简单的测试用exe，修改t.xml就可以看到效果"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
    pFrame->CenterWindow();
    pFrame->ShowWindow(true);
    CPaintManagerUI::MessageLoop();

    ::CoUninitialize();
    return 0;
}
