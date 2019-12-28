//
// Created by Mayank Parasar on 2019-12-28.
//

/*
 * A look-and-say sequence is defined as the integer sequence beginning with a single digit
 * in which the next term is obtained by describing the previous term. An example is easier to understand:

Each consecutive value describes the prior value.

1      #
11     # one 1's
21     # two 1's
1211   # one 2, and one 1.
111221 # #one 1, one 2, and two 1's.

Your task is, return the nth term of this sequence.
 * */

#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

vector<int> look_and_say(vector<int>& vect) {
    assert(vect.size() >= 1);

    vector<int> next_term;
    int counter=1; // this is the 0th term
    int ii=0; // iterator for vect
    bool counted = false;
    while(ii < vect.size()) {

        if(ii == (vect.size() - 1)) {
            // this is the return condition
            // if next_term is not populated before
            // populate it and return
            if(counted == false) {
                // assert(counter == 0);
                next_term.push_back(1); // this is a new term at the end
                next_term.push_back(vect[ii]);
            }
            return (next_term);
        }
        else if(vect[ii] == vect[ii + 1]) {

            counter++;
            if(ii+1 == (vect.size() - 1)) {
                counted = true;
                next_term.push_back(counter);
                next_term.push_back(vect[ii]);
            }
        }
        else {
            // push the counter and then the vect[ii]
            // into the next term
            next_term.push_back(counter);
            next_term.push_back(vect[ii]);
            counter = 1; // reset the counter
        }
        ii++; // increment counter.
    }
    // control will never reach here
    assert(0);
    return(next_term); // this is to make compiler happy!
}

int main() {

    vector<int> vect = {1};
    // vector<int> nth_term;
    for(int kk=0; kk < 5; kk++) {
        vect = look_and_say(vect);

        for(auto i : vect)
            cout << i;

        cout << endl;
    }
    cout << "Nth term in the sequence is: ";
    for(auto i : vect)
        cout << i;

    return 0;
}