# PHASE 1 — Absolute Core C++

**Goal:** Writing C++ becomes mechanical. Your brain focuses on logic, not syntax.

We begin at the smallest atom: how a C++ program actually exists and runs.

## 1. The C++ Program Is Not Magic

It is a pipeline.

```
Your code → Preprocessing → Compilation → Linking → Executable
```

When CP problems fail, they fail at one of these stages. Knowing which one saves hours.

### Minimal valid C++ program
```cpp
#include <iostream>

int main() {
    return 0;
}
```

That's it. Everything else is decoration.

### What each part really means

**`#include <iostream>`**

- Copy-pastes declarations from the standard library
- Happens before compilation
- Zero runtime cost

**`int main()`**

- Program entry point
- OS calls this
- Returning 0 means "success"

No main, no program. Ever.

## 2. Compilation Model (This Matters More Than People Admit)

When you run:

```bash
g++ main.cpp
```

Internally:

1. Preprocessor expands `#include`
2. Compiler turns code → object file
3. Linker connects everything

**Why you care in CP:**

- "undefined reference" errors = linker
- Syntax errors = compiler
- Weird macro bugs = preprocessor

You don't panic; you diagnose.

## 3. Input / Output — Your Lifeline in CP

### Naive I/O (slow but clear)
```cpp
#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    cout << x << '\n';
}
```

### CP-ready I/O (fast)
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;
    cout << x << '\n';
}
```

### Why this matters

- `cin`/`cout` are synchronized with C I/O by default
- Turning it off removes unnecessary locking
- This alone can turn TLE into AC

## 4. Control Flow — Not Syntax, but Shape

You already "know" `if`, `for`, `while`. Now we sharpen instincts.

### if vs switch

Use `switch` when:

- Checking equality against constants
- Many branches
- Integers / chars

```cpp
switch (x) {
    case 1: break;
    case 2: break;
    default: break;
}
```

Compiler can optimize this into jump tables. Sometimes faster than chained `if`.

### Loops and Time Intuition
```cpp
for (int i = 0; i < n; i++) { }      // O(n)
for (int i = 0; i < n; i++)
  for (int j = 0; j < n; j++) { }   // O(n²)
```

In CP, your eyes should auto-convert loops into time complexity.

## 5. Scope Is a Weapon
```cpp
int x = 10;

if (true) {
    int x = 5;
    cout << x << '\n'; // 5
}

cout << x << '\n';     // 10
```

This is not a trick.  
This is how bugs are born.

CP codebases rely heavily on tight scopes to avoid state leaks.

## 6. Functions — Beyond "It Works"

### Pass by value
```cpp
void f(int x) {
    x++;
}
```

### Pass by reference (CP default)
```cpp
void f(int& x) {
    x++;
}
```

### Pass by pointer (rare in CP)
```cpp
void f(int* x) {
    (*x)++;
}
```

**Rule of thumb for CP:**

- Read-only → `const int&`
- Modify → `int&`
- Pointer only when optional/null matters

## 7. Recursion (With Stack Awareness)
```cpp
int fact(int n) {
    if (n == 0) return 1;
    return n * fact(n - 1);
}
```

Each call:

- Allocates a stack frame
- Stores parameters + return address
- Too deep = stack overflow.

Good CP programmers feel when recursion is dangerous.

## Phase 1 — Day-1 Exercises (Mandatory)

Do these by hand, not mentally.

### Exercise 1 — Compile Error Awareness

Write a program without main. Compile it. Read the error.

### Exercise 2 — Scope Trap

Predict output before running:

```cpp
int x = 1;
for (int i = 0; i < 3; i++) {
    int x = i;
}
cout << x << '\n';
```

### Exercise 3 — Reference Reality

Predict output:

```cpp
void inc(int& x) {
    x++;
}

int main() {
    int a = 5;
    inc(a);
    cout << a << '\n';
}
```

Then rewrite `inc` using value, observe difference.

### Exercise 4 — Fast I/O Discipline

Write a loop that reads n numbers and prints their sum.  
Use fast I/O from the start. Make it muscle memory.

## Where This Phase Is Going Next

In the next Phase 1 conversation, we will:

- Tear apart arrays (static vs dynamic)
- Kill fear of segmentation faults
- Build loop + array patterns used in CP daily

No OOP yet. No STL yet. Just raw steel.

You're doing this the right way: foundations first, speed later.

