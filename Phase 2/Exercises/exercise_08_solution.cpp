#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

// Exercise 8: Cache Awareness Experiment
// Solution: Demonstrates performance difference between row-major and column-major access

const int MATRIX_SIZE = 1024; // Large enough to show cache effects
const int ITERATIONS = 10;    // Multiple runs for accurate timing

void initializeMatrix(vector<vector<int>> &matrix)
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            matrix[i][j] = i * MATRIX_SIZE + j;
        }
    }
}

long long rowMajorTraversal(const vector<vector<int>> &matrix)
{
    long long sum = 0;
    auto start = high_resolution_clock::now();

    for (int iter = 0; iter < ITERATIONS; iter++)
    {
        for (int i = 0; i < MATRIX_SIZE; i++)
        {
            for (int j = 0; j < MATRIX_SIZE; j++)
            {
                sum += matrix[i][j];
            }
        }
    }

    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}

long long columnMajorTraversal(const vector<vector<int>> &matrix)
{
    long long sum = 0;
    auto start = high_resolution_clock::now();

    for (int iter = 0; iter < ITERATIONS; iter++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            for (int i = 0; i < MATRIX_SIZE; i++)
            {
                sum += matrix[i][j];
            }
        }
    }

    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}

// Raw array versions for comparison
long long rowMajorRawArray(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    long long sum = 0;
    auto start = high_resolution_clock::now();

    for (int iter = 0; iter < ITERATIONS; iter++)
    {
        for (int i = 0; i < MATRIX_SIZE; i++)
        {
            for (int j = 0; j < MATRIX_SIZE; j++)
            {
                sum += matrix[i][j];
            }
        }
    }

    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}

long long columnMajorRawArray(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    long long sum = 0;
    auto start = high_resolution_clock::now();

    for (int iter = 0; iter < ITERATIONS; iter++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            for (int i = 0; i < MATRIX_SIZE; i++)
            {
                sum += matrix[i][j];
            }
        }
    }

    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}

void explainCacheEffects()
{
    cout << "\n=== Why Cache Matters ===\n"
         << endl;
    cout << "Modern CPUs have multiple cache levels:" << endl;
    cout << "• L1 Cache: ~32KB, <1ns access" << endl;
    cout << "• L2 Cache: ~256KB, ~4ns access" << endl;
    cout << "• L3 Cache: ~8MB, ~12ns access" << endl;
    cout << "• Main Memory: ~64GB, ~100ns access" << endl;
    cout << endl;

    cout << "Cache lines are typically 64 bytes (16 integers)" << endl;
    cout << "When you access matrix[i][j], the cache loads nearby elements" << endl;
    cout << endl;

    cout << "Row-major access (matrix[i][j]):" << endl;
    cout << "  • Accesses consecutive memory locations" << endl;
    cout << "  • Cache hits are high" << endl;
    cout << "  • Memory access is sequential" << endl;
    cout << endl;

    cout << "Column-major access (matrix[j][i]):" << endl;
    cout << "  • Jumps between rows (large gaps)" << endl;
    cout << "  • Cache misses are frequent" << endl;
    cout << "  • Memory access is scattered" << endl;
    cout << endl;

    cout << "Performance difference can be 2-10x or more!" << endl;
}

int main()
{
    cout << "=== Exercise 8: Cache Awareness Experiment ===\n"
         << endl;
    cout << "Matrix size: " << MATRIX_SIZE << "x" << MATRIX_SIZE << endl;
    cout << "Iterations: " << ITERATIONS << endl;
    cout << "Total operations: " << (long long)MATRIX_SIZE * MATRIX_SIZE * ITERATIONS << endl;
    cout << endl;

    // Test with vector<vector<int>> (cache-unfriendly by default)
    cout << "Testing with vector<vector<int>> (double indirection):" << endl;
    vector<vector<int>> vecMatrix(MATRIX_SIZE, vector<int>(MATRIX_SIZE));
    initializeMatrix(vecMatrix);

    cout << "Row-major traversal..." << endl;
    long long vecRowTime = rowMajorTraversal(vecMatrix);
    cout << "Time: " << vecRowTime << " ms" << endl;

    cout << "Column-major traversal..." << endl;
    long long vecColTime = columnMajorTraversal(vecMatrix);
    cout << "Time: " << vecColTime << " ms" << endl;

    double vecRatio = (double)vecColTime / vecRowTime;
    cout << "Column/Row ratio: " << vecRatio << "x slower" << endl;
    cout << endl;

    // Test with raw 2D array (contiguous memory)
    cout << "Testing with raw 2D array (contiguous memory):" << endl;
    static int rawMatrix[MATRIX_SIZE][MATRIX_SIZE];
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            rawMatrix[i][j] = i * MATRIX_SIZE + j;
        }
    }

    cout << "Row-major traversal..." << endl;
    long long rawRowTime = rowMajorRawArray(rawMatrix);
    cout << "Time: " << rawRowTime << " ms" << endl;

    cout << "Column-major traversal..." << endl;
    long long rawColTime = columnMajorRawArray(rawMatrix);
    cout << "Time: " << rawColTime << " ms" << endl;

    double rawRatio = (double)rawColTime / rawRowTime;
    cout << "Column/Row ratio: " << rawRatio << "x slower" << endl;
    cout << endl;

    // Summary
    cout << "=== Performance Summary ===" << endl;
    cout << "vector<vector>: " << vecRatio << "x slower (column vs row)" << endl;
    cout << "raw array: " << rawRatio << "x slower (column vs row)" << endl;
    cout << endl;

    cout << "Key insights:" << endl;
    cout << "• Memory layout affects performance dramatically" << endl;
    cout << "• vector<vector> is cache-unfriendly due to double indirection" << endl;
    cout << "• Raw arrays are faster but less safe" << endl;
    cout << "• Always prefer row-major access in C/C++" << endl;
    cout << "• Cache-aware programming can improve performance 2-10x" << endl;

    explainCacheEffects();

    return 0;
}