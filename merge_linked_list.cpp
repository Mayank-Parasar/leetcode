//
// Created by Mayank Parasar on 2019-12-25.
//

// This is the linked-list version of the merge.cpp

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int val_) {
        val = val_;
        next = nullptr;
    }
};

Node* merge(Node* node1, Node* node2) {

    if(node1 == nullptr &&
        node2 == nullptr)
        return nullptr;

    // int val = node1->val > node2->val ? node1->val : node2->val;
    // Node* result = new Node(val);
    Node* result = nullptr;
    Node* result_head = nullptr;

    while(node1 != nullptr ||
        node2 != nullptr) {
        if(node1 == nullptr &&
            node2 != nullptr) {
            if (result == nullptr) {
                result = new Node(node2->val);
                result_head = result;
            }
            else {
                result->next = new Node(node2->val);
                result = result->next;
            }
            node2 = node2->next;
        }
        else if (node1 != nullptr &&
                node2 == nullptr) {
            if (result == nullptr) {
                result = new Node(node1->val);
                result_head = result;
            }
            else {
                result->next = new Node(node1->val);
                result = result->next;
            }
            node1 = node1->next;
        }
        else if(node1->val < node2->val) {
            if (result == nullptr) {
                result = new Node(node1->val);
                result_head = result;
            }
            else {
                result->next = new Node(node1->val);
                result = result->next;
            }
            node1 = node1->next;
        }
        else if (node1->val > node2->val) {
            if (result == nullptr) {
                result = new Node(node2->val);
                result_head = result;
            }
            else {
                result->next = new Node(node2->val);
                result = result->next;
            }
            node2 = node2->next;
        }
        else
            assert(0);
    }

    return result_head;
}

int main() {

    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);

    // conect them
    node1->next = node3;
    node3->next = node5;

    node2->next = node4;
    node4->next = node6;

    Node* result = merge(node1, node2);

    // print the merged linked-list
    while(result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}