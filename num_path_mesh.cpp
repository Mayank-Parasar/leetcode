//
// Created by Mayank Parasar on 2019-12-09.
//

#include <iostream>
#include <vector>

using namespace std;

// global variable
int paths = 0;

struct ListNode {
    int index;
    ListNode *down;
    ListNode *right;
    bool visited;

    // ctor-1
    ListNode(int x) : index(x), right(nullptr), down(nullptr)
    {
        visited = false;
    }

    // ctor-2
    ListNode(int x, ListNode* right_, ListNode* down_) : index(x), right(right_), down(down_)
    {
        visited = false;
    }
};

void printList(ListNode *head) {
    ListNode * node = head; // starting node
    // while (node != nullptr) {
    if(node != nullptr) {
        cout << node->index << " -> ";
        printList(node->right);
        printList(node->down);
    }
    else {
        return;
    }
    // }
    if (node->right == nullptr &&
        node->down == nullptr) {
        cout << endl;
        paths++;
    }
    return;
}

int recurse_mesh(int dim1, int dim2) {

    if(dim1 == 1)
        return (++paths);

    if(dim2 == 1)
        return (++paths);

    // else resurse this mesh in both dimensions
    ++paths; // <--inc the path then recurse in one dimention
    recurse_mesh(--dim1, dim2);

    ++paths; // <--inc the path then recurse in one dimention
    recurse_mesh(dim1, --dim2);

    return paths;
}


int main() {
    int row, col;
    row = 2; // modify this to set the generic row of your mesh
    col = 3; // modify this to set the generic col of your mesh
    // cout << recurse_mesh(row, col);
    vector<vector<ListNode*>> mesh(row);
    for(int r=0; r < row; r++) {
        mesh[r].resize(col);
    }
    // generate a tree based on the
    // row and cols
    for(int r=0; r < row; r++) {
        for(int c=0; c < col; c++) {
            mesh[r][c] = new ListNode(row*r + c);
        }
    }

    // connect them appropriately
    for(int r=0; r < row; r++) {
        for(int c=0; c < col; c++) {
            // connect the right links
            if ( c + 1 < col )
                mesh[r][c]->right = mesh[r][c+1];
            // connect the down links
            if ( r+1 < row)
                mesh[r][c]->down = mesh[r+1][c];
        }
    }

    printList(mesh[0][0]); // this function will do DFS and update the num of paths
    cout << "number of paths from node-0 to last-node:  "<< paths << endl;

    return 0;
}
