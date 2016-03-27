// MYString.cpp: implementation of the CMYString class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MYString.h"

bool operator ==(const char *pStr, CMYString &r)
{
	return r.Compare(pStr);
}

ostream& operator <<(ostream &out, const CMYString &r)
{
	out<<r.m_pStr;
	return out;
}

istream& operator >>(istream &in, CMYString &r)
{
	char szBuf[255] = "";
	cin>>szBuf;
	r.Copy(szBuf);
	return in;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMYString::CMYString()
{
	m_pStr = NULL;
	m_nSize = 0;
}

CMYString::CMYString(const char *pStr)
{
	m_pStr = NULL;
	m_nSize = 0;
	if(NULL != pStr)
	{
		Copy(pStr);
	}
}

CMYString::CMYString(const CMYString &r)
{
	m_pStr = NULL;
	m_nSize = 0;
	if(NULL != this)
	{
		Copy(r.m_pStr);
	}
}

CMYString::~CMYString()
{
	if(NULL != m_pStr)
	{
		delete [] m_pStr;
	}
	m_pStr = NULL;
	m_nSize = 0;
}

int CMYString::GetSize() const
{
	return m_nSize;
}
	
char* CMYString::GetString() const
{
	return m_pStr;
}

int CMYString::IsEmpty()
{
	return !m_nSize;
}

CMYString& CMYString::Copy(const char *pStr)
{
	if(NULL != m_pStr)
	{
		delete [] m_pStr;
		m_pStr = NULL;
		m_nSize = 0;
	}
	if(NULL != pStr)
	{
		m_nSize = StrLen(pStr);
		m_pStr = new char[m_nSize +1];
		StrCpy(m_pStr, pStr);
	}
	return *this;
}

CMYString& CMYString::Cat(const char *pStr)
{
	int nSize = m_nSize + StrLen(pStr) +1;
	char *pTemp = new char[nSize];
	if(NULL != m_pStr)
	{
		StrCpy(pTemp, m_pStr);
		delete [] m_pStr;
		m_pStr = NULL;
	}
	m_pStr = pTemp;
	StrCpy(&m_pStr[m_nSize], pStr);

	m_nSize = nSize -1;
	return *this;
}

bool CMYString::Compare(const char *pStr) const
{
	if(NULL != pStr)
	{
		if(m_nSize != StrLen(pStr))
		{
			return false;
		}
		for(int i = 0; i<m_nSize; i++)
		{
			while(m_pStr[i] != pStr[i])
			{
				return false;
			}
		}
	}
	else
	{
		if(NULL != m_pStr)
		{
			return false;
		}
	}
	return true;
}

CMYString& CMYString::operator = (const char *pStr)
{
	return Copy(pStr);
}

CMYString& CMYString::operator = (const CMYString &r)
{
	return Copy(r.m_pStr);
}

CMYString& CMYString::operator += (const char *pStr)
{
	return Cat(pStr);
}

CMYString& CMYString::operator += (const CMYString &r)
{
	return Cat(r.m_pStr);
}

char CMYString::operator [](int nIdex)
{
	return m_pStr[nIdex];
}

bool CMYString::operator == (const char *pStr)
{
	return Compare(pStr);
}

bool CMYString::operator == (const CMYString &r)
{
	return Compare(r.m_pStr);
}

int CMYString::StrLen(const char *pStr) const
{
	int nSize = 0;
	while('\0' != *pStr++)
	{
		nSize++;
	}

	return nSize;
}
	
void CMYString::StrCpy(char *pStrDest, const char *pStrSrc)
{
	while('\0' != (*pStrDest++ = *pStrSrc++));
}