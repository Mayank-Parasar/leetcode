//
// Created by Mayank Parasar on 2020-03-08.
//

/* Program to merge two arrays*/

#include<iostream>
#include<vector>
#include<assert.h>


using namespace std;

vector<int> merge_sorted(vector<int>& v1, vector<int>& v2) {
    vector<int> v3;
    int ii = 0; // for v1
    int jj = 0; // for v2

    while(ii < v1.size() ||
          jj < v2.size()) {
        // v1 exhausted
        if(ii == v1.size() &&
           jj < v2.size()) {
            v3.push_back(v2[jj]);
            jj++;
        } // v2 exhausted
        else if(ii < v1.size() &&
                jj == v2.size()) {
            v3.push_back(v1[ii]);
            ii++;
        }
        else if(v1[ii] <= v2[jj]){
            v3.push_back(v1[ii]);
            if(ii < v1.size())
                ii++;
        }
        else if(v1[ii] > v2[jj]) {
            v3.push_back(v2[jj]);
            if(jj < v2.size())
                jj++;
        }
        else {
            assert(0);
        }
    }

    return v3;
}

void do_swap(int& a, int & b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;

    return;
}

vector<int> custom_sort(vector<int> v) {
    bool swap_ = true;
    while (swap_) {
        swap_ = false;
        for(int ii = 0; ii < v.size()-1; ii++){
            if(v[ii] > v[ii+1]){
                do_swap(v[ii], v[ii+1]);
                swap_ = true;
            }
        }
    }

    return v;
}

int main() {
    vector<int> v1 = {12, 32, 28, 3, 11};
    vector<int> v2 = {1, 3, 5, 7, 9};

    v1 = custom_sort(v1);
    v2 = custom_sort(v2);

    vector<int> v3 = merge_sorted(v1, v2);

    for(auto i : v3)
        cout << i << " ";

    return 0;
}