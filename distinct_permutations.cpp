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
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
//#include <algorithm>
#include <chrono>
using namespace  std;
using namespace std::chrono;
vector<vector<int> > result;
#define MAX_PERMUTATIONS (5000)

void permute(vector<int> v, int start, int end) {
    if(result.size() >= MAX_PERMUTATIONS)
        return;
    if(start == end) {
        // check if this vector present in
        // the 'circular_permutation
        // if not, store all its circular permutations
        // before storing it in 'result' vectore

        for(int i = 0; i < v.size(); i++) {
            rotate(v.begin(), v.begin()+1, v.end());
            for(auto i : result)
                if (i == v)
                    return;
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
            if(result.size() >= MAX_PERMUTATIONS)
                return;
            permute(v, start+1, end);

            // Backtrack: SwapBack
            swap(v[start],v[i]);
        }
    }
}
// To be used only for very large number of permutations
// only to get jumbled permutations
// put in the terminating condition
void permute2(vector<int>(v)) {
    if (v.size() < 10)
        return;
    srand((unsigned) time(0));
    int sizeOfVector = v.size();
    // shuffle
    shuffle:
    /* Fisher-Yates shuffle algorithm */
    for (int k = 0; k < sizeOfVector; k++) {
        int r = k + rand() % (sizeOfVector - k); // careful here!
        swap(v[k], v[r]);
    }
    // check
    for(int i = 0; i < v.size(); i++) {
        rotate(v.begin(), v.begin()+1, v.end());
        for(auto i : result)
            if (i == v)
                goto shuffle;
    }
    //store
    if(result.size() < MAX_PERMUTATIONS) {
        result.push_back(v);
        goto shuffle;
    }
    else
        return;
}

int main() {
//    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};
//    vector<int> vec = {1, 1, 2, 2, 2, 2};
//    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    // Print all rotation of this vector:
//    for(int i = 0; i <= vec.size(); i++) {
//        for(auto i : vec) cout<< i << " ";
//        cout << endl;
//        rotate(vec.begin(), vec.begin()+1, vec.end());
//    }
    // Get starting timepoint
    auto start = high_resolution_clock::now();
    permute(vec, 0, vec.size()-1);
//    permute2(vec);
    // Get ending timepoint
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
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
    cout << "Duration of time elapsed: " << duration.count() << " microseconds" << endl;
    // prune this result

    return 0;

}