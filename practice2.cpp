// insert in a linked list at a given posiiton

#include<iostream>
#include<vector>

using namespace std;

struct node{
    int val;
    node* next;

    node(int x) : val(x), next(nullptr)
    {};
};

void insert_node(node* root, node* node_) {
    node* node_itr = root;

    while(node_itr->next != nullptr ) {
        if(node_itr->next->val < node_->val) {
            node_itr = node_itr->next;
        }
        else {
            break; // this is the place where node_ should be node_itr->next.
        }
    }

    node_->next = node_itr->next;
    node_itr->next = node_;

    return;

}


node* delete_node(node* root, node* n4) {
    node* node_itr = root;

    // if n4 == root
    if(n4 == root) {
        root = root->next;
        delete(n4);
        return (root);
    }

    while(node_itr->next != nullptr) {
        if(node_itr->next == n4){
            break;
        }
        else{
            node_itr = node_itr->next;
            continue;
        }
    }


    node_itr->next = node_itr->next->next;
    delete(n4);


    return (root);
}

void traverse_ll(node* root) {
    node* node_itr = root;

    while(node_itr != nullptr) {
        cout<< node_itr->val << " ";
        node_itr = node_itr->next;
    }

    return;
}


int main() {

    node* n1 = new node(1);
    node* n2 = new node(2);
    node* n3 = new node(3);
    node* n5 = new node(5);

    // connect them,
    n1->next = n2;
    n2->next = n3;
    n3->next = n5;

    // insert node n4 at 4th poisiton.

    node* n4 = new node(4);

    traverse_ll(n1);
    cout << endl;

    insert_node(n1, n4);
    cout << endl;

    traverse_ll(n1);

    delete_node(n1, n4);
    cout << endl;
    traverse_ll(n1);
    return 0;
}