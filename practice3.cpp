//
// Created by Mayank Parasar on 2020-02-03.
//

#include<iostream>
#include<vector>

using namespace std;

vector<int> top_k(vector<int>& x, vector<int>& y) {
    vector<int> result;

    for(int ii =0; ii < x.size(); ii++) {
        for(int kk=0; kk < y.size(); kk++) {
            result.push_back(x[ii] + y[kk]);
        }

    }

    int max = -1;
    int max1, max2, max3;
    for(auto i : result) {
        if((i > max))
            max = i;
    }

    max1 = max;

    max = -1;

    for(auto i : result) {
        if((i > max) && (max1 > i))
            max = i;
    }

    max2 = max;
    max = -1;

    for(auto i : result) {
        if((i > max) && (max1 > i) && (max2 > i))
            max = i;
    }

    max3 = max;

    vector<int> result2;

    result2.push_back(max1);
    result2.push_back(max2);
    result2.push_back(max3);

    return result2;

}

int main() {

    vector<int> x = {20, 25, 16, 31, 26};
    vector<int> y = {27, 18, 31, 15, 14};

    vector<int> z = top_k(x, y);

    for(auto i : z)
        cout << i << " ";

    return 0;
}