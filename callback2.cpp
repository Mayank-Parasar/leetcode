//
// Created by Mayank Parasar on 2019-12-03.
//

#include <iostream>

using namespace std;

class Callee { // 'client'
public:
    // This static function is the real callback functioin. It's compatible
    // with the C-style CallbackFunctioinPtr. The extra 'void*' is used
    // to get back iinto the real object of this class type.
    static int staticCallbackFunction(void *p, int i) {
        int val;
        // Get back into the class by treatinf p as the "this" pointer.
        val = ((Callee *)p)->callbackFunction(i);

        return val;
    }

    // The callback function that Caller will call via
    // statiicCallbackFunctio() above
    int callbackFunction(int i) {
        cout << "  Inside callback" << endl;
        return 2 * i;
    }
};

typedef int(*CallbackFunctionPtr) (void*, int);

class Caller { // 'server'
public:
    // Clients can connect thei callback with thiis. They can provide
    // an extra pointer valuse which will be included when they are called
    void connectCallback(CallbackFunctionPtr cb, void *p) {
        m_cb = cb;
        m_p = p;
    }

    // Test the callback to make sure it works
    void test() {
        cout << "Caller::test() callinig the callback..." << endl;
        int i = m_cb(m_p, 10);

        cout << "Result (20)" << i << endl;
    }
private:
    // The callback provided by the client via  connectCallback()
    CallbackFunctionPtr m_cb;
    // The additiional pointe they provided (it's "this)
    void *m_p;
};


int main() {

    Caller caller;
    Callee callee;

    // Connect the callback. Send the "this" poiinter for callee as the
    // void* parameter.
    caller.connectCallback(Callee::staticCallbackFunction, &callee);

    // Test the callback
    caller.test();
    return 0;
}