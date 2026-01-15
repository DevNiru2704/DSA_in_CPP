#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int a[1000];

    // Pattern 1 - Input array
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Pattern 2 - Sum / aggregate
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    cout << "Sum: " << sum << '\n';

    // Pattern 3 - Maximum / minimum
    int mx = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > mx)
            mx = a[i];
    }
    cout << "Maximum: " << mx << '\n';

    return 0;
}
