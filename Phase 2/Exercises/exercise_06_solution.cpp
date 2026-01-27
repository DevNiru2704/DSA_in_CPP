#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;

// Exercise 6: Memory Leak Detector
// Solution: Creates intentional leaks, demonstrates effects, then fixes them

class MemoryTracker
{
private:
    vector<void *> allocations;
    size_t totalBytes;

public:
    MemoryTracker() : totalBytes(0) {}

    void *trackAllocation(size_t size)
    {
        void *ptr = malloc(size);
        if (ptr)
        {
            allocations.push_back(ptr);
            totalBytes += size;
            cout << "Allocated " << size << " bytes at " << ptr << endl;
        }
        return ptr;
    }

    void trackDeallocation(void *ptr, size_t size)
    {
        auto it = find(allocations.begin(), allocations.end(), ptr);
        if (it != allocations.end())
        {
            allocations.erase(it);
            totalBytes -= size;
            free(ptr);
            cout << "Deallocated " << size << " bytes from " << ptr << endl;
        }
    }

    void report()
    {
        cout << "\n=== Memory Report ===" << endl;
        cout << "Active allocations: " << allocations.size() << endl;
        cout << "Total bytes allocated: " << totalBytes << endl;
        if (!allocations.empty())
        {
            cout << "LEAK DETECTED! " << allocations.size() << " unfreed allocations" << endl;
        }
        else
        {
            cout << "No memory leaks detected!" << endl;
        }
    }

    ~MemoryTracker()
    {
        for (void *ptr : allocations)
        {
            free(ptr);
        }
        cout << "MemoryTracker cleanup: freed " << allocations.size() << " remaining allocations" << endl;
    }
};

void createLeaks(int count)
{
    cout << "=== Creating " << count << " Memory Leaks ===" << endl;

    for (int i = 0; i < count; i++)
    {
        int *leak = new int[100]; // 400 bytes each (assuming 4-byte ints)
        for (int j = 0; j < 100; j++)
        {
            leak[j] = i * 100 + j;
        }
        cout << "Created leak " << i + 1 << " at " << leak << endl;
        // Intentionally no delete - this leaks memory!
    }

    cout << "Created " << count << " leaks of 400 bytes each = " << (count * 400) << " bytes leaked!" << endl;
}

void demonstrateMemoryPressure()
{
    cout << "\n=== Demonstrating Memory Pressure ===" << endl;

    vector<int *> allocations;

    // Allocate memory in a loop
    for (int i = 0; i < 100; i++)
    {
        int *block = new int[1000]; // 4KB each
        allocations.push_back(block);

        if (i % 20 == 0)
        {
            cout << "Allocated " << (i + 1) << " blocks (" << ((i + 1) * 4000) << " bytes)" << endl;
            this_thread::sleep_for(chrono::milliseconds(100)); // Small delay
        }
    }

    cout << "Holding " << allocations.size() << " allocations..." << endl;
    this_thread::sleep_for(chrono::seconds(1));

    // Now free them properly
    cout << "Freeing all allocations..." << endl;
    for (int *ptr : allocations)
    {
        delete[] ptr;
    }
    allocations.clear();

    cout << "All memory freed!" << endl;
}

void properMemoryManagement()
{
    cout << "\n=== Proper Memory Management Demo ===" << endl;

    MemoryTracker tracker;

    // Allocate some memory
    int *ptr1 = (int *)tracker.trackAllocation(sizeof(int) * 10);
    double *ptr2 = (double *)tracker.trackAllocation(sizeof(double) * 5);
    char *ptr3 = (char *)tracker.trackAllocation(sizeof(char) * 20);

    // Use the memory
    for (int i = 0; i < 10; i++)
        ptr1[i] = i;
    for (int i = 0; i < 5; i++)
        ptr2[i] = i * 1.5;
    strcpy(ptr3, "Hello, Memory!");

    cout << "Memory in use..." << endl;
    tracker.report();

    // Free some memory
    tracker.trackDeallocation(ptr2, sizeof(double) * 5);
    tracker.trackDeallocation(ptr1, sizeof(int) * 10);

    cout << "After freeing some allocations..." << endl;
    tracker.report();

    // ptr3 is intentionally leaked to demonstrate tracking
    cout << "\nNote: ptr3 was not freed - it will be cleaned up by MemoryTracker destructor" << endl;
}

int main()
{
    cout << "=== Exercise 6: Memory Leak Detector ===\n"
         << endl;

    // Part 1: Create intentional leaks
    createLeaks(5);

    cout << "\nMemory leaked! In a real program, this would accumulate over time." << endl;
    cout << "Long-running programs (servers, games) would eventually crash." << endl;

    // Part 2: Memory pressure demonstration
    demonstrateMemoryPressure();

    // Part 3: Proper memory management with tracking
    properMemoryManagement();

    cout << "\n=== Key Takeaways ===" << endl;
    cout << "• Every new/delete must be balanced" << endl;
    cout << "• Memory leaks accumulate over time" << endl;
    cout << "• Use RAII and smart pointers when possible" << endl;
    cout << "• Track allocations in complex programs" << endl;

    return 0;
}