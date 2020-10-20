//
// Created by Mayank Parasar on 2020-05-17.
//
/*
 * Given a list of numbers and a target number n, find 3 numbers in the list that sums closest to the target number n.
 * There may be multiple ways of creating the sum closest to the target number, you can return any combination
 * in any order.

Here's an example and some starter code.

def closest_3sum(nums, target):
  # Fill this in.

print(closest_3sum([2, 1, -5, 4], -1))
# Closest sum is -5+1+2 = -2 OR -5+1+4 = 0
# print [-5, 1, 2]
*/


#include <iostream>
#include <vector>

using namespace std;

vector<int> nums = {2, 1, -5, 4};
void print_combinations_new(vector<vector<int> >& ans,
                         vector<int>& tmp, int n, int left, int k) {
    if(k == 0) {
        ans.push_back(tmp);
        return;
    }

    // i iterates from left to n-1. First time
    // left will be 0
    for(int i = left; i < n; ++i) {
        tmp.push_back(nums[i]);
        print_combinations_new(ans, tmp, n,i+1, k-1);

        // popping out last inserted element from the vector
        tmp.pop_back();
    }
}


int main() {



    vector<vector<int>> result;
    vector<int> tmp;
    int size = 3;
    int start = 0;
    print_combinations_new(result, tmp, nums.size(), start, size);

    // this is the final dara structure:
    vector<pair<vector<int>, int>> vector_sum;

    for(auto i : result) {
        int sum = 0;
        for(auto k : i) {
            sum += k;
            // cout << k << " ";
        }
        vector_sum.push_back(make_pair(i, sum));
        // cout << endl;
    }

    int closest_sum = -1; // set this to find the closest sum
    uint32_t min = -1;
    vector<int> min_vector;
    for(auto i : vector_sum) {
        if(abs(i.second-closest_sum) < min) {
            min = abs(i.second-closest_sum);
            min_vector = i.first;
        }
    }

    cout << "Minimum vector is:" << endl;

    for(auto i : min_vector)
        cout << i << " ";
    cout << endl;

    return 0;
}