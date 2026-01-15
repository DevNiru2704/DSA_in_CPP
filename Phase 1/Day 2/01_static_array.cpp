#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Static array - compile time size
    int a[5] = {1, 2, 3, 4, 5};

    cout << "Array elements: ";
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << '\n';

    return 0;
}
