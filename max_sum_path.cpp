//
// Created by Mayank Parasar on 2020-04-05.
//

/*
 * Given a binary tree, find and return the largest path from root to leaf.

Here's an example and some starter code:

class Node:
  def __init__(self, value, left=None, right=None):
    self.value = value
    self.left = left
    self.right = right

def largest_path_sum(tree):
  # Fill this in.

tree = Node(1)
tree.left = Node(3)
tree.right = Node(2)
tree.right.left = Node(4)
tree.left.right = Node(5)
#    1
#  /   \
# 3     2
#  \   /
#   5 4
print(largest_path_sum(tree))
# [1, 3, 5]
*/

#include <iostream>
// #include <map>
#include <vector>

using namespace std;


struct node {
    int val;
    node* left;
    node* right;

    node(int x) : val(x) {
        left = nullptr;
        right = nullptr;
    }
};

vector<pair<int, vector<int>>> path_traversal;

void tree_traversal(node* node_, int sum, vector<int> visited_nodes) {

    if(node_ == nullptr) {
        return;
    }
    else if(node_->left == nullptr &&
            node_->right == nullptr) {
        sum += node_->val;
        visited_nodes.push_back(node_->val);
        // this is leaf node
        path_traversal.push_back(make_pair(sum, visited_nodes));
        return;
    }
    else {
        // do the traversal..
        if(node_->left != nullptr) {
            sum += node_->val;
            visited_nodes.push_back(node_->val);
            tree_traversal(node_->left, sum, visited_nodes);
            // undo change
            sum -= node_->val;
            visited_nodes.pop_back();
        }

        if(node_->right != nullptr) {
            sum += node_->val;
            visited_nodes.push_back(node_->val);
            tree_traversal(node_->right, sum, visited_nodes);
            // undo change
            sum -= node_->val;
            visited_nodes.pop_back();
        }
    }

    return;

}

int main() {

    node* node1 = new node(1);
    node* node2 = new node(2);
    node* node3 = new node(3);
    node* node4 = new node(4);
    node* node5 = new node(5);

    // connect them
    node1->left = node3;
    node1->right = node2;
    node3->right = node5;
    node2->left = node4;

    vector<int> path;
    tree_traversal(node1, 0, path);

    int max = -1;
    // find the vector with maximum sum val.
    for(auto i : path_traversal) {
        cout << i.first << ": ";
        if( (int)i.first > max) {
            max = i.first;
            path = i.second;
        }
        for(auto k : i.second) {
            cout << k << ", ";
        }
        cout << endl;
    }

    cout << "maximum sum path is:" << endl;
    for(auto i : path)
        cout << i << " ";

    return 0;
}