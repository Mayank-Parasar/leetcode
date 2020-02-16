//
// Created by Mayank Parasar on 2020-02-10.
//

/*delete a node*/

#include<iostream>
#include<vector>

using namespace std;

struct node {
    int val;

    node* next;

    node(int x) : val(x), next(nullptr)
    {}
};


void print_ll(node* node_) {

    while(node_ != nullptr) {
        cout << node_->val << " ";
        node_ = node_->next;
    }

    return;
}

void del_node(node* root, node* node_) {
    if(node_ == root) {
        root = root->next;
        delete(node_);
    }
    else {
        node* node_tmp = root;

        while(node_tmp->next != node_) {
            node_tmp = node_tmp->next;
        }

        node_tmp->next = node_->next;
        delete(node_);

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

    print_ll(node1);
    cout << endl;

    del_node(node1, node3);
    print_ll(node1);



    return 0;
}