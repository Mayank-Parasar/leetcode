//
// Created by Mayank Parasar on 2020-03-06.
//

/*
 * You are given a list of n numbers, where every number is at most k indexes away from its properly sorted index.
 * Write a sorting algorithm (that will be given the number k) for this list that can solve this in O(n log k)

Example:
Input: [3, 2, 6, 5, 4], k=2
Output: [2, 3, 4, 5, 6]
As seen above, every number is at most 2 indexes away from its proper sorted index.
*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int> sort_partial_array(vector<int> vec, int k) {
    // this will sort the 0 to k array inside 'pq'
    priority_queue<int, vector<int>, greater<int>>pq(vec.begin(), vec.begin() + k+1);
    int index = 0;
    // this for-loop will sort the 0 to n-k element in the vec
    for(int i = k+1; i < vec.size(); i++) {
        vec[index++] = pq.top();
        pq.pop();
        pq.push(vec[i]);
    }
    // insert the last k sorted elements in the vector
    while(!pq.empty()) {
        vec[index++] = pq.top();
        pq.pop();
    }


    return(vec);
}


int main() {

    vector<int> v = {3, 2, 6, 5, 4};
    int k = 2;
    vector<int> result;

    result = sort_partial_array(v, k);

    for(auto i : result)
        cout << i << " ";

    return 0;
}