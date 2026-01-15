#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int rows = 3, cols = 4;

    int **p = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        p[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            p[i][j] = i * cols + j;
        }
    }

    cout << "Scattered memory (int**):" << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "Row " << i << " address: " << p[i] << endl;
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] p[i];
    }
    delete[] p;

    return 0;
}
