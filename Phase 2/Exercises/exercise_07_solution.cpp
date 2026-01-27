#include <iostream>
using namespace std;

// Exercise 7: Pointer vs Reference Challenge
// Solution: Rewrites functions to use appropriate parameter types

// Original functions (pointer-based)
void swapPointers(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int *findMaxPointers(int *arr, int size)
{
    if (size == 0)
        return nullptr;
    int *maxPtr = arr;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > *maxPtr)
        {
            maxPtr = &arr[i];
        }
    }
    return maxPtr;
}

void updateValuePointers(int *ptr)
{
    if (ptr)
        *ptr = 999;
}

// Improved versions using references where appropriate
void swapReferences(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// This should still use pointers because it returns a pointer to an element
// References cannot be used for return values in this case
int *findMaxMixed(int *arr, int size)
{
    if (size == 0)
        return nullptr;
    int *maxPtr = arr;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > *maxPtr)
        {
            maxPtr = &arr[i];
        }
    }
    return maxPtr;
}

// This can use references - we know ptr is not null when called
void updateValueReferences(int &value)
{
    value = 999;
}

// Additional examples showing when to use each
void printValue(const int &value)
{
    cout << "Value: " << value << endl;
}

void modifyValue(int &value)
{
    value *= 2;
}

void processArray(int *arr, int size)
{
    // Must use pointers here because we need to handle null arrays
    if (!arr || size <= 0)
    {
        cout << "Invalid array" << endl;
        return;
    }

    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void safeDivision(double dividend, double divisor, double &result)
{
    // Use reference for output parameter
    if (divisor == 0)
    {
        cout << "Division by zero!" << endl;
        result = 0;
        return;
    }
    result = dividend / divisor;
}

int main()
{
    cout << "=== Exercise 7: Pointer vs Reference Challenge ===\n"
         << endl;

    int x = 10, y = 20;
    cout << "Original values: x=" << x << ", y=" << y << endl;

    // Test swap functions
    cout << "\n1. Testing swap functions:" << endl;

    int a = 100, b = 200;
    cout << "Before swapPointers: a=" << a << ", b=" << b << endl;
    swapPointers(&a, &b);
    cout << "After swapPointers: a=" << a << ", b=" << b << endl;

    a = 300, b = 400;
    cout << "Before swapReferences: a=" << a << ", b=" << b << endl;
    swapReferences(a, b);
    cout << "After swapReferences: a=" << a << ", b=" << b << endl;

    // Test findMax functions
    cout << "\n2. Testing findMax functions:" << endl;
    int arr[] = {3, 7, 2, 9, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int *maxPtr = findMaxPointers(arr, size);
    cout << "Max value (pointers): " << *maxPtr << " at index " << (maxPtr - arr) << endl;

    maxPtr = findMaxMixed(arr, size);
    cout << "Max value (mixed): " << *maxPtr << " at index " << (maxPtr - arr) << endl;

    // Test update functions
    cout << "\n3. Testing update functions:" << endl;
    int val1 = 42, val2 = 84;

    cout << "Before updateValuePointers: val1=" << val1 << endl;
    updateValuePointers(&val1);
    cout << "After updateValuePointers: val1=" << val1 << endl;

    cout << "Before updateValueReferences: val2=" << val2 << endl;
    updateValueReferences(val2);
    cout << "After updateValueReferences: val2=" << val2 << endl;

    // Demonstrate const references
    cout << "\n4. Const reference usage:" << endl;
    printValue(42); // No copy needed

    // Reference for modification
    cout << "\n5. Reference for modification:" << endl;
    int num = 5;
    cout << "Before modifyValue: " << num << endl;
    modifyValue(num);
    cout << "After modifyValue: " << num << endl;

    // Pointer for optional parameters
    cout << "\n6. Pointer for optional/array parameters:" << endl;
    processArray(arr, size);
    processArray(nullptr, 0); // Safe with pointers

    // Reference for output parameters
    cout << "\n7. Reference for output parameters:" << endl;
    double result;
    safeDivision(10.0, 2.0, result);
    cout << "10 / 2 = " << result << endl;

    safeDivision(10.0, 0.0, result);
    cout << "10 / 0 = " << result << endl;

    cout << "\n=== Guidelines ===" << endl;
    cout << "Use REFERENCES when:" << endl;
    cout << "  • Parameter cannot be null" << endl;
    cout << "  • You want to modify the caller's variable" << endl;
    cout << "  • For efficiency (avoid copying)" << endl;
    cout << "  • For output parameters" << endl;
    cout << endl;
    cout << "Use POINTERS when:" << endl;
    cout << "  • Parameter can be null/optional" << endl;
    cout << "  • Working with arrays/C-strings" << endl;
    cout << "  • Need to track ownership" << endl;
    cout << "  • Dynamic memory management" << endl;

    return 0;
}