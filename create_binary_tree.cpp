//
// Created by Mayank Parasar on 2020-02-01.
//

/*
 * Given a binary tree, remove the nodes in which there is only 1 child, so that the binary tree is a full binary tree.

So leaf nodes with no children should be kept, and nodes with 2 children should be kept as well.

# Given this tree:
#     1
#    / \
#   2   3
#  /   / \
# 0   9   4

# We want a tree like:
#     1
#    / \
#   0   3
#      / \
#     9   4

 AND
# Given this tree:
#     1
#    / \
#   2   3
#  /   / \
# 0   9   4
            \
             7

# We want a tree like:
#     1
#    / \
#   0   3
#      / \
#     9   7

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

void tree_traversal(node* node_) {

    if(node_ == nullptr) {
        return;
    }
    else if (node_->left == nullptr &&
            node_->right == nullptr) {
        return;
    }
    //////////////// iterating left sub-tree //////////////////////
    if( node_->left->left != nullptr &&
             node_->left->right != nullptr) {
        // traverse the tree in left direction
        tree_traversal(node_->left);
    }
    else if(node_->left->left != nullptr &&
            node_->left->right == nullptr) {
        // delete this node and traverse again to  its left
        node* tmp = node_->left;
        node_->left = node_->left->left;
        delete(tmp);
        tree_traversal(node_->left);
    }
    else if(node_->left->left == nullptr &&
            node_->left->right != nullptr) {
        // delete this node and traverse again to  its left
        node* tmp = node_->right;
        node_->left = node_->left->right;
        delete(tmp);
        tree_traversal(node_->left);
    }
    else if(node_->left->left == nullptr &&
            node_->left->right == nullptr) {
        // return;
    }
    //////////////// iterating right sub-tree //////////////////////
    if( node_->right->left != nullptr &&
        node_->right->right != nullptr) {
        // traverse the tree in left direction
        tree_traversal(node_->right);
    }
    else if(node_->right->left != nullptr &&
            node_->right->right == nullptr) {
        // delete this node and traverse again to  its left
        node* tmp = node_->right;
        node_->right = node_->right->left;
        delete(tmp);
        tree_traversal(node_->right);
    }
    else if(node_->right->left == nullptr &&
            node_->right->right != nullptr) {
        // delete this node and traverse again to  its left
        node* tmp = node_->right;
        node_->right = node_->right->right;
        delete(tmp);
        tree_traversal(node_->right);
    }
    else if(node_->right->left == nullptr &&
            node_->right->right == nullptr) {
        // return;
    }
    else {
        // this case should not come...

        assert(0);
    }
    return;
}

int main() {

    node* node1 = new node(1);
    node* node2 = new node(2);
    node* node3 = new node(3);
    node* node4 = new node(0);
    node* node5 = new node(9);
    node* node6 = new node(4);
    node* node7 = new node(7);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;

    node3->left = node5;
    node3->right = node6;
    node6->right = node7;

    tree_traversal(node1);

    return 0;
}