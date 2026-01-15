#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {5, 12, 8, 23, 17, 9, 14, 6, 20, 11};
    int largest1 = -1, largest2 = -1;
    for (int i = 0; i < size(arr); i++)
    {
        if (arr[i] > largest1)
        {
            largest2 = largest1;
            largest1 = arr[i];
        }
        else if (arr[i] < largest1 && arr[i] > largest2)
        {
            largest2 = arr[i];
        }
    }
    cout << "Largest Number:" << largest1 << "\nSecond Largest Number:" << largest2 << endl;
    return 0;
}