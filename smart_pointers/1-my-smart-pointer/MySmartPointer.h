#include <bits/stdc++.h>

class SmartPtr {
    // Actual pointer wrap by object
    int* ptr;
public:
    // Take ownership of the given pointer
    SmartPtr(int* p = nullptr) : ptr(p) {}

    // At destructor, free the memory allocated in constructor
    ~SmartPtr() {
        delete ptr;
    }

    // Overloading dereferencing operator to return the value of the actual pointer
    int& operator*() {
        return *ptr;
    }

    // Not allowing copy constructor and copy assignment operator to avoid double deletion of the same pointer
    SmartPtr(const SmartPtr&) = delete; // disable copy constructor
    SmartPtr& operator=(const SmartPtr&) = delete; // disable copy assignment operator
};
