#include <iostream>
#include <chrono>
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

    auto start1 = chrono::high_resolution_clock::now();
    long long sum1 = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            sum1 += a[i][j];
        }
    }
    auto end1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);

    auto start2 = chrono::high_resolution_clock::now();
    long long sum2 = 0;
    for (int j = 0; j < C; j++)
    {
        for (int i = 0; i < R; i++)
        {
            sum2 += a[i][j];
        }
    }
    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);

    cout << "Row-wise sum: " << sum1 << " (Time: " << duration1.count() << " µs)" << endl;
    cout << "Column-wise sum: " << sum2 << " (Time: " << duration2.count() << " µs)" << endl;
    cout << "\nRow-wise is faster due to cache locality!" << endl;

    return 0;
}
