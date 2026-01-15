#include <iostream>
using namespace std;

void printArray(int a[], int n)
{
    cout << "Inside function - sizeof(a): " << sizeof(a) << endl;
    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "In main - sizeof(arr): " << sizeof(arr) << endl;

    // Array decays to pointer when passed
    printArray(arr, 10);

    return 0;
}
