//
// Created by Mayank Parasar on 11/5/20.
//

/* ---  Necklace Permutations   ---
 * Given a vector of integers print all the unique permutation of this vector
 * That is one permutation instance may not be derived from another permutation instance
 * by merely rotating the first one
 * */

#include <iostream>
#include <vector>

using namespace  std;

vector<vector<int> > result;
vector<vector<int>> circular_permulations;

void permute(vector<int> v, int start, int end) {
    if(start == end) {
        // check if this vector present in
        // the 'circular_permutation
        // if not, store all its circular permutations
        // before storing it in 'result' vectore
        for(auto  i : circular_permulations) {
            if (v == i) {
                return;
            }
        }
        /* vector is not present.. store all its circular
         * permutations*/
        for(int i = 0; i < v.size(); i++) {
            rotate(v.begin(), v.begin()+1, v.end());
            circular_permulations.push_back(v);
        }
        // now push this vector in the result
        result.push_back(v);
        return;
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
//    vector<int> vec = {1, 2, 3, 4, 5};
    vector<int> vec = {1, 1, 2, 2, 2, 2};

    // Print all rotation of this vector:
//    for(int i = 0; i <= vec.size(); i++) {
//        for(auto i : vec) cout<< i << " ";
//        cout << endl;
//        rotate(vec.begin(), vec.begin()+1, vec.end());
//    }

    permute(vec, 0, vec.size()-1);
    // print the result:
    int count = 0;
    for(auto i : result) {
        for (auto k : i) {
            cout << k << " ";
        }
        cout << endl;
        count++;
    }
    cout << "Total ring topologies (aka Necklace permutations) : " << count << endl;
    // prune this result

    return 0;

}