#include <iostream>
using namespace std;

int main()
{
    int n = 10;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
        cout << arr + i << endl;
    }
    return 0;
}

/*
OUTPUT
0x55a222f10320
0x55a222f10324
0x55a222f10328
0x55a222f1032c
0x55a222f10330
0x55a222f10334
0x55a222f10338
0x55a222f1033c
0x55a222f10340
0x55a222f10344
*/