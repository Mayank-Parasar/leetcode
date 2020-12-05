//
// Created by Mayank Parasar on 2020-01-11.
//

/*
 * This file will contain various sorting algorithms
 * */

#include <iostream>
#include <vector>
#include <cstdlib>  // for random-number generator
#include <assert.h>

using namespace std;

template<typename T>
vector<T> selection_sort(vector<T> a) { // deliberately passed by value so
    // as not to modify the original array

    for(int ii= 0; ii < a.size(); ii++) {
        for(int kk=ii+1; kk < a.size(); kk++) {
            if(a[ii] > a[kk])
                swap(a[ii], a[kk]);
        }
    }

    return a;
}

template<typename T>
vector<T> bubble_sort(vector<T> a) {
    // end condition is the pass where there is no swap
    bool swapped = true;
    int num_pass = 0;
    while(swapped) {
        num_pass++;
        // do the bubble sort
        // reset the swap here
        swapped = false; // end condition
        for(int ii = 0; ii < a.size() - 1; ii++) {
            if(a[ii] > a[ii+1]) {
                swap(a[ii], a[ii+1]);
                swapped = true;
            }
        }
    }
    cout << "num_pass: " << num_pass << endl;
    return a;
}

template<typename T>
vector<T> insertion_sort(vector<T> a) {
    // starting from size = 1, check if the subarray is sorted
    // if not then insert the element at appropriate position
    // in the subarray.
    for(int ii=0; ii < a.size(); ii++) {
        for(int kk=0; kk <= ii; kk++) {
            // you  are always checking if the last element in the
            // sub array is sorted or not
            if(a[ii] < a[kk]) {
                //  this is the condition to reorder the array
                // sort this sub array by moving elements
                // from ii-1 --> kk by one position
                int tmp = a[ii];
                for(int jj = ii-1; jj>=kk; jj-- ) {
                    a[jj+1] = a[jj];
                }
                a[kk] = tmp;
            }
        }
    }
    return a;
}

template<typename T>
T partition(vector<T>& a, int low, int high) {
    int pivot = low + ( std::rand() % ( high - low + 1 ) );

    // cout << "low: " << low << " high: " << high << " pivot: " << pivot << endl;
    assert(pivot > low);

    // assert(pivot < high);

    int ii = low - 1; // this will keep track at what location (index)
                    // should pivot element be inserted
                    // such that left of it are all elements which are less than
                    // and right of it are all elements which are greater than

    for(int jj = low; jj <= high-1; jj++) {
        if(a[jj] < a[pivot]) {
            ii++;
            swap(a[ii], a[jj]);
        }
    }
    swap(a[ii+1], a[pivot]);
    return (ii + 1); // left of 'ii+1' are all less than element and right of 'ii+1' are all greater than element
}

// with randomized 'pivot'
template<typename T>
vector<T> quick_sort(vector<T>& a, int low, int high) { // need to pass by
    // reference for quick sort
    if(low < high) {

        int pivot_ = partition(a, low, high);

        // recursively call quick-sort
        quick_sort(a, low, pivot_ - 1);
        quick_sort(a, pivot_+1, high);
    }

    return a;
}

// merge the two sub array of a into a
// first sub-array is a[l ... m]
// second sub-array is a[m+1 ... r] 
void merge(vector<int>&a, int l, int m, int r) {

    vector<int>::const_iterator left = a.begin() + l;
    vector<int>::const_iterator middle = a.begin() + m;
    vector<int>::const_iterator right = a.begin() + r;

    vector<int> left_vector(left, middle+1); // copied the original vector slice
    vector<int> right_vector(middle+1, right+1); // copied the original vector slice

    // merge the sub-array into the original array a[l ... r]
    int ii = 0; // for left_vector
    int kk = 0; // for right_vector
    int jj = l; // for the original vector 'a'

    while(ii != (left_vector.size()) ||
        kk != (right_vector.size())) {

        if(ii == left_vector.size() &&
            kk <= right_vector.size() - 1) {
            a[jj] = right_vector[kk];
            jj++;
            if (kk <= right_vector.size() - 1)
                kk++;
        }
        else if(ii <= left_vector.size() - 1 &&
                kk == right_vector.size()) {
            a[jj] = left_vector[ii];
            jj++;
            if(ii <= left_vector.size() - 1)
                ii++;
        }
        else if(left_vector[ii] < right_vector[kk]) {
            a[jj] = left_vector[ii];
            jj++;
            if(ii <= left_vector.size() - 1)
                ii++;
        }
        else if(right_vector[kk] <= left_vector[ii]) {
            a[jj] = right_vector[kk];
            jj++;
            if(kk <= right_vector.size() - 1)
                kk++;
        }
        else
            assert(0); // should not come here
    }
    // cout <<"l: " << l <<" m:" << m << " r: " << r << " jj: " << jj << endl;
    assert(jj == r+1);

    return;
}

vector<int> merge_sort(vector<int>&a, int l, int r) {

    if(l < r) {
        int m = l + (r - l)/2;

        merge_sort(a, l, m);
        merge_sort(a, m+1, r);

        merge(a, l, m, r);
    }

    return a;
}

vector<int> heap_sort(vector<int>a) {

    return(a);
}

int main() {

    srand(42);

    vector<int> a = {2, 5, 1, 7, 9, 3, 6, 8, 5};
    vector<int> b = {1, 2, 3, 4, 5, 6, 7};
    vector<int> orig_a = a;
    vector<int> orig_a2 = a;

    vector<int> selection_sorted = selection_sort(a);
    vector<int> bubble_sorted = bubble_sort(a);
    vector<int> insertion_sorted = insertion_sort(a);
    vector<int> quick_sorted = quick_sort(orig_a, 0, a.size() - 1); // with randomized pivot [divide and conquer]

    vector<int> merge_sorted = merge_sort(orig_a2, 0, orig_a2.size() - 1);

    cout << "Original vector" << endl;
    for(auto  i: a)
        cout << i << " ";

    cout << endl;

    cout << "Output from selection-sort" << endl;

    for(auto i : selection_sorted)
        cout << i << " ";

    cout << endl;

    cout << "Output from bubble-sort" << endl;

    for(auto i : bubble_sorted)
        cout << i << " ";

    cout << endl;

    cout << "Output from insertion-sort" << endl;

    for(auto i : insertion_sorted)
        cout << i << " ";

    cout << endl;

    cout << "Output from quick-sort" << endl;

    for(auto i : quick_sorted)
        cout << i << " ";

    cout << endl;

    cout << "Output from merge-sort" << endl;

    for(auto i : merge_sorted)
        cout << i << " ";

    return 0;
}