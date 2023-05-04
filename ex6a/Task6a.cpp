#include<iostream>
#pragma once

using namespace std;

size_t Get_Hash_Value(const char* str, size_t sizesubstr,int b, int Q = 0x7fffffff)
{
	size_t hashres = 0;

	for (size_t i = 0; i < sizesubstr; i++)
	{
		signed char charcode = str[i];
		hashres = (hashres * b + charcode) % Q;
	}
	return hashres;
}

size_t Shift_Hash(size_t PrevHash, const char* strPrevSymbol, const char* strNewSymbol, size_t mSizeSub, int b, int Q = 0x7fffffff)
{
	size_t hashH = PrevHash;

	size_t m = 1;
	for (size_t i = 1; i < mSizeSub; i++)
	{
		m = (m * b) % Q;
	}

	hashH += Q;
	hashH -= (m * strPrevSymbol[0]) % Q;
	hashH *= b;
	hashH += strNewSymbol[mSizeSub - 1];
	hashH %= Q;

	return hashH;
}

bool Is_Hashes_Equval(const char* str_1, const char* str_2, size_t lenStrs)
{
	bool is_Ok = true;
	int16_t i = 0;
	for (i = 0; i < lenStrs; i++)
		if (*(str_1 + i) != *(str_2 + i))
		{
			is_Ok = false;
			break;
		}
	return is_Ok;
}

int main()
{
	const char* ptr_String = "123456714445678900--ddabcbbbbbdc*";
	const char* ptr_SubStr = "00";

	cout << "String: " << ptr_String << endl;
	cout << "SubString: " << ptr_SubStr << endl;

	int start_pos = -1;

	size_t  RollHash = Get_Hash_Value(ptr_String, strlen(ptr_SubStr), 13);
	size_t  HashSubStr = Get_Hash_Value(ptr_SubStr, strlen(ptr_SubStr), 13);
	size_t  LenSearch = strlen(ptr_String) - strlen(ptr_SubStr);
	size_t  LenSub = strlen(ptr_SubStr);

	for (int i = 0; i <= LenSearch; i++)
	{
		if (RollHash == HashSubStr)
		{
			cout << "nRollHash:  0x" << hex << RollHash << " == nHashSubStr:  0x" << HashSubStr << endl;
			start_pos = i;
			if (Is_Hashes_Equval(ptr_String + 1, ptr_SubStr, LenSub))
				start_pos = -1;
			break;
		}
		else
			RollHash = Shift_Hash(RollHash, (ptr_String + i), (ptr_String + (i + 1)), LenSub, 13);
	}

	if (start_pos >= 0)
		cout << "Sub string beginner with " << dec << start_pos << " position!" << endl;
	else
		cout << "Sub string not found!" << endl;

	system("pause");

}

