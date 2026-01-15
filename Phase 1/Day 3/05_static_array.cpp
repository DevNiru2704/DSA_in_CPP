#include <iostream>
using namespace std;

// Global/static array for large size
static int globalArr[200000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Initialize global array
    for (int i = 0; i < 200000; i++)
    {
        globalArr[i] = i;
    }

    cout << "Large static array created successfully" << endl;
    cout << "First element: " << globalArr[0] << endl;
    cout << "Last element: " << globalArr[199999] << endl;

    return 0;
}
