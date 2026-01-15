# PHASE 1 — DAY 3

Pointers, Arrays, Memory Truths, and Performance Intuition

## 1. Pointer–Array Equivalence (Fully, No Myths)

### The core identity (this is not metaphorical)

```cpp
int a[5];
```

The name `a` is not a variable.  
It is a constant pointer to the first element.

Formally:

```cpp
a == &a[0]
```

and

```cpp
a[i] == *(a + i)
```

This is why indexing starts at 0.  
Indexing is just pointer arithmetic wearing a friendly mask.

### Proof by code (do this)

```cpp
#include <iostream>
using namespace std;

int main() {
    int a[3] = {10, 20, 30};

    cout << a << endl;        // address
    cout << &a[0] << endl;   // same address
    cout << *(a + 1) << endl; // 20
    cout << a[1] << endl;     // 20
}
```

Same memory. Same value. Different spelling.

### Important restriction

```cpp
a = a + 1;   // ❌ illegal
```

Because:

- `a` is a constant pointer
- You can move a pointer
- You cannot move an array name

This distinction matters later.

## 2. Passing Arrays to Functions (The Big Lie)

### What beginners think

```cpp
void f(int a[10]) { }
```

### What actually happens

```cpp
void f(int* a) { }
```

Arrays do not get passed.  
They decay into pointers.

### Demonstration

```cpp
#include <iostream>
using namespace std;

void f(int a[]) {
    cout << sizeof(a) << endl;
}

int main() {
    int arr[10];
    cout << sizeof(arr) << endl;
    f(arr);
}
```

Typical output:

```
40
8
```

**Why?**

- `sizeof(arr)` → size of entire array
- `sizeof(a)` inside `f` → size of pointer

This is not a bug.  
This is the language design.

### Consequence (critical)

A function receiving an array has NO idea how big it is.

You must pass the size explicitly.

```cpp
void f(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
```

This is mandatory discipline in CP.

## 3. Why sizeof Lies to Beginners

`sizeof` does exactly what it promises.  
Beginners misunderstand what they're asking.

### On arrays (in same scope)

```cpp
int a[5];
sizeof(a);        // 5 * sizeof(int)
```

### On pointers

```cpp
int* p = a;
sizeof(p);        // size of pointer (8 bytes on 64-bit)
```

### Inside functions

```cpp
void f(int a[]) {
    sizeof(a);    // size of pointer
}
```

Because `a` is a pointer there.

### Rule to memorize

`sizeof` only knows the truth where the array is declared.

Everywhere else, it sees a pointer.

## 4. Stack vs Heap (When It Really Matters)

### Stack memory

```cpp
int a[1000];
```

- automatic
- extremely fast
- limited
- freed automatically

Too big → stack overflow → crash.

### Heap memory

```cpp
int* a = new int[n];
```

- slower
- much larger
- manual lifetime control

```cpp
delete[] a;
```

### Competitive programming reality

You usually do this:

```cpp
static int a[200000];
```

**Why?**

- avoids stack overflow
- avoids heap overhead
- predictable
- fast

This is intentional, not hacky.

### Rule of thumb

| Use case | Choice |
|----------|--------|
| Small fixed size | stack array |
| Large known max | static/global array |
| Runtime flexible | heap (later: vector) |

## 5. First Taste of Cache Friendliness (This Is Big)

Modern CPUs are much faster than memory.

They love contiguous access.

### Fast (cache-friendly)

```cpp
for (int i = 0; i < n; i++) {
    sum += a[i];
}
```

Sequential memory.  
CPU prefetches.  
Blazing fast.

### Slow (cache-hostile)

```cpp
for (int i = 0; i < n; i++) {
    sum += a[random_index[i]];
}
```

Random jumps.  
Cache misses.  
Same complexity, slower in reality.

### Why arrays beat linked lists

**Arrays:**

- contiguous
- predictable
- cache-friendly

**Linked lists:**

- scattered
- pointer chasing
- cache nightmare

This is why CP prefers arrays/vectors.

## 6. Mental Model Upgrade (Important)

From now on, think like this:

- An array is memory
- An index is an offset
- A loop is a memory walk
- Performance = how friendly you are to the cache

This is hardware-aware programming.

## Day 3 Exercises (Mandatory)

1. Print addresses of `a[i]` and observe spacing.
2. Pass an array to a function and try to compute its size inside.
3. Write a function that reverses an array in-place.
4. Cause a stack overflow with a huge local array. Then fix it.
5. Compare row-wise vs column-wise traversal of a 2D array.

