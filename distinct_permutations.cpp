//
// Created by Mayank Parasar on 11/5/20.
//

/*
 * Given a vector of distinct interger print all the unique permutation of this vector
 * That is one permutation instance may not be derived from another permutation instance
 * by merely rotating the first one
 * */

#include <iostream>
#include <vector>

using namespace  std;

vector<vector<int>> result;

void permute(vector<int> v, int start, int end) {
    if(start == end) {
        result.push_back(v);
    }
    else {
        for(int i = start; i <= end; i++) {
            // Swap
            swap(v[start], v[i]);
            // Recurse
            permute(v, start+1, end);

            // Backtrack: SwapBack
            swap(v[start],v[i]);
        }
    }
}
int main() {
    vector<int> vec = {0,1,2,3,4};
    permute(vec, 0, vec.size()-1);
    // print the result:
    for(auto i : result) {
        for (auto k : i) {
            cout << k << " ";
        }
        cout << endl;
    }
    return 0;

}