#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Dynamic array - runtime size
    int *a = new int[n];

    // Input
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Output
    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << '\n';

    // Don't forget to free memory
    delete[] a;

    return 0;
}
