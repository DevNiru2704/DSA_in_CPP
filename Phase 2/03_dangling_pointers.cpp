#include <iostream>
using namespace std;

// Drill 3: Dangling Pointers
void demonstrate_dangling()
{
    cout << "Drill 3: Dangling Pointers" << endl;

    // Case 1: Delete but keep pointer
    int *p1 = new int(42);
    cout << "Before delete: " << *p1 << endl;
    delete p1;
    // p1 is now dangling - points to freed memory
    cout << "After delete: " << *p1 << endl; // Undefined behavior!

    // Case 2: Function returning local address
    int *p2 = nullptr;
    {
        int local = 100;
        p2 = &local;
    }
    cout << "Dangling from scope: " << *p2 << endl; // Undefined behavior!
}

int main()
{
    demonstrate_dangling();
    return 0;
}