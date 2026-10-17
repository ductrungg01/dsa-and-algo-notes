# weak_ptr and Cyclic Dependency

## 1. weak_ptr

`weak_ptr` observes an object managed by `shared_ptr` without owning it.

- `lock()`: Returns a `shared_ptr` if the object still exists; otherwise, returns an empty `shared_ptr`.
- `expired()`: Checks whether the object has been destroyed.
- `weak_ptr` does not increase the reference count.

## 2. Cyclic Dependency

Cyclic dependency occurs when objects own each other through `shared_ptr`, causing a memory leak.

Example:

```cpp
struct B;

struct A {
    shared_ptr<B> ptr;
    ~A() { cout << "A destroyed\n"; }
};

struct B {
    shared_ptr<A> ptr;
    ~B() { cout << "B destroyed\n"; }
};

int main() {
    auto a = make_shared<A>();
    auto b = make_shared<B>();

    a->ptr = b;
    b->ptr = a;
}
```

### Why does this cause a memory leak?

1. `A` owns `B`, and `B` owns `A`.
2. When `main()` ends, both reference counts remain `1`.
3. Neither object is destroyed because their reference counts never reach `0`.

### Fix with `weak_ptr`

Change `B` to use `weak_ptr<A>`:

```cpp
struct B {
    weak_ptr<A> ptr;
    ~B() { cout << "B destroyed\n"; }
};
```

