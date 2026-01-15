#include <iostream>
using namespace std;

int mainFake()
{
    cout << "hello" << endl;
    return 0;
}

/*
Compiling Phase 1/Exercises/01_compile_error_awareness.cpp...
/usr/bin/ld: /usr/lib/gcc/x86_64-pc-linux-gnu/15.2.1/../../../../lib/Scrt1.o: in function `_start':
(.text+0x1b): undefined reference to `main'
collect2: error: ld returned 1 exit status
Compilation failed!
*/