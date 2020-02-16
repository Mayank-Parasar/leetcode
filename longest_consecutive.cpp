//
// Created by Mayank Parasar on 2020-02-13.
//
/*
 * You are given an array of integers. Return the length of the longest consecutive elements sequence in the array.

For example, the input array [100, 4, 200, 1, 3, 2] has the longest consecutive sequence 1, 2, 3, 4,
 and thus, you should return its length, 4.

def longest_consecutive(nums):
  # Fill this in.

print longest_consecutive([100, 4, 200, 1, 3, 2])
# 4
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>


using namespace std;

void sort_arr(vector<int>& arr) {
    int min = 9999;
    int idx = -1;
    int ii;
    for(ii = 0; ii < arr.size(); ii++) {
        min = arr[ii];
        idx = ii;
        int kk;
        for(kk = ii; kk < arr.size(); kk++) {
            // find the minimum element
            if(min > arr[kk]) {
                min = arr[kk];
                idx = kk;
            }
        }
        // swap the minimum element and put it at 'ii' position
        swap(arr[ii], arr[idx]);
    }
}

map<int, vector<int>> find_consecutive(vector<int> arr) {
    map<int, vector<int>> consecutive_elem;
    int map_key=arr[0];

    consecutive_elem[map_key].push_back(arr[0]);


    for(int ii = 1; ii < arr.size(); ii++) {
        if(arr[ii] == arr[ii-1]+1) {
            consecutive_elem[map_key].push_back(arr[ii]);
        }
        else {
            map_key = arr[ii];
            consecutive_elem[map_key].push_back(arr[ii]);
        }
    }

    return consecutive_elem;
}

int main() {

    vector<int> arr={100, 4, 200, 1, 3, 2};

    sort_arr(arr);

    for(auto i : arr)
        cout << i << " ";

    cout << endl;


    // vector is now sorted.
    // now count the number of consecutive elements.
    map<int, vector<int>> num_consecutive = find_consecutive(arr);



    int max = -1;
    int count = 0;
    for(auto i : num_consecutive) {
        // cout << i.first << " :: ";
        for (auto k : i.second) {
            // cout << k << " " ;
            count++;
        }
        // cout << "   size: " << i.second.size();
        cout << endl;
        if(count > max)
            max = i.second.size();
        count = 0; // reset
    }


    cout << max << endl;

    return 0;
}