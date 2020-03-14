//
// Created by Mayank Parasar on 2020-03-14.
//

/*
A fixed point in a list is where the value is equal to its index. So for example the list [-5, 1, 3, 4],
 1 is a fixed point in the list since the index and value is the same. Find a fixed point (there can be many,
 just return 1) in a sorted list of distinct elements, or return None if it doesn't exist.

Here is a starting point:

def find_fixed_point(nums):
  # Fill this in.

print find_fixed_point([-5, 1, 3, 4])
# 1
*/

#include<iostream>
#include<vector>

using namespace std;

// this works with both sorted and unsorted
int brute_force(const vector<int>& vec) {

    for(int ii = 0; ii < (int)vec.size(); ii++){
        if(ii == vec[ii])
            return (ii);
    }

    return (-1);

}

// optimization for sorted list of distinct elements,
int optimized_search(const vector<int>& vec) {
    // assuming vector is sorted in acending order...
    for(int ii = 0; ii < (int)vec.size(); ii++){
        if(vec[ii] > ii) {
            return -1; // short-circuit logic
        }
        else if (vec[ii] < ii) {
            continue;
        }
        else if (vec[ii] == ii) {
            return (ii);
        }
    }
    return (-1);
}

int main() {

    vector<int> vec = {-5, 1, 3, 4};

    if(brute_force(vec) == -1) {
        cout << "None";
    }
    else {
        cout << brute_force(vec) << endl;
    }
    //////////////////////
    vector<int> new_vec = {5, 6, 7, 8};
    if(optimized_search(new_vec) == -1) {
        cout << "None";
    }
    else {
        cout << optimized_search(new_vec) << endl;
    }

    return 0;
}