//
// Created by Mayank Parasar on 2020-03-16.
//
/*
Find the Minimum length Unsorted Subarray, sorting which makes the complete array sorted
Given an unsorted array arr[0..n-1] of size n, find the minimum length subarray arr[s..e] such that sorting this subarray makes the whole array sorted.

Examples:
1) If the input array is [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60], your program should be able to find that the subarray lies between the indexes 3 and 8.

*/

#include <iostream>
#include <vector>

using namespace std;

pair<int, int> scanVec(vector<int> v) {

    pair<int, int> result_vec;
    int s, e;
    for(vector<int>::iterator it = v.begin(); it != v.end()-1; it++) {
        cout << *it << " ";
        if(*it > *(it+1)) {
            s = it - v.begin() + 1;
            break;
        }
    }

    cout << endl;

    for(vector<int>::iterator it = v.end()-1; it > v.begin(); it--) {
        cout << *it << " ";
        if(*it < *(it-1)) {
            e = it - v.begin() - 1;
            break;
        }
    }

    cout << endl;

    cout << "s: " << s;
    cout << " e: " << e;
    cout << endl;

    int min, max;

    max = v[s];
    min = v[e];
    // find min and max within v[s] -- v[e]
    for(int ii = s; ii <= e; ii++) {
        if(v[ii] < min){
            min = v[ii];
        }
        if(v[ii] > max) {
            max = v[ii];
        }
    }
    cout << "min: " << min << endl;
    cout << "max: " << max << endl;
    for(int ii = 0; ii < s; ii++) {
        if(v[ii] > min) {
            s = ii;
            break;
        }
    }

    for(int ii = (int)v.size()-1; ii > e; ii--) {
        if(v[ii] < max) {
            e = ii;
            break;
        }
    }
    cout << "s: " << s;
    cout << " e: " << e;
    cout << endl;
    result_vec.first = s;
    result_vec.second = e;

    return result_vec;
}


int main() {

    vector<int> vec = { 10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60 };
    pair<int, int> result = scanVec(vec);

    return 0;
}
