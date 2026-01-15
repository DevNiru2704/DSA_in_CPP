#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, sum = 0;
    for (int i = 1; i <= 10; i++)
    {
        cin >> n;
        sum += n;
    }
    cout << sum << endl;
    return 0;
}