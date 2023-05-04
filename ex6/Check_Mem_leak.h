#pragma once
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

class Check_Mem_leak
{
	_CrtMemState MemState_1;
	_CrtMemState MemState_2;
	_CrtMemState MemState_3;
	_CrtMemState sDiff;

public:

	Check_Mem_leak() : MemState_1 {0}, MemState_2 {0}, MemState_3 {0}, sDiff {0}
	{
		//  MemState_1 = { 0 }, MemState_2 = { 0 }, MemState_3 = { 0 }, sDiff = { 0 };
		cout << "(1)- Check_Mem_leak::Check_Mem_leak() " << endl;
	}

	~Check_Mem_leak()
	{
		cout << "(2)- Check_Mem_leak::~Check_Mem_leak() " << endl;
		GetLastMemState();
		GetResultMemState(false);
		system("pause");
	}
	void GetFirstMemState() 
	{
		_CrtMemCheckpoint(&MemState_1);
	}

	void GetMiddleMemState()
	{
		_CrtMemCheckpoint(&MemState_2);
	}

	void GetLastMemState()
	{
		_CrtMemCheckpoint(&MemState_3);
	}

	void GetResultMemState(bool is_First = true)
	{
		_CrtMemState startState = MemState_1;
		_CrtMemState endState = is_First ? MemState_2 : MemState_3;
		
		cout << "Check memory leak: " << endl;

		if (_CrtMemDifference(&sDiff, &startState, &endState)) // if there is a difference
		{
			cout << "DumpMemoryLeaks see trace window ..." << endl;
			_CrtDumpMemoryLeaks();
		}
		else 
		{
			cout << "+++ No memory leak!" << endl;
		}
	}
};

