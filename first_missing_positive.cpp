//
// Created by Mayank Parasar on 2019-12-29.
//

/*
 * You are given an array of integers. Return the smallest positive integer that is not present in the array.
 * The array may contain duplicate entries.
 * For example, the input [3, 4, -1, 1] should return 2 because it is the smallest positive integer
 * that doesn't exist in the array.
 * */

#include <iostream>
#include <vector>

using namespace std;

int first_missing_positive(vector<int>& nums) {
    int elem = *max_element(nums.begin(), nums.end()) + 1; // max
    // or
    // int elem = 9999999999; // theoretical max
    for(auto i : nums) {
        if(i > 1) {
            if (elem >= i) {
                elem = i - 1;
            }
        }
    }
    if (elem == *max_element(nums.begin(), nums.end()) + 1)
        return -1;
    else
        return(elem);
}

int main() {

    vector<int> nums = {3, 4, 2, -1, 1};
    // vector<int> nums = {-3, -4, -1, -1};

    int result = first_missing_positive(nums);
    if(result == -1)
        cout << "No smallest positive integer present";
    else
        cout << first_missing_positive(nums);

    return 0;
}