#include <iostream>

using namespace std;

// Demonstrates a "definitely lost" memory leak
void definitely_lost_array() {
    // Allocate an array of 10 integers on the heap.
    // int = 4 bytes, so the allocation is 10 * 4 = 40 bytes.
    int* arr = new int[10];

    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    cout << "Allocated an array of 10 integers." << endl;

    // When this function ends, the pointer 'arr' is destroyed,
    // but the 40-byte heap allocation is still there.
    //
    // 40 bytes -> definitely lost

    // delete[] arr;
}


// Demonstrates a "definitely lost" leak with an object
void definitely_lost_object() {
    // Allocate a string object on the heap.
    //
    // On a typical 64-bit GCC/libstdc++ system:
    // sizeof(string) = 32 bytes.
    string* str = new string("Hello Valgrind");

    cout << "Allocated string: " << *str << endl;

    // When this function ends, the pointer 'str' is destroyed,
    // but the 32-byte string object is still allocated.
    //
    // 32 bytes -> definitely lost

    // delete str;
}


// Demonstrates a "still reachable" allocation
int* global_pointer = nullptr;

void still_reachable() {
    // Allocate an integer on the heap.
    // int = 4 bytes.
    global_pointer = new int(999);

    cout << "Allocated global integer: "
         << *global_pointer << endl;

    // The global pointer still exists when the program exits,
    // so Valgrind can still reach this 4-byte allocation.
    //
    // 4 bytes -> still reachable
    //
    // We should still free it:
    // delete global_pointer;
}


int main() {
    cout << "--- Program started ---" << endl;

    definitely_lost_array();
    definitely_lost_object();
    still_reachable();

    cout << "--- Program ended ---" << endl;

    return 0;
}

/*
### Expected Valgrind result

With the `delete` statements commented out:

```text
definitely lost:    72 bytes in 2 blocks
indirectly lost:     0 bytes in 0 blocks
possibly lost:       0 bytes in 0 blocks
still reachable:     4 bytes in 1 blocks
```

The **72 bytes** come from:

```text
10 × sizeof(int) = 10 × 4 = 40 bytes
sizeof(string)   = 32 bytes
                              ----
                              72 bytes
```

And:

```text
global int = 4 bytes → still reachable
```

So there are **76 bytes of heap memory not freed**, but Valgrind categorizes them differently:

```text
40 bytes → definitely lost
32 bytes → definitely lost
 4 bytes → still reachable
```

To make the program completely leak-free, uncomment all three:

```cpp
delete[] arr;
delete str;
delete global_pointer;
```

Then the target is:

```text
definitely lost:    0 bytes in 0 blocks
indirectly lost:    0 bytes in 0 blocks
possibly lost:      0 bytes in 0 blocks
still reachable:    0 bytes in 0 blocks
```
*/