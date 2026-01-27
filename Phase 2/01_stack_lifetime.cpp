#include <iostream>
using namespace std;

// Drill 1: Stack Lifetime (Dangling Pointer)
int *dangling_pointer()
{
    int x = 10;
    return &x; // DANGER: returning address of local variable
}

int main()
{
    cout << "Drill 1: Stack Lifetime" << endl;
    cout << "This demonstrates a dangling pointer:" << endl;

    int *ptr = dangling_pointer();
    cout << "Value: " << *ptr << endl; // Undefined behavior!

    return 0;
}