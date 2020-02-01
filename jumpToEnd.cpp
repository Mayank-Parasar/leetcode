//
// Created by Mayank Parasar on 2020-01-31.
//

/*
 * Starting at index 0, for an element n at index i,
 * you are allowed to jump at most n indexes ahead. Given a list of numbers,
 * find the minimum number of jumps to reach the end of the list.
 *
 Example:
    Input: [3, 2, 5, 1, 1, 9, 3, 4]
    Output: 2
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int depth = 0;

int get_max_elem_idx(vector<int> arr, int strt, int end) {

    int max_elm_idx = end;
    int max_elm = arr[end];
    for(int ii = end; ii >= strt; ii--) {
        if(max_elm < arr[ii]) {
            max_elm = arr[ii];
            max_elm_idx = ii;
        }
    }

    return max_elm_idx;
}

int num_jumps(vector<int> arr, int start,
                int end) { // recursive-function

    depth++;
    cout << "depth: " << depth << endl;
    int max_elem_idex = get_max_elem_idx(arr, start, end); // should start from the end
                                                           // so as not to stuck in local minima

    cout << "max_elem_idex: " << max_elem_idex << endl;
    cout << "value of max_elem: " << arr[max_elem_idex] << endl;

    if(max_elem_idex + arr[max_elem_idex] >= arr.size())
        return depth;

//    vector<int>::iterator strt = arr.begin() + max_elem_idex;
//    vector<int>::iterator ed = strt + arr[max_elem_idex];

    num_jumps(arr, max_elem_idex, max_elem_idex + arr[max_elem_idex]);

    return depth;

}

int main() {

    vector<int> arr = {3, 2, 5, 1, 1, 9, 3, 4};
    vector<int> arr2 = {1, 1, 1, 1, 1, 1, 1, 1};
    int start = 0;
    int end = arr[0];
    cout << "number of jumps: " << num_jumps(arr, start, end);

    return 0;
}