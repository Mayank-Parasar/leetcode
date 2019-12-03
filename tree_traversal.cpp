//
// Created by Mayank Parasar on 2019-12-03.
//

#include <iostream>

using namespace std;

/* A binary tree has data, pointer to left child
 * and a pointer to right child*/
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node (int data) {
        this->data = data;
        left = right = NULL;
    }
};


/* Given a binary tree print its node accoring to the post order*/
/*left, right, root*/
void printPostorder(struct Node* node) {
    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    cout << node->data << " ";
}

/* Given a binary tree, print its nodes in inorder*/
/*left, root, right*/
void printInorder(struct Node* node) {
    if (node == NULL)
        return;

    // first recur on left child
    printInorder(node->left);

    // then print the data of node
    cout << node->data << " ";

    // now recur on the right child
    printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
/* root, left, right*/
void printPreorder(struct Node* node) {
    if (node == NULL)
        return;

    /* fiirst print data of node */
    cout << node->data << " ";

    // then recur on left child
    printPreorder(node->left);

    // now recur on right child
    printPreorder(node->right);
}

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "\n Preoder traversal of binary tree is \n";
    printPreorder(root);

    cout << "\nInoder traversal of binary tree is \n";
    printInorder(root);

    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);

    return 0;
}