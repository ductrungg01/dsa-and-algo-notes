#include <bits/stdc++.h>
#include "MySmartPointer.h"

using namespace std;

// f() use smart pointer instead of raw pointer 
void f() {
    SmartPtr p(new int(100));
    *p = 200; // use overloaded dereferencing operator to set value
    cout << *p << endl; // use overloaded dereferencing operator to get value

    // This line will cause a compilation error because copy constructor is deleted
    // If p1 is copied to p2, both will try to delete the same pointer when they go out of scope, leading to double deletion and undefined behavior.
    // SmartPtr p2(p1); 
    
    // destructor of SmartPtr will be called automatically when p goes out of scope, so no need to manually delete the pointer
}

int main() {
    for (int i = 0; i < 1000; ++i) {
        f();
    }
    return 0;
}
