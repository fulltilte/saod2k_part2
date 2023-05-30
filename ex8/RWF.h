#pragma once
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;

class RWF
{
	string s, t;
	int M, N;
	int** pm;

public:

	RWF(string S, string T)
	{
		s = S;
		t = T;
		M = S.size() + 1;
		N = T.size() + 1;
		pm = new int* [N];
	}

	~RWF()
	{
		for (int i = 0; i < N; i++)
		{
			delete[] pm[i];
		}
		delete[] pm;
		//cout << "delete" << endl;
	}

	void Init()
	{

		string Sc = s;
		string Tc = t;
		for (int i = 0; i < N; i++)
		{
			pm[i] = new int[M];
		}
		int count = M - 1;
		for (int j = 0; j < M; j++)
		{
			pm[N - 1][j] = count;
			count--;
		}
		count = N - 1;
		for (int i = 0; i < N; i++)
		{
			pm[i][M - 1] = count;
			count--;
		}



		for (int i = N - 2; i >= 0; i--)
		{
			for (int j = M - 2; j >= 0; j--)
			{
				if (Sc[j + 1] == Tc[i + 1])
				{
					pm[i][j] = min(min(pm[i + 1][j + 1], pm[i + 1][j]), pm[i][j + 1]);
				}
				else
				{
					pm[i][j] = min(min(pm[i + 1][j + 1] + 1, pm[i + 1][j] + 1), pm[i][j + 1] + 1);
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cout << pm[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	//возвращает расстояние между строками
	int ProximityOfLines()
	{
		return pm[N - 1][M - 1];
	}

	//возвращает кол-во строк
	int Rows() const
	{
		return N;
	}

	//возвращает кол-во столбцов
	int Columns() const
	{
		return M;
	}

	//получение элемента по индексу
	int Get(int i, int j) const
	{
		if (i >= N || j >= M)
		{
			throw out_of_range("Get: Index out of range");
		}
		else
		{
			return pm[i][j];
		}
	}

	//изменение элемента по индексу
	void Set(int i, int j, int val)
	{
		if (i > N || j > N)
		{
			throw out_of_range("Set: Index out of range");
		}
		else
		{
			pm[i][j] = val;
		}
	}
};

