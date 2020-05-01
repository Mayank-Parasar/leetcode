//
// Created by Mayank Parasar on 2020-05-01.
//

/*
 * Given a binary tree, find all duplicate subtrees (subtrees with the same value and same structure)
 * and return them as a list of list [subtree1, subtree2, ...] where subtree1 is a duplicate of subtree2 etc.
# Looks like
#     1
#    / \
#   2   2
#  /   /
# 3   3

print(dup_trees(n1))
# [[(3), (3)], [(2, (3)), (2, (3))]]
# There are two duplicate trees
#
#     2
#    /
#   3
# and just the leaf
#
# 3
 * */
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix;

struct node{
    int val;
    node* left;
    node* right;
    node(int x): val(x), left(nullptr), right(nullptr)
    { }
};

vector<int> in_order_traversal(node* node_, vector<int>& vec) {

    if(node_ == nullptr) {
        return vec;
    }
    else {
        in_order_traversal(node_->left, vec);
        vec.push_back(node_->val);
        in_order_traversal(node_->right, vec);
    }

    return vec;
}

// populate matrix
void populate_matrix(node* node_) {
    if(node_ == nullptr) {
        return;
    }
    else {
        vector<int> tmp;
        populate_matrix(node_->left);
        matrix.push_back(in_order_traversal(node_, tmp));
        populate_matrix(node_->right);
    }
}

bool compare_vec(vector<int> vec1, vector<int> vec2) {

    if(vec1.size() != vec2.size())
        return false;
    else {
        for(int ii =0; ii < vec1.size(); ii++)
            if(vec1[ii] != vec2[ii])
                return false;
            else
                continue;
    }

    return true;
}

vector<pair<int, vector<vector<int>>>> matching_trees;

void populate_matching_trees() {
    vector<int> added_idxs;
    for(int ii=0; ii< matrix.size(); ii++) {
        vector<vector<int>> mat;
        // if ii is present in added index then  go to next indx
        bool skip = false;
        for(auto k : added_idxs) {
            if (ii == k)
                skip = true;
        }
        if (skip)
            continue;
        mat.push_back(matrix[ii]);
        for(int jj = ii+1; jj < matrix.size(); jj++) {
            if(compare_vec(matrix[ii], matrix[jj])) {
                mat.push_back(matrix[jj]);
                added_idxs.push_back(jj);
            }
        }
        matching_trees.push_back(make_pair(ii, mat));
    }
}

int main() {

    node* node1 = new node(1);
    node* node2 = new node(2);
    node* node3 = new node(2);
    node* node4 = new node(3);
    node* node5 = new node(3);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node3->left = node5;
    vector<int> tmp;
    vector<int> result = in_order_traversal(node1, tmp);

//    for(auto i : result)
//        cout << i << " ";

    populate_matrix(node1);
    for(auto i : matrix) {
        for(auto k : i) {
            cout << k << " ";
        }
        cout << endl;
    }
    populate_matching_trees();
    cout << "Mating trees are" << endl;

    for(auto i : matching_trees) {
        if (i.second.size() == 1) {
            continue;
        }
        else {
            cout << i.first << ":" << endl;
        }

        for(auto j : i.second) {
            for(auto k : j) {
                cout << k << " ";
            }
            cout << endl;
        }
    }


    return 0;
}
