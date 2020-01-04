//
// Created by Mayank Parasar on 2020-01-03.
//

/*
 * Given a binary tree, return all values given a certain height h.
 * Example:

    a
   / \
  b   c
 /
d
*/

#include <iostream>
#include <vector>

using namespace std;

struct node {
    char val;
    node* left;
    node* right;

    node(char val_) {
        val = val_;
        left = nullptr;
        right = nullptr;
    }
};

int level;
bool flag = false;
void in_order_traversal(node* node_, int& h) {
    if (node_ == nullptr)
        return;

    /*code for checking the depth*/
    if (level == h){
        cout << node_->val << " ";
        flag = true;
    }

    level++;
    in_order_traversal(node_->left, h);
    level--;
    // cout << node_->val;
    level++;
    in_order_traversal(node_->right, h);
    level--;
}

int main() {

    node* node_a = new node('a');
    node* node_b = new node('b');
    node* node_c = new node('c');
    node* node_d = new node('d');

    // connect them
    node_a->left = node_b;
    node_a->right = node_c;
    node_b->left = node_d;

    level = 0;
    int h = 1; // enter the height here for which you would like to get the value
    in_order_traversal(node_a, h);

    if(!flag) {
        cout << " Tree depth is lower than input depth therefore no element was found" << endl;
    }

    return 0;
}
