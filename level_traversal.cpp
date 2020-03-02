//
// Created by Mayank Parasar on 2020-03-01.
//

/*
 * You are given a tree, and your job is to print it level-by-level with linebreaks.

    a
   / \
  b   c
 / \ / \
d  e f  g

The output should be
a
bc
defg
 */

#include <iostream>
#include <vector>


using namespace std;

struct node {
    char val;
    node* left;
    node* right;

    node(char v) : val(v), left(nullptr), right(nullptr)
    { }
};

struct node_info{
    node* nde;
    int level;
};

std::vector<node_info> traversal;
// print level order traversal of the tree
// keep track of the level as you are traversing the tree...
void level_order_traversal(node* node_) {
    int level = 0;
    traversal.push_back({node_, level});
    int ii = 0;
    while (ii != traversal.size()){
        node * left_child = nullptr;
        node * right_child = nullptr;
        int next_level = traversal[ii].level + 1;
        if(traversal[ii].nde->left != nullptr) {
            left_child = traversal[ii].nde->left;
        }

        if(traversal[ii].nde->right != nullptr) {
            right_child = traversal[ii].nde->right;
        }

        if(left_child != nullptr)
            traversal.push_back({left_child, next_level});
        if(right_child != nullptr)
            traversal.push_back({right_child, next_level});

        ii++;
    }
}

void print_traversal(const std::vector<node_info>& traversal) {
    int ii;
    for(ii=0; ii < traversal.size()-1; ii++) {
        cout << traversal[ii].nde->val;
        if(traversal[ii].level < traversal[ii+1].level)
            cout << endl;
    }
    cout << traversal[ii].nde->val;
}

int main() {

    node* node_a = new node('a');
    node* node_b = new node('b');
    node* node_c = new node('c');
    node* node_d = new node('d');
    node* node_e = new node('e');
    node* node_f = new node('f');
    node* node_g = new node('g');

    // connect them
    node_a->left = node_b;
    node_a->right = node_c;
    node_b->left = node_d;
    node_b->right = node_e;
    node_c->left = node_f;
    node_c->right = node_g;

    level_order_traversal(node_a);
    print_traversal(traversal);

    return 0;
}