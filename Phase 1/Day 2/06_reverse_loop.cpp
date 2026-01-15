#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int a[1000];

    // Input
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Reverse loop - safe version (i is signed int)
    cout << "Reversed: ";
    for (int i = n - 1; i >= 0; i--)
    {
        cout << a[i] << " ";
    }
    cout << '\n';

    return 0;
}
