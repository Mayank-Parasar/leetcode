//
// Created by Mayank Parasar on 2020-02-13.
//

/*
 * implement a simple call back mechanism using classes (not function pointer)
 * show how polymorphism work
 * */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Agent;

struct event{
    long int cycle_count;
    Agent* ptr;
};

vector<event*> queue;

void process_queue() {
    for(auto i : queue) {
        i->ptr->process(i);
    }
};
class Agent {
public:
    Agent() {
        name = "Agent";
    }

    virtual void schedule() = 0;
    virtual void process(event* ev) = 0;


protected:
    string name;
};

class component_a : public Agent {
public:

    component_a() {
        name += ".CPU";
    }

    void schedule() {
        event ev = {1, this};
        queue.push_back(&ev);
    }

    void process(event* ev) {
        cout << " Cycle count is: " << ev->cycle_count << endl;
        cout << "My name is: " << name << endl;
    }

private:


};

class component_b : public Agent {
public:

    component_b() {
        name += ".Memory";
    }
    void schedule() {
        event ev = {2, this};
        queue.push_back(&ev);
    }

    void process(event* ev) {
        cout << " Cycle count is: " << ev->cycle_count << endl;
        cout << "My name is: " << name << endl;
    }
private:


};

int main() {

    class component_a* a = new(component_a);
    class component_b* b = new(component_b);


    return 0;
}