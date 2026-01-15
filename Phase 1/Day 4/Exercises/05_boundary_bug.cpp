#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[100][100];
    int n = 50, m = 50;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            a[i][j] = 0;
        }
    }

    cout << "Buggy version ran (may crash or show undefined behavior)" << endl;

    return 0;
}
