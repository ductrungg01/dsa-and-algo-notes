# std::shared_ptr

## Implementation
`shared_ptr` allows **multiple `shared_ptr` instances to share ownership** of the same dynamically allocated object.
- **Initialization:** Use `make_shared<int>(10)` to create an integer managed by a `shared_ptr`.
- **Shared ownership:** Copy `p1` to `p2` and `p3`. All three pointers share ownership of the same object.
- **Reference counting:** Use `use_count()` to check how many `shared_ptr` instances share ownership of the object.
- **Release ownership:** Call `reset()` to release a pointer's ownership and decrease the reference count. The object is destroyed when the last owner releases it.

## Benefits

- Automatically manages memory through RAII.
- Allows multiple pointers to share ownership of an object.
- Automatically destroys the object when no owners remain.

> **Note:** Never manually `delete` the object managed by a `shared_ptr`. Use `reset()` or let the `shared_ptr` go out of scope to release ownership safely.