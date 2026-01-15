#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int rows = 1000, cols = 1000;
    int arr[1000][1000];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = i * cols + j;
        }
    }

    long long sum1 = 0, sum2 = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum1 += arr[i][j];
        }
    }

    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            sum2 += arr[i][j];
        }
    }

    cout << "Row-wise sum: " << sum1 << endl;
    cout << "Column-wise sum: " << sum2 << endl;

    return 0;
}
