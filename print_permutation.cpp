//
// Created by Mayank Parasar on 2020-02-09.
//

/*
 * Given a vector print all the permutations of that vector
 *
 * */

#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int>& v) {
    for(auto i : v)
        cout << i << " ";
    cout <<endl;
}

void permutate(vector<int>& v, int l, int r) {
    if(l == r) {
        print_vector(v);
    }
    else {
        for(int ii = l; ii <= r; ii++) {
            swap(v[l], v[ii]);
            permutate(v, l+1, r);
            swap(v[l], v[ii]);
        }
    }
}

int main() {

    vector<int> v = {1, 2, 3, 4, 5};

    permutate(v, 0, v.size()-1);

    return 0;
}