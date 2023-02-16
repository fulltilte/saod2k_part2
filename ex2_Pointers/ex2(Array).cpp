#include <iostream>
using namespace std;

void Swap(int& a, int& b) {
    cout << "a = " << a << ", b = " << b << endl;

    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void rotate(int a[], int n, bool clockwise) {

    if (clockwise) {
        int x = a[n - 1];
        for (int i = n - 1 ; i > 0; i--)
            a[i] = a[i - 1];
        a[0] = x;
    }
    else {
        int x = a[0];
        for (int i = 1; i < n; i++)
            a[i - 1] = a[i];
        a[n - 1] = x;
    }
}

int main()
{
    /*int x = 3;
    int* p = &x;
    cout << x << ' ' << *p << ' ' << p << endl;

    p++;
    cout << p << endl;

    cout << p - &x << endl;

    typedef unsigned char byte;

    byte* pb = (byte*)--p;
    for (byte* pt = pb; pt - pb < sizeof(int); pt++)
        cout << (int)*pt << ' ';

    cout << endl;*/

    int a = 3, b = 5;

    Swap(a, b);
    cout << "a = " << a << ", b = " << b << '\n' << endl;

    int array[5]{ 1,2,3,4,5 };

    for (int i = 0; i < 5; i++)
        cout << array[i] << ' ';
    cout << endl;

    for (int* p = array; p - array < 5; p++)
        cout << *p << ' ';
    cout << endl;
    
    bool clockwise = true;

    rotate(array, 5, clockwise);

    for (int i = 0; i < 5; i++)
        cout << array[i] << ' ';
    cout << endl;

    char str[] = "Hello!";
    cout << str << endl;

    cout << strlen(str) << ' ' << sizeof(str) << endl;

    char t[32];
    for (char* pd = t, *ps = str; *pd++ = *ps++;);

    cout << sizeof(t) << endl;
}
