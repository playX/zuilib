#pragma once

#include "StdAfx.h"

class CMainFrame : public DuiLib::WindowImplBase
{
public:
	CMainFrame(void);
	~CMainFrame(void);
public:
	DuiLib::CDuiString GetSkinFolder() {return _T(""); };
	DuiLib::CDuiString GetSkinFile() {return _T("t2.xml"); };
	LPCTSTR GetWindowClassName() const { return _T("UIMainFrame"); };
	UINT GetClassStyle() const { return UI_CLASSSTYLE_FRAME | CS_DBLCLKS; };


	void Notify(DuiLib::TNotifyUI& msg);

public:
	virtual void InitWindow();
	virtual LRESULT OnTimer(UINT , WPARAM , LPARAM , BOOL& bHandled);
};
