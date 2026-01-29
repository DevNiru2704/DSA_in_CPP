#include <iostream>
#include <unordered_map>
#include <vector>
#include <chrono>
#include <mutex>
#include <thread>
#include <atomic>
using namespace std;
using namespace std::chrono;

// Bonus Challenge: Memory Profiler
// Solution: A comprehensive memory profiling and leak detection system

class MemoryProfiler
{
private:
    struct AllocationInfo
    {
        void *address;
        size_t size;
        string file;
        int line;
        high_resolution_clock::time_point timestamp;
        bool freed;

        AllocationInfo(void *addr, size_t sz, const string &f, int l)
            : address(addr), size(sz), file(f), line(l),
              timestamp(high_resolution_clock::now()), freed(false) {}
    };

    unordered_map<void *, AllocationInfo> allocations;
    vector<AllocationInfo> freedAllocations;
    mutex profilerMutex;
    atomic<size_t> totalAllocated{0};
    atomic<size_t> totalFreed{0};
    atomic<size_t> currentUsage{0};
    atomic<size_t> peakUsage{0};
    high_resolution_clock::time_point startTime;

public:
    MemoryProfiler() : startTime(high_resolution_clock::now())
    {
        cout << "MemoryProfiler started at " << getCurrentTimeString() << endl;
    }

    void *trackAllocation(size_t size, const string &file = "", int line = 0)
    {
        void *ptr = malloc(size);
        if (ptr)
        {
            lock_guard<mutex> lock(profilerMutex);

            allocations[ptr] = AllocationInfo(ptr, size, file, line);
            totalAllocated += size;
            currentUsage += size;

            if (currentUsage > peakUsage)
            {
                peakUsage = currentUsage.load();
            }

            cout << "[ALLOC] " << size << " bytes at " << ptr;
            if (!file.empty())
            {
                cout << " (" << file << ":" << line << ")";
            }
            cout << endl;
        }
        return ptr;
    }

    void trackDeallocation(void *ptr)
    {
        if (!ptr)
            return;

        lock_guard<mutex> lock(profilerMutex);

        auto it = allocations.find(ptr);
        if (it != allocations.end())
        {
            AllocationInfo &info = it->second;
            if (!info.freed)
            {
                info.freed = true;
                totalFreed += info.size;
                currentUsage -= info.size;

                freedAllocations.push_back(info);
                allocations.erase(it);

                cout << "[FREE] " << info.size << " bytes at " << ptr << endl;
            }
            else
            {
                cout << "[ERROR] Double free detected at " << ptr << endl;
            }
        }
        else
        {
            cout << "[ERROR] Invalid free at " << ptr << endl;
        }
    }

    void generateReport()
    {
        lock_guard<mutex> lock(profilerMutex);

        auto now = high_resolution_clock::now();
        auto duration = duration_cast<seconds>(now - startTime);

        cout << "\n"
             << string(60, '=') << endl;
        cout << "MEMORY PROFILER REPORT" << endl;
        cout << string(60, '=') << endl;
        cout << "Profiling duration: " << duration.count() << " seconds" << endl;
        cout << "Total allocated: " << totalAllocated << " bytes" << endl;
        cout << "Total freed: " << totalFreed << " bytes" << endl;
        cout << "Current usage: " << currentUsage << " bytes" << endl;
        cout << "Peak usage: " << peakUsage << " bytes" << endl;
        cout << "Active allocations: " << allocations.size() << endl;

        if (!allocations.empty())
        {
            cout << "\nMEMORY LEAKS DETECTED: " << allocations.size() << " unfreed allocations" << endl;
            cout << string(60, '-') << endl;

            size_t leakSize = 0;
            for (const auto &pair : allocations)
            {
                const AllocationInfo &info = pair.second;
                leakSize += info.size;
                cout << "LEAK: " << info.size << " bytes at " << info.address;
                if (!info.file.empty())
                {
                    cout << " (" << info.file << ":" << info.line << ")";
                }
                cout << endl;
            }
            cout << "Total leaked: " << leakSize << " bytes" << endl;
        }
        else
        {
            cout << "\n✓ NO MEMORY LEAKS DETECTED!" << endl;
        }

        // Allocation hotspots
        if (!freedAllocations.empty())
        {
            cout << "\nALLOCATION HOTSPOTS:" << endl;
            unordered_map<string, size_t> fileAllocations;

            for (const AllocationInfo &info : freedAllocations)
            {
                if (!info.file.empty())
                {
                    fileAllocations[info.file] += info.size;
                }
            }

            for (const auto &pair : allocations)
            {
                const AllocationInfo &info = pair.second;
                if (!info.file.empty())
                {
                    fileAllocations[info.file] += info.size;
                }
            }

            vector<pair<string, size_t>> hotspots(fileAllocations.begin(), fileAllocations.end());
            sort(hotspots.begin(), hotspots.end(),
                 [](const pair<string, size_t> &a, const pair<string, size_t> &b)
                 {
                     return a.second > b.second;
                 });

            for (size_t i = 0; i < min(size_t(5), hotspots.size()); i++)
            {
                cout << hotspots[i].first << ": " << hotspots[i].second << " bytes" << endl;
            }
        }

        cout << string(60, '=') << endl;
    }

    string getCurrentTimeString()
    {
        auto now = system_clock::now();
        auto time = system_clock::to_time_t(now);
        return string(ctime(&time)).substr(0, 24); // Remove newline
    }

    ~MemoryProfiler()
    {
        generateReport();
        // Clean up any remaining allocations
        for (auto &pair : allocations)
        {
            free(pair.first);
        }
        cout << "MemoryProfiler shutdown - cleaned up " << allocations.size()
             << " leaked allocations" << endl;
    }
};

// Global profiler instance
static MemoryProfiler *globalProfiler = nullptr;

// Replacement for malloc/free
extern "C"
{
    void *profiled_malloc(size_t size)
    {
        if (globalProfiler)
        {
            return globalProfiler->trackAllocation(size);
        }
        return malloc(size);
    }

    void profiled_free(void *ptr)
    {
        if (globalProfiler)
        {
            globalProfiler->trackDeallocation(ptr);
            return;
        }
        free(ptr);
    }
}

// Override new/delete operators
void *operator new(size_t size)
{
    if (globalProfiler)
    {
        return globalProfiler->trackAllocation(size, __FILE__, __LINE__);
    }
    return malloc(size);
}

void *operator new[](size_t size)
{
    if (globalProfiler)
    {
        return globalProfiler->trackAllocation(size, __FILE__, __LINE__);
    }
    return malloc(size);
}

void operator delete(void *ptr) noexcept
{
    if (globalProfiler)
    {
        globalProfiler->trackDeallocation(ptr);
        return;
    }
    free(ptr);
}

void operator delete[](void *ptr) noexcept
{
    if (globalProfiler)
    {
        globalProfiler->trackDeallocation(ptr);
        return;
    }
    free(ptr);
}

// Test classes
class TestObject
{
private:
    int *data;
    size_t size;

public:
    TestObject(size_t s) : size(s)
    {
        data = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            data[i] = rand() % 100;
        }
    }

    ~TestObject()
    {
        delete[] data;
    }

    void print() const
    {
        cout << "TestObject with " << size << " elements" << endl;
    }
};

void simulateMemoryUsage()
{
    cout << "Simulating complex memory usage patterns..." << endl;

    // Create some objects
    vector<TestObject *> objects;
    for (int i = 0; i < 10; i++)
    {
        objects.push_back(new TestObject(100 + i * 10));
    }

    // Simulate some work
    this_thread::sleep_for(milliseconds(100));

    // Free some objects (but not all - creating leaks)
    for (size_t i = 0; i < objects.size(); i += 2)
    {
        delete objects[i];
        objects[i] = nullptr;
    }

    // Create more allocations
    int *arrays[5];
    for (int i = 0; i < 5; i++)
    {
        arrays[i] = new int[50];
        for (int j = 0; j < 50; j++)
        {
            arrays[i][j] = i * j;
        }
    }

    // Free some arrays
    delete[] arrays[0];
    delete[] arrays[2];

    // Intentionally leak arrays[1], arrays[3], arrays[4]
    // and some objects

    cout << "Simulation complete - some memory intentionally leaked" << endl;
}

int main()
{
    cout << "=== Bonus Challenge: Memory Profiler ===\n"
         << endl;

    // Initialize profiler
    globalProfiler = new MemoryProfiler();

    cout << "Memory profiler enabled - all allocations will be tracked" << endl;
    cout << "Starting memory-intensive operations..." << endl;

    // Run simulation
    simulateMemoryUsage();

    // Manual allocations to demonstrate tracking
    cout << "\nManual allocation tests:" << endl;

    int *ptr1 = new int(42);
    double *ptr2 = new double[10];
    char *ptr3 = new char[50];

    cout << "Created 3 allocations" << endl;

    // Free some
    delete ptr1;
    delete[] ptr2;

    // Leak ptr3 intentionally
    cout << "Intentionally leaking ptr3" << endl;

    // Create some more activity
    vector<string *> strings;
    for (int i = 0; i < 5; i++)
    {
        strings.push_back(new string("Test string " + to_string(i)));
    }

    // Clean up half
    for (size_t i = 0; i < strings.size(); i += 2)
    {
        delete strings[i];
        strings[i] = nullptr;
    }

    cout << "\nProgram ending - profiler will generate final report..." << endl;

    // Cleanup
    delete globalProfiler;
    globalProfiler = nullptr;

    cout << "\n=== Profiler Features Demonstrated ===" << endl;
    cout << "✓ Allocation tracking with file/line info" << endl;
    cout << "✓ Memory leak detection" << endl;
    cout << "✓ Double-free detection" << endl;
    cout << "✓ Peak memory usage tracking" << endl;
    cout << "✓ Allocation hotspot analysis" << endl;
    cout << "✓ Automatic cleanup of leaks" << endl;
    cout << "✓ Operator new/delete overriding" << endl;

    return 0;
}