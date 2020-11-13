//
// Created by m.parasar on 11/12/2020.
//

#include <iostream>

using namespace std;

class base {
public:
    void iam() {
        cout << "I am base class" << endl;
    }
};

class derived : public base {
public:
    derived() {a = 5;}

    int a;
    void iam() {
        cout << "I am derived class" << endl;
    }
};

int main () {

    base *b;
    derived *d;
    d = new derived();
    b = d;      // because derived IS A base class (is-a relation)
    b->iam();

    d->iam();
    cout << "d->a : " << d->a << endl;

    base *bb = new base();
    derived *dd;
    
    // dd = bb;    // ERROR: because base is not a derived class (NOT is-a relation)
    bb->iam();
    dd = static_cast<derived *>(bb);
    dd->iam();
    cout << "dd->a : " << dd->a << endl;

    return 0;
}
