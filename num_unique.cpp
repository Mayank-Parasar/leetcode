//
// Created by Mayank Parasar on 2019-12-17.
//

/* print num unique elems*/

#include <iostream>
#include <vector>

using namespace std;

int num_unique(vector<int>& vect) {
    if(vect.size() == 0)
        return 0;

    int elem = vect[0];
    int counter = 1;
    for (auto i: vect) {
        if(i > elem) {
            elem = i;
            counter++;
        }
    }
    return counter;
}


int main() {
    vector<int> a = {};
    cout << num_unique(a);
    return 0;
}
