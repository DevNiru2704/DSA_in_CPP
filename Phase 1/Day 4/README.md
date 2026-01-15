# PHASE 1 — DAY 4 (FINAL)

2D Arrays, Pointer Arithmetic, and the Lies That Cause WA/TLE

## 1. 2D Arrays: What They Actually Are

You write:

```cpp
int a[3][4];
```

**What your brain might imagine:**

"A grid"

**What the machine actually sees:**

One contiguous block of memory

Layout in memory (row-major order):

```
a[0][0] a[0][1] a[0][2] a[0][3]
a[1][0] a[1][1] a[1][2] a[1][3]
a[2][0] a[2][1] a[2][2] a[2][3]
```

No gaps. No pointers. No magic.

## 2. Indexing Formula (Burn This In)

For:

```cpp
int a[R][C];
```

Accessing:

```cpp
a[i][j]
```

Is equivalent to:

```cpp
*(*(a + i) + j)
```

**Meaning:**

- `a` → pointer to row 0
- `a + i` → pointer to row i
- `*(a + i)` → array of C integers
- `+ j` → j-th element in that row

This is pure pointer arithmetic.

## 3. Pointer Arithmetic on 2D Arrays (No Hand-Waving)

Let's inspect addresses:

```cpp
#include <iostream>
using namespace std;

int main() {
    int a[2][3];

    cout << a << endl;        // address of row 0
    cout << a + 1 << endl;    // address of row 1
    cout << &a[1][0] << endl; // same as a + 1
}
```

**Key fact:**

`a + 1` jumps by one full row, not one element.

**Why?**  
Because the type of `a` is:

```cpp
int (*)[3]
```

Pointer to an array of 3 ints.

## 4. Why int** Is NOT a 2D Array (Critical CP Trap)

This is one of the most dangerous beginner misunderstandings.

### What people think:
```cpp
int** p;  // "2D array"
```

### What it actually means:
```cpp
p -> pointer to pointer to int
```

This represents scattered memory, not a grid.

**Example:**

```cpp
int** p = new int*[rows];
for (int i = 0; i < rows; i++) {
    p[i] = new int[cols];
}
```

Memory layout:

```
p -> row pointers
row 0 -> heap block
row 1 -> heap block
row 2 -> heap block
```

This is NOT contiguous.

## 5. Why This Matters in Competitive Programming

| Aspect | `int a[R][C]` | `int** p` |
|--------|---------------|-----------|
| Memory | contiguous | scattered |
| Cache | friendly | hostile |
| Passing | simple | complex |
| Bugs | fewer | many |
| CP usage | preferred | avoid |

In CP:

Never use `int**` unless the problem explicitly demands it.

## 6. Passing 2D Arrays to Functions (The Correct Way)

This is where many people break down.

### ❌ Wrong (will not compile)
```cpp
void f(int a[][]) { }
```

Compiler needs to know row size.

### ✅ Correct (static 2D array)
```cpp
void f(int a[][4], int rows) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < 4; j++)
            cout << a[i][j] << " ";
}
```

Or explicitly:

```cpp
void f(int (*a)[4], int rows) { }
```

Both are the same.

### Why column size is mandatory

Because:

```cpp
a[i][j] == *(*(a + i) + j)
```

The compiler must know:

- how far `a + i` should jump
- that depends on number of columns

## 7. Passing Dynamic 2D Arrays (Avoid for Now)

This works:

```cpp
void f(int** a);
```

But:

- memory is fragmented
- performance worse
- easy to leak
- ugly code

This is Phase 2+ territory.

## 8. First CP-Grade Bug Hunt (Realistic)

### Buggy code
```cpp
int a[100][100];

for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
        a[i][j] = 0;
    }
}
```

**What's wrong?**

- `<=` instead of `<`
- writes to `a[n][*]` and `a[*][m]`
- undefined behavior
- may pass small tests
- explodes on hidden cases

This is classic WA/RE bait.

## 9. Performance Insight (Quiet but Deadly)

### Row-wise traversal:

```cpp
for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
        sum += a[i][j];
```

### Column-wise traversal:

```cpp
for (int j = 0; j < C; j++)
    for (int i = 0; i < R; i++)
        sum += a[i][j];
```

Same complexity.  
Different speed.

Row-wise is much faster due to cache locality.

Judges don't tell you this. Your runtime does.

## 10. Phase 1 Mental Checklist (If You Pass This, You're Ready)

You now understand:

- Arrays are contiguous memory
- Indexing is pointer arithmetic
- 2D arrays are not pointers-to-pointers
- Why function signatures matter
- Why bugs hide in boundary conditions
- Why performance ≠ just Big-O

This is not beginner knowledge.

## Day 4 Exercises (Mandatory)

1. Write a function that takes a 2D array and prints it. Verify column size must be specified.
2. Create a 2D array and print all element addresses. Observe contiguous layout.
3. Compare memory addresses of `int**` vs static 2D array. See the difference.
4. Write a function to transpose a 2D matrix in-place.
5. Find a boundary bug in given code and fix it.
6. Measure time difference between row-wise and column-wise traversal on large arrays.


