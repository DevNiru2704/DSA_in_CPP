#include <iostream>
using namespace std;

// Drill 4: Memory Leaks
void memory_leak_demo()
{
    cout << "Drill 4: Memory Leaks" << endl;
    cout << "This will leak memory (don't run for long!)" << endl;

    int count = 0;
    while (count < 10)
    { // Limited to prevent actual damage
        int *leak = new int(5);
        // No delete - memory leak!
        cout << "Leaked: " << *leak << endl;
        count++;
    }

    cout << "Memory leaked: " << (count * sizeof(int)) << " bytes" << endl;
}

void proper_memory_management()
{
    cout << "\nProper memory management:" << endl;

    int *proper = new int(10);
    cout << "Value: " << *proper << endl;
    delete proper; // Proper cleanup
    cout << "Memory freed" << endl;
}

int main()
{
    memory_leak_demo();
    proper_memory_management();
    return 0;
}