#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // sizeof on array in same scope
    int a[5] = {1, 2, 3, 4, 5};
    cout << "sizeof(a) = " << sizeof(a) << endl;
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "Number of elements = " << sizeof(a) / sizeof(int) << endl;

    // sizeof on pointer
    int *p = a;
    cout << "sizeof(p) = " << sizeof(p) << endl;

    // This only works in the scope where array is declared
    int size = sizeof(a) / sizeof(a[0]);
    cout << "Array size using sizeof trick: " << size << endl;

    return 0;
}
