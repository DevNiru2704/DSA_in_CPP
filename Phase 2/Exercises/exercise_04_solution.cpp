#include <iostream>
using namespace std;

// Exercise 4: 2D Array Memory Layout
// Solution: Proves that 2D arrays are contiguous in memory

void print2DArrayAddresses(int arr[][4], int rows, int cols)
{
    cout << "Memory addresses of 2D array elements:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "&arr[" << i << "][" << j << "] = " << &arr[i][j] << " ";
        }
        cout << endl;
    }
}

void demonstrateContiguity(int arr[][4], int rows, int cols)
{
    cout << "\nProving contiguity (row-major order):" << endl;

    // Treat 2D array as 1D array
    int *flatPtr = &arr[0][0];
    int totalElements = rows * cols;

    cout << "As 1D array: ";
    for (int i = 0; i < totalElements; i++)
    {
        cout << flatPtr[i] << " ";
    }
    cout << endl;

    // Show addresses are consecutive
    cout << "\nAddress sequence: ";
    for (int i = 0; i < totalElements; i++)
    {
        cout << &flatPtr[i] << " ";
    }
    cout << endl;

    // Calculate differences
    cout << "\nAddress differences (should be " << sizeof(int) << " bytes):" << endl;
    for (int i = 0; i < totalElements - 1; i++)
    {
        ptrdiff_t diff = (char *)&flatPtr[i + 1] - (char *)&flatPtr[i];
        cout << "&arr[" << i + 1 << "] - &arr[" << i << "] = " << diff << " bytes" << endl;
    }
}

void compareWithIntStarStar(int rows, int cols)
{
    cout << "\n=== Comparison with int** (non-contiguous) ===" << endl;

    // Create int** array (jagged array)
    int **jagged = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        jagged[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            jagged[i][j] = (i + 1) * 10 + j;
        }
    }

    cout << "int** array addresses (NOT contiguous):" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "&jagged[" << i << "][" << j << "] = " << &jagged[i][j] << " ";
        }
        cout << endl;
    }

    // Row addresses
    cout << "\nRow addresses: ";
    for (int i = 0; i < rows; i++)
    {
        cout << "jagged[" << i << "] = " << (void *)jagged[i] << " ";
    }
    cout << endl;

    // Cleanup
    for (int i = 0; i < rows; i++)
    {
        delete[] jagged[i];
    }
    delete[] jagged;
}

int main()
{
    cout << "=== Exercise 4: 2D Array Memory Layout ===\n"
         << endl;

    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    cout << "Original 2D array:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Show addresses
    print2DArrayAddresses(matrix, 3, 4);

    // Prove contiguity
    demonstrateContiguity(matrix, 3, 4);

    // Compare with int**
    compareWithIntStarStar(3, 4);

    cout << "\n=== Key Insights ===" << endl;
    cout << "• Real 2D arrays (int arr[][4]) are contiguous in memory" << endl;
    cout << "• Elements are stored in row-major order" << endl;
    cout << "• int** creates jagged arrays (non-contiguous)" << endl;
    cout << "• Each row in int** can be anywhere in memory" << endl;

    return 0;
}