# Phase 1 — Day-1 Exercises (Mandatory)

Do these by hand, not mentally.

## Exercise 1 — Compile Error Awareness

Write a program without main. Compile it. Read the error.

## Exercise 2 — Scope Trap

Predict output before running:

```cpp
int x = 1;
for (int i = 0; i < 3; i++) {
    int x = i;
}
cout << x << '\n';
```

## Exercise 3 — Reference Reality

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

## Exercise 4 — Fast I/O Discipline

Write a loop that reads n numbers and prints their sum.  
Use fast I/O from the start. Make it muscle memory.