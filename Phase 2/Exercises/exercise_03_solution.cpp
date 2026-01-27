#include <iostream>
using namespace std;

// Exercise 3: Pointer Arithmetic Mastery
// Solution: Demonstrates pointer arithmetic with arrays

// Custom strlen using pointer arithmetic
size_t myStrlen(const char *str)
{
    const char *start = str;
    while (*str != '\0')
    {
        str++;
    }
    return str - start;
}

void printArrayForward(int *arr, int size)
{
    cout << "Forward traversal: ";
    for (int *ptr = arr; ptr < arr + size; ptr++)
    {
        cout << *ptr << " ";
    }
    cout << endl;
}

void printArrayReverse(int *arr, int size)
{
    cout << "Reverse traversal: ";
    for (int *ptr = arr + size - 1; ptr >= arr; ptr--)
    {
        cout << *ptr << " ";
    }
    cout << endl;
}

void demonstrateAddresses(int *arr, int size)
{
    cout << "Memory addresses:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "&arr[" << i << "] = " << &arr[i] << endl;
    }

    cout << "\nAddress differences:" << endl;
    cout << "&arr[1] - &arr[0] = " << (&arr[1] - &arr[0]) << " elements" << endl;
    cout << "In bytes: " << ((char *)&arr[1] - (char *)&arr[0]) << " bytes" << endl;
    cout << "sizeof(int) = " << sizeof(int) << " bytes" << endl;
}

void demonstrateOutOfBounds(int *arr, int size)
{
    cout << "\nOut of bounds demonstration (DANGER!):" << endl;
    cout << "Valid access: arr[4] = " << arr[4] << endl;
    cout << "Out of bounds: arr[5] = " << arr[5] << " (UNDEFINED!)" << endl;
    cout << "Using pointer: *(arr + 5) = " << *(arr + 5) << " (UNDEFINED!)" << endl;
}

int main()
{
    cout << "=== Exercise 3: Pointer Arithmetic Mastery ===\n"
         << endl;

    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl
         << endl;

    // Forward traversal
    printArrayForward(arr, size);
    cout << endl;

    // Reverse traversal
    printArrayReverse(arr, size);
    cout << endl;

    // Address demonstration
    demonstrateAddresses(arr, size);
    cout << endl;

    // Out of bounds (commented out for safety)
    // demonstrateOutOfBounds(arr, size);

    // Custom strlen demonstration
    cout << "Custom strlen demonstration:" << endl;
    const char *testStr = "Hello, World!";
    cout << "String: \"" << testStr << "\"" << endl;
    cout << "Length using myStrlen: " << myStrlen(testStr) << endl;
    cout << "Length using std::strlen: " << strlen(testStr) << endl;

    return 0;
}