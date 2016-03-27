// MainPage.h: interface for the CMainPage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINPAGE_H__66DC5C95_BF1E_4572_832A_3338FF45F25A__INCLUDED_)
#define AFX_MAINPAGE_H__66DC5C95_BF1E_4572_832A_3338FF45F25A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include"CmdProc.h"
#include"stdlib.h"
#include"MYString.h"
struct CMDMAP;

class CMainPage  
{
public:
	CMainPage();
	~CMainPage();
	CMDMAP * GetCmdMap();
	CMYString& GetPageName();

	void Student();
	void Teacher();
	void Help();
	void Exit();

	static CMDMAP m_MainPage[];
	static CMDMAP m_SubPage[];

private:
	CMYString m_MainPageName;
	CMDMAP *m_CmdMap;

};

#endif // !defined(AFX_MAINPAGE_H__66DC5C95_BF1E_4572_832A_3338FF45F25A__INCLUDED_)
