#include <iostream>
#include <vector>
using namespace std;

// Exercise 10: The Ultimate Bug Hunt
// Solution: Fixed version of the complex buggy program

class DataHolder
{
private:
    int *data;
    int size;

public:
    DataHolder(int s) : data(nullptr), size(s)
    {
        if (size > 0)
        {
            data = new int[size];
            for (int i = 0; i < size; i++)
            {
                data[i] = i * 10;
            }
        }
    }

    // Proper copy constructor
    DataHolder(const DataHolder &other) : data(nullptr), size(other.size)
    {
        if (size > 0)
        {
            data = new int[size];
            for (int i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }
    }

    // Proper assignment operator
    DataHolder &operator=(const DataHolder &other)
    {
        if (this != &other)
        {
            delete[] data; // Clean up existing data

            size = other.size;
            data = nullptr;
            if (size > 0)
            {
                data = new int[size];
                for (int i = 0; i < size; i++)
                {
                    data[i] = other.data[i];
                }
            }
        }
        return *this;
    }

    ~DataHolder()
    {
        delete[] data;
        cout << "DataHolder destroyed, memory freed" << endl;
    }

    void print() const
    {
        cout << "Data: ";
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    int getSize() const { return size; }
};

// Fixed: Return by value, not reference
DataHolder createHolder()
{
    DataHolder holder(5);
    cout << "Created holder with data: ";
    holder.print();
    return holder; // Returns a copy - safe!
}

void processData(const DataHolder &holder)
{
    cout << "Processing data: ";
    holder.print();
}

int main()
{
    cout << "=== Exercise 10: The Ultimate Bug Hunt (FIXED) ===\n"
         << endl;

    // Bug 1: FIXED - No more dangling pointer
    cout << "1. Safe holder creation and processing:" << endl;
    DataHolder h1 = createHolder(); // Copy returned value
    processData(h1);                // Safe to use
    cout << "Holder h1 is still valid after function call" << endl;
    h1.print();
    cout << endl;

    // Bug 2: FIXED - No double deletion
    cout << "2. Safe single allocation/deallocation:" << endl;
    int *arr = new int[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i * 2;
    }
    cout << "Array contents: ";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr; // Single deletion
    cout << "Array safely deleted" << endl;
    cout << endl;

    // Bug 3: FIXED - Proper memory management
    cout << "3. Proper vector usage with RAII:" << endl;
    vector<DataHolder> holders;
    for (int i = 0; i < 5; i++)
    {
        holders.emplace_back(i + 1); // Create in-place
        cout << "Created holder " << i + 1 << " with size " << holders.back().getSize() << endl;
    }

    cout << "Processing all holders:" << endl;
    for (const auto &holder : holders)
    {
        holder.print();
    }

    // No manual cleanup needed - vector handles it automatically
    cout << "Vector going out of scope - automatic cleanup" << endl;

    cout << "\n=== All Bugs Fixed! ===" << endl;
    cout << "✓ No dangling pointers" << endl;
    cout << "✓ No double deletions" << endl;
    cout << "✓ No memory leaks" << endl;
    cout << "✓ RAII principles applied" << endl;
    cout << "✓ Proper copy semantics" << endl;

    cout << "\n=== Key Lessons ===" << endl;
    cout << "• Never return references/pointers to local variables" << endl;
    cout << "• Use RAII (Resource Acquisition Is Initialization)" << endl;
    cout << "• STL containers handle memory management for you" << endl;
    cout << "• Implement proper copy constructors and assignment operators" << endl;
    cout << "• Prefer value semantics over reference semantics when possible" << endl;
    cout << "• Use smart pointers for dynamic memory when manual management is needed" << endl;

    return 0;
}