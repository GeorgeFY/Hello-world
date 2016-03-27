// CmdProc.cpp: implementation of the CCmdProc class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CmdProc.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCmdProc::CCmdProc()
{

}

CCmdProc::~CCmdProc()
{

}

void CCmdProc::CmdProc()
{
	CMDMAP *pTemp = m_MainPage.GetCmdMap();
	CMYString CmdName;

	while(1)
	{
		cout<<m_MainPage.GetPageName()<<">";
		cin>>CmdName;

		while(NULL != pTemp->pFun)
		{
			if(CmdName == pTemp->pszCmdName)
			{
				(m_MainPage.*(pTemp->pFun))();
				break;
			}
			pTemp++;
		}
		if(NULL == pTemp->pFun)
		{
			cout<<"Errror!"<<endl;
		}
		pTemp = m_MainPage.GetCmdMap();
	}
}

void CCmdProc::Help()
{

}

void CCmdProc::Swap(char *)
{

}
