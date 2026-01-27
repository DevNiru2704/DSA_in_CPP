#include <iostream>
using namespace std;

// Drill 2: Object Lifetime (Scope vs Lifetime)
void demonstrate_lifetime()
{
    cout << "Drill 2: Object Lifetime" << endl;

    // Stack variable - dies at end of scope
    {
        int stack_var = 5;
        cout << "Stack variable: " << stack_var << endl;
    }
    // stack_var is gone here

    // Heap variable - lives until deleted
    int *heap_var = new int(42);
    cout << "Heap variable: " << *heap_var << endl;
    // heap_var lives beyond this scope until we call delete
    delete heap_var;
}

void dangling_scope_demo()
{
    cout << "\nDrill 2: Dangling pointer from scope" << endl;
    int *ptr;
    {
        int local_var = 7;
        ptr = &local_var;
        cout << "Inside scope: " << *ptr << endl;
    }
    // local_var is dead, ptr is dangling
    cout << "Outside scope: " << *ptr << endl; // Undefined behavior!
}

int main()
{
    demonstrate_lifetime();
    dangling_scope_demo();
    return 0;
}