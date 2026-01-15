#include <iostream>
using namespace std;

// void transposeMatrix(int **arr, int row, int col)
int *transposeMatrix(int *arr, int row, int col)
{
    int *transpose = new int[col * row];
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            transpose[i * row + j] = arr[j * col + i];
        }
    }
    return transpose;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int row, col;
    cin >> row >> col;
    // int **arr = new int *[row];
    int *arr = new int[row * col];
    for (int i = 0; i < row; i++)
    {
        // arr[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i * col + j];
            // cin >> arr[i][j];
        }
    }

    cout << "Original Matrix" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i * col + j] << " ";
            // cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int *transpose = transposeMatrix(arr, row, col);
    cout << "Transposed Matrix" << endl;

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << arr[j * row + i] << " ";
        }
        cout << endl;
    }

    delete[] arr;
    delete[] transpose;
    return 0;
}