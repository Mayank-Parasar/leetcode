//
// Created by Mayank Parasar on 2019-12-26.
//

/*
You are given the root of a binary tree. Return the deepest node (the furthest node from the root).

Example:

    a
   / \
  b   c
 /
d
=====
 *                  20
 *                /    \
 *               8      30              <<== Tree-1
 *                     /  \
 *                    18   35

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

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


int level = 0; // global variable
vector<int> level_vector;
map<int, int> level_map;


void in_order_traversal( node* node_ ) {

    if (node_ == nullptr)
        return;
    if(node_->left != nullptr) {
        // cout << level++ << endl;
        level++;
        // if value doesn't already
        if(level_map.find(node_->left->val) == level_map.end()) {
            // not found
            level_map[node_->left->val] = level;
        }
        level_vector.push_back(level);
        in_order_traversal(node_->left);
        level--;
        // cout << level-- << endl;
    }
    cout << node_->val << " ";
    if(node_->right != nullptr) {
        // cout << level++ << endl;
        level++;
        // if value doesn't already
        if(level_map.find(node_->right->val) == level_map.end()) {
            // not found
            level_map[node_->right->val] = level;
        }
        level_vector.push_back(level);
        in_order_traversal(node_->right);
        // cout << level-- << endl;
        level--;
    }
}

int main() {

    // Tree- 1
    node* node1 = new node(20);
    node* node2 = new node(8);
    node* node3 = new node(30);
    node* node4 = new node(18);
    node* node5 = new node(35);

    // connect them
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;
    // this function is called with the root node.
    // push it in the map with 0 level/depth
    level_map[node1->val] = 0;
    in_order_traversal(node1);

    cout << endl;
    for(auto i : level_vector)
        cout << i << endl;
    cout << " ------------ " << endl;
    cout << "max depth of the tree is: " << *max_element(level_vector.begin(), level_vector.end()) << endl;

    // find the max depth in that tree..
    // print all the elements with that depth
    int max_depth = -1;
    for(auto i : level_map) {
        if(i.second > max_depth)
            max_depth = i.second;
    }

    cout << "Max depth of the tree is: " << max_depth << endl;
    cout << "Element(s) associated with this max depth: " << endl;
    for(auto i : level_map) {
        if(i.second == max_depth)
            cout << i.first << " ";
    }
    cout << endl;
    return 0;
}