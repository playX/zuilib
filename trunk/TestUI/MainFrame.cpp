#include "StdAfx.h"
#include "MainFrame.h"

UINT	g_nCount = 1;

CMainFrame::CMainFrame(void)
{
}

CMainFrame::~CMainFrame(void)
{
}

void CMainFrame::Notify(DuiLib::TNotifyUI& msg)
{
	if (_tcsicmp(msg.sType, _T("click")) == 0) 
		OnClick(msg);
}

void	CMainFrame::InitWindow()
{
	DWORD	d = 0xaabbccdd;
	BYTE	r = GetRValue(d);
	BYTE	g = GetGValue(d);
	BYTE	b = GetBValue(d);
	CString strResourcePath=m_PaintManager.GetInstancePath();
	strResourcePath+=GetSkinFolder().GetData();
	CString	sPic;
	sPic.Format(_T("%smain.bmp"), strResourcePath);
	DuiLib::STRINGorID tmp(sPic.GetBuffer());
	HRGN hRgn = DuiLib::CRenderEngine::CreateImageRegion((DuiLib::CRenderEngine::LoadImage(tmp)), RGB(0,255,0));
	SetRgn(hRgn);

// 	CRgn	rgn;
// 	rgn.CreateRectRgn(100,100,200,200);
// 	::SetWindowRgn(m_hWnd, rgn, TRUE);

	SetTimer(2, 1000);
}

LRESULT	CMainFrame::OnTimer(UINT /*uMsg*/, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	bHandled = TRUE;
	UINT	nIDEvent = (UINT)wParam;
	switch(nIDEvent)
	{
	case 1:
	case 2:
	default:break;
	}

	if (g_nCount > 5) g_nCount = 0;
	CString strResourcePath=m_PaintManager.GetInstancePath();
	strResourcePath+=GetSkinFolder().GetData();
	CString	sPic;
	sPic.Format(_T("%sSignalRect0%d.png"), strResourcePath, g_nCount);
	DuiLib::CControlUI* pctrl = static_cast<DuiLib::CControlUI*>(m_PaintManager.FindControl(_T("ctrl")));
	if (pctrl) pctrl->SetBkImage(sPic);
	g_nCount++;
	return 0;
}