//
// Created by Mayank Parasar on 2019-09-12.
//
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 */

#include <iostream>
#include <vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * l3 = new ListNode(0);
        int carry = 0;
        int sum = 0;
        int total = 0;
        ListNode * node1 = l1;
        ListNode * node2 = l2;
        int itr = 0;

        while(node1 != NULL ||
            node2 != NULL) {
            ListNode * newNode = new ListNode(0);
            // condition - 1
            if(node1 != NULL && node2 != NULL) {
                total = node1->val + node2->val + carry;
                sum = total % 10;
                newNode->val = sum;
                carry = total / 10;
            }
            // condition - 2
            if(node1 == NULL && node2 != NULL) {
                total = node2->val + carry;
                sum = total % 10;
                newNode->val = sum;
                carry = total / 10;
            }
            // condition - 3
            if(node1 != NULL && node2 == NULL) {
                total = node1->val + carry;
                sum = total % 10;
                newNode->val = sum;
                carry = total / 10;
            }
            /////////////////////////////////////
            if (node1 != NULL)
                node1 = node1->next;
            else
                node1 = NULL;

            if (node2 != NULL)
                node2 = node2->next;
            else
                node2 = NULL;
//            node2 = node2->next;
            if ((l3->val == 0) && (l3->next == NULL) &&
                    (itr == 0)) {
                l3->val = newNode->val;
            }
            else {
                // add a node at the end of l3
                // parse the l3
                ListNode * node = l3;
                while(node->next != NULL)
                    node = node->next;
                node->next = newNode;
            }
//            ListNode * node = l3;
//            while(node != NULL) {
//                cout << node->val << " ";
//                node = node->next;
//            }
            itr++;
        }
        // check the leading carry
        if (carry != 0) {
            ListNode * carryNode = new ListNode(carry);
            // add this fucking carry at the end of l3
            ListNode * node = l3;
            while(node->next != NULL)
                node = node->next;
            node->next = carryNode;
        }
        return l3;
    }
};

int main() {
    // std::cout << "Hello, World!" << std::endl;
    Solution *sol;
//    ListNode *l1(2), l2(5), l3(0);
    ListNode * l1 = new ListNode(1);
    ListNode * l2 = new ListNode(9);
//    ListNode * l3 = new ListNode(0);
//    Constructing ListNode - 1
//    ListNode * l1_elem = new ListNode(8);
//    l1->next = l1_elem;
//    ListNode * l1_elem2 = new ListNode(3);
//    l1->next->next = l1_elem2;

//    Constructing ListNode - 2
    ListNode * l2_elem = new ListNode(9);
    l2->next = l2_elem;
//    ListNode * l2_elem2 = new ListNode(4);
//    l2->next->next = l2_elem2;

    ListNode * node = l2;
//    while(node != NULL) {
//        cout << node->val << " ";
//        node = node->next;
//    }


    node = sol->addTwoNumbers(l1, l2);

    while(node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    return 0;
}