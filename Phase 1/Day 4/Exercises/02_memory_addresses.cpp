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

    cout << "Element addresses (contiguous layout):" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << &a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nAddress differences (should be 4 bytes for int):" << endl;
    long long diff = (long long)&a[0][1] - (long long)&a[0][0];
    cout << "a[0][1] - a[0][0]: " << diff << " bytes" << endl;

    return 0;
}
