//
// Created by Mayank Parasar on 2019-12-19.
//

/*
 * Implement a class for a stack that supports all the regular functions (push, pop) and
 * an additional function of max() which returns the maximum element in the stack
 * (return None if the stack is empty). Each method should run in constant time.
 *
    s = MaxStack()
    s.push(1)
    s.push(2)
    s.push(3)
    s.push(2)
    print s.max()
    # 3
    s.pop()
    s.pop()
    print s.max()
    # 2

*/

#include <iostream>
#include <vector>

using namespace std;

class MaxStack {
public:
    MaxStack() {
        // default
    }

    void push(int val) {
        m_stack.push_back(val);
        return;
    }

    int pop() {
        if(m_stack.size() == 0) {
            cout <<  "MaxStack::pop() called on a empty vector" << endl;
            return (-1);
        }
        int tmp = m_stack.back();
        m_stack.pop_back();
        return tmp;
    }

    int max() {
        return (*max_element(m_stack.begin(), m_stack.end()));
    }
private:
    vector<int> m_stack;
};

int main() {

    MaxStack *s = new MaxStack();
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(2);

    cout << s->max() << endl;

    s->pop();
    s->pop();

    cout << s->max();

    delete s;

    return 0;
}