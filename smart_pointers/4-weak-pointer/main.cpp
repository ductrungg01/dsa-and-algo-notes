#include <bits/stdc++.h>
using namespace std;

int main(){
    shared_ptr<int> p1 = make_shared<int>(10);
    weak_ptr<int> w1 = p1; // OK: copy constructor is allowed for weak_ptr

    cout << "Value pointed by p1: " << *p1 << endl;
    cout << "Value pointed by w1: " << *w1.lock() << endl; // OK: lock() returns a shared_ptr

    cout << "Number of shared_ptr instances pointing to the same object: " << p1.use_count() << endl; // Still 1 because weak_ptr does not increase the reference count

    p1.reset(); // OK: reset p1, which decreases the reference count
    cout << "After resetting p1:" << endl;
    cout << "Number of shared_ptr instances pointing to the same object: " << p1.use_count() << endl;
    if(w1.expired()){
        cout << "Weak pointer is expired" << endl;
    }

    return 0;
}