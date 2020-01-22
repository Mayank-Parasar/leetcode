//
// Created by Mayank Parasar on 2020-01-21.
//

/*
 * Given preorder traversal of a binary search tree, construct the BST.

For example, if the given traversal is {10, 5, 1, 7, 40, 50}, then the output should be root of following tree.
     10
   /   \
  5     40
 /  \      \
1    7      50

 */

#include <iostream>
#include <vector>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;

    node(int x) : val(x), left(nullptr), right(nullptr)
    {}
};


// construct the tree.

node* construct_bst_tree(vector<int> pre_order, int start, int end) {

    if (end >= start) {

        node *node_ = new node(pre_order[start]); // this is the root

        int ii;

        for (ii = start; ii <= end; ii++) {
            if (pre_order[ii] > pre_order[start])
                break;
        }
        vector<int>::iterator left_strt = pre_order.begin() + start+1;
        vector<int>::iterator left_end = pre_order.begin() + (ii);

        vector<int> left_arry(left_strt, left_end);
        vector<int> right_arry(left_end, pre_order.end());
        node_->left = construct_bst_tree(left_arry, 0, left_arry.size()-1);
        node_->right = construct_bst_tree(right_arry, 0, right_arry.size()-1);

        return (node_);
    }
    else {
        return (nullptr);
    }
}

// do a in-order traversal of the newly constructed tree

void in_order(node* node_) {
    if(node_ == nullptr)
        return;

    else {
        in_order(node_->left);
        cout << node_->val << " ";
        in_order(node_->right);
    }
}


int main() {

    vector<int> pre_order = {10, 5, 1, 7, 40, 50};

    node* root = construct_bst_tree(pre_order, 0, pre_order.size()-1);

    cout << root->val;
    cout << endl;
    in_order(root);
    cout << endl;

    return 0;
}