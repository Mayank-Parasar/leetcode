//
// Created by Mayank Parasar on 2020-01-20.
//

/*
 * Given a simple expression tree, consisting of basic binary operators i.e., + , – ,* and / and some integers,
 * evaluate the expression tree.
 *
    *
   / \
  +    +
 / \  / \
3  2  4  5
 * */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node {
    string info;

    node* left;
    node* right;

    node(string val) : info(val), left(nullptr), right(nullptr)
    {}
};

int eval(node* node_) {

    if(node_ != nullptr) {
        if(node_->info != "+" && node_->info != "-" &&
            node_->info != "*" && node_->info != "/") {
            return stoi(node_->info);
        }

        else {
            int A, B;
            if(node_->left != nullptr)
                A = eval(node_->left);
            if(node_->right != nullptr)
                B = eval(node_->right);


            if(node_->info == "+")
                return (A+B);
            else if(node_->info == "-")
                return (A-B);
            else if(node_->info == "*")
                return(A*B);
            else if(node_->info == "/")
                return (A/B);

        }
    }
}

int main() {

    node* node1 = new node("*");
    node* node2 = new node("+");
    node* node3 = new node("+");
    node* node4 = new node("3");
    node* node5 = new node("2");
    node* node6 = new node("4");
    node* node7 = new node("5");

    // connect them:
    node1->left = node2;
    node1->right = node3;

    node2->left = node4;
    node2->right = node5;

    node3->left = node6;
    node3->right = node7;


    cout << eval(node1);

    return 0;
}