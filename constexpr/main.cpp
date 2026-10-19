#include "bits/stdc++.h"
using namespace std;

void demo0(){
    constexpr int x = 5;
    constexpr int y = 10;
    constexpr int sum = x + y;

    cout << "Demo0  Sum: " << sum << endl; // Output: Sum: 15
}

void demo1(){
    const int a = 10;
    constexpr int b = 20;

    cout << "Demo1  a = " << a << '\n';
    cout << "Demo1  b = " << b << '\n';
}

void demo2(){
    cout << "Demo2  Enter a value: ";
    int x;
    cin >> x;

    const int a = x;       // OK
    //constexpr int b = x; // Compile error

    cout << a << '\n';
}

void demo3(){
    constexpr int SIZE = 5;
    //const int SIZE = 5; // it's also possible to use const instead of constexpr, but constexpr is preferred for compile-time constants

    int arr[SIZE] = {1, 2, 3, 4, 5};

    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

constexpr int square(int x) {
    return x * x;
}

void demo4() {
    constexpr int value = 5;
    constexpr int result = square(value);

    cout << "Demo4  Square of " << value << " is: " << result << endl; // Output: Square of 5 is: 25

    cout << "Demo4  Enter a value: ";
    int x;
    cin >> x;
    square(x); // This will not be evaluated at compile time since x is not a constant expression
}

int main() {
    demo0();
    demo1();
    demo2();
    demo3();
    demo4();

    return 0;
}