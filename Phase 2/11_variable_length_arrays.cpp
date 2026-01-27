#include <iostream>
using namespace std;

// Drill 11: Variable Length Arrays - The Bug Hunt
void demonstrate_vla_bug()
{
    cout << "Drill 11: Variable Length Arrays (VLA) Bug" << endl;

    // This is the dangerous code from the README
    cout << "Dangerous VLA code:" << endl;
    cout << "int n, m;" << endl;
    cout << "cin >> n >> m;" << endl;
    cout << "int a[n][m];  // NOT STANDARD C++!" << endl;

    cout << "\nWhy this is dangerous:" << endl;
    cout << "1. Not part of C++ standard" << endl;
    cout << "2. GCC allows it as extension" << endl;
    cout << "3. Stack overflow risk with large n,m" << endl;
    cout << "4. Undefined behavior in strict C++" << endl;

    // Safe alternatives
    cout << "\nSafe alternatives:" << endl;

    // Alternative 1: Static arrays with max bounds
    cout << "\n1. Static arrays with max bounds:" << endl;
    const int MAX_N = 1000;
    const int MAX_M = 1000;
    int static_array[MAX_N][MAX_M];
    cout << "int static_array[" << MAX_N << "][" << MAX_M << "];" << endl;

    // Alternative 2: Dynamic allocation
    cout << "\n2. Dynamic allocation:" << endl;
    int n = 10, m = 20;
    int **dynamic_array = new int *[n];
    for (int i = 0; i < n; i++)
    {
        dynamic_array[i] = new int[m];
    }
    cout << "Allocated " << n << "x" << m << " array dynamically" << endl;

    // Cleanup
    for (int i = 0; i < n; i++)
    {
        delete[] dynamic_array[i];
    }
    delete[] dynamic_array;

    // Alternative 3: Flattened array
    cout << "\n3. Flattened 1D array (CP favorite):" << endl;
    int *flattened = new int[n * m];
    // Access as flattened[i * m + j]
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            flattened[i * m + j] = i * m + j;
        }
    }
    cout << "Flattened array: flattened[i * m + j]" << endl;
    delete[] flattened;
}

int main()
{
    demonstrate_vla_bug();
    return 0;
}