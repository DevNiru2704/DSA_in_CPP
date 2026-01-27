#include <iostream>
using namespace std;

// Exercise 1: Stack vs Heap Lifetime
// Solution: Demonstrates the difference between stack and heap variable lifetimes

int *returnStackPointer()
{
    int stackVar = 42;
    cout << "Stack variable created: " << stackVar << endl;
    return &stackVar; // DANGER: returning address of stack variable
}

int *returnHeapPointer()
{
    int *heapVar = new int(42);
    cout << "Heap variable created: " << *heapVar << endl;
    return heapVar; // SAFE: heap variable persists after function returns
}

int main()
{
    cout << "=== Exercise 1: Stack vs Heap Lifetime ===\n"
         << endl;

    // Test stack pointer (dangerous)
    cout << "1. Testing stack pointer:" << endl;
    int *stackPtr = returnStackPointer();
    cout << "Trying to access stack pointer after function returned..." << endl;
    // This causes undefined behavior - stackPtr is dangling!
    cout << "Value: " << *stackPtr << " (UNDEFINED BEHAVIOR!)" << endl;
    cout << endl;

    // Test heap pointer (safe)
    cout << "2. Testing heap pointer:" << endl;
    int *heapPtr = returnHeapPointer();
    cout << "Accessing heap pointer after function returned..." << endl;
    cout << "Value: " << *heapPtr << " (SAFE - heap memory persists)" << endl;

    // Clean up heap memory
    delete heapPtr;
    cout << "Heap memory cleaned up." << endl;

    cout << "\nKey Difference:" << endl;
    cout << "- Stack variables die when function exits" << endl;
    cout << "- Heap variables live until explicitly deleted" << endl;

    return 0;
}