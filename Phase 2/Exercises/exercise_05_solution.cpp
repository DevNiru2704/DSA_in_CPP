#include <iostream>
using namespace std;

// Exercise 5: Function Parameter Bug Hunt
// Solution: Demonstrates all three correct ways to pass 2D arrays

// Method 1: Fixed column size (most common in CP)
void printMatrix_Method1(int arr[][4], int rows)
{
    cout << "Method 1 - Fixed columns (int arr[][4]):" << endl;
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
void printMatrix_Method1_Explicit(int (*arr)[4], int rows)
{
    cout << "Method 1 explicit - Pointer to array (int (*arr)[4]):" << endl;
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
void printMatrix_Method2(int **arr, int rows, int cols)
{
    cout << "Method 2 - Dynamic (int**):" << endl;
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
void printMatrix_Method3(const int *arr, int rows, int cols)
{
    cout << "Method 3 - Flattened 1D array:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i * cols + j] << " ";
        }
        cout << endl;
    }
}

// Performance comparison
#include <chrono>
using namespace std::chrono;

void performanceTest(int iterations = 100000)
{
    cout << "\n=== Performance Comparison ===" << endl;

    const int ROWS = 10;
    const int COLS = 10;

    // Setup test data
    int real2D[ROWS][COLS];
    int *flattened = new int[ROWS * COLS];
    int **dynamic = new int *[ROWS];

    for (int i = 0; i < ROWS; i++)
    {
        dynamic[i] = new int[COLS];
        for (int j = 0; j < COLS; j++)
        {
            int val = i * COLS + j;
            real2D[i][j] = val;
            flattened[i * COLS + j] = val;
            dynamic[i][j] = val;
        }
    }

    // Test Method 1 (real 2D array)
    auto start = high_resolution_clock::now();
    for (int iter = 0; iter < iterations; iter++)
    {
        volatile int sum = 0;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                sum += real2D[i][j];
            }
        }
    }
    auto end = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(end - start);

    // Test Method 3 (flattened)
    start = high_resolution_clock::now();
    for (int iter = 0; iter < iterations; iter++)
    {
        volatile int sum = 0;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                sum += flattened[i * COLS + j];
            }
        }
    }
    end = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(end - start);

    // Test Method 2 (dynamic)
    start = high_resolution_clock::now();
    for (int iter = 0; iter < iterations; iter++)
    {
        volatile int sum = 0;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                sum += dynamic[i][j];
            }
        }
    }
    end = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end - start);

    cout << "Method 1 (real 2D): " << duration1.count() << " microseconds" << endl;
    cout << "Method 2 (int**): " << duration2.count() << " microseconds" << endl;
    cout << "Method 3 (flattened): " << duration3.count() << " microseconds" << endl;

    // Cleanup
    delete[] flattened;
    for (int i = 0; i < ROWS; i++)
    {
        delete[] dynamic[i];
    }
    delete[] dynamic;
}

int main()
{
    cout << "=== Exercise 5: Function Parameter Bug Hunt ===\n"
         << endl;

    int realMatrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    // Method 1: Fixed columns
    printMatrix_Method1(realMatrix, 3);
    cout << endl;

    printMatrix_Method1_Explicit(realMatrix, 3);
    cout << endl;

    // Method 2: Dynamic allocation
    int rows = 3, cols = 4;
    int **dynamicMatrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        dynamicMatrix[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            dynamicMatrix[i][j] = realMatrix[i][j];
        }
    }
    printMatrix_Method2(dynamicMatrix, rows, cols);
    cout << endl;

    // Method 3: Flattened
    int flattened[12];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            flattened[i * 4 + j] = realMatrix[i][j];
        }
    }
    printMatrix_Method3(flattened, 3, 4);

    // Performance comparison
    performanceTest();

    // Cleanup
    for (int i = 0; i < rows; i++)
    {
        delete[] dynamicMatrix[i];
    }
    delete[] dynamicMatrix;

    cout << "\n=== Summary ===" << endl;
    cout << "Method 1: Safest, fastest, but fixed column size" << endl;
    cout << "Method 2: Flexible, but slower and more complex" << endl;
    cout << "Method 3: Fastest, most flexible, CP favorite" << endl;

    return 0;
}