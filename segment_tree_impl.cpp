//
// Created by Mayank Parasar on 2020-03-30.
//

/*
 * Create a class that initializes with a list of numbers and has one method called sum. sum should take in
 * two parameters, start_idx and end_idx and return the sum of the list
 * from start_idx (inclusive) to end_idx (inclusive).

You should optimize for the sum method.
print(ListFastSum([1, 2, 3, 4, 5, 6, 7]).sum(2, 5))
# 12 because 3 + 4 + 5 = 12
 *
 * */

#include <iostream>
#include <vector>

using namespace std;

struct node {
    int sum;
    node* left;
    node* right;
    int strt;
    int end;
    node(int x) : sum(x)
    {
        left = nullptr;
        right = nullptr;
        strt = -1;
        end = -1;
    }

};

class fastSum {
public:

    //ctor
    fastSum(vector<int> vec) {
        arr = vec;
        // build tree in ctor
        arrTree = this->build(0, vec.size()-1);
    }

    int range_sum(int start, int end) {
        int sum = 0;
        for (int ii = start; ii <= end; ii++) {
            sum += arr[ii];
        }
        return sum;
    }

    // this is a segment tree
    node* build(int start, int end) {
        int mid = (start + end) / 2;
        // cout << "start: " << start << " mid: " << mid << " end: " << end << endl;
        if(mid > end || start > mid || start > end)
            return nullptr;

        node* node_ = new node(range_sum(start, end));
        node_->strt = start;
        node_->end = end;
        if(start == end)
            return node_;

        if(mid >= start)
            node_->left = build(start, mid);
        if(end >= mid + 1)
            node_->right = build(mid+1, end);

        return node_;
    }

    void inorder_traversal(node* node_) {
        if(node_ == nullptr)
            return;
        else {
            inorder_traversal(node_->left);
            cout << node_->sum << " " << "[ " << node_->strt
                 << "," <<node_->end <<" ]" << "\t" ;
            inorder_traversal(node_->right);
        }
    }

    int Query(node* node_, int start, int end) {
        assert(end > start);
        if(node_ == nullptr)
            return 0;
        // no overlap
        if(start > node_->end || end < node_->strt)
            return 0;

        // total overlap
        if(start<= node_->strt && end >= node_->end) {
            query_sum += node_->sum;
            return query_sum;
        }

        // partial overlap: proceed in both direction
        if(start>= node_->strt || end <= node_->end) {
            Query(node_->left, start, end);
            Query(node_->right, start, end);
        }

        return query_sum;
    }
    int fast_sum(int start, int end) {
        query_sum = Query(arrTree, start, end);
        return query_sum;
    }

    int naive_sum(int start, int end) {
        int sum = 0;
        for(int ii = start; ii <= end; ii++) {
            sum += arr[ii];
        }
        return sum;
    }

private:
    node* arrTree;   // root node of a segment tree
    vector<int> arr;
    int query_sum;
};

int main() {
    vector<int> vec = {1, 3, 5, 7, 9, 1};
    // vector<int> vec(50000000, 1); // for large array

    fastSum* obj_ptr = new fastSum(vec);

    // cout << "naive-sum: " << obj_ptr->naive_sum(20000000, 40000000);
    cout << "naive-sum: " << obj_ptr->naive_sum(2, 4);
    cout << endl;
    // cout << "fast-sum: " << obj_ptr->fast_sum(20000000, 40000000);
    cout << "fast-sum: " << obj_ptr->fast_sum(2, 4);
    return 0;
}