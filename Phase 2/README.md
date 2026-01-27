Phase 2 — Memory, Pointers, and Reality
Mental Reframe (Read This First)

C++ does not manage memory for you.
C++ gives you rules. You follow them or the program lies to you.

From now on, every variable you write must answer three questions:

Where does it live?

Who owns it?

When does it die?

If you can’t answer all three, the bug already exists.

2.1 The Memory Model (Stack vs Heap)

Think of memory as two worlds:

Stack

Automatic

Fast

Scope-bound

Dies when the scope ends

Heap

Manual

Slower

Lifetime independent of scope

Dies only when you kill it

Drill 1: Stack Lifetime (Write + Break)
int* f() {
    int x = 10;
    return &x;
}


Compile. Run. Use it.
This returns a dangling pointer.
Why? Because x dies when f() exits.

Fix it by explaining why the fix works, not just by applying it.

2.2 Object Lifetime (The Rule You Can’t Ignore)

Lifetime is not scope.
Scope is visibility.
Lifetime is existence.

{
    int x = 5;
}


At }, x stops existing. Not hidden. Gone.

Now contrast with:

int* p = new int(5);


This lives until delete p; happens. Even if the scope ends.

Drill 2: Predict the Crash
int* p;
{
    int x = 7;
    p = &x;
}
cout << *p << endl;


You must be able to say exactly why this is undefined behavior without running it.

2.3 Dangling Pointers (The Silent Killers)

A dangling pointer is:

A valid address

Pointing to invalid data

That’s why it’s dangerous.

Common sources:

Returning address of a local variable

Deleting memory but keeping the pointer

Reallocations invalidating pointers

Drill 3: Spot the Landmine
int* p = new int(42);
delete p;
cout << *p << endl;


Why does this sometimes “work”?
Why is that worse than crashing?

2.4 Memory Leaks (The Invisible Failure)

A memory leak is not dramatic.
It’s quiet.
It kills long-running programs.

while (true) {
    int* p = new int(5);
}


No crash. No error. Just death by accumulation.

Rule:

Every new must have exactly one delete.

Not zero. Not two.

2.5 Pointers vs References (Do Not Treat Them as Twins)
Pointer

Can be null

Can be reassigned

Explicit dereference

int* p = nullptr;

Reference

Must bind at initialization

Cannot be reseated

Always valid (if code is correct)

int& r = x;

CP Rule:

Use references for function parameters

Use pointers only when nullability or ownership matters

Drill 4: Rewrite

Take a function using pointers and rewrite it using references.
Then explain which version is safer and why.

2.6 Pointer Arithmetic (Understand, Don’t Abuse)

Arrays and pointers are related but not identical.

int a[5];
int* p = a;


p + 1 moves by sizeof(int) bytes, not 1 byte.

Drill 5: Predict Addresses

Print:

&a[0]

p

p + 1

&a[1]

Explain every difference numerically.

2.7 Arrays — The Competitive Programming Backbone
Static Arrays
int a[100000];


Fast

Stack-bound (watch size limits)

Dynamic Arrays
int* a = new int[n];


Heap-bound

Manual cleanup required

Multidimensional Arrays (This Will Hurt Later If Skipped)
int a[3][4];


Memory is contiguous, row-major.

Drill 6: Cache Awareness

Traverse a 2D array:

Row-wise

Column-wise

Measure or reason about which is faster and why.

2.8 new / delete — Why STL Exists

new and delete are power tools.
STL containers are safety gear.

In competitive programming:

You can use new

You usually shouldn’t

You must understand them so STL makes sense, not so you use them everywhere.

2.9 2D Arrays Are Not Arrays of Arrays (Mentally)

You write:

int a[3][4];


Your brain wants to imagine:

“An array of 3 arrays, each with 4 ints”

That intuition is half-right and half-dangerous.

Reality

Memory is laid out contiguously, row by row:

a[0][0] a[0][1] a[0][2] a[0][3]
a[1][0] a[1][1] a[1][2] a[1][3]
a[2][0] a[2][1] a[2][2] a[2][3]


No gaps. No pointers between rows.

This matters because pointer arithmetic depends on it.

2.10 What Does a 2D Array Decay Into?

Given:

int a[3][4];


The type of a is:

int [3][4]


When passed to a function, it decays to:

int (*)[4]


Read that carefully:

pointer to an array of 4 ints

Not int**.

Never int**.

2.11 Why int** Is NOT a 2D Array

This is the single most important correction in Phase 2.

What int** Actually Means
int** p;


This means:

p points to a pointer

That pointer points to an int

This implies two levels of indirection and non-contiguous memory.

Visual Difference
Real 2D array
[ int int int int | int int int int | int int int int ]

int**
p -> [ ptr ] -> [ int int int ]
      [ ptr ] -> [ int int int ]
      [ ptr ] -> [ int int int ]


Rows can be anywhere in memory.

Different beast. Different rules.

2.12 The Classic Bug (You Must Recognize This Instantly)
void f(int** a) {
    cout << a[1][2];
}

int main() {
    int arr[3][4];
    f(arr);  // ❌ WRONG
}


This must trigger an internal alarm.

Why this is wrong:

arr decays to int (*)[4]

Function expects int**

Types are incompatible

Compiler may accept it with a warning

Runtime behavior is undefined

If this ever “works” on your machine, that is bad luck, not correctness.

2.13 The Correct Ways to Pass 2D Arrays
Method 1: Fixed Column Size (Most Common in CP)
void f(int a[][4], int rows) {
    cout << a[1][2];
}


or explicitly:

void f(int (*a)[4], int rows) {
}


You must specify the second dimension.
The compiler needs it for pointer arithmetic.

Method 2: Fully Dynamic (Advanced, Rare in CP)
int** a = new int*[n];
for (int i = 0; i < n; i++)
    a[i] = new int[m];


This matches int**, but:

Slower

More allocations

Cache-unfriendly

Easy to leak memory

Know it. Avoid it in contests.

Method 3: Flattened 1D Array (CP Favorite)
int a[n * m];
a[i * m + j];


Fast.
Cache-friendly.
Simple.

This is how high-performance solutions are written.

2.14 Pointer Arithmetic on 2D Arrays (Non-Negotiable)

Given:

int a[3][4];


a → pointer to row 0

a + 1 → pointer to row 1

*(a + 1) → row 1 (array of 4 ints)

*(*(a + 1) + 2) → a[1][2]

If this feels uncomfortable, you are exactly where you should be.

Drill 7 (Mandatory)

Rewrite:

a[i][j]


Using:

Only *

Only +

Until it feels mechanical.

2.15 The First CP-Grade Bug Hunt

This is not optional.

Buggy Code
int n, m;
cin >> n >> m;
int a[n][m];


Why this is dangerous:

Variable Length Arrays are not standard C++

GCC allows them

Stack overflow risk

Undefined behavior under strict standards

Fixes:

Use vector

Or static arrays with max bounds

Or heap allocation

You must learn to smell non-portable code instantly.