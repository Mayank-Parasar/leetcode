// iceCream Store simulator

#include <iostream>
#include <queue>
using namespace std;

class event {
public:
    // construct sets of time of event.
    event (unsigned int t) : time(t)
    { }
    virtual ~event() {};
    // Execute event by invoking this method.
    virtual void processEvent() = 0;

    const unsigned int time;
};


struct eventComparator {
    bool operator()(const event* left, const event* right) const {
        return left->time > right->time;
    }
};

class simulation {
public:
    simulation() : time (0), eventQueue()
    { }
    void run (); // consumes the event
    void scheduleEvent (event * newEvent) {
        eventQueue.push(newEvent);
    }
    unsigned int time;
protected:
    std::priority_queue<event*, std::vector<event *, std::allocator<event*>>,
    eventComparator> eventQueue;
};

void simulation::run() {
    while(! eventQueue.empty()) {
        event * nextEvent = eventQueue.top();
        eventQueue.pop();
        time = nextEvent->time;
        nextEvent->processEvent();
        delete nextEvent;
    }
}

class storeSimulation : public simulation {
public:
    storeSimulation() : simulation(), freeChairs(35), profit (0.0)
    { }

    bool canSeat (unsigned int numberOfPeople);
    void order (unsigned int numberOfScoops);
    void leave (unsigned int numberOfPeople);

    // Data fields.
    unsigned int freeChairs;
    double profit;
} theSimulation;

bool storeSimulation::canSeat(unsigned int numberOfPeople) {

    cout << "Time: " << time;
    cout << " group of " << numberOfPeople << " customers arrives";

    if (numberOfPeople < freeChairs) {
        cout << " is seated\n";
        freeChairs -= numberOfPeople;
        return true;
    }
    else {
        cout << " no room, they leave \n";
        return false;
    }
}

void storeSimulation::order (unsigned int numberOfScoops) {
    cout << "Time: " << time << " serviced order for "
        << numberOfScoops << endl;
    profit += 0.35 * numberOfScoops;
}

void storeSimulation::leave(unsigned int numberOfPeople) {
    cout << "Time: " << time << " serviced order for "
        << numberOfPeople << endl;
    freeChairs += numberOfPeople;
}

class arriveEvent : public event {
public:
    arriveEvent (unsigned int t, unsigned int groupSize)
    : event(t), size(groupSize)
    { }
    ~arriveEvent(){ };
    virtual void processEvent();
private:
    unsigned int size;
};

class orderEvent : public event {
public:
    orderEvent (unsigned int t, unsigned int groupSize)
    : event (t), size(groupSize)
    { }
    ~orderEvent() { };
    virtual void processEvent();

private:
    unsigned int size;
};

class leaveEvent : public event {
public:
    leaveEvent(unsigned int t, unsigned int groupSize)
    : event(t), size(groupSize)
    { }
    ~leaveEvent() { };
    virtual void processEvent();
private:
    unsigned int size;
};

void leaveEvent::processEvent() {
    theSimulation.leave(size);
}

void orderEvent::processEvent() {
    // Each person orders some number of scoops.
    for (unsigned int i = 0; i < size; i++) {
        theSimulation.order(1 + (rand() % 4));
    }
    // then we schedule the leave event.
    theSimulation.scheduleEvent(
            new leaveEvent(time + 1 + (rand()%10), size)
            );
}

void arriveEvent::processEvent() {
    if(theSimulation.canSeat(size)) {
        theSimulation.scheduleEvent(new orderEvent (time + 1 + (rand() % 4), size));
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    // Load queue with some number of initial events.
    for(unsigned t = 0; t < 20; t += (rand()%6)) {
        cout << "Pumping queue with event " << t << endl;
        theSimulation.scheduleEvent(new arriveEvent(t, 1+(rand()%4)));
    }

    // Run the simulation.
    theSimulation.run();

    cout << "Total profits " << theSimulation.profit <<endl;
    cout << "End of icecream store simulation" << endl;

    return 0;
}