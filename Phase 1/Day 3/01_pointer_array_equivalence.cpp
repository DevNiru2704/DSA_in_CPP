#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[3] = {10, 20, 30};

    // Array name is a pointer to first element
    cout << "Address of array: " << a << endl;
    cout << "Address of a[0]: " << &a[0] << endl;

    // Pointer arithmetic equivalence
    cout << "a[1] = " << a[1] << endl;
    cout << "*(a + 1) = " << *(a + 1) << endl;

    // Both access the same memory
    cout << "a[2] = " << a[2] << endl;
    cout << "*(a + 2) = " << *(a + 2) << endl;

    return 0;
}
