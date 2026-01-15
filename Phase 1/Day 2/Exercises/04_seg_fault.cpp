#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {0, 1, 2, 3, 4};

    // This will cause segfault - out of bounds access
    cout << arr[1000000] << endl;

    return 0;
}