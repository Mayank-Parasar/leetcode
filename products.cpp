//
// Created by Mayank Parasar on 2020-01-15.
//

/*
 * You are given an array of integers. Return an array of the same size where the element at each index is
 * the product of all the elements in the original array except for the element at that index.

For example, an input of [1, 2, 3, 4, 5] should return [120, 60, 40, 30, 24].

You cannot use division in this problem.
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> product(vector<int>& arr) {
    vector<int> prod;

    for(int ii=0; ii < arr.size(); ii++) {
        int product = 1;
        for(int kk=0; kk < arr.size(); kk++) {
            if(kk != ii) {
                product *= arr[kk];
            }
        }
        prod.push_back(product);
    }

    return prod;
}

int main() {


    vector<int> arr = {1, 2, 3, 4, 5};

    vector<int> prod = product(arr);

    for(auto i : prod)
        cout << i << " ";

    return 0;
}
