#include <iostream>
using namespace std;

void f(int x) // call by value
{
    x++;
    cout << "Call by value" << endl;
}

// void f(const int &x) // call by reference CPP default
// {
//     x++;
//     cout << "Call by reference" << endl;
// }

void f(int *x) // call by pointers
{
    (*x)++;
    cout << "Call by pointer" << endl;
}

int main()
{
    int x = 5;
    int *y = &x;
    f(5);
    cout << x << endl;
    // int &r = x;
    // f(r);
    cout << x << endl;
    f(&x);
    cout << x << endl;
}

/*
Why f(r) is ambiguous when f(int) and f(int&) are both present
--------------------------------------------------------------

Key idea:
Overload resolution depends on the *type and value category of the expression*,
not on how the variable was declared.

Given:
    int x = 5;
    int& r = x;

Important fact:
- Although r is declared as a reference, in an expression r is just an
  lvalue of type int.
- References do not exist as separate entities at the call site.

Overload candidates for f(r):

1) void f(int)
   - An int lvalue can be copied into an int
   - Viable (exact match)

2) void f(int&)
   - An int lvalue can bind directly to int&
   - Viable (exact match)

3) void f(int*)
   - int is not convertible to int*
   - Not viable

Result:
Both f(int) and f(int&) are equally good matches.
The C++ standard gives no preference between them.

Therefore:
The call f(r) is ambiguous and compilation fails.

Why f(5) works:
- 5 is a temporary (rvalue)
- Non-const int& cannot bind to temporaries
- Only f(int) is viable

Why f(&x) works:
- &x has type int*
- Only f(int*) matches

Conclusion:
Overloading functions on T vs T& is dangerous.
Avoid it in real code unless you fully understand overload resolution.
Prefer clear, unambiguous function signatures.
*/
