#include <iostream>
using namespace std;

// Drill 6: Pointer Arithmetic
void demonstrate_pointer_arithmetic()
{
    cout << "Drill 6: Pointer Arithmetic" << endl;

    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    cout << "Array elements: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Addresses:" << endl;
    cout << "&arr[0] = " << &arr[0] << endl;
    cout << "ptr = " << ptr << endl;
    cout << "ptr + 1 = " << (ptr + 1) << endl;
    cout << "&arr[1] = " << &arr[1] << endl;

    cout << "Values via pointer arithmetic:" << endl;
    cout << "*ptr = " << *ptr << endl;
    cout << "*(ptr + 1) = " << *(ptr + 1) << endl;
    cout << "*(ptr + 2) = " << *(ptr + 2) << endl;

    // Difference in addresses
    cout << "Address differences:" << endl;
    cout << "ptr + 1 - ptr = " << ((ptr + 1) - ptr) << " (elements)" << endl;
    cout << "(char*)(ptr + 1) - (char*)ptr = " << ((char *)(ptr + 1) - (char *)ptr) << " (bytes)" << endl;
}

int main()
{
    demonstrate_pointer_arithmetic();
    return 0;
}