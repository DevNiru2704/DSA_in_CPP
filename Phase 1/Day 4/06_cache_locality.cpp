#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R = 1000, C = 1000;
    int a[1000][1000];

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            a[i][j] = i * C + j;
        }
    }

    long long sum1 = 0, sum2 = 0;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            sum1 += a[i][j];
        }
    }

    for (int j = 0; j < C; j++)
    {
        for (int i = 0; i < R; i++)
        {
            sum2 += a[i][j];
        }
    }

    cout << "Row-wise (cache-friendly) sum: " << sum1 << endl;
    cout << "Column-wise (cache-hostile) sum: " << sum2 << endl;

    return 0;
}
