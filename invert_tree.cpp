//
// Created by Mayank Parasar on 2019-12-19.
//
/*
 * You are given the root of a binary tree. Invert the binary tree in place.
 * That is, all left children should become right children, and all right children should become left children.

Example:

    a
   / \
  b   c
 / \  /
d   e f

The inverted version of this tree is as follows:

  a
 / \
 c  b
 \  / \
  f e  d
*/


#include <iostream>
#include <vector>

using namespace std;

struct node {
    char val;
    node* left_child;
    node* right_child;

    node(char val_) {
        val = val_;
        left_child = nullptr;
        right_child = nullptr;
    }
};

void print_tree(node* node_) { // in-order traversal

    if(node_ == nullptr)
        return;
    // print the in-order tree trraversal
    print_tree(node_->left_child);
    cout << node_->val << " ";
    print_tree(node_->right_child);
}

void invert_tree(node* node_) {
    // starting from the root invert
    if(node_ == nullptr)
        return;

    swap(node_->left_child, node_->right_child);
    invert_tree(node_->left_child);
    invert_tree(node_->right_child);
}

int main() {

    node* node_a = new node('a');
    node* node_b = new node('b');
    node* node_c = new node('c');
    node* node_d = new node('d');
    node* node_e = new node('e');
    node* node_f = new node('f');

    node_a->left_child = node_b;
    node_a->right_child = node_c;
    node_b->left_child = node_d;
    node_b->right_child = node_e;
    node_c->left_child = node_f;

    print_tree(node_a);
    invert_tree(node_a);
    cout << endl;
    print_tree(node_a);

    return 0;
}