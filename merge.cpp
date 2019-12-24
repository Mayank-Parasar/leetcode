//
// Created by Mayank Parasar on 2019-12-24.
//

/*
 * You are given an array of k sorted singly linked lists.
 * Merge the linked lists into a single sorted linked list and return it.
 *
 * */

// doing it with vectors

#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

vector<int> merge(vector<int>& vect1, vector<int>& vect2) {
    vector<int> result;
    int ii = 0; // for vect1
    int kk = 0; // for vect2
    while(ii != (vect1.size()) ||
        kk != (vect2.size())) {
        if(ii == (vect1.size()) &&
           kk <= (vect2.size() - 1)) {
            result.push_back(vect2[kk]);
            if (kk <= vect2.size() - 1)
                kk++;
        }
        else if(ii <= (vect1.size() - 1) &&
                kk == (vect2.size())) {
            result.push_back(vect1[ii]);
            if (ii <= vect1.size() - 1)
                ii++;
        }
        else if(vect1[ii] < vect2[kk]) {
            result.push_back(vect1[ii]);
            if (ii <= vect1.size() - 1)
                ii++;
        }
        else if(vect2[kk] < vect1[ii]) {
            result.push_back(vect2[kk]);
            if (kk <= vect2.size() - 1)
                kk++;
        }
        else
            assert(0); // should not reach here
    }


    return result;
}

int main() {

    vector<int> vec1 = {1, 3, 5, 7, 8, 10};
    vector<int> vec2 = {2, 4, 6, 9};

    vector<int> result = merge(vec1, vec2);

    for(auto i : result)
        cout << i << " ";

    return 0;
}