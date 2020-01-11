//
// Created by Mayank Parasar on 2020-01-11.
//
/*
 * Given an array, nums, of n integers, find all unique triplets (three numbers, a, b, & c) in nums
 * such that a + b + c = 0. Note that there may not be any triplets that sum to zero in nums,
 * and that the triplets must not be duplicates.

Example:
Input: nums = [0, -1, 2, -3, 1]
Output: [0, -1, 1], [2, -3, 1]

 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, vector<int>> triplets;

// this function populates the global 'triplets' map
void find_triplets(const vector<int>& nums) {
    int index = 0;
    for(int ii = 0; ii < nums.size(); ii++) {
        for(int jj=ii+1; jj < nums.size(); jj++) {
            for(int kk = jj+1; kk < nums.size(); kk++) {
                if((nums[ii] + nums[jj] + nums[kk]) == 0) {
                    // add it to the map
                    triplets[index++] = {nums[ii], nums[jj], nums[kk]};
                }
            }
        }
    }

}

int main() {

    vector<int> nums = {0, -1, 2, -3, 1};

    find_triplets(nums);

    for(auto i : triplets) {
        for(auto k : i.second) {
            cout << k << " ";
        }
        cout << endl;
    }

    return 0;
}