#include <iostream>
#include "WF.h"
#include "RWF.h"
using namespace std;

int Distance(const WF& wf, const RWF& rwf)
{
	if (wf.Rows() == rwf.Rows())
	{
		int min = 1000000000;
		for (int i = 0; i < rwf.Rows(); i++)
		{
			int k = rwf.Get(i, rwf.Columns() - 1) + wf.Get(i, 0);
			if (min > k)
			{
				min = k;
			}
		}
		return min;
	}
	else
	{
		throw logic_error("Distance: wf.Rows() != rwf.Rows()");
	}
}


int main()
{
	
	WF srav1 = WF("ono", "n");
	RWF srav2 = RWF("ono", "o");
	WF srav_glav = WF("ono", "no");


	srav1.Init();
	srav2.Init();
	srav_glav.Init();

	cout << "srav_glav = " << srav_glav.ProximityOfLines() << endl;
	cout << "srav = " << Distance(srav1, srav2) << endl;

	
}

