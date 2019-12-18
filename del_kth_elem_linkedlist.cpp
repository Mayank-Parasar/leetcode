//
// Created by Mayank Parasar on 2019-12-18.
//

/*
 * You are given a singly linked list and an integer k. Return the linked list,
 * removing the k-th last element from the list.
 * */

#include <iostream>
#include <vector>

using namespace std;

struct node {
    int val;
    node* next;

    node(int val_, node* node_ = nullptr) {
        val = val_;
        next = node_;
    }
};

void print_linked_list(node* root) {
    node* node_ = root;
    while(node_ != nullptr) {
        cout << node_->val << " ";
        node_  = node_->next;
    }
    cout << endl;
}

node* remove_last_kth_elem(node* root, int k) {
    // first calculate the size of link-list
    int size = 0;
    node* node_ = root;
    while (node_ != nullptr) {
        node_ = node_->next;
        size++;
    }
    cout << " size: " << size << endl;
    // node* nodek = nullptr;
    // kth elem from last size-k + 1 from the beginnning
    int cntr = 0;
    node_ = root;
    while(node_ != nullptr) {
        cntr++;
        if(cntr == (size - k)) {
            // next node needs to be deleted
            node* tmp_node;
            tmp_node = node_->next;
            node_->next = node_->next->next;
            delete(tmp_node);
            break; // deleted
        }
        node_ = node_->next;
    }

    return(root);
}

int main() {

    node* node1 = new node(1);
    node* node2 = new node(2);
    node* node3 = new node(3);
    node* node4 = new node(4);
    node* node5 = new node(5);
    node* node6 = new node(6);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    print_linked_list(node1);
    remove_last_kth_elem(node1, 3);
    print_linked_list(node1);

    return 0;
}