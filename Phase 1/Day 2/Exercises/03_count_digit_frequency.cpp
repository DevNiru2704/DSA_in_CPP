#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long unsigned int n, temp;
    int r;
    int freq[10] = {0};
    cin >> n;
    temp = n;
    while (temp != 0)
    {
        r = temp % 10;
        freq[r]++;
        cout << r << " " << freq[r] << endl;
        temp /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        if (freq[i] == 0)
            continue;
        cout << "Frequency of digit " << i << " = " << freq[i] << endl;
    }
    return 0;
}