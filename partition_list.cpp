//
// Created by Mayank Parasar on 2020-04-02.
//
/*
Given a list of numbers and an integer k, partition/sort the list such that the all numbers less than k occur before k,
 and all numbers greater than k occur after the number k.

def partition_list(nums, k):
  # Fill this in.

print(partition_list([2, 2, 2, 5, 2, 2, 2, 2, 5], 3))
# [2, 2, 2, 2, 2, 2, 2, 2, 5]
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> sort(vector<int> vec) {

    bool swap_ = true;
    while(swap_) {
        swap_ = false;
        for(int ii = 0; ii < vec.size()-1; ii++) {
            if(vec[ii] > vec[ii+1]) {
                swap(vec[ii], vec[ii+1]);
                swap_ = true;
            }
        }
    }

    return (vec);
}

vector<int> partition(vector<int> vec, int k) {
    vector<int> partition_1;
    vector<int> partition_2;

    for(int ii=0; ii< vec.size(); ii++) {
        if(vec[ii] < k) {
            partition_1.push_back(vec[ii]);
        }
        else {
            partition_2.push_back(vec[ii]);
        }
    }

    partition_1 = sort(partition_1);
    partition_2 = sort(partition_2);

    vector<int> result;
    result.reserve(partition_1.size() + partition_2.size());
    result.insert(result.end(), partition_1.begin(), partition_1.end());
    result.insert(result.end(), partition_2.begin(), partition_2.end());

    return result;
}

int  main() {

     vector<int> vec = {2, 2, 2, 5, 2, 2, 2, 2, 5};
//    vector<int> vec = {40, 55, 63, 17, 22, 68, 89, 97, 89};
     int k = 3;
//    int k = 70;

    vector<int> result = partition(vec, k);

    for(auto i : result) {
        cout << i << " ";
    }

    return 0;
}
