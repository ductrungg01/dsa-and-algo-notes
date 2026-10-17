# std::unique_ptr

## Implementation

`unique_ptr` manages a dynamically allocated object with **exclusive ownership**. Only one `unique_ptr` can own the object at a time.
- **Ownership transfer:** Use `std::move(p1)` to transfer ownership from `p1` to `p2`. After the transfer, `p1` becomes `nullptr`.
- **Prevent copying:** Copying is disabled to ensure that only one `unique_ptr` owns the object at a time, preventing double deletion.

## Benefits

- Automatic memory management through RAII.
- Exclusive ownership prevents multiple pointers from owning the same object.
- Supports move semantics to transfer ownership safely.

> **Note:** Use `std::make_unique<int>(10)` instead of `new int(10)` in modern C++ for safer and cleaner initialization.