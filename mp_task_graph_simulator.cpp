//
// Created by Mayank Parasar on 2020-03-03.
//

/*
 *   =========
 *  || Task-1 ||
 *   ========= \
 *              \   =========
 *                 || Task-4 ||
 *              /   ========= \
 *   ========= /               \
 *  || Task-2 ||                \
 *   =========                   \
 *                                 =========
 *                                || Task-5 ||
 *                                 =========
 *                               /
 *   =========                  /
 *  || Task-3 || --------------/
 *   =========
 *
 *   In this above task graph a task can only execute if all the previous tasks
 *   have been finished. Device a event driven simulation framework for this task-graph
 * */

#include <iostream>
#include <queue>

using namespace std;



class event {
public:
    unsigned int time;
    event(unsigned int t) : time(t)
    { }
    virtual void processEvent(/*event* ev = nullptr*/) = 0;
    virtual ~event() { };
};

struct eventComparator {
    bool operator()(const event* left, const event* right) {
        return (left->time > right->time);
    }
};

class simulation {
public:
    simulation()
    { }
    void run(); // this runs the simulation
    void scheduleEvent (event* newEvent) {
        eventQueue.push(newEvent);
    }
    static unsigned int time;
    static priority_queue<event*, vector<event*>, eventComparator> eventQueue;

};

unsigned int simulation::time = 0;
priority_queue<event*, vector<event*>, eventComparator> simulation::eventQueue;

void simulation::run() {
    while(!eventQueue.empty()) {
        event * nextEvent = eventQueue.top();
        eventQueue.pop();
        time = nextEvent->time;
        cout << "Event Queue is processing the event at time: " << time << endl;
        nextEvent->processEvent();
        // delete nextEvent;
    }
}

class task1;
class task2;
class task3;
class task4;


class task5 : public event {
public:
    task5(unsigned int t) : event(t) {

    }
    void enqueue_task3(task3* evT3) {
        task3_queue.push_back(evT3);
    }

    void enqueue_task4(task4* evT4) {
        task4_queue.push_back(evT4);
    }
    vector<task4*> task4_queue;
    vector<task3*> task3_queue;

    void processEvent() {
        // cout << "Trying to process task5 event at time: " << time << endl;
        if(task3_queue.size() > 0 &&
           task4_queue.size() > 0) {
            cout << "Processing task5 event at time: " << time << endl;
            task3_queue.pop_back();
            task4_queue.pop_back();
        }
    }
};

class task4 : public event {
public:
    task4(unsigned int t, task5* tk5, simulation* sim_) : event(t) {
        t5 = tk5;
        simulator = sim_;
    }
    void enqueue_task1(task1* evT1) {
        task1_queue.push_back(evT1);
    }

    void enqueue_task2(task2* evT2) {
        task2_queue.push_back(evT2);
    }
    vector<task1*> task1_queue;
    vector<task2*> task2_queue;

    void processEvent() {
        // cout << "Trying to process task4 event at time: " << time << endl;
        if(task1_queue.size() > 0 &&
            task2_queue.size() > 0) {
            cout << "Processing task4 event at time: " << time << endl;
            t5->task4_queue.push_back(this);
            t5->time = simulator->time+2;
            simulator->scheduleEvent(t5);
            task1_queue.pop_back();
            task2_queue.pop_back();
        }
    }

    task5 *t5;
    simulation* simulator;
};

class task3 : public event {
public:
    task3(unsigned int t, task5* tk5, simulation* sim_) : event(t) {
        t5 = tk5;
        simulator = sim_;
    }
    void processEvent() {
        cout << "Processing task3 event at time: " << time << endl;
        t5->task3_queue.push_back(this);
        t5->time = simulator->time+2;
        simulator->scheduleEvent(t5);
    }

    task5 *t5;
    simulation* simulator;
};

class task2 : public event {
public:
    task2(unsigned int t, task4* tk4, simulation* sim_) : event(t) {
        t4 = tk4;
        simulator = sim_;
    }
    void processEvent() {
        cout << "Processing task2 event at time: " << time << endl;
        t4->task2_queue.push_back(this);
        t4->time = simulator->time+2;
        simulator->scheduleEvent(t4);
    }

    task4 *t4;
    simulation* simulator;
};


class task1 : public event {
public:
    task1(unsigned int t, task4* tk4, simulation* sim_) : event(t) {
        t4 = tk4;
        simulator = sim_;
    }
    void processEvent() {
        cout << "Processing task1 event at time: " << time << endl;
        t4->task1_queue.push_back(this);
        // update the time for task-4;
        t4->time = simulator->time+2; // current_time +2
        simulator->scheduleEvent(t4);
    }

    task4 *t4; // connect it to class task-4 at the ctor...
    simulation* simulator;
};



////////////////////////////////////////////////////////////////////////

int main() {

    simulation* task_graph_simulator = new simulation();
    /*Event Instances*/
    task5* tk5 = new task5(0)/*time*/; // instance of task-5
    task4* tk4 = new task4(0/*time*/, tk5, task_graph_simulator);
    task3* tk3 = new task3(90/*time*/, tk5, task_graph_simulator);
    task2* tk2 = new task2(11/*time*/, tk4, task_graph_simulator);
    task1* tk1 = new task1(12/*time*/, tk4, task_graph_simulator);

    /*Schedule independent events*/
    task_graph_simulator->scheduleEvent(tk3);
    task_graph_simulator->scheduleEvent(tk2);
    task_graph_simulator->scheduleEvent(tk1);

    task_graph_simulator->run();

    return 0;
}