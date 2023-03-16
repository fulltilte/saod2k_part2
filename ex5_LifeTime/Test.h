#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Test
{
public:
	static int nCount;
	int a, b;
	int* f;
public:
	Test(int aa = 0, int bb = 0)
	{
		a = aa;
		b = bb;
		cout << "const" << endl;
		nCount++;
		cout << nCount << " " << "nCount in const" << endl;
		//cout << "Address is " << this << endl;
	}

	Test(const Test& t) {
		a = t.a;
		b = t.b;
		cout << "const cpy" << endl;
		nCount++;
		cout << nCount << " " << "nCount in const cpy" << endl;
	}
	void foo(Test t) {
		cout << "foo is running" << endl;
	}

	~Test() {
		cout << "dest" << endl;
		nCount--;
		cout << nCount << " " << "nCount in dest" << endl;
	}
};

