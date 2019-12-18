//
// Created by Mayank Parasar on 2019-12-17.
//
/*
 *                  6
 *                /  \
 *              5      7
 *             / \    / \
 *            2   1  4    9
 *           /             \
 *          3              8
 * */
#include <iostream>
#include <vector>

using namespace std;

struct node {
    int val;
    int row_id;
    int col_id;
    node* left_child;
    node* right_child;

    node(int val_, int row_id_ = -1, int col_id_ = -1,
            node* left_child_= nullptr, node* right_child_= nullptr) {
        val = val_;
        row_id = row_id_;
        col_id = col_id_;
        left_child = left_child_;
        right_child = right_child_;
    }

};

void in_order_traversal(node* node_) {

    if(node_ == nullptr)
        return;

    in_order_traversal(node_->left_child);
    cout << node_->val << " ";
//    pre_order_traversal(node_);
//    cout << node_->val;
    if(node_->right_child != nullptr)
        in_order_traversal(node_->right_child);
    // cout << node_->val;

}

vector<node*> working_set; // global working queue

void bfs(node* node_) {

    cout << node_->val << " ";
    // erase this node from the working set
    if(working_set.size() != 0)
        working_set.erase(working_set.begin());

    // populate the working queue
    if(node_->left_child != nullptr)
        working_set.push_back(node_->left_child);
    if(node_->right_child != nullptr)
        working_set.push_back(node_->right_child);

    if(working_set.size() != 0)
        bfs(*(working_set.begin()));

    // loop until the working set is finished

}

int main() {
    node* node1 = new node(1);
    node* node2 = new node(2);
    node* node3 = new node(3);
    node* node4 = new node(4);
    node* node5 = new node(5);
    node* node6 = new node(6);  // start node
    node* node7 = new node(7);
    node* node8 = new node(8);
    node* node9 = new node(9);

    // connect the node appropriately
    node6->left_child = node5;
    node6->right_child = node7;
    node5->left_child = node2;
    node5->right_child = node1;
    node2->left_child = node3;

    node7->left_child = node4;
    node4->right_child = node8;
    node7->right_child = node9;

    // node9->right_child = node8;

    // in_order_traversal(node6);

    working_set.push_back(node6);
    bfs(node6);

    return 0;
}