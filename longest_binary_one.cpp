//
// Created by Mayank Parasar on 2020-02-26.
//

/*
 * Return the longest run of 1s for a given integer n's binary representation.
 * Example:
Input: 242
Output: 4
242 in binary is 0b11110010, so the longest run of 1 is 4.
 * */

#include <iostream>
#include <deque>

using namespace std;

deque<int> return_binary(int num) {
    deque<int> binary;
    while( num > 0) {
        binary.push_front(num % 2);
        num = num / 2;
    }

    return binary;
}

int longest_run(deque<int> const &binary) {
    int cntr = 0;
    int max_cntr = 0;
    for(auto i : binary) {
        if( i == 1) {
            cntr++;
            if(cntr > max_cntr)
                max_cntr = cntr;
        }
        else {
            cntr = 0;
        }
    }
    return max_cntr;
}

int main() {

    int num = 242;
    deque<int> binary = return_binary(num);

    for(auto i : binary)
        cout << i;

    cout << endl;

    // cont the longest run of 1s in this binary
    cout << longest_run(binary);

    return 0;
}