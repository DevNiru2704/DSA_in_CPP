# Phase 1 — Absolute Core C++

**Goal:** Master the mechanical foundations of C++ so syntax becomes invisible and logic becomes clear.

This phase covers arrays, pointers, memory management, and performance intuition — the bedrock of competitive programming.

---

## Day 1 — Fundamentals & Setup

**Focus:** C++ program structure, I/O optimization, control flow, and functions

### Topics Covered
- Compilation model (preprocessing, compilation, linking)
- Fast I/O techniques (`ios::sync_with_stdio`, `cin.tie`)
- Control flow patterns (`if`, `switch`, loops)
- Scope and lifetime
- Function passing (value, reference, pointer)
- Recursion with stack awareness

### Files
- `01_boilerplate.cpp` - Minimal C++ program
- `02_input.cpp` - Basic I/O
- `03_input_optimized.cpp` - Fast I/O for CP
- `04_scope.cpp` - Variable scope demonstration
- `05_functions.cpp` - Different parameter passing methods

### Exercises
1. Compile error awareness
2. Scope trap prediction
3. Reference vs value passing
4. Fast I/O with array sum

---

## Day 2 — Arrays, Segfaults & Loop Patterns

**Focus:** Static/dynamic arrays, memory safety, and fundamental loop patterns

### Topics Covered
- Static vs dynamic arrays
- Segmentation faults (causes and prevention)
- Safe loop patterns
- Array + loop idioms (input, sum, max/min)
- Frequency counting
- Reverse iteration

### Files
- `01_static_array.cpp` - Stack-allocated arrays
- `02_dynamic_array.cpp` - Heap-allocated arrays
- `03_segfault_demo.cpp` - Common segfault causes
- `04_loop_patterns.cpp` - Essential array patterns
- `05_frequency_counting.cpp` - Frequency array technique
- `06_reverse_loop.cpp` - Safe reverse iteration

### Exercises
1. Reverse array printing
2. Find largest and second-largest
3. Digit frequency counting
4. Intentional segfault demonstration

---

## Day 3 — Pointers, Memory & Performance

**Focus:** Pointer-array equivalence, memory models, and cache awareness

### Topics Covered
- Pointer-array identity (`a[i] == *(a + i)`)
- Array decay in functions
- `sizeof` behavior and limitations
- Stack vs heap memory
- Static/global arrays for large data
- Cache-friendly vs cache-hostile access patterns

### Files
- `01_pointer_array_equivalence.cpp` - Pointer arithmetic basics
- `02_array_decay.cpp` - Function parameter decay
- `03_sizeof_truth.cpp` - How sizeof really works
- `04_stack_vs_heap.cpp` - Memory allocation comparison
- `05_static_array.cpp` - Large static arrays
- `06_cache_friendliness.cpp` - Sequential access patterns

### Exercises
1. Print array element addresses
2. Compute array size inside function
3. In-place array reversal
4. Stack overflow and fix
5. 2D array traversal comparison

---

## Day 4 — 2D Arrays & Memory Reality (FINAL)

**Focus:** Multidimensional arrays, pointer arithmetic, and competitive programming pitfalls

### Topics Covered
- 2D array memory layout (row-major order)
- Indexing formula (`a[i][j] == *(*(a + i) + j)`)
- Why `int**` ≠ 2D array
- Passing 2D arrays to functions
- Common boundary bugs
- Cache locality in 2D traversal

### Files
- `01_2d_array_basics.cpp` - Contiguous 2D memory
- `02_pointer_arithmetic.cpp` - 2D pointer math
- `03_scattered_memory.cpp` - `int**` vs static array
- `04_passing_2d_arrays.cpp` - Function signatures
- `05_boundary_bug_fixed.cpp` - Off-by-one prevention
- `06_cache_locality.cpp` - Row vs column traversal

### Exercises
1. Write 2D array print function with proper signature
2. Print memory addresses to verify contiguous layout
3. Compare `int**` vs static 2D array memory
4. Transpose matrix in-place
5. Debug boundary condition bugs
6. Measure row-wise vs column-wise traversal performance

---

## Phase 1 Completion Checklist

After completing Phase 1, you should:

✅ Write C++ syntax mechanically without thinking  
✅ Understand arrays as contiguous memory blocks  
✅ Predict segmentation faults before they happen  
✅ Know when to use stack vs heap vs static storage  
✅ Recognize cache-friendly access patterns  
✅ Debug using pointer arithmetic and memory addresses  
✅ Avoid common boundary and indexing bugs  

---

## What's Next?

Phase 2 will cover:
- Advanced memory management
- Object-oriented programming foundations
- Move semantics and modern C++
- Template basics

**You're building expertise, not speed-running concepts. Take your time.**
