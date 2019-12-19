//
// Created by Mayank Parasar on 2019-12-18.
//

/*
 * Given a linked list of integers, remove all consecutive nodes that sum up to 0.

Example:
Input: 10 -> 5 -> -3 -> -3 -> 1 -> 4 -> -4
Output: 10
 */

#include <iostream>
#include <vector>

using namespace std;

struct node {
    int val;
    node* next;

    node(int val_) {
        val = val_;
        next = nullptr;
    }
};

void print_linked_list(node* root ) {
    node* nd = root;
    while (nd != nullptr) {
        cout << nd->val << " ";
        nd = nd->next;
    }
    return;
}

void fix_linked_list(node* root, node* node1, node* node2) {
    node* nd = root;
    bool start = false;
    bool stop = false;
    while(nd != nullptr) {
        node* tmp;
        tmp = nd;

        if(nd == node2) {
            start= false;
            stop = true;
            nd = nd->next;
        }
        else if(start == true &&
            stop == false) {
            nd = nd->next;
            delete tmp;
        }
        else if(nd == node1) {
            start = true;
            // make the previous node's next nullptr
            nd = nd->next;
            delete tmp;
        }
        else if(nd->next == node1) {
            tmp = nd->next;
            nd->next = nullptr;
            nd = tmp;
        }
        else
            nd = nd->next;
    }
    // fix the linked list
    if(root == nullptr) {
        root = node2;
        return;
    }
    else {
        nd = root;
        while(nd->next != nullptr) {
            nd = nd->next;
        }
        nd->next = node2;
        return;
    }
}

void removeConsecutiveSumTo0(node* root) {
    repeat:
    node* nd = root;
    int running_sum = 0;
    bool flag;
    // strt from the back to remove the node
    while(nd != nullptr) {
        node* nd2 = nd;
        flag = false;
        while(nd2 != nullptr) {
            running_sum += nd2->val;
            if(running_sum == 0) {
                // delete uptill nd
                // nd = nd2->next;
                fix_linked_list(root, nd, nd2->next);
                // flag = true;
                // break;
                // NOTE: in general goto statement are bad
                // to use in the code... I will rervisit to
                // fix it.. for now this is working...
                goto repeat;
            }
            nd2 = nd2->next;
        }
        if(flag == false) {
            nd = nd->next;
        }
        // reset the running_sum
        running_sum = 0;
    }



    return;
}


int main() {

    node* node1 = new node(10);
    node* node2 = new node(5);
    node* node3 = new node(3);
    node* node4 = new node(-3);
    node* node5 = new node(1);
    node* node6 = new node(4);
    node* node7 = new node(-4);

    // connect them
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;

    print_linked_list(node1);
    cout << endl;
    removeConsecutiveSumTo0(node1);
    print_linked_list(node1);

    return 0;
}