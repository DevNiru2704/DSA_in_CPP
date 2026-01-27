#include <iostream>
using namespace std;

// Drill 7: Arrays in Competitive Programming
void demonstrate_arrays()
{
    cout << "Drill 7: Arrays - Static, Dynamic, Multidimensional" << endl;

    // Static array - stack allocated, fast
    cout << "Static array:" << endl;
    const int MAX_SIZE = 100000;
    static int static_arr[MAX_SIZE];
    static_arr[0] = 42;
    cout << "static_arr[0] = " << static_arr[0] << endl;

    // Dynamic array - heap allocated, manual cleanup
    cout << "\nDynamic array:" << endl;
    int n = 10;
    int *dynamic_arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        dynamic_arr[i] = i * 10;
        cout << dynamic_arr[i] << " ";
    }
    cout << endl;
    delete[] dynamic_arr;

    // Multidimensional array - contiguous memory
    cout << "\n2D Array (3x4):" << endl;
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void cache_awareness_demo()
{
    cout << "\nCache Awareness Demo:" << endl;
    const int ROWS = 1000;
    const int COLS = 1000;
    static int matrix[ROWS][COLS];

    // Initialize
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            matrix[i][j] = i + j;
        }
    }

    long long sum = 0;

    // Row-wise traversal (cache-friendly)
    cout << "Row-wise traversal..." << endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            sum += matrix[i][j];
        }
    }
    cout << "Row-wise sum: " << sum << endl;

    sum = 0;
    // Column-wise traversal (cache-unfriendly)
    cout << "Column-wise traversal..." << endl;
    for (int j = 0; j < COLS; j++)
    {
        for (int i = 0; i < ROWS; i++)
        {
            sum += matrix[i][j];
        }
    }
    cout << "Column-wise sum: " << sum << endl;
}

int main()
{
    demonstrate_arrays();
    cache_awareness_demo();
    return 0;
}