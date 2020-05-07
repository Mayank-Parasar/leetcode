//
// Created by Mayank Parasar on 2020-05-06.
//

/*
 * Hi, here's your problem today. This problem was recently asked by AirBNB:

Given a list of sorted numbers, and two integers k and x, find k closest numbers to the pivot x.

Here's an example and some starter code:

def closest_nums(nums, k, x):
 # Fill this in.

print(closest_nums([1, 3, 7, 8, 9], 3, 5))
# [7, 3, 8]
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> k_closest_neighbours(vector<int> arr, int k, int x) {
    vector<int> result;
    for(auto i : arr) {
        if( result.size() < k) {
            result.push_back(i);
        }
        else {

            int max_diff = -1;
            int curr_diff;
            int idx;
            for(int ii = 0; ii < result.size(); ii++) {
                curr_diff = abs(result[ii] - x);
                if((curr_diff > max_diff)) {
                    max_diff = curr_diff;
                    idx = ii;
                }
            }

            if(max_diff > abs(x-i)) {
                result[idx] = i;
            }
        }
    }

    return result;
}

int main() {
    vector<int> arr = {1, 3, 7, 8, 9};  // given that this array is sorted
//    vector<int> arr1 = {6, 7, 8, 9, 5};
    int k = 3;
    int x = -1;

    vector<int> result = k_closest_neighbours(arr, k, x);

    for(auto i : result)
        cout << i << " ";
}