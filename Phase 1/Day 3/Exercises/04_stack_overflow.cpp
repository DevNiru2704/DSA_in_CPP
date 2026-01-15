#include <iostream>
using namespace std;

static int largeArr[200000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 200000; i++)
    {
        largeArr[i] = i;
    }

    cout << "Array created successfully using static storage" << endl;
    cout << "First: " << largeArr[0] << ", Last: " << largeArr[199999] << endl;

    return 0;
}
