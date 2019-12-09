//
// Created by Mayank Parasar on 2019-12-08.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    // ctor-1
    ListNode(int x) : val(x), next(nullptr)
    {}

    // ctor-2
    ListNode(int x, ListNode* node) : val(x), next(node)
    {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *intersection = new ListNode(0);
        ListNode *nodeA = headA;
        ListNode *nodeB = headB;
        // Loop through list-A
        while(nodeA != nullptr) {

            nodeB = headB; // for every itneration restart listB
            while(nodeB != nullptr) {

                if(nodeA->val == nodeB->val) {
                    // loop here both nodes to know they are same onwards
                    // else break
                    ListNode *checkNodeA = nodeA;
                    ListNode *checkNodeB = nodeB;
                    while (checkNodeA != nullptr && checkNodeB!= nullptr) {
                        if ( checkNodeA->val == checkNodeB->val ) {
                            checkNodeA = checkNodeA->next;
                            checkNodeB = checkNodeB->next;
                        }
                        else {
                            break;
                        }
                    }
                    if (checkNodeA == nullptr && checkNodeB == nullptr)
                        return nodeA;
                }
                nodeB = nodeB->next;
            }

            nodeA = nodeA->next;
        }

            // for each element in list A loop list-B
                // if the element is found in the listB
                // return that element

            // at the end of this loop if control reaches here
            // then there is no match... put an assert
            assert(nodeA->next == nullptr &&
                nodeB->next == nullptr);
        return intersection;
    }

    void printList(ListNode *head) {
        ListNode * node = head; // starting node
        while (node != nullptr) {
            cout << node->val << " -> ";
            node = node->next;
        }
        cout << endl;
        return;
    }
};

int main() {
    Solution sol;
    // let the list-1 A = 1 -> 2 -> 3 -> 4
    ListNode *headA = new ListNode(1);
    (headA->next) = new ListNode(2);
    (headA->next->next) = new ListNode(3);
    (headA->next->next->next) = new ListNode(4);

    sol.printList(headA);

    // let the list-2 B = 6 -> 3 -> 4
    ListNode *headB = new ListNode(6);
    (headB->next) = new ListNode(3);
    (headB->next->next) = new ListNode(4);
    sol.printList(headB);

    // [4,1,8,4,5]
    // [5,0,1,8,4,5]
    ListNode *headC = new ListNode(4);
    (headC->next) = new ListNode(1);
    (headC->next->next) = new ListNode(8);
    (headC->next->next->next) = new ListNode(4);
    (headC->next->next->next->next) = new ListNode(5);

    ListNode *headD = new ListNode(5);
    (headD->next) = new ListNode(0);
    (headD->next->next) = new ListNode(1);
    (headD->next->next->next) = new ListNode(8);
    (headD->next->next->next->next) = new ListNode(4);
    (headD->next->next->next->next->next) = new ListNode(5);

    // ListNode* sol_ = sol.getIntersectionNode(headA, headB);
    ListNode* sol_ = sol.getIntersectionNode(headC, headD);
    cout << sol_->val << " " << sol_->next << endl;

    return 0;
}