#include <bits/stdc++.h>
using namespace std;

int main(){
    shared_ptr<int> p1 = make_shared<int>(10);
    shared_ptr<int> p2 = p1; // OK: copy constructor is allowed for shared_ptr
    shared_ptr<int> p3 = p2; // OK: copy constructor is allowed for shared_ptr

    cout << "Value pointed by p1: " << *p1 << endl;
    cout << "Value pointed by p2: " << *p2 << endl;
    cout << "Value pointed by p3: " << *p3 << endl;
    cout << "Number of shared_ptr instances pointing to the same object: " << p1.use_count() << endl;

    p1.reset(); // OK: reset p1, which decreases the reference count
    cout << "After resetting p1:" << endl;
    cout << "Number of shared_ptr instances pointing to the same object: " << p2.use_count() << endl;

    // Cannot use delete on shared_ptr, use reset() instead 
    //delete p2; 
    p2.reset(); // OK: reset p2, which decreases the reference count
    cout << "After resetting p2:" << endl;
    cout << "Number of shared_ptr instances pointing to the same object: " << p3.use_count() << endl;

    return 0;
}