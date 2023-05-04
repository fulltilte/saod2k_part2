#pragma once
#include <string.h>
#include "_str.h"

using namespace std;
class Str {

	_str* m_pStr;

public:
	Str() 
	{ 
		m_pStr = new _str;
		cout << "(1)- Str::Str() " << endl;
	}

	Str(const char* p) 
	{		
		m_pStr = new _str(p);
		cout << "(2)- Str::Str(const char* p) " << endl;
	}
	~Str() 
	{
		cout << "(2)- Str::~Str() " << endl;
		m_pStr->Release();
	}				

	size_t  len() const 
	{
		return strlen(m_pStr->m_pszData);
	}
	operator const char* () const 
	{ 
		return m_pStr->m_pszData;
	}
	const Str& operator = (const Str& s) 
	{
		if (&s == this)
			return	*this;
		delete[] m_pStr->m_pszData;

		size_t  len = strlen(s.m_pStr->m_pszData) + 1;

		m_pStr->m_pszData = new char[len];
		strcpy_s(m_pStr->m_pszData, len, s.m_pStr->m_pszData);

		return *this;
	}

	Str& operator +=(const char* sz)
	{
		size_t len_1 = strlen(m_pStr->m_pszData);
		size_t len_2 = strlen(sz) + 1;

		char* ptr = new char[len_1 + len_2];

		strcpy_s(ptr, len_1 + len_2, m_pStr->m_pszData);
		strcat_s(ptr, len_1 + len_2, sz);

		delete[] m_pStr->m_pszData;

		m_pStr->m_pszData = ptr;
		return *this;
	}

	int find(const char* t, int off) const 
	{
		size_t l_str = len();
		size_t l_substr = strlen(t);
		
		int   pos = off;
		bool  IsOk = false;

		for ( ; pos <= (l_str - l_substr); pos++)
		{
			int n = 0;
			char* ptr_s = m_pStr->m_pszData + pos;
			char* ptr_ss = (char*)t;

			while (*ptr_s && (*ptr_s == *ptr_ss) )
			{
				n++;
				ptr_s++;
				ptr_ss++;
			}

			if (n == l_substr)
			{
				IsOk = true;
				break;
			}
		}

		return  IsOk ? pos : -1;
	}
};

