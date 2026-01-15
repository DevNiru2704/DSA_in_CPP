#include <iostream>
using namespace std;

void reverseArray(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] == arr[n - i - 1])
            continue;
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

int main()
{
    int arr[] = {5, 10, 6, 1, 3, 4, 2, 8};
    int n = size(arr);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    reverseArray(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}