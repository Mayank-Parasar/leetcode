//
// Created by Mayank Parasar on 2020-04-06.
//

/*
 * str = "aaaabbbbbdddffg"
 *
 * Huffman-tree of above string is as follows:
                      ┌────┐
                      │ 15 │
                      └────┘
                         ▲
                         │
             ┌───────────┴──────────┐
             │                      │
             │                      │
             │                   ┌────┐
          ┌────┐                 │ 6  │
          │ 9  │                 └────┘
          └────┘                    ▲
             ▲                      ├─────────┐
             │                      │         │
             │                      │         │
             │                      │      ┌────┐
             │                      │      │ 3  │
             │                ┌─────┘      └────┘
      ┌──────┴─────┐          │               ▲
      │            │          │               │
      │            │          │               │
      │            │          │         ┌─────┴───────┐
      │            │          │         │             │
      │            │          │         │             │
      │            │          │         │             │
    ┌────┐      ┌────┐     ┌────┐    ┌────┐        ┌────┐
    │ 4  │      │ 5  │     │ 3  │    │ 2  │        │ 1  │  <== freq of each character
    └────┘      └────┘     └────┘    └────┘        └────┘
    ┌────┐      ┌────┐     ┌────┐    ┌────┐        ┌────┐
    │ a  │      │ b  │     │ c  │    │ d  │        │ e  │
    └────┘      └────┘     └────┘    └────┘        └────┘
 * */

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

map<char, int> char_freq;

struct node {
    int freq;
    node* left;
    node* right;

    node(int x) : freq(x) {
        left = nullptr;
        right = nullptr;
    }
};

vector<node*> mysort(vector<node*>& vec) {
    bool swap_ = true;
    while(swap_) {
        swap_ = false;
        for(int ii = 0; ii < vec.size()-1; ii++) {
            if(vec[ii]->freq < vec[ii+1]->freq) {
                swap(vec[ii], vec[ii+1]);
                swap_ = true;
            }
        }
    }

    return vec;
}

struct node_info{
    node* nde;
    int level;
};

std::vector<node_info> traversal;
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

void print_traversal() {
    int ii;
    for(ii=0; ii < traversal.size()-1; ii++) {
        cout << traversal[ii].nde->freq << " ";
        if(traversal[ii].level < traversal[ii+1].level)
            cout << endl;
    }
    cout << traversal[ii].nde->freq << " ";
}

int main() {

    string str = "aaaabbbbbdddffg";

    for(int ii = 0; ii < str.length(); ii++) {
        char_freq[str[ii]]++;  // '[]' operrator allocates
    }

    vector<node*> node_vec;
    for(auto i : char_freq) {
        cout << i.first << ": " << i.second << endl;
        node_vec.push_back(new node(i.second));
    }
    // sort the vector as per value of the freq.
    for (auto i : node_vec) {
        cout << i->freq << " ";
    }
    cout << endl;
    node_vec = mysort(node_vec);

    for (auto i : node_vec) {
        cout << i->freq << " ";
    }
    cout << endl;
    node* node1;
    while(node_vec.size() > 1 ) {
        node1 = new node(node_vec[node_vec.size() - 2]->freq + node_vec[node_vec.size() - 1]->freq);
        node1->right = node_vec.back();
        node_vec.pop_back();
        node1->left = node_vec.back();
        node_vec.pop_back();
        node_vec.push_back(node1);
        node_vec = mysort(node_vec);
        for (auto i : node_vec) {
            cout << i->freq << " ";
        }
        cout << endl;
    }

    // node1 is now the root of this tree...
    // a level-order traversal of this tree
    level_order_traversal(node1);
    print_traversal();

    return 0;
}