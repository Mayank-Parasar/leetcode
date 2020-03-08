/*
Given a directed graph, reverse the directed graph so all directed edges are reversed.

Example:
Input:
A -> B, B -> C, A ->C

Output:
B->A, C -> B, C -> A
*/

#include<iostream>

using namespace std;

struct node {
    int val;
    node *next;

    node(int x) : val(x), next(nullptr)
    { }
};

int level = 0;
node* reverse_linked_list(node* node_) {
    if(node_->next == nullptr)
        return node_;
    else {
        level++;
        node* start_node = reverse_linked_list(node_->next);
        level--;
        start_node->next = node_;
        if(level == 0)
            node_->next = nullptr;
        return node_;
    }
}

void parse_linked_list(node* root) {
    node * node_ = root;
    while(node_ != nullptr) {
        cout << node_->val;
        node_ = node_->next;
    }

    return;
}

int main() {

    node* node1 = new node(1);
    node* node2 = new node(2);
    node* node3 = new node(3);
    node* node4 = new node(4);

    // connect them
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    parse_linked_list(node1);

    reverse_linked_list(node1);
    cout << endl;

    parse_linked_list(node4);


    return 0;
}