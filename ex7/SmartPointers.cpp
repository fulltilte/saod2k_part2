// SmartPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "Test.h"

using namespace std;

int main()
{
    //shared_ptr<Test[]> sp(new Test[3]);
    /*shared_ptr<Test> sp(new Test[3], default_delete<Test[]>());
	for (size_t i = 0; i < 3; i++)
	{
		sp.get()[i].val = i;
	}*/

	unique_ptr<Test[]> p(new Test[3]);
	for (size_t i = 0; i < 3; i++)
	{
		p.get()[i].val = i;
	}
	cout << "-----------" << endl;
	p.reset(new Test[2]);
	cout << "-----end-Main------" << endl;
}