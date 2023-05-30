#pragma once
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;

class WF
{
	string s, t;
	int M, N;
	int ** pm;

public:
	
	WF(string S, string T)
	{
		s = S;
		t = T;
		M = S.size() + 1;
		N = T.size() + 1;
		pm = new int* [N];
	}

	~WF()
	{
		for (int i = 0; i < N; i++)
		{
			delete[] pm[i];
		}
		delete[] pm;
		cout << "delete" << endl;
	}

	void Init()
	{

		string Sc = s;
		string Tc = t;
		for (int i = 0; i < N; i++)
		{
			pm[i] = new int[M];
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (i == 0)
				{
					pm[i][j] = j;
				}
				else if (j == 0)
				{
					pm[i][j] = i;
				}
				else
				{
					pm[i][j] = 10;
				}
			}
		}



		for (int i = 1; i < N; i++)
		{
			for (int j = 1; j < M; j++)
			{
				if (Sc[j - 1] == Tc[i - 1])
				{
					pm[i][j] = min(min(pm[i - 1][j - 1], pm[i - 1][j]), pm[i][j - 1]);
				}
				else
				{
					pm[i][j] = min(min(pm[i - 1][j - 1] + 1, pm[i - 1][j] + 1), pm[i][j - 1] + 1);
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

	//возвращает значение i-го,j-го элемента матрицы
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

	//задает значение i-го,j-го элемента матрицы
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

