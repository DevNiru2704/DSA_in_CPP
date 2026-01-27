#include <iostream>
using namespace std;

// Drill 9: Correct Ways to Pass 2D Arrays
// Method 1: Fixed column size (most common in CP)
void method1_fixed_columns(int arr[][4], int rows)
{
    cout << "Method 1 - Fixed columns: arr[][4]" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Method 1 explicit: Using pointer to array
void method1_explicit(int (*arr)[4], int rows)
{
    cout << "Method 1 explicit - Pointer to array: (*arr)[4]" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Method 2: Fully dynamic (int**)
void method2_dynamic(int **arr, int rows, int cols)
{
    cout << "Method 2 - Dynamic: int**" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Method 3: Flattened 1D array (CP favorite)
void method3_flattened(int *arr, int rows, int cols)
{
    cout << "Method 3 - Flattened: 1D array" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i * cols + j] << " ";
        }
        cout << endl;
    }
}

void demonstrate_all_methods()
{
    cout << "Drill 9: Correct Ways to Pass 2D Arrays" << endl;

    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    // Method 1: Fixed columns
    method1_fixed_columns(matrix, 3);
    cout << endl;

    method1_explicit(matrix, 3);
    cout << endl;

    // Method 2: Dynamic allocation
    int rows = 3, cols = 4;
    int **dynamic_matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        dynamic_matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            dynamic_matrix[i][j] = matrix[i][j];
        }
    }
    method2_dynamic(dynamic_matrix, rows, cols);

    // Cleanup
    for (int i = 0; i < rows; i++)
    {
        delete[] dynamic_matrix[i];
    }
    delete[] dynamic_matrix;
    cout << endl;

    // Method 3: Flattened
    int flattened[12];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            flattened[i * 4 + j] = matrix[i][j];
        }
    }
    method3_flattened(flattened, 3, 4);
}

int main()
{
    demonstrate_all_methods();
    return 0;
}