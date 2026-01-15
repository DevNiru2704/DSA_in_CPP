#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Stack allocation - small, fast
    int stackArr[1000];
    for (int i = 0; i < 1000; i++)
    {
        stackArr[i] = i;
    }
    cout << "Stack array created successfully" << endl;

    // Heap allocation - larger, manual control
    int n = 5000;
    int *heapArr = new int[n];
    for (int i = 0; i < n; i++)
    {
        heapArr[i] = i;
    }
    cout << "Heap array created successfully" << endl;

    // Must free heap memory
    delete[] heapArr;

    return 0;
}
