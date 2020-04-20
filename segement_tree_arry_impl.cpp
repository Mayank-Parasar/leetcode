//
// Created by Mayank Parasar on 2020-04-19.
//

/*
 * Array implementation of segment-tree data structure
 * */

#include <iostream>
#include <cmath>

using namespace std;

int construct_ST(int arr[], int ss, int se, int *st, int si) {
    // if there is one element in array, store it in current node
    // of segment tree and return
    if (ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }
        // if there are more than one elemets then recur for left and
        // right subtrees and store the sum of values in this node
        int mid = ss + (se-ss)/2;
        st[si] = construct_ST(arr, ss, mid, st, si*2+1) +
                construct_ST(arr, mid+1, se, st, si*2+2);
    return st[si];
}

int* construct_segment_tree(int arr[], int n) {
    // Height of segment tree
    int x = (int) ceil(log2(n));

    // number of elements of the segment_tree_array
    int max_size = 2*(int)pow(2, x) - 1;

    // allocate memory
    int *seg_tree = new int[max_size];
    // construct the segment tree array
    construct_ST(arr, 0, n-1, seg_tree, 0);

    // print segment tree
    /*
    for (int ii = 0; ii < max_size; ii++) {
        cout << seg_tree[ii] << " ";
    }
    */
    // return the contructed segment tree
    return seg_tree;
}

int get_sum(int *st, int ss, int se, int qs, int qe, int si) {

    // if segment of this node is a part of given range, then return
    // the sum of the segment (complete overlap)
    if (qs <= ss && qe >= se)
        return st[si];

    // if segment of this node is outside the given range (no overlap)
    if (se < qs || ss > qe)
        return 0;

    // if a part of this segment overlaps with the given range (partial overlap)
    int mid = ss + (se-ss)/2;
    return get_sum(st, ss, mid, qs, qe, 2*si+1) +
            get_sum(st, mid+1, se, qs, qe, 2*si+2);
}

int get_sum(int *st, int n, int qs, int qe) {
    // input errors
    if (qs < 0 || qe > n-1 || qs > qe) {
        cout << "Invalid Input";
        return -1;
    }

    return get_sum(st, 0, n-1, qs, qe, 0);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Build segment tree from given array
    int *st = construct_segment_tree(arr, n);
    cout<<"Sum of values in given range = "<<get_sum(st, n, 1, 3)<<endl;


}