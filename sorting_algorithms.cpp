//
// Created by Mayank Parasar on 2020-01-11.
//

/*
 * This file will contain various sorting algorithms
 * */

#include <iostream>
#include <vector>

using namespace std;

vector<int> selection_sort(vector<int> a) { // deliberately passed by value so as not to modify the original array

    for(int ii= 0; ii < a.size(); ii++) {
        for(int kk=ii+1; kk < a.size(); kk++) {
            if(a[ii] > a[kk])
                swap(a[ii], a[kk]);
        }
    }

    return a;
}

vector<int> bubble_sort(vector<int> a) {
    // end condition is the pass where there is no swap
    bool swaped = true;
    int num_pass = 0;
    while(swaped) {
        num_pass++;
        // do the bubble sort
        // reset the swap here
        swaped = false; // end condition
        for(int ii = 0; ii < a.size() - 1; ii++) {
            if(a[ii] > a[ii+1]) {
                swap(a[ii], a[ii+1]);
                swaped = true;
            }
        }
    }
    cout << "num_pass: " << num_pass << endl;
    return a;
}

int main() {

    vector<int> a = {2, 5, 1, 7, 9, 3, 6, 8, 5};
    vector<int> b = {1, 2, 3, 4, 5, 6, 7};

    vector<int> selection_sorted = selection_sort(a);
    vector<int> bubble_sorted = bubble_sort(a);

    cout << "Original vector" << endl;
    for(auto  i: a)
        cout << i << " ";

    cout << endl;

    cout << "Output from selection-sort" << endl;

    for(auto i : selection_sorted)
        cout << i << " ";

    cout << endl;

    cout << "Output from bubble-sort" << endl;

    for(auto i : bubble_sorted)
        cout << i << " ";

    return 0;
}