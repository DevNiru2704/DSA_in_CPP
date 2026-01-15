# PHASE 1 — DAY 2

Arrays, Segmentation Faults, and Loop Patterns

## 1. What an Array Really Is

An array is one contiguous block of memory.

```cpp
int a[5] = {1, 2, 3, 4, 5};
```

Memory (conceptually):

```
| a[0] | a[1] | a[2] | a[3] | a[4] |
```

- No bounds checking
- No size stored
- No mercy

C++ will let you read garbage and write death.

## 2. Static Arrays (Compile-Time Size)

```cpp
int a[1000];
```

**Properties:**

- Allocated on the stack
- Size must be known at compile time
- Very fast
- Very dangerous if too large

This will crash:

```cpp
int a[100000000]; // stack explosion
```

**Rule of thumb:**

- Stack arrays → small (≤ 10⁶ ints, often much less)
- Bigger → heap (later)

## 3. Dynamic Arrays (Runtime Size)

Classic C-style dynamic allocation:

```cpp
int* a = new int[n];
```

- Allocated on the heap
- Size decided at runtime
- Slower than stack
- Must be manually freed

```cpp
delete[] a;
```

In competitive programming:

- You rarely use `new`
- Prefer static arrays with max constraints
- STL vector later replaces this safely

For now, understand it—not love it.

## 4. The Birth of Segmentation Faults

A segmentation fault means:

> "You touched memory that does not belong to you."

That's it. No drama. No philosophy.

### Common ways to summon it

**1. Out-of-bounds access**
```cpp
int a[5];
a[10] = 3;   // undefined behavior
```

**2. Negative index**
```cpp
a[-1] = 7;
```

**3. Uninitialized pointer**
```cpp
int* p;
*p = 5;     // instant death
```

**4. Using deleted memory**
```cpp
delete[] a;
a[0] = 1;   // zombie memory
```

Segfaults are not random.  
They are predictable once you understand memory.

## 5. Arrays + Loops = Power (and Danger)

This is the CP bread-and-butter.

### Canonical safe loop
```cpp
for (int i = 0; i < n; i++) {
    // access a[i]
}
```

The condition `i < n` is sacred.  
Change it casually and bugs are born.

### Reverse loop (common trap)
```cpp
for (int i = n - 1; i >= 0; i--) {
    // BUG if i is unsigned
}
```

Safe version:

```cpp
for (int i = n - 1; i >= 0; i--) {
    // only if i is signed int
}
```

In CP:

- Prefer `int` for indices unless forced otherwise

## 6. Loop + Array Patterns You Will Use Daily

### Pattern 1 — Input array
```cpp
for (int i = 0; i < n; i++) {
    cin >> a[i];
}
```

### Pattern 2 — Sum / aggregate
```cpp
long long sum = 0;
for (int i = 0; i < n; i++) {
    sum += a[i];
}
```

### Pattern 3 — Maximum / minimum
```cpp
int mx = a[0];
for (int i = 1; i < n; i++) {
    if (a[i] > mx) mx = a[i];
}
```

### Pattern 4 — Frequency counting (core CP idea)
```cpp
int freq[101] = {0};

for (int i = 0; i < n; i++) {
    freq[a[i]]++;
}
```

This replaces nested loops.  
This prevents TLE.  
This is a weapon.

## 7. Why Indexing Starts at 0 (Not Philosophical)

Because:

```cpp
a[i] == *(a + i)
```

- Array name = base address
- Index = offset

This is not theory.  
This is pointer arithmetic hiding in plain sight.

## 8. Debugging Arrays Like a Pro

When something smells wrong:

1. Print indices
2. Print array size
3. Check loop bounds
4. Check initialization

Example:

```cpp
cout << "i = " << i << endl;
```

Primitive. Effective.

## 9. Mental Rules (Memorize These)

- Every array access is a potential segfault
- The compiler will not save you
- If it crashes, it's your fault—and that's good
- Arrays + loops decide CP performance

## Day 2 Mini-Exercises (Do Them)

1. Create an array of size n, read values, print them in reverse.
2. Find the largest and second-largest element.
3. Count how many times each digit (0–9) appears.
4. Intentionally cause a segfault. Then fix it.

Yes—intentionally. Fear dies when exposed.


An array is one contiguous block of memory.

int a[5] = {1, 2, 3, 4, 5};


Memory (conceptually):

| a[0] | a[1] | a[2] | a[3] | a[4] |


No bounds checking

No size stored

No mercy

C++ will let you read garbage and write death.

2. Static Arrays (Compile-Time Size)
int a[1000];


Properties:

Allocated on the stack

Size must be known at compile time

Very fast

Very dangerous if too large

This will crash:

int a[100000000]; // stack explosion


Rule of thumb:

Stack arrays → small (≤ 10⁶ ints, often much less)

Bigger → heap (later)

3. Dynamic Arrays (Runtime Size)

Classic C-style dynamic allocation:

int* a = new int[n];


Allocated on the heap

Size decided at runtime

Slower than stack

Must be manually freed

delete[] a;


In competitive programming:

You rarely use new

Prefer static arrays with max constraints

STL vector later replaces this safely

For now, understand it—not love it.

4. The Birth of Segmentation Faults

A segmentation fault means:

“You touched memory that does not belong to you.”

That’s it. No drama. No philosophy.

Common ways to summon it
1. Out-of-bounds access
int a[5];
a[10] = 3;   // undefined behavior

2. Negative index
a[-1] = 7;

3. Uninitialized pointer
int* p;
*p = 5;     // instant death

4. Using deleted memory
delete[] a;
a[0] = 1;   // zombie memory


Segfaults are not random.
They are predictable once you understand memory.

5. Arrays + Loops = Power (and Danger)

This is the CP bread-and-butter.

Canonical safe loop
for (int i = 0; i < n; i++) {
    // access a[i]
}


The condition i < n is sacred.
Change it casually and bugs are born.

Reverse loop (common trap)
for (int i = n - 1; i >= 0; i--) {
    // BUG if i is unsigned
}


Safe version:

for (int i = n - 1; i >= 0; i--) {
    // only if i is signed int
}


In CP:

Prefer int for indices unless forced otherwise

6. Loop + Array Patterns You Will Use Daily
Pattern 1 — Input array
for (int i = 0; i < n; i++) {
    cin >> a[i];
}

Pattern 2 — Sum / aggregate
long long sum = 0;
for (int i = 0; i < n; i++) {
    sum += a[i];
}

Pattern 3 — Maximum / minimum
int mx = a[0];
for (int i = 1; i < n; i++) {
    if (a[i] > mx) mx = a[i];
}

Pattern 4 — Frequency counting (core CP idea)
int freq[101] = {0};

for (int i = 0; i < n; i++) {
    freq[a[i]]++;
}


This replaces nested loops.
This prevents TLE.
This is a weapon.

7. Why Indexing Starts at 0 (Not Philosophical)

Because:

a[i] == *(a + i)


Array name = base address

Index = offset

This is not theory.
This is pointer arithmetic hiding in plain sight.

8. Debugging Arrays Like a Pro

When something smells wrong:

Print indices

Print array size

Check loop bounds

Check initialization

Example:

cout << "i = " << i << endl;


Primitive. Effective.

9. Mental Rules (Memorize These)

Every array access is a potential segfault

The compiler will not save you

If it crashes, it’s your fault—and that’s good

Arrays + loops decide CP performance

Day 2 Mini-Exercises (Do Them)

Create an array of size n, read values, print them in reverse.

Find the largest and second-largest element.

Count how many times each digit (0–9) appears.

Intentionally cause a segfault. Then fix it.

Yes—intentionally. Fear dies when exposed.