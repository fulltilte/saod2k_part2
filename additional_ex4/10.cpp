#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <vector>

using namespace std;

size_t naive(const string& str, const string& sub)
{
	size_t n = str.size(), m = sub.size(), j = 0;
	for (size_t i = 0; i < n - m + 1; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (str[i + j] != sub[j])
				break;
		}
		if (j == m)
			return i;
	}
	return string::npos;
}

size_t kmp(const string& str, const string& sub)
{
	size_t n = str.size(), m = sub.size();
	int* pi = new int[m];
	pi[0] = 0;
	for (size_t i = 1, j = 0; i < m; i++) {

		while (j > 0 && sub[i] != sub[j])
			j = pi[j - 1];
		if (sub[i] == sub[j])
			j++;
		pi[i] = j;
	}

	for (size_t i = 0, j = 0; i < n; i++) {
		while (j > 0 && str[i] != sub[j])
			j = pi[j - 1];
		if (str[i] == sub[j])
			j++;
		if (j == m)
		{
			delete[] pi;
			return i - m + 1;
		}
	}
	delete[] pi;
	return string::npos;
}

size_t bm(const string& str, const string& sub)
{
	size_t n = str.size(), m = sub.size();
	vector<int> badchar(128, -1);
	for (size_t i = 0; i < m; i++) {
		badchar[sub[i]] = i;
	}

	int s = 0;
	while (s <= (n - m))
	{
		int j = m - 1;
		while (j >= 0 && sub[j] == str[s + j])
		{
			--j;
		}
		if (j < 0) return s;
		else s += max(1, j - badchar[str[s + j]]);
	}
	return string::npos;
}

int main()
{
	string str, sub = "was born in a small town called Sceptre";
	ifstream fin("engwiki_ascii.txt", ios::binary);
	if (!fin.is_open())
	{
		cout << "not open!"<< endl;
		return 0;
	}
	str.append((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());

	size_t n = 10;
	vector<size_t> times(n), indx(n);

	cout << "\n find\n";
	for (size_t i = 0; i < n; i++)
	{
		auto time_one = chrono::high_resolution_clock::now();
		auto index = str.find(sub);
		if (index == string::npos)
			cout << "not found\n";
		else
			indx[i] = index;
		auto time_two = chrono::high_resolution_clock::now();
		times[i] = chrono::duration_cast<chrono::milliseconds>(time_two - time_one).count();
	}
	for (size_t i = 0; i < n; i++)
	{
		cout << indx[i] << '\t' << times[i] << endl;
	}

	cout << "\nnaive\n";
	for (size_t i = 0; i < n; i++)
	{
		auto time_one = chrono::high_resolution_clock::now();
		auto index = naive(str, sub);
		if (index == string::npos)
			cout << "not found\n";
		else
			indx[i] = index;
		auto time_two = chrono::high_resolution_clock::now();
		times[i] = chrono::duration_cast<chrono::milliseconds>(time_two - time_one).count();
	}
	for (size_t i = 0; i < n; i++)
	{
		cout << indx[i] << '\t' << times[i] << endl;
	}

	cout <<  "\nkmp\n";
	for (size_t i = 0; i < n; i++)
	{
		auto time_one = chrono::high_resolution_clock::now();
		auto index = kmp(str, sub);
		if (index == string::npos)
			cout << "not found\n";
		else
			indx[i] = index;
		auto time_two = chrono::high_resolution_clock::now();
		times[i] = chrono::duration_cast<chrono::milliseconds>(time_two - time_one).count();
	}
	for (size_t i = 0; i < n; i++)
	{
		cout << indx[i] << '\t' << times[i] << endl;
	}

	cout << "\nbm\n";
	for (size_t i = 0; i < n; i++)
	{
		auto time_one = chrono::high_resolution_clock::now();
		auto index = bm(str, sub);
		if (index == string::npos)
			cout << "not found\n";
		else
			indx[i] = index;
		auto time_two = chrono::high_resolution_clock::now();
		times[i] = chrono::duration_cast<chrono::milliseconds>(time_two - time_one).count();
	}
	for (size_t i = 0; i < n; i++)
	{
		cout << indx[i] << '\t' << times[i] << endl;
	}
}

