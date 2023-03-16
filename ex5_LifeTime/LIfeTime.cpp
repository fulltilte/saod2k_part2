#include <iostream>
#include "Test.h"
#include "Child.h"
#include "Aggregate.h"
#include "AggregateT.h"
using namespace std;


Test* test = new Test();
int Test::nCount = 0;

int main()
{

	/*cout << "before create t" << endl;
	Test* t = new Test(1,2);
	cout << "after create t" << endl;
	cout << "before delete t" << endl;
	delete t;
	cout << "after delete t" << endl;
	cout << "before delete test" << endl;
	delete test;
	cout << "after delete test" << endl;
	Test* p = new Test;
	delete p;
	Test* m = new Test[3]{ 1, Test(2,1), 3 };
	delete[] m;
	Test n(2,3);
	cout << "foo" << endl;
	n.foo(n);
	Child c(3);
	cout << "pupa" << endl;
	Aggregate s;*/
	AggregareT<Test> n(1);
	AggregareT<Child> a;
}
