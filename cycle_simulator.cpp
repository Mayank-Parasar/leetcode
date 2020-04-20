//
// Created by Mayank Parasar on 2020-04-12.
//

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {

    srand(time(0));
    pair<int, int> router_cycle;  // { '--routers--'; '--cycle number--' }
    int num_bufferless_router = 1;
    router_cycle.first = num_bufferless_router; // allowing at most 5 routers to make packet bufferless
    router_cycle.second = 0; // Cycle ID
    for(int ii=0; ii < 1000; ii += (rand()%10)) {
        cout << "Cycle: " << ii << "\t";
        if ((router_cycle.second == ii) && (router_cycle.first > 0)) {
            router_cycle.first--;
        }
        else {
            // refill
            router_cycle.first = num_bufferless_router;
            router_cycle.second = ii;
        }
        cout << "{ " << router_cycle.first << " : " << router_cycle.second << " }" << endl;
    }

    return 0;
}