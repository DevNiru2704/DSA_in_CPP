#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Exercise 9: Custom Memory Manager
// Solution: Implements a simple memory pool for fixed-size allocations

class MemoryPool
{
private:
    vector<void *> freeBlocks;
    vector<void *> allocatedBlocks;
    size_t blockSize;
    size_t poolSize;
    char *poolMemory;

public:
    MemoryPool(size_t blockSize, size_t poolSize = 1024)
        : blockSize(blockSize), poolSize(poolSize)
    {

        // Allocate one large contiguous block
        poolMemory = new char[blockSize * poolSize];

        // Initialize free list
        freeBlocks.reserve(poolSize);
        for (size_t i = 0; i < poolSize; i++)
        {
            freeBlocks.push_back(poolMemory + i * blockSize);
        }

        cout << "MemoryPool created: " << poolSize << " blocks of "
             << blockSize << " bytes each" << endl;
        cout << "Total memory: " << (blockSize * poolSize) << " bytes" << endl;
    }

    void *allocate()
    {
        if (freeBlocks.empty())
        {
            throw runtime_error("Memory pool exhausted!");
        }

        void *block = freeBlocks.back();
        freeBlocks.pop_back();
        allocatedBlocks.push_back(block);

        cout << "Allocated block at " << block << endl;
        return block;
    }

    void deallocate(void *ptr)
    {
        // Validate pointer is from this pool
        if (ptr < poolMemory || ptr >= poolMemory + blockSize * poolSize)
        {
            throw runtime_error("Pointer not from this memory pool!");
        }

        // Check if it's aligned to block boundaries
        size_t offset = (char *)ptr - poolMemory;
        if (offset % blockSize != 0)
        {
            throw runtime_error("Invalid block alignment!");
        }

        // Find and remove from allocated list
        auto it = find(allocatedBlocks.begin(), allocatedBlocks.end(), ptr);
        if (it == allocatedBlocks.end())
        {
            throw runtime_error("Block not currently allocated!");
        }

        allocatedBlocks.erase(it);
        freeBlocks.push_back(ptr);

        cout << "Deallocated block at " << ptr << endl;
    }

    void report()
    {
        cout << "\n=== Memory Pool Status ===" << endl;
        cout << "Block size: " << blockSize << " bytes" << endl;
        cout << "Total blocks: " << poolSize << endl;
        cout << "Free blocks: " << freeBlocks.size() << endl;
        cout << "Allocated blocks: " << allocatedBlocks.size() << endl;
        cout << "Memory utilization: "
             << (allocatedBlocks.size() * 100.0 / poolSize) << "%" << endl;
    }

    ~MemoryPool()
    {
        delete[] poolMemory;
        cout << "MemoryPool destroyed - all memory freed" << endl;
    }
};

// Comparison class for standard new/delete
class StandardAllocator
{
private:
    vector<void *> allocatedBlocks;
    size_t totalAllocated;

public:
    StandardAllocator() : totalAllocated(0) {}

    void *allocate(size_t size)
    {
        void *ptr = new char[size];
        allocatedBlocks.push_back(ptr);
        totalAllocated += size;
        cout << "Standard alloc: " << size << " bytes at " << ptr << endl;
        return ptr;
    }

    void deallocate(void *ptr)
    {
        auto it = find(allocatedBlocks.begin(), allocatedBlocks.end(), ptr);
        if (it != allocatedBlocks.end())
        {
            allocatedBlocks.erase(it);
            delete[] (char *)ptr;
            cout << "Standard dealloc: " << ptr << endl;
        }
    }

    void report()
    {
        cout << "\n=== Standard Allocator Status ===" << endl;
        cout << "Allocated blocks: " << allocatedBlocks.size() << endl;
        cout << "Total memory: " << totalAllocated << " bytes" << endl;
    }

    ~StandardAllocator()
    {
        for (void *ptr : allocatedBlocks)
        {
            delete[] (char *)ptr;
        }
        cout << "StandardAllocator cleanup: freed " << allocatedBlocks.size()
             << " remaining allocations" << endl;
    }
};

void performanceTest()
{
    cout << "\n=== Performance Comparison ===\n"
         << endl;

    const int ALLOCATIONS = 10000;
    const int BLOCK_SIZE = 64;

    // Test Memory Pool
    MemoryPool pool(BLOCK_SIZE, ALLOCATIONS);
    vector<void *> poolPtrs;

    auto start = high_resolution_clock::now();
    for (int i = 0; i < ALLOCATIONS; i++)
    {
        poolPtrs.push_back(pool.allocate());
    }
    auto poolAllocTime = duration_cast<microseconds>(high_resolution_clock::now() - start);

    start = high_resolution_clock::now();
    for (void *ptr : poolPtrs)
    {
        pool.deallocate(ptr);
    }
    auto poolDeallocTime = duration_cast<microseconds>(high_resolution_clock::now() - start);

    // Test Standard Allocator
    StandardAllocator stdAlloc;
    vector<void *> stdPtrs;

    start = high_resolution_clock::now();
    for (int i = 0; i < ALLOCATIONS; i++)
    {
        stdPtrs.push_back(stdAlloc.allocate(BLOCK_SIZE));
    }
    auto stdAllocTime = duration_cast<microseconds>(high_resolution_clock::now() - start);

    start = high_resolution_clock::now();
    for (void *ptr : stdPtrs)
    {
        stdAlloc.deallocate(ptr);
    }
    auto stdDeallocTime = duration_cast<microseconds>(high_resolution_clock::now() - start);

    cout << "Memory Pool allocation: " << poolAllocTime.count() << " microseconds" << endl;
    cout << "Standard allocation: " << stdAllocTime.count() << " microseconds" << endl;
    cout << "Pool is " << (double)stdAllocTime.count() / poolAllocTime.count()
         << "x faster for allocation" << endl;

    cout << "Memory Pool deallocation: " << poolDeallocTime.count() << " microseconds" << endl;
    cout << "Standard deallocation: " << stdDeallocTime.count() << " microseconds" << endl;
    cout << "Pool is " << (double)stdDeallocTime.count() / poolDeallocTime.count()
         << "x faster for deallocation" << endl;
}

int main()
{
    cout << "=== Exercise 9: Custom Memory Manager ===\n"
         << endl;

    // Demonstrate memory pool
    MemoryPool pool(sizeof(int), 10); // Pool of 10 integers

    // Allocate some blocks
    vector<int *> ints;
    for (int i = 0; i < 5; i++)
    {
        int *ptr = (int *)pool.allocate();
        *ptr = i * 10;
        ints.push_back(ptr);
    }

    pool.report();

    // Use the allocated memory
    cout << "\nAllocated integers: ";
    for (int *ptr : ints)
    {
        cout << *ptr << " ";
    }
    cout << endl;

    // Deallocate some
    for (int i = 0; i < 3; i++)
    {
        pool.deallocate(ints[i]);
    }
    ints.erase(ints.begin(), ints.begin() + 3);

    pool.report();

    // Allocate more
    for (int i = 0; i < 3; i++)
    {
        int *ptr = (int *)pool.allocate();
        *ptr = 100 + i;
        ints.push_back(ptr);
    }

    cout << "\nFinal allocated integers: ";
    for (int *ptr : ints)
    {
        cout << *ptr << " ";
    }
    cout << endl;

    pool.report();

    // Clean up remaining allocations
    for (int *ptr : ints)
    {
        pool.deallocate(ptr);
    }

    // Performance comparison
    performanceTest();

    cout << "\n=== Key Benefits of Memory Pools ===" << endl;
    cout << "• Constant-time allocation/deallocation" << endl;
    cout << "• No fragmentation within pool" << endl;
    cout << "• Reduced system call overhead" << endl;
    cout << "• Predictable performance" << endl;
    cout << "• Memory locality (cache-friendly)" << endl;
    cout << "• Leak detection capabilities" << endl;

    return 0;
}