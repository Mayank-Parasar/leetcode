//
// Created by Mayank Parasar on 2020-02-03.
//

// Merge array
// code for merging two sorted arry into a sorted arry

#include<iostream>
#include<vector>

using namespace std;

vector<int> merge(vector<int>&v1, vector<int>& v2) {
    vector<int> result;

    int ii = 0; // for vector v1
    int kk = 0; // for vector v2

    while(ii < v1.size() ||
          kk < v2.size()) {
        //-------------------------//
        if(ii == (v1.size()) &&
           kk < v2.size()){
            result.push_back(v2[kk]);
            if(kk <= v2.size() - 1)
                kk++;
        }
        else if(ii < v1.size() &&
                kk == v2.size()){
            result.push_back(v1[ii]);
            if(ii <= v1.size() - 1)
                ii++;
        }
        else if(v1[ii] > v2[kk]){
            result.push_back(v2[kk]);
            if(kk <= v2.size() - 1)
                kk++;
        }
        else if(v2[kk] > v1[ii]) {
            result.push_back(v1[ii]);
            if(ii <= v1.size() - 1)
                ii++;
        }
        else {
            assert(0);
        }
    }


    return result;
}

int main() {

    vector<int> v1 = {2, 4, 6, 8, 10};
    vector<int> v2 = {1, 3, 5, 7, 9};

    vector<int> v3 = merge(v1, v2);

    cout << endl;
    for(auto i : v3)
        cout << i << " ";

    cout << endl;

    return 0;
}