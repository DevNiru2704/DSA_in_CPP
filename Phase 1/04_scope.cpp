#include <iostream>
using namespace std;
int main()
{
    int x = 10;

    if (true)
    {
        int x = 5;
        cout << x << '\n'; // 5
    }

    cout << x << '\n'; // 10
}