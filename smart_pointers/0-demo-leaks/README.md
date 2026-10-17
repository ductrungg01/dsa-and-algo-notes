# Memory Leak Demo

This demo shows:

1. **Memory leaks** and how they happen with raw pointers.
2. **Smart pointers** and how they help manage memory automatically.
3. How to use **Valgrind** to detect memory leaks.

## Check Memory Leak with Valgrind

### 1. Compile with debug information

```bash
g++ -g -O0 main.cpp -o main
```

* `-g`: allows Valgrind to show source code locations.
* `-O0`: disables optimization for easier debugging.

### 2. Run Valgrind

```bash
valgrind --leak-check=full --show-leak-kinds=all ./main
```

Look for the **LEAK SUMMARY**:

```text
definitely lost: ...
indirectly lost: ...
possibly lost: ...
still reachable: ...
```

For example:

```text
definitely lost: 40 bytes in 1 blocks
```

means memory was allocated but no pointer to it remains, so it cannot be freed anymore.

### 3. Goal

Our goal is to make the program **free of memory leaks**.

The target Valgrind output should be:

```text
definitely lost: 0 bytes in 0 blocks
indirectly lost: 0 bytes in 0 blocks
possibly lost: 0 bytes in 0 blocks
still reachable: 0 bytes in 0 blocks
```

In other words, **all leak kinds should report 0 bytes**.
