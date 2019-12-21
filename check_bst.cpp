//
// Created by Mayank Parasar on 2019-12-19.
//
/*
 *                  20
 *                /    \
 *               8      30              <<== Tree-1
 *                     /  \
 *                    18   35
 *
 *                    4
 *                 /     \
 *               2        6            <<== Tree-2
 *              / \      /  \
*              1   3    5    7
 * */

// the above tree is not a BST.. write a program to idenfify the given tree is bst or not
// BST: Binary Search Tree

#include <iostream>
#include <algorithm>  // for std::is_sorted()
#include <vector>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;

    // ctor
    node(int val_) {
        val = val_;
        left = nullptr;
        right = nullptr;
    }
};

// do an in order traversal of BST, store it in a vector and
// it should be always in ascending order
vector<int> tree_traversal;

void in_order_traversal(node* node_) {
    if(node_ == nullptr)
        return;

    in_order_traversal(node_->left);
    tree_traversal.push_back(node_->val);
    cout << node_->val << "  ";
    in_order_traversal(node_->right);
}

int main() {

    // Tree - 2 (Is a BST)
    node* node_1 = new node(4);
    node* node_2 = new node(2);
    node* node_3 = new node(1);
    node* node_4 = new node(3);
    node* node_5 = new node(6);
    node* node_6 = new node(5);
    node* node_7 = new node(7);

    node_1->left = node_2;
    node_1->right = node_5;
    node_2->left = node_3;
    node_2->right = node_4;
    node_5->left = node_6;
    node_5->right = node_7;

    // Tree- 1 (Is not a BST)
    node* node1 = new node(20);
    node* node2 = new node(8);
    node* node3 = new node(30);
    node* node4 = new node(18);
    node* node5 = new node(35);

    // connec them
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;

    in_order_traversal(node1); // this populates the vector
    cout << endl;

    if(is_sorted(tree_traversal.begin(), tree_traversal.end()))
        cout << "The given tree is a BST" << endl;
    else
        cout << "The given tree is not a BST" << endl;

    return 0;
}