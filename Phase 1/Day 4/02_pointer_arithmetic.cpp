#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    cout << "a[1][2] using indexing: " << a[1][2] << endl;
    cout << "a[1][2] using pointer arithmetic: " << *(*(a + 1) + 2) << endl;

    cout << "\nRow addresses:" << endl;
    cout << "a (row 0): " << a << endl;
    cout << "a + 1 (row 1): " << a + 1 << endl;
    cout << "a + 2 (row 2): " << a + 2 << endl;

    cout << "\nElement addresses:" << endl;
    cout << "&a[1][0]: " << &a[1][0] << endl;
    cout << "a + 1: " << a + 1 << endl;

    return 0;
}
