//
// Created by Mayank Parasar on 2020-01-30.
//

/*
 * A k-ary tree is a tree with k-children, and a tree is symmetrical
 * if the data of the left side of the tree is the same as the right side of the tree.

Here's an example of a symmetrical k-ary tree.
        4
     /     \
    3        3
  / | \    / | \
9   4  1  1  4  9
Given a k-ary tree, figure out if the tree is symmetrical.
 *
 */


#include <iostream>
#include <vector>

using namespace std;

struct node {
    int val;

    vector<node*> child;

    node(int x) : val(x)
    {}

};

//

bool is_equal(node* left, node* right) {  // this is the recursive function

    // base condition goes here...
    if(left == nullptr && right == nullptr) {
        return true;
    }
    else if(left != nullptr && right == nullptr) {
        return false;
    }
    else if(left == nullptr && right != nullptr) {
        return false;
    }
    else if( left->child.size() != right->child.size()) {
        return false;
    }
    // traverse the children of left from idx 0
    // traverse the children of right from idx size-1
    // recursively call this function
    int start, end;
    for(start=0, end = (right->child.size() - 1); ((end >= 0) && (start <= left->child.size() - 1));
            end--, start++) {
        is_equal(left->child[start], right->child[end]);
    }

    // base condition geos here...
    if(left->val == right->val) {
        return true;
    }
    else if(left->val != right->val) {
        return false;
    }

}

bool is_symmetric(node* node_) {  // this is the driver function...
    // do a breath first search on child

    // traverse the vector from both sides;
    int start, end;
    for(start = 0, end = (node_->child.size() - 1);
        end > start; start++, end--) {
        if(is_equal(node_->child[start], node_->child[end])) {
            continue;
        }
        else {
            return false;
        }
    }
    // all the children of current node exhausted...
    // go to next
    return true;
}

int main() {

    node *node1 = new node(4);
    node *node2 = new node(3);
    node *node3 = new node(3);
    node *node4 = new node(9);
    node *node5 = new node(4);
    node *node6 = new node(1);
    node *node7 = new node(1);
    node *node8 = new node(4);
    node *node9 = new node(9);

    node1->child.push_back(node2);
    node1->child.push_back(node3);

    node2->child.push_back(node4);
    node2->child.push_back(node5);
    node2->child.push_back(node6);

    node3->child.push_back(node7);
    node3->child.push_back(node8);
    node3->child.push_back(node9);

    cout << boolalpha;

    cout << is_symmetric(node1);

    return 0;
}