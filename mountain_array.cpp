//
// Created by Mayank Parasar on 2020-01-13.
//

/*
 * You may recall that an array A is a mountain array if and only if:

A.length >= 3
There exists some i with 0 < i < A.length - 1 such that:
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target.
If such an index doesn't exist, return -1.
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> indx;

int binary_search(vector<int>& arr, int elem, int start, int end) {

    int mid = (start + end)/2;
    // base condition
    if(elem == arr[mid]) {
        return mid;
    }
    else if(mid >= end ||
        mid <= start) {
        // we could't find the element;
        // return -1;
        return -1;
    }



    if(elem > arr[mid]) {
        start = mid;
        return (binary_search(arr, elem, start, end));
    }
    else if (elem < arr[mid]) {
        end = mid;
        return(binary_search(arr, elem, start, end));
    }

    assert(0);
    return mid;
    // return -1;
}


int main() {

    vector<int> arr = {2, 4, 6, 8, 10, 12, 14};
    vector<int> arr1 = {1,2,3,4,5,3,1};
    vector<int> arr2 = {0,1,2,4,2,1};

    cout << " result from first search: " << binary_search(arr, 5, 0, (arr.size() - 1));
    cout << endl;
    // do the pre-processing of the mountain array here.
    vector<int> sub_array1;
    vector<int> sub_array2;

    for(int ii = 1; ii < arr1.size(); ii++) {
        if(arr1[ii-1] < arr1[ii]) {
            sub_array1.push_back(arr1[ii-1]);
            if(ii == (arr1.size() - 1))
                sub_array1.push_back(arr1[ii]);
        }
        else if(arr1[ii-1] > arr1[ii]) {
            sub_array2.push_back(arr1[ii-1]);

            if(ii == (arr1.size()-1))
                sub_array2.push_back(arr1[ii]);
        }
    }

    int indx1 = binary_search(sub_array1, 3, 0, (sub_array1.size() - 1));
    int indx2 = binary_search(sub_array2, 3, 0, (sub_array2.size() - 1));

    cout << "First index: " << indx1 << endl;
    cout << "Second index: " << indx2 << endl;



    return 0;
}