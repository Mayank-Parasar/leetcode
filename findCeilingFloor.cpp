//
// Created by Mayank Parasar on 2019-12-19.
//

/*
 * Given an integer k and a binary search tree,
 * find the floor (less than or equal to) of k, and the ceiling (larger than or equal to) of k.
 * If either does not exist, then print them as None.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;

    node(int val_) {
        val = val_;
        left = nullptr;
        right = nullptr;
    }
};

void print_tree(node* node_) { // in-order traversal

    if(node_ == nullptr)
        return;
    // print the in-order tree trraversal
    print_tree(node_->left);
    cout << node_->val << " ";
    print_tree(node_->right);
}

void findFloor(node* node_, int& floor, int& k) {

    if(node_ == nullptr)
        return;

    if(k > node_->val) {
        // store
        floor = node_->val;
        // go to right
        findFloor(node_->right, floor, k);
    }
    else if(k < node_->val) {
        // don't store
        // go to left
        findFloor(node_->left, floor, k);
    }
    else if(k == node_->val) {
        floor = node_->val;
        return;
    }
}

int main() {

    node *node1 = new node(8);
    node *node2 = new node(4);
    node *node3 = new node(12);
    node *node4 = new node(2);
    node *node5 = new node(6);
    node *node6 = new node(10);
    node *node7 = new node(14);

    // connect them:
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;

    print_tree(node1);
    cout << endl;
    int floor = -1;
    int k = 5;
    findFloor(node1, floor, k);
    cout << floor;

    return 0;
}