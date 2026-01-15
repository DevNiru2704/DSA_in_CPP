#include <iostream>
using namespace std;

void printArray(int a[][4], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    cout << "Passing 2D array to function:" << endl;
    printArray(arr, 3);

    return 0;
}
