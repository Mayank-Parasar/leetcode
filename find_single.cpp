//
// Created by Mayank Parasar on 2020-02-02.
//

/*
 * Given an array of integers, arr, where all numbers occur twice except one number which occurs once,
 * find the number. Your solution should ideally be O(n) time and use constant extra space.
Example:
Input: arr = [7, 3, 5, 5, 4, 3, 4, 8, 8]
Output: 7

 */

#include <iostream>
#include <vector>

using namespace std;

int findSingle(vector<int>& arr, vector<int>& v, int min) {

    for(auto i : arr) {
        if(v[i-min] == -1)
            v[i-min] = i;
        else
            v[i-min] = -1;
    }

    // now traverse the v-vector and return the first non '-1' number.

    for(auto i : v){
        if(i != -1)
            return i;
    }

}

int main() {

    vector<int> arr = {7, 3, 5, 5, 4, 3, 4, 8, 8};
    // considering we know the min and max of this array
    // sparsity of number can be dealth with another level
    // of indirection.
    vector<int> v(6, -1); // '3' maps to 0 and '8' maps to 5 index

    cout << findSingle(arr, v, 3);

    return 0;
}