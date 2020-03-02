//
// Created by Mayank Parasar on 2020-02-28.
//

/*
 * Design a Vending machine simulator
 * It has 4 products: A, B, C and D
 * Have some initial quatity of products
 * Any number of user can visit the vending machine to
 *
 * Calculate the profit after vending products.
 * the machine takes 'k' cycles before ejecting the selected product.
 * */

// TODO:
// Model contention ==>
// 1. Suppose k people made simultaneous order...
// Each order takes delta time to serve, model queuing delay
// 2. when the machine is not able to satisfy the order then it fills
// itself one-by-one serially to satisfy the order unlike refill
// where the machine can be refilled with fixed content simultaneously
// 3. Create priority among customers.. something along the line of
// express-checkout (order-size) present in grocery stores today (example whole-food market)
// Have not thought this through...
// 4. order serving time should be a function of the order-size

#include <iostream>
#include <queue>

using namespace std;

/////////////////////////// Bioler-plate ///////////////////////////

class event {
public:
	unsigned int time;
	event(unsigned int t) : time(t)
	{ }
	virtual void processEvent() = 0;  // pure virtual function, therefore we need virtual dtor
	// Must have a virtual distructor to avoid memory leaks
	virtual ~event() { };
};

struct eventComparator {
	bool operator()(const event* left, const event* right) {
		return (left->time > right->time);
	}
};

class simulation {
public:
	simulation() /*:*/ /*time(0),*/ /*eventQueue()*/
	{ }
	void run(); // this runs the simulation
	void scheduleEvent (event* newEvent) {
		eventQueue.push(newEvent);
	}
    static unsigned int time; // this time should be updated for all of its children therefore make it static
    // make event queue 'static' too, so that its derived class can schedule the event on the same event queue
    static priority_queue<event*, vector<event*>, eventComparator> eventQueue;
// protected:


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
		delete nextEvent;
	}
}

////////////////////////////////////////////////////////////////////////

class vendingMachineSimulation : public simulation {
public:
	vendingMachineSimulation() :
		simulation(),
		Quant_A(10),
		Quant_B(5),
		Quant_C(4),
		Quant_D(0),
		profit_A(0.5),
		profit_B(0.2),
		profit_C(0.1),
		profit_D(0.7),
		profit(0.0)
		{ };

		void order (unsigned int Quant_A=0, unsigned int Quant_B=0,
					unsigned int Quant_C=0, unsigned int Quant_D=0);
		void refill(unsigned int Quant_A=0, unsigned int Quant_B=0,
					unsigned int Quant_C=0, unsigned int Quant_D=0);

	// data fields
	unsigned int Quant_A, Quant_B, Quant_C, Quant_D;
	double profit_A, profit_B, profit_C, profit_D;
	double profit;
} simulator;


class orderEvent : public event {
public:
    orderEvent(unsigned int t, unsigned int q_a,
               unsigned int q_b, unsigned int q_c,
               unsigned int q_d) : event(t) {
        quant_a = q_a;
        quant_b = q_b;
        quant_c = q_c;
        quant_d = q_d;
    }

    virtual void processEvent();

    // data fields
    unsigned int quant_a, quant_b, quant_c, quant_d;
};

class refillEvent : public event {
public:
    refillEvent(unsigned int t, unsigned int q_a,
                unsigned int q_b, unsigned int q_c,
                unsigned int q_d) : event(t) {
        refill_quant_a = q_a;
        refill_quant_b = q_b;
        refill_quant_c = q_c;
        refill_quant_d = q_d;
    }

    virtual void processEvent();

    // data fields
    unsigned int refill_quant_a, refill_quant_b, refill_quant_c, refill_quant_d;
};

void
vendingMachineSimulation::order(unsigned int q_a, unsigned int q_b,
                               unsigned int q_c, unsigned int q_d) {
    cout << "vendingMachineSimulation::order is simulated at time: " << time << endl;
    bool need_reoder_a = false; // this flag if set, would reschedule the order event
                                // if all the items are not satisfied
    bool need_reoder_b = false;
    bool need_reoder_c = false;
    bool need_reoder_d = false;

    if(Quant_A >= q_a) {
        Quant_A = Quant_A - q_a;
        profit += q_a * profit_A;
    }
    else {
        need_reoder_a = true;
    }

    if(Quant_B >= q_b) {
        Quant_B = Quant_B - q_b;
        profit += q_b * profit_B;
    }
    else {
    	need_reoder_b = true;
    }

    if(Quant_C >= q_c) {
        Quant_C = Quant_C - q_c;
        profit += q_c * profit_C;
    }
    else {
    	need_reoder_c = true;
    }

    if(Quant_D >= q_d) {
        Quant_D = Quant_D - q_d;
        profit += q_d * profit_D;
    }
    else {
    	need_reoder_d = true;
    }

    cout << "Updated values of Quantity is: Quantity-A: " << Quant_A
    << " Quantity-B: " << Quant_B << " Quantity-C: " << Quant_C << " Quantity-D: " << Quant_D << endl;
    cout << "Total profit earned: " << profit << "$ at time: " << time << endl;

    if (need_reoder_a || need_reoder_b || need_reoder_c || need_reoder_d) {
        // the flag when set should refill the vending machine appropriately
        cout << "Rescheduling the refill event in next cycle as we ran out of the items!!" << endl;
        /*Caution: For this to work as intended, the eventQueue should be static for the base-class*/
        int schedule_time = time + 2;
        this->scheduleEvent(new refillEvent(schedule_time, (need_reoder_a ? q_a : 0),
                                            (need_reoder_b ? q_b : 0),
                                            (need_reoder_c ? q_c : 0),
                                            (need_reoder_d ? q_d : 0)));

        // then order the vending machine in next cycle.
        cout << "Refilled the vending machine! Now completing the order in next to next cycle" << endl;
        schedule_time = time + 4;
        this->scheduleEvent(new orderEvent(schedule_time, (need_reoder_a ? q_a : 0),
                                           (need_reoder_b ? q_b : 0),
                                           (need_reoder_c ? q_c : 0),
                                           (need_reoder_d ? q_d : 0)));
    }
}

void
vendingMachineSimulation::refill(unsigned int q_a, unsigned int q_b,
                               unsigned int q_c, unsigned int q_d) {
    cout << "vendingMachineSimulation::refill is simulated at time: " << time << endl;

    Quant_A = Quant_A + q_a;
        // profit += q_a * profit_A;


    Quant_B = Quant_B + q_b;
        // profit += q_b * profit_B;


    Quant_C = Quant_C + q_c;
        // profit += q_c * profit_C;


    Quant_D = Quant_D + q_d;
        // profit += q_d * profit_D;


    cout << "Updated values of Quantity is: Quantity-A: " << Quant_A
    << " Quantity-B: " << Quant_B << " Quantity-C: " << Quant_C << " Quantity-D: " << Quant_D << endl;
    cout << "Total profit earned: " << profit << "$ at time: " << time << endl;
}


void orderEvent::processEvent() {
	cout << "orderEvent is processed at time: " << time << endl;
	simulator.order(quant_a, quant_b, quant_c, quant_d);
}


void refillEvent::processEvent() {
	cout << "refillEvent is processed at time: " << time << endl;
	simulator.refill(refill_quant_a, refill_quant_b, refill_quant_c, refill_quant_d);
}

int main(int argc, char const *argv[]) {

	// pump the event in the event queue (out-of-order)
	vendingMachineSimulation * simulator = new vendingMachineSimulation();
	simulator->scheduleEvent(new orderEvent(5/*time*/, 3/*quantity-a*/, 1/*quantity-b*/, 2/*quantity-c*/, 1/*quantity-d*/));
    simulator->scheduleEvent(new orderEvent(1/*time*/, 3, 1, 2, 1));
    simulator->scheduleEvent(new orderEvent(2/*time*/, 3, 1, 2, 1));
    simulator->scheduleEvent(new orderEvent(3/*time*/, 3, 1, 2, 1));
    simulator->scheduleEvent(new orderEvent(4/*time*/, 3, 1, 2, 1));
	simulator->scheduleEvent(new orderEvent(7/*time*/, 3, 1, 2, 1));

    // Now we don't need this  function as machine will refill itself to satisfy the order... but just in case...
	// fill the vending machine (to complete the simulation faster)
	simulator->scheduleEvent(new refillEvent(6/*time*/, 3, 1, 2, 1));

	// run  the simulation
	simulator->run();

	delete simulator;
	return 0;
}