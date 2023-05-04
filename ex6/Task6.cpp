#include <iostream>
#include "Str.h"
#include "Check_Mem_leak.h"

using namespace std;

Check_Mem_leak  check_mem;

int main()
{
    check_mem.GetFirstMemState();

    Str s = "Hello"; 

    const char* ptr_s = s;
    cout << "Input text: " << (const char*)s << endl;

    Str t;
    t = s;
    t += "_abc";

    cout << "S: Our text: " << s << endl;
    cout << "S: Size our text: " << s.len() << endl;

    cout << "S: Pos_1: " << s.find("el", 0) << endl;
    cout << "S: Pos_2: " << s.find("ll", 1) << endl;
    cout << "S: Pos_3: " << s.find("llo", 0) << endl;
    cout << "S: Pos_4: " << s.find("_ab", 0) << endl;
    cout << "S: Pos_5: " << s.find("_ab", 4) << endl;
    cout << "S: Pos_6: " << s.find("abc", 4) << endl;
    cout << "S: Pos_7: " << s.find("abc", 6) << endl;
    cout << "S: Pos_7.1: " << s.find("abc", 7) << endl;
    cout << "S: Pos_8: " << s.find("H", 0) << endl;
    cout << "S: Pos_9: " << s.find("c", 7) << endl;
    cout << "S: Pos_10: " << s.find("_abb", 3) << endl;
    
    cout << "T: Our text: " << t << endl;
    cout << "T: Size our text: " << t.len() << endl;

    cout << "T: Pos_1: " << t.find("el", 0) << endl;
    cout << "T: Pos_2: " << t.find("ll", 1) << endl;
    cout << "T: Pos_3: " << t.find("llo", 0) << endl;
    cout << "T: Pos_4: " << t.find("_ab", 0) << endl;
    cout << "T: Pos_5: " << t.find("_ab", 4) << endl;
    cout << "T: Pos_6: " << t.find("abc", 4) << endl;
    cout << "T: Pos_7: " << t.find("abc", 6) << endl;
    cout << "T: Pos_7.1: " << t.find("abc", 7) << endl;
    cout << "T: Pos_8: " << t.find("H", 0) << endl;
    cout << "T: Pos_9: " << t.find("c", 7) << endl;
    cout << "T: Pos_10: " << t.find("_abb", 3) << endl;

    check_mem.GetMiddleMemState();
    check_mem.GetResultMemState();

    return 0;
}

