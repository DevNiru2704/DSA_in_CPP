#include <iostream>
using namespace std;

// Exercise 2: Dangling Pointer Hunter
// Solution: Fixed version of the buggy code with proper memory management

int *getPointer1()
{
    // Fixed: Return heap-allocated memory instead of stack
    int *ptr = new int(42);
    return ptr;
}

int *getPointer2()
{
    int *ptr = new int(100);
    return ptr; // Now properly returns the allocated memory
}

void processArray(const int *arr, int size)
{
    // Made arr const to prevent modification
    cout << "Processing array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "=== Exercise 2: Dangling Pointer Hunter ===\n"
         << endl;

    // Case 1: Now returns heap memory (safe)
    cout << "1. Heap-allocated pointer:" << endl;
    int *p1 = getPointer1();
    cout << "p1 points to: " << *p1 << endl;
    delete p1; // Clean up
    cout << "p1 cleaned up." << endl;
    cout << endl;

    // Case 2: Now properly returns allocated memory
    cout << "2. Another heap pointer:" << endl;
    int *p2 = getPointer2();
    cout << "p2 points to: " << *p2 << endl;
    delete p2; // Clean up
    cout << "p2 cleaned up." << endl;
    cout << endl;

    // Case 3: Array processing (now safe with const)
    cout << "3. Array processing:" << endl;
    int arr[] = {1, 2, 3, 4, 5};
    processArray(arr, 5);

    cout << "\nAll memory properly managed - no leaks or dangling pointers!" << endl;

    return 0;
}