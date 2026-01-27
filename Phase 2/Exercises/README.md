# Phase 2 Exercises — Memory, Pointers, and Reality

## Exercise Guidelines

- **Compile and run** each exercise
- **Predict the output** before running
- **Explain any crashes** or unexpected behavior
- **Fix the bugs** where indicated
- **Write your solutions** in separate `.cpp` files
- **Test thoroughly** with different inputs

## Exercise 1: Stack vs Heap Lifetime

**Problem**: Create a program that demonstrates the difference between stack and heap variable lifetimes.

**Requirements**:
- Create a function that returns a pointer to a stack variable
- Create another function that returns a pointer to a heap variable
- Show what happens when you try to use both pointers after the functions return
- Explain the difference in behavior

**Expected Output**: One should crash/undefined behavior, the other should work.

---

## Exercise 2: Dangling Pointer Hunter

**Problem**: Find and fix all dangling pointers in the following code:

```cpp
#include <iostream>
using namespace std;

int* getPointer1() {
    int x = 42;
    return &x;
}

int* getPointer2() {
    int* ptr = new int(100);
    return ptr;
    // Oops, forgot something...
}

void processArray(int* arr, int size) {
    // Process array elements
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Case 1: Stack variable
    int* p1 = getPointer1();
    cout << "p1 points to: " << *p1 << endl;

    // Case 2: Heap variable
    int* p2 = getPointer2();
    cout << "p2 points to: " << *p2 << endl;

    // Case 3: Array processing
    int arr[] = {1, 2, 3, 4, 5};
    processArray(arr, 5);

    return 0;
}
```

**Tasks**:
1. Identify all dangling pointers
2. Fix the memory leaks
3. Ensure all pointers are properly managed
4. Test with valgrind or similar memory checker if available

---

## Exercise 3: Pointer Arithmetic Mastery

**Problem**: Write a program that demonstrates pointer arithmetic with arrays.

**Requirements**:
- Create an array of integers
- Use pointer arithmetic to traverse the array (no `[]` operator)
- Print the array in forward and reverse order using pointers
- Show the memory addresses and differences between consecutive elements
- Demonstrate what happens when you go out of bounds

**Bonus**: Implement your own version of `strlen()` using pointer arithmetic.

---

## Exercise 4: 2D Array Memory Layout

**Problem**: Prove that 2D arrays are contiguous in memory.

**Requirements**:
- Create a 2D array (e.g., `int arr[3][4]`)
- Print the memory addresses of all elements
- Show that elements are stored row by row
- Demonstrate pointer arithmetic to access elements
- Compare with a dynamically allocated "2D array" using `int**`

**Expected Insight**: Real 2D arrays are contiguous, `int**` arrays are not.

---

## Exercise 5: Function Parameter Bug Hunt

**Problem**: The following code has a critical bug. Find and fix it:

```cpp
#include <iostream>
using namespace std;

void printMatrix(int** matrix, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int realMatrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    printMatrix(realMatrix, 3, 4);  // This will fail!

    return 0;
}
```

**Tasks**:
1. Explain why this code fails to compile or crashes
2. Fix it using the correct method for passing 2D arrays
3. Implement all three methods discussed in the theory
4. Compare their performance and memory usage

---

## Exercise 6: Memory Leak Detector

**Problem**: Write a program that intentionally creates memory leaks and then fix them.

**Requirements**:
- Create functions that allocate memory but don't free it
- Use loops to create multiple leaks
- Demonstrate the effect on system resources
- Implement proper cleanup
- Add memory tracking to verify leaks are fixed

**Tools to use**: Consider using `ps` command or system monitors to observe memory usage.

---

## Exercise 7: Pointer vs Reference Challenge

**Problem**: Rewrite functions to use references instead of pointers where appropriate.

**Original Code**:
```cpp
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* findMax(int* arr, int size) {
    if(size == 0) return nullptr;
    int* maxPtr = arr;
    for(int i = 1; i < size; i++) {
        if(arr[i] > *maxPtr) {
            maxPtr = &arr[i];
        }
    }
    return maxPtr;
}

void updateValue(int* ptr) {
    if(ptr) *ptr = 999;
}
```

**Tasks**:
1. Identify which functions should use references
2. Rewrite them appropriately
3. Explain why references are better in some cases
4. Keep pointers where nullability is important

---

## Exercise 8: Cache Awareness Experiment

**Problem**: Demonstrate the performance difference between row-major and column-major access.

**Requirements**:
- Create a large 2D array (e.g., 1000x1000)
- Implement row-wise traversal (cache-friendly)
- Implement column-wise traversal (cache-unfriendly)
- Time both operations
- Calculate and explain the performance difference

**Expected Result**: Row-wise should be significantly faster.

---

## Exercise 9: Custom Memory Manager

**Problem**: Implement a simple memory pool for fixed-size allocations.

**Requirements**:
- Create a class that manages a pool of memory blocks
- Provide `allocate()` and `deallocate()` methods
- Avoid calling `new`/`delete` for individual allocations
- Demonstrate reduced allocation overhead
- Show memory fragmentation is eliminated

**Bonus**: Add memory statistics and leak detection.

---

## Exercise 10: The Ultimate Bug Hunt

**Problem**: Debug this complex program with multiple memory issues:

```cpp
#include <iostream>
#include <vector>
using namespace std;

class DataHolder {
public:
    int* data;
    int size;

    DataHolder(int s) : size(s) {
        data = new int[size];
        for(int i = 0; i < size; i++) {
            data[i] = i * 10;
        }
    }

    ~DataHolder() {
        delete[] data;  // Is this called?
    }
};

DataHolder* createHolder() {
    DataHolder holder(5);
    return &holder;  // DANGER!
}

void processData(DataHolder* holder) {
    for(int i = 0; i < holder->size; i++) {
        cout << holder->data[i] << " ";
    }
    cout << endl;
}

int main() {
    // Bug 1: Dangling pointer
    DataHolder* h1 = createHolder();
    processData(h1);

    // Bug 2: Double deletion
    int* arr = new int[10];
    delete[] arr;
    // delete[] arr;  // Uncomment to see crash

    // Bug 3: Memory leak
    vector<DataHolder*> holders;
    for(int i = 0; i < 5; i++) {
        holders.push_back(new DataHolder(i + 1));
    }
    // Forgot to delete them!

    return 0;
}
```

**Tasks**:
1. Identify all memory bugs (dangling pointers, double deletion, leaks)
2. Fix each bug with proper memory management
3. Add RAII principles where appropriate
4. Ensure the program runs without crashes or leaks

---

## Exercise 11: STL vs Raw Pointers

**Problem**: Compare the safety and performance of STL containers vs raw pointers.

**Requirements**:
- Implement the same data structure using:
  - Raw pointers with manual memory management
  - STL containers (vector, etc.)
- Compare code complexity, safety, and performance
- Demonstrate how STL prevents common bugs
- Show proper resource management patterns

**Focus Areas**:
- Exception safety
- Memory leaks
- Bounds checking
- Code maintainability

---

## Bonus Challenge: Memory Profiler

**Problem**: Create a simple memory profiling tool.

**Requirements**:
- Track all allocations and deallocations
- Detect memory leaks
- Report double frees
- Show allocation patterns
- Generate memory usage reports

**Advanced Features**:
- Memory fragmentation analysis
- Allocation hotspots identification
- Performance impact measurement

---

## Phase 2 Exercise Completion Checklist

Mark each exercise as you complete it:

- [ ] Exercise 1: Stack vs Heap Lifetime
- [ ] Exercise 2: Dangling Pointer Hunter
- [ ] Exercise 3: Pointer Arithmetic Mastery
- [ ] Exercise 4: 2D Array Memory Layout
- [ ] Exercise 5: Function Parameter Bug Hunt
- [ ] Exercise 6: Memory Leak Detector
- [ ] Exercise 7: Pointer vs Reference Challenge
- [ ] Exercise 8: Cache Awareness Experiment
- [ ] Exercise 9: Custom Memory Manager
- [ ] Exercise 10: The Ultimate Bug Hunt
- [ ] Exercise 11: STL vs Raw Pointers
- [ ] Bonus: Memory Profiler

**Mastery Level**: You have mastered Phase 2 when you can:
- Predict program behavior without running it
- Spot memory bugs in unfamiliar code instantly
- Choose appropriate memory management strategies
- Debug crashes and undefined behavior efficiently
- Write leak-free, crash-free C++ code consistently