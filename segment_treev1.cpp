//
// Created by Mayank Parasar on 2020-03-31.
//
// Code to create the segment tree
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <assert.h>

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

int range_sum(vector<int> vec, int start, int end) {
    int sum = 0;
    for (int ii = start; ii <= end; ii++) {
        sum += vec[ii];
    }
    return sum;
}

node* build(vector<int> vec, int start, int end) {
    int mid = (start + end) / 2;
    cout << "start: " << start << " mid: " << mid << " end: " << end << endl;
    if(mid > end || start > mid || start > end)
        return nullptr;

    node* node_ = new node(range_sum(vec, start, end));
    node_->strt = start;
    node_->end = end;
    if(start == end)
        return node_;

    if(mid >= start)
        node_->left = build(vec, start, mid);
    if(end >= mid + 1)
        node_->right = build(vec, mid+1, end);

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
int query_sum = 0;
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

int main() {
	// your code goes here
	vector<int> vec = {1, 3, 5, 7, 9, 1};

	node* root = build(vec, 0, vec.size()-1);

	cout << endl;

	inorder_traversal(root);

	cout << endl;

//    int sum = Query(root, 2, 4);
    int sum = Query(root, 0, 1);
//    int sum = Query(root, 1, 3);
	cout << "sum: " << sum << endl;
	return 0;
}

