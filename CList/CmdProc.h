// CmdProc.h: interface for the CCmdProc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CMDPROC_H__29590370_773C_428B_8355_716CFAAA6A5C__INCLUDED_)
#define AFX_CMDPROC_H__29590370_773C_428B_8355_716CFAAA6A5C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include"MainPage.h"
#include"MYString.h"

class CMainPage;

typedef void(CMainPage::*PFUN)();

class CCmdProc
{
public:
	CCmdProc();
	~CCmdProc();

	void CmdProc();
	void Help();
	void Swap(char *);

private:
	CMainPage m_MainPage;

};

struct CMDMAP
{
	const char *pszCmdName;
	const char *pszCmdInfo;
	PFUN pFun;
};

#define CMDMAP_BEGIN(name, type) CMDMAP name##::##type[] ={

#define CMDMAP(name, info, pFun){name, info, pFun},

#define CMDMAP_END() {NULL, NULL, NULL}};

#endif // !defined(AFX_CMDPROC_H__29590370_773C_428B_8355_716CFAAA6A5C__INCLUDED_)
