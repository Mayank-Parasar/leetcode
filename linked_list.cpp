//
// Created by Mayank Parasar on 2019-12-02.
//

#include <iostream>

using namespace std;

struct node {
    int value;
    node* next;

    node(int val, node* ptr= nullptr)
        : value(val), next(ptr)
    {};

    void add_elem_last(node* list, node* elem) {
        int size_of_list = 0;
        // traverse the linked-list till the end
        // then add this ptr at the end
        while (list->next != nullptr) {
            list = list->next;
            size_of_list++;
        }
        list->next = elem;
        elem->next = nullptr;
        cout << " size of the list is: " << ++size_of_list << endl;
        return;
    }
};

ostream & operator << (ostream &out, node* n1) {
    out << n1->value << endl;
    // cout << *(n1->next);
    if (n1->next == nullptr)
        out << "This node is the last node in link-list" << endl;
    else
        out << "This node points to next node, with value: " \
            << n1->next->value << endl;

    return out;
}

int main(int argc, char const *argv[]) {
    /* code */

    node a(1, nullptr);
    cout << a.value << endl;
    node* b = new node(2, &a); // b is the head of this list
    cout << b << endl;
    node* c = new node(3);
    b->add_elem_last(b, c);
    return 0;
}