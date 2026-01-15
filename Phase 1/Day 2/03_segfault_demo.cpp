#include <iostream>
using namespace std;

int main()
{
    int a[5] = {1, 2, 3, 4, 5};

    // Safe access
    cout << "Safe: a[0] = " << a[0] << '\n';

    // Uncomment below to cause segmentation fault

    // 1. Out of bounds access
    // a[10] = 3;

    // 2. Negative index
    // a[-1] = 7;

    // 3. Uninitialized pointer
    // int* p;
    // *p = 5;

    // 4. Using deleted memory
    // int* b = new int[5];
    // delete[] b;
    // b[0] = 1;

    cout << "Program ran safely\n";
    return 0;
}
