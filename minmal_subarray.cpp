//
// Created by Mayank Parasar on 2019-12-18.
//

/*
 * Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray
 * of which the sum ≥ s. If there isn't one, return 0 instead.
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
*/

#include <iostream>
#include <vector>

using namespace std;

int minimal_contiguous_arrray(vector<int>& nums, int sum) {
    vector<int> len;
    int accum= 0;
    for(int i = 0; i < nums.size(); i++) {
        for(int k = i; k < nums.size(); k++) {
            accum+=nums[k];
            if(accum >= sum) {
                // put the length into the vector and break
                int length = (k-i + 1);
                len.push_back(length);
                break;
            }
        }
        // reset accum
        accum = 0;
    }
    return (*min_element(len.begin(), len.end()));
}

int main() {

    vector<int> num = {2, 3, 1, 2, 4, 3};
    cout << minimal_contiguous_arrray(num, 7);
    return 0;
}