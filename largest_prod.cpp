//
// Created by Mayank Parasar on 2019-12-17.
//

/*
 * You are given an array of integers. Return the largest product that can be made by multiplying any 3 integers
 * in the array.
*/

#include <iostream>
#include <vector>

using namespace std;

int largest_product(vector<int>& a) {
    int larg_prod = 0;
    vector<int> prod;
    for(int i = 0; i < a.size(); i++) {
        for(int j = i+1; j < a.size(); j++) {
            for(int k = 0; k < a.size(); k++) {
                prod.push_back(a[i]*a[j]*a[k]);
            }
        }
    }

    // return the largest element in that vector
    larg_prod = *max_element(prod.begin(), prod.end());
    return(larg_prod);
}


int main() {
    vector<int> array = {-4, -4, 2, 8};
    vector<int> array2 = {-4, -4, 2, 8, 9, 9, 9};

    cout << largest_product(array2);
    return 0;
}
