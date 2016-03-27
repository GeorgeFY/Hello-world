// MainPage.cpp: implementation of the CMainPage class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainPage.h"

CMDMAP_BEGIN(CMainPage, m_MainPage)

	CMDMAP("studnet", "Student", CMainPage::Student)
	CMDMAP("teacher", "Teacher", CMainPage::Teacher)
	CMDMAP("help", "Help", CMainPage::Help)
	CMDMAP("exit", "Exit", CMainPage::Exit)

CMDMAP_END()
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMainPage::CMainPage()
{
	m_CmdMap = m_MainPage;
	m_MainPageName = "MainPage V1.0";
}

CMainPage::~CMainPage()
{

}

CMDMAP* CMainPage::GetCmdMap()
{
	return m_CmdMap;
}

CMYString& CMainPage::GetPageName()
{
	return m_MainPageName;
}

void CMainPage::Student()
{
	m_MainPageName = "Student V1.0";
	m_CmdMap = m_SubPage;

	system("cls");
}

void CMainPage::Teacher()
{
	m_MainPageName = "Teacher V1.0";
	m_CmdMap = m_SubPage;

	system("cls");
}

void CMainPage::Help()
{

}

void CMainPage::Exit()
{
	exit(0);
}