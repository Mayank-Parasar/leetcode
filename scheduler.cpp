//
// Created by Mayank Parasar on 2020-01-18.
//

/*
 * Design a scheduler
 * input: [1,1,2,1,1]; window: 2
 * output: (1--12-1--1)
 * input: [1,1,2,3,1]; window: 2
 * output: (1--1231)
 * */

#include <iostream>
#include <vector>
#include <deque>
#include <assert.h>

using namespace std;

vector<int> scheduler(vector<int> task_queue, int window) {
    vector<int> schedule;
    deque<int> win (window, -1);

    for(int ii= 0; ii < task_queue.size(); ii++) {
        // search within the window
        int kk;
        for(kk = 0; kk < win.size(); kk++) {
            if(task_queue[ii] == win[kk]) {
                schedule.push_back(-1);
                win.pop_front();
                win.push_back(-1);
                ii--; // so as to retry
                break;
            }

        }
        if(kk == win.size()) {
            schedule.push_back(task_queue[ii]);
            win.pop_front();
            win.push_back(task_queue[ii]);
        }

        assert(win.size() == window);

        // print out the schedule-list for each iteration.
//        for(auto i : schedule)
//            cout << i << " ";
//
//        cout << endl;
    }

    return(schedule);
}

int main() {

    // vector<int> task_queue = {1,1,2,1,1};
    vector<int> task_queue = {1,1,2,3,1};
    int window = 2;

    vector<int> schedule = scheduler(task_queue, window);

    for(auto i : schedule) {
        if (i == -1)
            cout << "-";
        else
            cout << i;
    }

    return 0;
}