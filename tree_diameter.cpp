//
// Created by Mayank Parasar on 2020-01-08.
//

/*Given a binary tree find its diameter
 *
 *
    a
   / \
  b   c
 / \ / \
d  e f  g
         \
          h
           \
            i
             \
              j
               \
                k
 *                  6
 *                /  \
 *              5      7
 *             / \    / \
 *            2   1  4    9
 *           /             \
 *          3              8
 */

#include <iostream>
#include <vector>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;

    node(int x) : val(x), left(nullptr), right(nullptr)
    {}
};

int height(node* node_) {
    if(node_ == nullptr)
        return 0;

    return( 1 + max(height(node_->left), height(node_->right)));
}

int tree_diameter(node* node_) {
    if(node_ == nullptr)
        return 0;

    int left_height = height(node_->left);
    int right_height = height(node_->right);

    int left_diameter = tree_diameter(node_->left);
    int right_diameter = tree_diameter(node_->right);

    return max(1 + left_height + right_height, max(left_diameter, right_diameter));
}

int main() {

    vector<int> inorder = {3, 2, 5, 1, 6, 4, 7, 9, 8};

    node* node1 = new node(1);
    node* node2 = new node(2);
    node* node3 = new node(3);
    node* node4 = new node(4);
    node* node5 = new node(5);
    node* node6 = new node(6);
    node* node7 = new node(7);
    node* node8 = new node(8);
    node* node9 = new node(9);

    // connect them:
    node6->left = node5;
    node6->right = node7;
    node5->left = node2;
    node5->right = node1;
    node2->left = node3;

    node7->left = node4;
    node7->right = node9;
    node9->right = node8;

    cout << "diameter of given binary tree is: " << tree_diameter(node6);

    return 0;
}