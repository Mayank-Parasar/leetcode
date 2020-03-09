//
// Created by Mayank Parasar on 2020-03-09.
//

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

#include<iostream>
#include<vector>
#include<map>

using namespace std;

map<int, vector<int>> mymap;

struct node{
    int val;
    node* left;
    node* right;

    node(int x) : val(x), left(nullptr), right(nullptr)
    { };
};

int counter = 0;

void in_order_traversal(node* node_) {
    if(node_ == nullptr)
        return;
    else {
        // put the node val and counter val in the map
        mymap[counter].push_back(node_->val);
        counter--;
        in_order_traversal(node_->left);
        counter++;
        counter++;
        in_order_traversal(node_->right);
        counter--;
    }
}


int main() {

    node* node6 = new node(6);
    node* node5 = new node(5);
    node* node7 = new node(7);
    node* node2 = new node(2);
    node* node1 = new node(1);
    node* node4 = new node(4);
    node* node9 = new node(9);
    node* node3 = new node(3);
    node* node10 = new node(10);
    node* node8 = new node(8);

    // connect them:
    node6->left = node5;
    node6->right = node7;
    node5->left = node2;
    node5->right = node1;
    node7->left = node4;
    node7->right = node9;
    node2->left = node3;
    node9->left = node10;
    node9->right = node8;
    ///////////////////
    in_order_traversal(node6);

    for(auto i : mymap) {
        cout << i.first << " : ";
        for(int ii = 0; ii <=i.second.size()-1; ii++) {
            cout << i.second[ii] << " ";
        }
        cout << endl;
    }

    return 0;
}