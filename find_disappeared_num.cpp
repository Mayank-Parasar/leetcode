//
// Created by Mayank Parasar on 2020-02-17.
//

/*
 * Given an array of integers of size n, where all elements are between 1 and n inclusive,
 * find all of the elements of [1, n] that do not appear in the array. Some numbers may appear more than once.
 *
 * Example:
 * Input: [4,5,2,6,8,2,1,5]
 * Output: [3,7]
*/

#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int>& arr) {
    int min;
    int idx;
    for(int ii = 0; ii < arr.size(); ii++) {
        min = arr[ii];
        idx = ii;
        for(int kk = ii; kk < arr.size(); kk++) {
            if(arr[kk] < min) {
                min = arr[kk];
                idx = kk;
            }
        }
        swap(arr[ii], arr[idx]);
    }

}

void sort_2(vector<int>& arr) {
    bool flag = true;

    while(flag) {
        flag = false;
        for(int ii=0; ii < arr.size() - 1; ii++) {
            if(arr[ii] > arr[ii+1]) {
                swap(arr[ii], arr[ii+1]);
                flag = true;
            }
        }
    }
}

vector<int> missing_num(vector<int> a) {
    vector<int> result;

    for(int ii = 0; ii < a.size()-1; ii++) {
        if( (a[ii+1] == a[ii] + 1) ||
            (a[ii+1] == a[ii])) {
            continue;
        }
        else{

            a[ii] = a[ii] + 1;
            result.push_back(a[ii]);
            ii--; // do not increment the ii
        }
    }

    return result;
}

int main () {

    vector<int> arr = {4,5,2,6,8,2,1,5};

    sort_2(arr);
    for(auto i : arr) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> result = missing_num(arr);

    for(auto i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}