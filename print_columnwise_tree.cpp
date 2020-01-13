//
// Created by Mayank Parasar on 2019-12-17.
//

/*
 *                  6
 *                /  \
 *              5      7
 *             / \    / \
 *            2   1  4    9
 *           /          /  \
 *          3          10    8
 *          */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int counter = 0; // counter to tract the global distance from root

map<int, vector<int>> vertical_traversal_map;

struct node {
    int val;

    node* left;
    node* right;
    int vertical_distance;
    node(int x) : val(x), left(nullptr), right(nullptr)
    {
        vertical_distance = -999; // all the distance reset to be 0 from the root.
    }
};

void in_order_traversal(node* node_) {
    if(node_ == nullptr)
        return;

    if(node_->vertical_distance == -999)
        node_->vertical_distance = counter;

    counter--;
    in_order_traversal(node_->left);
    counter++; // this is to remove the side-effect of left traversal
    counter++;
    in_order_traversal(node_->right);
    counter--;
}


void print_tree(node* node_) {
    if(node_ == nullptr)
        return;
    print_tree(node_->left);
    cout << "  { " << node_->val <<" ; " << node_->vertical_distance <<" }  ";
    vertical_traversal_map[node_->vertical_distance].push_back(node_->val);
    // store this pair in a map.
    print_tree(node_->right);
}


int main() {
    // vector<vector<int*>> matrix;

    node* node1 = new node(1);
    node* node2 = new node(2);
    node* node3 = new node(3);
    node* node4 = new node(4);
    node* node5 = new node(5);
    node* node6 = new node(6);
    node* node7 = new node(7);
    node* node8 = new node(8);
    node* node9 = new node(9);
    node* node10 = new node(10);

    node6->left = node5;
    node6->right = node7;
    node5->left = node2;
    node5->right = node1;
    node2->left = node3;
    node7->left = node4;
    node7->right = node9;
    node9->right = node8;
    node9->left = node10;

    // set the distance and then travese again...

    in_order_traversal(node6);

    print_tree(node6);

    cout << endl;
    // now print them in vitcical order
    for(auto i : vertical_traversal_map) {
        cout << i.first <<": ";
        for(auto k : i.second) {
            cout << k << " ";
        }
        cout << endl;
    }

    return 0;
}