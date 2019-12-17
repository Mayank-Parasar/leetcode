//
// Created by Mayank Parasar on 2019-12-17.
//

/*
 * Given a list, find the k-th largest element in the list.
 * */

#include <iostream>
#include <vector>

using namespace std;

int kth_largest_elem(vector<int> vect, int k) {
    vector<int>::iterator itr;
    for(int i = 0; i < k-1; i++) {
       itr = max_element(vect.begin(), vect.end());
       vect.erase(itr);
    }

    return (*max_element(vect.begin(), vect.end()));
}

int main() {

    vector<int> vect = {3, 5, 2, 4, 6, 8};
    cout << kth_largest_elem(vect, 3);
    return 0;
}