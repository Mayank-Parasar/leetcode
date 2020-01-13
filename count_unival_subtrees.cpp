//
// Created by Mayank Parasar on 2020-01-11.
//

/*
 * A unival tree is a tree where all the nodes have the same value. Given a binary tree,
 * return the number of unival subtrees in the tree.

For example, the following tree should return 5:

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1

The 5 trees are:
- The three single '1' leaf nodes. (+3)
- The single '0' leaf node. (+1)
- The [1, 1, 1] tree at the bottom. (+1)
 */

#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

struct node {
    int val;

    node* left;
    node* right;

    node(int x) : val(x), left(nullptr), right(nullptr)
    {}
};

bool is_unival(node* node_) {

    if (node_->left == nullptr &&
        node_->right == nullptr)
        return true;

    if (is_unival(node_->left) && is_unival(node_->right) &&
        node_->val == node_->left->val &&
        node_->val == node_->right->val)
        return true;

    if(node_->left == nullptr) {
        if(is_unival(node_->right) && node_->val == node_->right->val)
            return true;
    }

    if(node_->right == nullptr) {
        if(is_unival(node_->left) && node_->val == node_->left->val)
            return true;
    }

}

int total_count = 0;

int count_univals(node* node_) {
    if(node_ == nullptr)
        return 0;

    total_count = count_univals(node_->left) + count_univals(node_->right);

    if(is_unival(node_))
        total_count +=1;

    return total_count;
}

int main() {

    node* node1 = new node(0);
    node* node2 = new node(1);
    node* node3 = new node(0);
    node* node4 = new node(1);
    node* node5 = new node(0);
    node* node6 = new node(1);
    node* node7 = new node(1);

    // connect them

    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;
    node4->left = node6;
    node4->right = node7;

    cout << boolalpha;

    cout << is_unival(node2);
    cout << endl;
    cout << "number of unival trees present: " << count_univals(node1);




    return 0;
}