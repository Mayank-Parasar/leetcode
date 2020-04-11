//
// Created by Mayank Parasar on 2020-04-10.
//

/*
 * Given a list of sorted numbers (can be both negative or positive), return the list of numbers squared in sorted order.

Here's an example and some starting code:

def square_numbers(nums):
 # Fill this in.

print(square_numbers([-5, -3, -1, 0, 1, 4, 5]))
# [0, 1, 1, 9, 16, 25, 25]

Solve this problem in O(n) time.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

vector<int> sorted_square(vector<int> sorted_number) {
    vector<int> result;
    vector<int> neg_nums;
    vector<int> pos_nums;
    for(auto i : sorted_number) {
        if(i < 0) {
            neg_nums.push_back(i*i);
        }
        else {
            pos_nums.push_back(i*i);
        }
    }

    // reverse the neg_nums
    std::reverse(neg_nums.begin(), neg_nums.end());

    // now merge these two arrays
    int ii = 0;
    int jj = 0;
    while(ii < neg_nums.size() ||
            jj < pos_nums.size())  {
        if (ii == neg_nums.size() &&
            jj < pos_nums.size()) {
            result.push_back(pos_nums[jj]);
            jj++;
        }
        else if (ii < neg_nums.size() &&
                 jj == pos_nums.size()) {
            result.push_back(neg_nums[ii]);
            ii++;
        }
        else if (neg_nums[ii] < pos_nums[jj]) {
            result.push_back(neg_nums[ii]);
            if(ii < neg_nums.size())
                ii++;
        }
        else if (pos_nums[jj] <= neg_nums[ii]) {
            result.push_back(pos_nums[jj]);
            if(jj < pos_nums.size())
                jj++;
        }
        else {
            // should not come here...
            assert(0);
        }
    }
    return result;
}

int main() {
    vector<int> sorted_num = {-5, -3, -1, 0, 1, 4, 5};
    vector<int> result = sorted_square(sorted_num);

    for(auto i : result) {
        cout << i << endl;
    }
}