# My Smart Pointer

## Implementation

- Create `MySmartPointer.h` and define a class `SmartPtr` to wrap a raw pointer (`int*`) pointing to heap memory.
- **Constructor:** Takes ownership of the given pointer.
- **Destructor:** Automatically frees the allocated memory using `delete` when the object goes out of scope.
- **Dereferencing operator (`*`):** Overloads `operator*()` to access and modify the pointed-to value.
- **Prevent copying:** Delete the copy constructor and copy assignment operator to prevent two objects from owning the same pointer, which could cause double deletion.

## Benefits

- Automatically manages memory without manually calling `delete`.
- Demonstrates RAII (Resource Acquisition Is Initialization): resource lifetime is tied to object lifetime.

> **Note:** RAII ties resource lifetime to object lifetime. `SmartPtr` acquires ownership in its constructor and releases the memory in its destructor. When the object goes out of scope, memory is freed automatically without manually calling `delete`.

## Limitations

- Only supports `int*`.
- Does not check for `nullptr` before dereferencing.
- Does not support move semantics.
- Passing the same raw pointer to multiple `SmartPtr` objects can still cause double deletion.

## Further Learning

Learn C++ standard smart pointers:
- `std::unique_ptr`: Exclusive ownership.
- `std::shared_ptr`: Shared ownership.
- `std::weak_ptr`: Observes shared resources without increasing the reference count.

These provide more complete ownership management and help prevent common memory errors.