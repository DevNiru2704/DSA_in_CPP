#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[100][100];
    int n = 50, m = 50;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = i + j;
        }
    }

    cout << "Array initialized correctly with < operator" << endl;
    cout << "a[0][0] = " << a[0][0] << endl;
    cout << "a[49][49] = " << a[49][49] << endl;

    return 0;
}
