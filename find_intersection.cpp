//
// Created by Mayank Parasar on 2020-05-13.
//

/*
 * Given 3 sorted lists, find the intersection of those 3 lists.

Here's an example and some starter code.

def intersection(list1, list2, list3):
  # Fill this in.

print(intersection([1, 2, 3, 4], [2, 4, 6, 8], [3, 4, 5]))
# [4]*/

#include <iostream>
#include <vector>

using namespace std;

void interection(const vector<int>& v1,
                const vector<int>& v2,
                const vector<int>& v3) {
    int x1 = 0;
    int x2 = 0;
    int x3 = 0;

    while((x1 < v1.size()) && (x2 < v2.size()) && (x3 < v3.size())) {
        if((v1[x1] == v2[x2]) &&
                (v2[x2] == v3[x3])) {
            cout << v1[x1];
            x1++;
            x2++;
            x3++;
        }
        else if(v1[x1] < v2[x2]) {
            x1++;
        }
        else if ((v2[x2] < v3[x3])) {
            x2++;
        }
        else {
            x3++;
        }
    }

    return;
}

int main() {
    vector<int> v1 = {1, 2, 3, 4};
    vector<int> v2 = {2, 4, 6, 8};
    vector<int> v3 = {3, 4, 5};

    interection(v1, v2, v3);

    return 0;
}