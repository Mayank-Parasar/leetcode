//
// Created by Mayank Parasar on 2020-04-06.
//

/*
 *
    Problem: Given a K-sorted array, finish sorting it

    Example: [4, 5, 2, 1, 6, 3]

    This is a k-sorted array where k=3

    Expected out: [1,2,3,4,5,6]

 * */

#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

vector<int> k_sort(vector<int> vec, int k) {
    assert(vec.size() > k);
    int start = 0;
    int end = start+k;
    unsigned int min, index;
    while((start < end) && (end <= vec.size() - 1)) {
        min = -1;
        index = -1;
        for(int ii = start; ii <= end; ii++) { // use segment tree to find min in O(log(n)) time
            if(vec[ii] < min) {
                min = vec[ii];
                index = ii;
            }
        }
        swap(vec[start], vec[index]);

        if(end == vec.size() - 1) {
            end = (vec.size() - 1);
            start++;
        }
        else {
            end++;
            start++;
        }
    }
    return vec;
}

int main () {

    vector<int> vec = {4, 5, 2, 1, 6, 3};
    int window = 3;
    vector<int> vec2 = {6, 7, 4, 3, 8, 5};
    vector<int> vec3 = {1, 2, 3, 4, 5, 6};
    vector<int> vec4 = {2, 1, 3, 4};


    vector<int> result = k_sort(vec4, window);

    for(auto i : result) {
        cout << i << " ";
    }

    return 0;
}

