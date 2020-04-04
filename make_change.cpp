//
// Created by Mayank Parasar on 2020-04-04.
//

/*
Given a list of possible coins in cents, and an amount (in cents) n,
 return the minimum number of coins needed to create the amount n. If it is not possible to
 create the amount using the given coin denomination, return None.

Here's an example and some starter code:

def make_change(coins, n):
  # Fill this in.

print(make_change([1, 5, 10, 25], 36))
# 3 coins (25 + 10 + 1)
*/

#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> matrix;  // contains all the combinations that can form the given sum

void make_change(vector<int> change, int target_amt, int sum, vector<int> sum_vector) {
    if(sum > target_amt) {
        return;
    }
    else if (sum == target_amt) {
        matrix.push_back(sum_vector);
    }
    else {
        // do a bruteforce search;
        for(int ii = 0; ii < change.size(); ii++) {
            sum_vector.push_back(change[ii]);
            sum += change[ii];
            make_change(change, target_amt, sum, sum_vector);
            // undo change
            sum -= change[ii];
            sum_vector.pop_back();
        }

    }
    return;
}

int main() {
    vector<int> change = {1, 5, 10, 25};
    int target_amt = 36;

    int initial_sum = 0;
    vector<int> sum_vector;
    make_change(change, target_amt, initial_sum, sum_vector);

    int min_length = target_amt / *(min_element(change.begin(), change.end()));

    for(auto i : matrix) {
        if((int)i.size() < min_length)
            min_length = (int)i.size();
        // for(auto k : i) {
            // cout << k << " ";

        // }
        // cout << endl;
    }

    cout << min_length << " coins" << endl;

    return 0;
}