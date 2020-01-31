//
// Created by Mayank Parasar on 2020-01-29.
//

/*
 * Given a list of publications of the number of citations a scholar has, find their h-index.
 * Example:
Input: [3, 5, 0, 1, 3]
Output: 3
 * */


#include <iostream>
#include <vector>
#include <map>

using namespace std;


int find_hindex(vector<int> citation_list) {

    map<int, vector<int>> h_index;
    // have key as h-index and
    int h_idx = 1;

    // search of number of citations greater than
    // or equal to citation index. if found find the next citation
    while (h_index[h_idx].size() < h_idx) {
        int ii;
        for(ii=0; ii < citation_list.size(); ii++) {

            if(citation_list[ii] >= h_idx) {
                h_index[h_idx].push_back(citation_list[ii]);
            }
            if(h_index[h_idx].size() == h_idx)
                break;
            // break and reset ii to 0
        }

        if ((ii == citation_list.size()) &&
                h_index[h_idx].size() < h_idx)
            break;
        h_idx++;
    }

    for(auto i : h_index) {
        cout << i.first << ": ";
        for(auto k : i.second)
            cout << k <<",";
        cout << endl;
    }

    return (--h_idx);
}

int main() {

    vector<int> citation = {3, 5, 0, 1, 3};

    cout << find_hindex(citation);

    return 0;
}
