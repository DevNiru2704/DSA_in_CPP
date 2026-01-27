#include <iostream>
using namespace std;

// Drill 5: Pointers vs References
void modify_with_pointer(int *ptr)
{
    if (ptr)
    {
        *ptr = 100;
    }
}

void modify_with_reference(int &ref)
{
    ref = 200; // Always safe, can't be null
}

void demonstrate_pointers_vs_references()
{
    cout << "Drill 5: Pointers vs References" << endl;

    int x = 10;
    int y = 20;

    cout << "Original values: x=" << x << ", y=" << y << endl;

    // Pointer version - can be null, explicit dereference
    int *ptr = &x;
    modify_with_pointer(ptr);
    cout << "After pointer modification: x=" << x << endl;

    // Reference version - always valid, no dereference needed
    int &ref = y;
    modify_with_reference(ref);
    cout << "After reference modification: y=" << y << endl;

    // Pointer can be reassigned
    ptr = &y;
    *ptr = 300;
    cout << "Pointer reassigned: y=" << y << endl;

    // Reference cannot be reseated
    // ref = x;  // This would change y, not rebind ref
}

int main()
{
    demonstrate_pointers_vs_references();
    return 0;
}