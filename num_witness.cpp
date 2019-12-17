//
// Created by Mayank Parasar on 2019-12-17.
//

/*
 * There are n people lined up, and each have a height represented as an integer.
 * A murder has happened right in front of them, and only people who are taller than everyone in front of them
 * are able to see what has happened. How many witnesses are there?
 * Input: [3, 6, 3, 4, 1]
 * */

#include <iostream>
#include <vector>

using namespace std;

int num_witness(vector<int> vect) {
    // vector<int> witness;
    int num_witness = 0;
    vector<int>::iterator itr = vect.begin();
    for(int i = 0; i < vect.size(); i++) {
        /*
        for(int k = 0; k < i; k ++) {
            if(vect[k] <= )
        }
        */
        // cout << *(vect.begin()+i) << endl;
        // cout << *max_element(vect.begin(), ++itr) << endl;
        if( vect.begin()+i == max_element(vect.begin(), ++itr)) {
            num_witness++;
        }
    }

    return num_witness;
}


int main() {

//    vector<int> height = {3, 6, 3, 4, 1};
    vector<int> height = {1, 4, 3, 6, 3};
    cout << num_witness(height);
    return 0;
}