#pragma once
#include <iostream>
#include "Test.h"
using namespace std;

class Child :public Test {
	int a;
public:
	Child(int A = 0) {
		a = A;
		cout << "const child------------" << endl;
	}

	~Child() {
		cout << "dest child----------" << endl;
	}
};