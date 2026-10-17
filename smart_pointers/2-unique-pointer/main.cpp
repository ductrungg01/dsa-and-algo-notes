#include <bits/stdc++.h>
using namespace std;

int main() {
    unique_ptr<int> p1(new int(100)); // OK: create a unique_ptr that owns an int initialized to 100
    unique_ptr<int> p2 = move(p1);     // OK: transfer ownership from p1 to p2
    //unique_ptr<int> p3 = p2;           // Error: copy constructor is deleted

    // => p1 is now nullptr, and p2 owns the pointer
    if (p1 == nullptr) {
        cout << "p1 is nullptr after move." << endl;
    }

    if (p2 != nullptr) {
        cout << "p2 owns the pointer." << endl;
        cout << "Value pointed by p2: " << *p2 << endl;
    }

    // => unique_ptr ensure that only one unique_ptr owns the pointer at any time, preventing double deletion and ensuring proper resource management.

    // safer and cleaner way to create a unique_ptr is to use make_unique
    // This is modern C++ best practice, as it avoids potential memory leaks and is exception-safe.
    unique_ptr<int> p4 = make_unique<int>(200); // OK: use make_unique to create a unique_ptr
    
    if (p4 != nullptr) {
        cout << "p4 owns the pointer." << endl;
        cout << "Value pointed by p4: " << *p4 << endl;
    }

    return 0;
}