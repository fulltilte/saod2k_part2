// ex1(HelloWorld).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    cout << "Hello, World!" << endl;

    int x, y;
    cout << "x = ? "; cin >> x;
    cout << "y = ? "; cin >> y;
    cout << x << " + " << y << " = " << x + y << endl;
    cout << x << " - " << y << " = " << x - y << endl;
    cout << x << " * " << y << " = " << x * y << endl;
    cout << x << " / " << y << " = " << x / y << endl;
    cout << x << " pow " << y << " = " << pow(x, y) << endl;
}