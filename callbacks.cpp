//
// Created by Mayank Parasar on 2019-12-03.
//

/*Implementing the callback using an interface-class*/

#include <iostream>

using namespace std;

class CallbackInterface {  // this is an abstract class
public:
    // the prefix 'cbi' to prevent naming clashes.
    virtual int cbi_CallbackFucntion(int)=0;
};

// The class that wants to be called back from the CallbackInterface
// and implementa the callback funciton
class Callee : public CallbackInterface {
public:
    // The callback function that caller will call.
    int cbi_CallbackFucntion(int i) {
        cout << "Callee::cbi_CallbackFunction() inside callback" << endl;
        return 2 * i;
    }
};


class Caller {
public:
    // Clients can connect theit callback with this
    void connectCallback(CallbackInterface *cb) {
        m_cb = cb;
    }

    // Test the callback to make sure it works.
    void test() {
        cout << "Caller::test() calling callback..." << endl;
        int i = m_cb->cbi_CallbackFucntion(10);

        cout << "Result (20): " << i << endl;
    }

private:
    // The callback provided by the client via connectCallback(
    CallbackInterface *m_cb;
};

int main() {
    // a pointer to callee can be passes to a function or object
    // that will call it back
    Caller caller;
    Callee callee;

    // Connect the callback
    caller.connectCallback(&callee);

    // Test the callback
    caller.test();
    return 0;
}