#include <iostream>
using namespace std;

void passArray(int arr[])
{
    cout << sizeof(arr) << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << sizeof(arr) << endl;
    passArray(arr);
    return 0;
}