// MYString.h: interface for the CMYString class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSTRING_H__A43D3FA0_FCBB_4E3F_956C_669D3C11F59F__INCLUDED_)
#define AFX_MYSTRING_H__A43D3FA0_FCBB_4E3F_956C_669D3C11F59F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMYString  
{
	friend bool operator ==(const char *pStr, CMYString &r);
	friend ostream& operator <<(ostream &out, const CMYString &r);
	friend istream& operator >>(istream &in, CMYString &r);
public:
	CMYString();
	CMYString(const char *pStr);
	CMYString(const CMYString &r);
	~CMYString();

	int GetSize() const;
	char* GetString() const;
	int IsEmpty();

	CMYString& Copy(const char *pStr);
	CMYString& Cat(const char *pStr);
	bool Compare(const char *pStr) const;

	CMYString& operator = (const char *pStr);
	CMYString& operator = (const CMYString &r);
	CMYString& operator += (const char *pStr);
	CMYString& operator += (const CMYString &r);
	char operator [](int nIdex);

	bool operator == (const char *pStr);
	bool operator == (const CMYString &r);
private:
	int StrLen(const char *pStr) const;
	void StrCpy(char *pStrDest, const char *pStrSrc);

private:
	char *m_pStr;
	int m_nSize;

};

#endif // !defined(AFX_MYSTRING_H__A43D3FA0_FCBB_4E3F_956C_669D3C11F59F__INCLUDED_)
