/*
Given a binary tree and a given node value, return all of the node's cousins.
 Two nodes are considered cousins if they are on the same level of the tree with different parents.
 You can assume that all nodes will have their own unique value.


#     1
#    / \
#   2   3
#  / \   \
# 4   6   5
root = Node(1)
root.left = Node(2)
root.left.left = Node(4)
root.left.right = Node(6)
root.right = Node(3)
root.right.right = Node(5)

print Solution().list_cousins(root, 5)
# [4, 6]
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;

    node(int x) : val(x), left(nullptr), right(nullptr)
    { };
    /*It is assumed that all the nodes have their unique value*/
};

map<int/*level*/, vector<int>/*nodes at that level*/> mymap;
int counter = 0;
int level_requested;

void in_order_traversal(node* node_) {
    if(node_ == nullptr)
        return;
    else {
        if(node_->val == 5) {
            level_requested = counter;
        }
        mymap[counter].push_back(node_->val);
        // if you are going a level down then increment the counter
        counter++;
        in_order_traversal(node_->left);
        counter--;
        counter++;
        in_order_traversal(node_->right);
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

    // connect them
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node6;

    node3->right = node5;

    in_order_traversal(node1);

    vector<int> answer;

    for(auto i : mymap) {
        // cout << i.first << " : ";
        for(auto k : i.second) {
            if(i.first == level_requested &&
               k != 5)
                answer.push_back(k);
            // cout << k << " ";
        }
        // cout << endl;
    }

    for(auto i : answer)
        cout << i << " ";

    return 0;
}