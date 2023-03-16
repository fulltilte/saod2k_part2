#include <iostream>
#include <cmath>
using namespace std;
#include "Complex.h"

int main()
{
    Complex a(1, 2), b = 3;
    cout << a << "," << b << endl;
    Complex x(2, 5);
    Complex y(7, 3);
    cout << x + y << endl;
    cout << x - y << endl;
    cout << x * y << endl;
    cout << x / y << endl;
    cout << x.Mod() << endl;
    cout << x.Arg() << endl;
    Complex v[4]{ 1,2,Complex(2,3) };
    for (int i = 0; i < 4; i++)
        cout << v[i] << ' ';
    cout << endl;
    Complex* pc = new Complex(1);
    cout << *pc << endl;
    delete pc;

}
