#pragma once
#include <iostream>
using namespace std;

class Test
{
public:
	int val;
	Test() {
		val = 0;
		cout << "//////" << endl;
		cout << "I was born" << endl;
	};
	~Test() {
		cout << "I dead: " << val << endl;
		cout << "//////" << endl;
	};
};

