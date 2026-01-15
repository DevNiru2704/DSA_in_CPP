#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int rows = 3, cols = 4;

    cout << "Static 2D array (contiguous):" << endl;
    int staticArr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    for (int i = 0; i < 3; i++)
    {
        cout << "Row " << i << " address: " << &staticArr[i][0] << endl;
    }

    cout << "\nint** (scattered memory):" << endl;
    int **dynArr = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        dynArr[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            dynArr[i][j] = i * cols + j + 1;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        cout << "Row " << i << " address: " << dynArr[i] << endl;
    }

    cout << "\nNotice: static array rows are adjacent, int** rows are scattered!" << endl;

    for (int i = 0; i < rows; i++)
    {
        delete[] dynArr[i];
    }
    delete[] dynArr;

    return 0;
}
