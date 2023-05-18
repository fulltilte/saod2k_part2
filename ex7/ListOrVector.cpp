// ListOrVector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <list>
#include <vector>

using namespace std;

void Test_1();
void Test_2();

int main()
{
	Test_2();
}

void Test_1() {
	int M = 400; // 400.
	int N = 1200; // 200.
	list<int> lst;
	for (auto i = 0; i < N; i++)
	{
		lst.push_back(i);
	}
	auto start = chrono::steady_clock::now();
	int k = 0;
	for (int i = 0; i < M; i++)
	{
		lst.push_front(N);
		k++;
		lst.erase(lst.begin());
		k++;
	}
	auto stop = chrono::steady_clock::now();
	auto dt = chrono::duration_cast<chrono::microseconds>(stop - start).count();
	cout << k << endl;
	cout << dt << endl;
}

void Test_2()  {
	int M = 300; // 300.
	int N = 1200; // 200.
	vector<int> vect;
	for (auto i = 0; i < N; i++)
	{
		vect.push_back(i);
	}
	auto start = chrono::steady_clock::now();
	int k = 0;
	for (int i = 0; i < M; i++)
	{
		vect.insert(vect.begin(), N);
		k++;
		vect.erase(vect.begin());
		k++;
	}
	auto stop = chrono::steady_clock::now();
	auto dt = chrono::duration_cast<chrono::microseconds>(stop - start).count();
	cout << k << endl;
	cout << dt << endl;
}