# C++ Competitive Programming Mastery Roadmap

> **Goal:** Master C++ deeply enough that it becomes an extension of your thinking, enabling long-term growth toward LeetCode Grandmaster–level competitive programming.

This roadmap blends:
- Your **college OOP modules (I–V)**
- **Industry-grade C++ knowledge**
- **Competitive programming–specific practices**

This is not a crash course. It is a foundation-for-life plan.

---

## Phase 0 — Learning Philosophy (Non-Negotiable)

- C++ is learned by **writing and breaking code**, not reading.
- For every concept:
  - Write code
  - Rewrite it differently
  - Break it
  - Fix it
  - Explain it to yourself

If a concept feels fuzzy, stop and rebuild it.

---

## Phase 1 — Absolute Core C++ (Procedural → Modern C++)

### Language Mechanics
- Compilation model (`.cpp`, headers, preprocessing, linking)
- `#include`, translation units
- `main()` return values and exit codes
- Fast I/O basics
  - `ios::sync_with_stdio(false)`
  - `cin.tie(nullptr)`

### Control Flow (With Cost Awareness)
- `if`, `switch`
- `for`, `while`, `do-while`
- `break`, `continue`
- Scope blocks and lifetime
- Nested loops and complexity intuition

### Functions (Beyond Syntax)
- Pass by value vs reference vs pointer
- Stack frame intuition
- Recursion with base-case discipline
- Inline functions: when they help, when they don’t

**Outcome:** Writing basic C++ should feel mechanical, not thoughtful.

---

## Phase 2 — Memory, Pointers, and Reality

### Memory Model
- Stack vs heap
- Object lifetime
- Dangling pointers
- Memory leaks

### Pointers and References
- Raw pointers (`*`, `&`, `->`)
- References vs pointers
- Pointer arithmetic (understand, don’t abuse)
- `new` / `delete` and why STL replaces them

### Arrays (Competitive Programming Backbone)
- Static arrays
- Dynamic arrays
- Multidimensional arrays
- Cache friendliness and locality

**Outcome:** Segmentation faults become predictable, not mysterious.

---

## Phase 3 — Object-Oriented C++ (Modules II–IV, Sharpened)

### Classes and Objects
- Constructors (default, parameterized, copy)
- Destructors and cleanup
- `const` correctness
- Static members
- Friend functions

### Rule of Three / Five (Professional Level)
- Copy constructor
- Copy assignment
- Destructor
- Move constructor
- Move assignment

### Inheritance
- Access specifiers in inheritance
- Constructor / destructor order
- Virtual base classes
- Diamond problem

### Polymorphism
- Virtual functions
- `override`
- Base-class pointers
- Virtual destructors
- Why polymorphism is rarely used in CP

**Outcome:** You understand OOP deeply without misusing it in contests.

---

## Phase 4 — Templates & Generic Programming

### Function Templates
- Type deduction
- Multiple template parameters
- Constraints and requirements

### Class Templates
- Template-based containers
- How STL is built conceptually

### Template Pitfalls
- Code bloat
- Reading complex compile-time errors

**Outcome:** STL stops feeling magical and starts feeling logical.

---

## Phase 5 — STL: The Competitive Programming Weapon

### Containers (Deep Understanding)
- `vector`
- `deque`
- `list`
- `stack`, `queue`, `priority_queue`
- `set`, `multiset`
- `map`, `multimap`
- `unordered_map`, `unordered_set`

### Iterators
- Iterator categories
- Iterator invalidation
- Why random-access iterators matter

### Algorithms
- `sort`, `stable_sort`
- `lower_bound`, `upper_bound`
- `binary_search`
- `find`, `count`, `accumulate`
- Custom comparators

**Outcome:** You stop writing loops unnecessarily.

---

## Phase 6 — Strings, Files, and Exceptions

### Strings (Very Important)
- `std::string` internals
- Substring operations
- Pattern searching
- Avoiding quadratic behavior

### Files and Exceptions
- Streams and file I/O (conceptual)
- Exception handling mechanics
- Why exceptions are avoided in CP

---

## Phase 7 — C++ Specifically for Competitive Programming

### Performance Techniques
- Fast I/O patterns
- Avoiding unnecessary copies
- Passing by reference
- `reserve()` vs `resize()`

### Core CP Idioms
- Prefix sums
- Difference arrays
- Two pointers
- Sliding window
- Coordinate compression
- Bit manipulation tricks

### Debugging Discipline
- Reading runtime errors
- Using assertions
- Logical dry-runs

**Outcome:** Implementation speed stops being a bottleneck.

---

## Phase 8 — Pattern Recognition (Later Phase)

- Mapping problems to data structures
- Identifying hidden constraints
- Translating ideas to code without hesitation

This phase begins **only after C++ becomes second nature**.

---

## Final Principle

> Competitive programming mastery is not about brilliance.
> It is about removing friction between your brain and the compiler.

This roadmap exists to remove that friction—permanently.
