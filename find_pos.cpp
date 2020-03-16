//
// Created by Mayank Parasar on 2020-03-16.
//

/*
Find index of first occurrence when an unsorted array is sorted
Given an unsorted array and a number x, find index of first occurrence of x when we sort the array. If x is not present, print -1.

Examples:

Input : arr[] = {10, 30, 20, 50, 20}
           x = 20
Output : 1
Sorted array is {10, 20, 20, 30, 50}

Input : arr[] = {10, 30, 20, 50, 20}
           x = 50
Output : -1
50 is not present in array.

*/

#include <iostream>
#include <vector>

using namespace std;

int find_pos(vector<int> v, int elem) {
    int pos = -1;
    // check if element is present in the array
    int kk;
    for(kk = 0; kk < (int)v.size(); kk++) {
        if (v[kk] == elem)
            break;
    }
    if (kk == (int)v.size())
        return pos;

    int counter = 0;
    for(int ii = 0; ii < (int)v.size(); ii++) {
        if(v[ii] < elem) {
            counter++;
        }
    }

    // cout << "counter: " << counter << endl;
    if(counter)
        pos = counter;

    return pos;
}

int main() {

    vector<int> vec = { 10, 30, 20, 50, 20 };
    int x = 20;
    cout << find_pos(vec, x);
    cout << endl;
    vec = { 10, 30, 20, 50, 20 };
    x = 50;
    cout << find_pos(vec, x);
    cout << endl;

    vec = { 10, 30, 20, 50, 20 };
    x = 60;
    cout << find_pos(vec, x);
    cout << endl;
    return 0;
}