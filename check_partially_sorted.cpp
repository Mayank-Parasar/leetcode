//
// Created by Mayank Parasar on 2020-03-07.
//

/*
 * Check if the vector is partially sorted
 * */
#include<iostream>
#include<vector>

using namespace std;

vector<int>sort_func(vector<int> vec) {

    bool sort = true;

    while(sort) {
        sort = false;
        for(int ii = 0; ii < vec.size()-1; ii++) {
            if(vec[ii] > vec[ii + 1]){
                swap(vec[ii], vec[ii+1]);
                sort = true;
            }
        }
    }
    return vec;
}

// given a value return its index in the sorted array provided above
int binary_search(vector<int>&arr, int val, int start, int end) {
    int mid = (start + end) / 2;
    int retval = -1;
    if( mid > end ) {
        return (retval); // not found condition
    }else {
        if(arr[mid] == val){
            retval = mid;
            return retval;
        }
        else if(arr[mid] > val) {
            retval=binary_search(arr, val, start, mid - 1);
            return(retval);
        }
        else if(arr[mid] < val) {
            retval = binary_search(arr, val, mid+1, end);
            return(retval);
        }
    }
    return (retval);
}


int main() {

    vector<int> v = {3, 2, 6, 5, 4};
    vector<int> v_sorted = sort_func(v);
    int k = 2;
    cout << boolalpha;
    for(int ii = 0; ii < v.size(); ii++) {
        int kk = binary_search(v_sorted, v[ii], 0, v_sorted.size());
        assert(kk != -1);
        if( abs( ii - kk) < k+1)
            continue;
        else {
            cout << false;
            return 0;
        }
    }
    cout << true;


    return 0;
}