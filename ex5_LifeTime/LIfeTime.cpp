// LIfeTime.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
