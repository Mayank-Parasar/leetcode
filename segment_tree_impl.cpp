//
// Created by Mayank Parasar on 2020-03-30.
//

/*
 * Create a class that initializes with a list of numbers and has one method called sum. sum should take in
 * two parameters, start_idx and end_idx and return the sum of the list
 * from start_idx (inclusive) to end_idx (exclusive).

You should optimize for the sum method.

Here's the class:

class ListFastSum:
  def __init__(self, nums):
    self.nums = nums

  def sum(self, start_idx, end_idx):
    # Fill this in.

print(ListFastSum([1, 2, 3, 4, 5, 6, 7]).sum(2, 5))
# 12 because 3 + 4 + 5 = 12
 *
 * */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct segmentTree {
    int sum;
    segmentTree *left;
    segmentTree *right;

    segmentTree() {
        sum = 0;
        left = nullptr;
        right = nullptr;
    }
};

class fastSum {
public:

    fastSum(vector<int> array) {
        arr = array;
        int x = (int) (ceil(log2(arr.size())));

        // maximum size of segment tree
        int max_size
    };

    int naive_sum(int start, int end);
    // this is a segment tree
    void populate_sumTree() {


    }
    int fast_sum(int start, int end);
private:
    segmentTree* arrTree;   // root node of a segment tree
    vector<int> arr;
};

int main() {

    return 0;
}