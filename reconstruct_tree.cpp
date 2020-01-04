//
// Created by Mayank Parasar on 2020-01-04.
//

/*
 * You are given the preorder and inorder traversals of a binary tree in the form of arrays.
 * Write a function that reconstructs the tree represented by these traversals.

Example:
Preorder: [a, b, d, e, c, f, g]
Inorder: [d, b, e, a, f, c, g]

The tree that should be constructed from these traversals is:

    a
   / \
  b   c
 / \ / \
d  e f  g
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct node {
    char val;
    node* left;
    node* right;

    node(int x) : val(x), left(nullptr), right(nullptr)
    {}
};

// Recursive function to perform inorder traversal of a binary tree
void inorderTraversal(node* root)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->val << ' ';
    inorderTraversal(root->right);
}

node* construct(int start, int end, vector<char>& preorder,
                int &pIndex, map<char, int>& map) {
    if(start > end)
        return nullptr;

    node* root = new node(preorder[pIndex++]);

    int index = map[root->val];

    // recursively construct the left subtree
    root->left = construct(start, index - 1, preorder, pIndex, map);

    // recursively construct the right subtree
    root->right = construct(index + 1, end, preorder, pIndex, map);

    // return current node
    return root;
}

node* reconstruct(vector<char>& inorder, vector<char>& preorder) {

    int n = inorder.size();

    map<char, int> map_;
    for (int i=0; i < n; i++)
        map_[inorder[i]] = i;

    int pIndex = 0;

    return construct(0, n-1, preorder, pIndex, map_);
}

int main() {

    vector<char> inorder = {'d', 'b', 'e', 'a', 'f', 'c', 'g'};
    vector<char> preorder = {'a', 'b', 'd', 'e', 'c', 'f', 'g'};

    node* root = reconstruct(inorder, preorder);

    // traverse the constructed tree

    cout << "Inorder: " << endl;
    inorderTraversal(root);

    return 0;
}