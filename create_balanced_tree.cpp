//
// Created by Mayank Parasar on 2020-03-08.
//


/*
Given a sorted list, create a height balanced binary search tree,
meaning the height differences of each node can only differ by at most 1.
tree = create_height_balanced_bst([1, 2, 3, 4, 5, 6, 7, 8])
*/


#include<iostream>
#include<vector>

using namespace std;


struct node{
    int val;
    node * left;
    node * right;
    // ctor
    node(int x): val(x), left(nullptr), right(nullptr)
    { }
};


node* make_tree(vector<int>& v, int start_indx, int end_indx) {

    int mid = (start_indx + end_indx) / 2;
    node * node_ = nullptr;
    if(mid > end_indx || mid < start_indx || start_indx > end_indx)
        return node_;
    else {
        node_ = new node(v[mid]);
        node_->left = make_tree(v, start_indx, mid-1);
        node_->right = make_tree(v, mid+1, end_indx);
    }

    return node_;

}

// in-ordeer tree traversal
void in_order_traversal(node* node_) {
	if(node_ == nullptr)
		return;
	else {
		in_order_traversal(node_->left);
		cout << node_->val;
		in_order_traversal(node_->right);
	}
}

int main() {

    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8};

    node* root = make_tree(v1, 0, v1.size()-1);
    in_order_traversal(root);

    return 0;
}