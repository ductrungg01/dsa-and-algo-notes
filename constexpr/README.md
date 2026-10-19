# const vs constexpr in C++

Both `const` and `constexpr` are used to define values that cannot be changed after initialization.

The main difference is that `constexpr` requires a variable's value to be known at compile time, while `const` can also be initialized with a value determined at runtime.

## 1. Basic Example

```cpp
#include <iostream>
using namespace std;

int main() {
    const int a = 10;
    constexpr int b = 20;

    cout << "a = " << a << '\n';
    cout << "b = " << b << '\n';

    return 0;
}
```

Output:

```
a = 10
b = 20
```

Both variables cannot be modified after initialization.

## 2. const Can Use Runtime Values

```cpp
#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;

    const int a = x;       // OK
    // constexpr int b = x; // Compile error

    cout << a << '\n';

    return 0;
}
```

Here, `x` is entered at runtime.

- `const int a = x` is valid because `const` allows runtime initialization.
- `constexpr int b = x` is invalid because `x` is not known at compile time.

## 3. Using constexpr with Arrays

```cpp
#include <iostream>
using namespace std;

int main() {
    constexpr int SIZE = 5;

    int arr[SIZE] = {1, 2, 3, 4, 5};

    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}
```

Output:
```
1 2 3 4 5
```
`constexpr` is useful when a value must be available at compile time, such as an array size.

A `const` variable can also be used as an array size if its initializer is a constant expression.

## 4. Using constexpr Functions

```cpp
constexpr int square(int x) {
    return x * x;
}

int main() {
    constexpr int result = square(5);

    return 0;
}
```

The compiler can calculate `square(5)` at compile time because its argument is known.

## 5. Comparison

| Feature | const | constexpr |
|---|---|---|
| Cannot be modified after initialization | Yes | Yes |
| Must be initialized | Yes | Yes |
| Allows runtime initialization | Yes | No |
| Can be used for compile-time calculations | Yes, when eligible | Yes |
| Can define constexpr functions | No | Yes |

## 6. When to Use

- **const:** Use when a value must not change after initialization, but may be determined at runtime.
- **constexpr:** Use when a value must be available at compile time.

Remember:

- `const` = cannot be modified after initialization.
- `constexpr` = compile-time constant when used to initialize a constexpr variable.

For ordinary variables, `constexpr` also implies `const`.