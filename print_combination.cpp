//
// Created by Mayank Parasar on 2020-02-09.
//

/*
 * given a vector 'v' of length >= r and the number r
 * print 'r' combination of the from the r elements of
 * the vector.
 * */

#include <iostream>
#include <vector>

using namespace std;

void print_combination(vector<int>& v, int r, vector<int> data,
                        int start, int end, int data_idx) {
    if(data_idx == r) {
        for(auto i : data)
            cout << i;
        cout << endl;
        return;
    }

    for(int ii = start; ii <= end; ii++ ) {

        data[data_idx] = v[ii];

        print_combination(v, r, data, ii+1, end, data_idx+1);

    }

    return;

}

int main() {

    vector<int> v = {1, 2, 3, 4, 5};
    int r = 4;
    vector<int> data(r,-1);
    print_combination(v, r, data, 0, v.size()-1, 0);

    return 0;
}