//
// Created by Mayank Parasar on 2020-03-15.
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

// Traverse the tree in the zig-zag manner:
// 6 7 5 2 1 4 9 8 10 3
#include <iostream>
#include <vector>
#include <map>
#include <deque>

using namespace std;

struct node{
    int val;
    node* left;
    node * right;

    node(int x) : val(x), left(nullptr), right(nullptr)
    {};

};

int counter = 0;

map<int, vector<int>> mymap;

void print_in_order_traversal(node* node_) {

    if(node_ == nullptr)
        return;
    else {
        print_in_order_traversal(node_->left);
        cout << node_->val << " ";
        print_in_order_traversal(node_->right);
    }

}

// deque<node*> task_queue;
// bool sense = true;
void print_zig_zag_traversal(node* node_) {

    if(node_== nullptr)
        return;

    else {
        mymap[counter].push_back(node_->val);
        counter++;
        // bf traversal
        print_zig_zag_traversal(node_->left);
        print_zig_zag_traversal(node_->right);
        counter--;
    }

}


int main() {

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

    // connect them
    node6->right = node7;
    node6->left = node5;
    node7->right = node9;
    node7->left = node4;
    node5->right = node1;
    node5->left = node2;
    node2->left = node3;
    node9->right = node8;
    node9->left = node10;

    // print_in_order_traversal(node6);
    print_zig_zag_traversal(node6);
    for(auto i : mymap) {
        cout << "level " << i.first << " : ";
        for (auto k : i.second) {
            cout << k << " ";
        }
        cout << endl;
    }
    cout << "----------" << endl;
    bool sense = false;
    int start, end;
    for(auto i : mymap) {
        if(sense) {
            start = 0;
            end = i.second.size();
        }
        else {
            start = i.second.size();
            end = 0;
        }
        // reverse sense for next itr
        sense = !sense;
        // for loop to print.
        if(start > end) {
            while(start > end) {
                cout << i.second[end] << " ";
                end++;
            }
        }
        else if(end > start) {
            while (end > start) {
                cout << i.second[end-1] << " ";
                end--;
            }
        }
    }

    return 0;
}