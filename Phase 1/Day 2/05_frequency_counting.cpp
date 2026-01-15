#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int a[1000];
    int freq[101] = {0}; // Frequency array for values 0-100

    // Input array
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++; // Increment frequency
    }

    // Output frequencies
    cout << "Frequencies:\n";
    for (int i = 0; i <= 100; i++)
    {
        if (freq[i] > 0)
        {
            cout << i << " appears " << freq[i] << " times\n";
        }
    }

    return 0;
}
