#include <iostream>
using namespace std;

int main()
{
    int x = 1;
    for (int i = 0; i < 3; i++)
    {
        int x = i;
    }
    cout << x << '\n'; // Output:1
}