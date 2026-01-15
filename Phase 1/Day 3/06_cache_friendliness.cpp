#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 10;
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Cache-friendly: sequential access
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    cout << "Sequential sum: " << sum << endl;

    // Print addresses to see contiguous memory
    cout << "\nMemory addresses (notice the spacing):" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] address: " << &a[i] << endl;
    }

    return 0;
}
