//
// Created by Mayank Parasar on 2020-03-06.
//

/*
 *
Example:

   3
  / \
 1   -3

The above tree has 3 subtrees. The root node with 3, and the 2 leaf nodes, which gives us a total of 3 subtree sums.
 The root node has a sum of 1 (3 + 1 + -3), the left leaf node has a sum of 1, and the right leaf node has a sum of -3.
 Therefore the most frequent subtree sum is 1.
*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int> global_sum_queue;

struct node{
    int val;
    node *left;
    node *right;

    node(int x) : val(x), left(nullptr), right(nullptr)
    { }
};

// sum function: populate the 'global_sum_queue'
int sum_ = 0;
int sum_func(node * node_) {
    if( node_ == nullptr) {
        return sum_;
    }
    else {
        sum_func(node_->left);
        sum_ += node_->val;
        sum_func(node_->right);
    }
    return sum_;
}


//in order tree-traversal
void in_order_traversal(node* node_) {


    if( node_ == nullptr) {
        return;
    }
    else {
        sum_ = 0;
        sum_func(node_->left); // recurse on left
        global_sum_queue.push_back(sum_);
        sum_=0;
        sum_func(node_);  // recurse on root
        global_sum_queue.push_back(sum_);
        sum_=0;
        sum_func(node_->right);  // recurse on right
        global_sum_queue.push_back(sum_);
    }
}


int main() {

    node* node1 = new node(3);
    node* node2 = new node(1);
    node* node3 = new node(-3);

    // connect them
    node1->left = node2;
    node1->right = node3;

    in_order_traversal(node1);
    map<int, int> sum_freq;

    for(auto i : global_sum_queue){
        sum_freq[i]++;
    }

    // now do the preprocessing on this array to find the most frequent sum.
    int max_freq = -1;
    int max_sum = -1;
    for(auto i : sum_freq) {
        if(i.second > max_freq) {
            max_freq = i.second;
            max_sum = i.first;
        }
    }

    cout << max_sum;
    return 0;

}