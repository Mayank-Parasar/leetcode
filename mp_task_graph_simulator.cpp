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
#include <deque>

#define DEBUG 0

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
        /*schedule only unique events*/
        eventQueue.push(newEvent);
        // showpq();
    }
    static unsigned int time;
    static priority_queue<event*, vector<event*>, eventComparator> eventQueue;
    /*Debug Prints*/
    void showpq() {
        priority_queue<event*, vector<event*>, eventComparator>g = eventQueue;
        while (!g.empty()) {
            cout << '\t' << g.top()->time;
            g.pop();
        }
        cout << '\n';
    }
};

unsigned int simulation::time = 0;
priority_queue<event*, vector<event*>, eventComparator> simulation::eventQueue;

void simulation::run() {
    while(!eventQueue.empty()) {
        event * nextEvent = eventQueue.top();
        eventQueue.pop();
        time = nextEvent->time;
        // cout << "Event Queue is processing the event at time: " << time << endl;
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
    task5(unsigned int t, simulation* sim_) : event(t) {
        simulator = sim_;
    }
    void enqueue_task3(task3* evT3) {
        task3_queue.push_back(evT3);
    }

    void enqueue_task4(task4* evT4) {
        task4_queue.push_back(evT4);
    }
    static deque<task4*> task4_queue;
    static deque<task3*> task3_queue;
    void processEvent();

    simulation* simulator;
};
deque<task4*> task5::task4_queue;
deque<task3*> task5::task3_queue;

class task4 : public event {
public:
    task4(unsigned int t, simulation* sim_) : event(t) {
        simulator = sim_;
    }
    void enqueue_task1(task1* evT1) {
        task1_queue.push_back(evT1);
    }

    void enqueue_task2(task2* evT2) {
        task2_queue.push_back(evT2);
    }
    static deque<task1*> task1_queue;
    static deque<task2*> task2_queue;
    void processEvent();

    simulation* simulator;
};
deque<task1*> task4::task1_queue;
deque<task2*> task4::task2_queue;

class task3 : public event {
public:
    task3(unsigned int t, simulation* sim_) : event(t) {
        simulator = sim_;
    }
    void processEvent() {
        cout << "Processing task3 event at time: " << simulator->time << endl;
        task5 * t5_ptr = new task5(simulator->time+2, simulator);
        t5_ptr->task3_queue.push_back(this);
        if(t5_ptr->task4_queue.size() > 0) {
            simulator->scheduleEvent(t5_ptr);
        }
    }

    simulation* simulator;
};

class task2 : public event {
public:
    task2(unsigned int t, simulation* sim_) : event(t) {
        simulator = sim_;
    }
    void processEvent() {
        cout << "Processing task2 event at time: " << simulator->time << endl;
        /* generate a new event here to put on the task queue... */
        task4* tk4_ptr = new task4(simulator->time+2/*time*/, simulator);
        tk4_ptr->task2_queue.push_back(this);
        if(tk4_ptr->task1_queue.size() > 0) {
            simulator->scheduleEvent(tk4_ptr);
        }
    }


    simulation* simulator;
};


class task1 : public event {
public:
    task1(unsigned int t, simulation* sim_) : event(t) {
        simulator = sim_;
    }
    void processEvent() {
        cout << "Processing task1 event at time: " << simulator->time << endl;
        /* generate a new event here to put on the task queue... */
        task4* tk4_ptr = new task4(simulator->time+2/*time*/, simulator);
        tk4_ptr->task1_queue.push_back(this);
        /* only schedule this event if the queue sizes at the tk4_ptr
           fmeet the requirement*/
        if(tk4_ptr->task2_queue.size() > 0) {
            simulator->scheduleEvent(tk4_ptr);
        }
    }

    simulation* simulator;
};

void
task4::processEvent() {
    // cout << "Trying to process task4 event at time: " << time << endl;
    while(task1_queue.size() > 0 &&
          task2_queue.size() > 0) {

        cout << "Processing task4 event at time: " << simulator->time << endl;
#if(DEBUG)
        for(auto i: task1_queue)
            cout << i->time << "\t";
        cout << endl;
        for(auto i: task2_queue)
            cout << i->time << "\t";
        cout << endl;
        cout << "Consuming: task1_queue.front()->time: " << task1_queue.front()->time << endl;
        cout << "Consuming: task2_queue.front()->time: " << task2_queue.front()->time << endl;
#endif
        task5 * t5_ptr = new task5(simulator->time+2, simulator);
        t5_ptr->task4_queue.push_back(this);
        if(t5_ptr->task3_queue.size() > 0) {
            simulator->scheduleEvent(t5_ptr);
        }
        task1* tmp_tk1 = task1_queue.front();
        task2* tmp_tk2 = task2_queue.front();
        task1_queue.pop_front();
        task2_queue.pop_front();
        delete(tmp_tk1);
        delete(tmp_tk2);
    }
}

void
task5::processEvent() {
    // cout << "Trying to process task5 event at time: " << time << endl;
    while(task3_queue.size() > 0 &&
          task4_queue.size() > 0) {
        cout << "Processing task5 event at time: " << simulator->time << endl;
#if(DEBUG)
        for(auto i: task3_queue)
            cout << i->time << "\t";
        cout << endl;
        for(auto i: task4_queue)
            cout << i->time << "\t";
        cout << endl;
        cout << "Consuming: task3_queue.front()->time: " << task3_queue.front()->time << endl;
        cout << "Consuming: task4_queue.front()->time: " << task4_queue.front()->time << endl;
#endif
        task3* tmp_tk3 = task3_queue.front();
        task4* tmp_tk4 = task4_queue.front();
        task3_queue.pop_front();
        task4_queue.pop_front();
        delete(tmp_tk3);
        delete(tmp_tk4);
    }
    delete this;
}

////////////////////////////////////////////////////////////////////////

int main() {

    simulation* task_graph_simulator = new simulation();
    /*Event Instances*/
    task5* tk5 = new task5(0, task_graph_simulator)/*time*/; // instance of task-5
    task4* tk4 = new task4(0/*time*/, task_graph_simulator);
    task3* tk3 = new task3(90/*time*/, task_graph_simulator);
    task2* tk2 = new task2(30/*time*/, task_graph_simulator);
    task1* tk1 = new task1(12/*time*/, task_graph_simulator);


    /*Schedule independent events*/
    // task-1
    for(int ii = 0; ii < 10; ii=ii+2) {
        task_graph_simulator->scheduleEvent(new task1(ii/*time*/, task_graph_simulator));
    }

    //task-2
    for(int ii = 0; ii < 25; ii=ii+5) {
        task_graph_simulator->scheduleEvent(new task2(ii/*time*/, task_graph_simulator));
    }

    //task-3
    for(int ii = 1; ii < 50; ii=ii + 10) {
        task_graph_simulator->scheduleEvent(new task3(ii/*time*/, task_graph_simulator));
    }

    task_graph_simulator->run();
    delete(tk5);
    delete(tk4);
    delete(tk3);
    delete(tk2);
    delete(tk1);
    delete(task_graph_simulator);

    return 0;
}