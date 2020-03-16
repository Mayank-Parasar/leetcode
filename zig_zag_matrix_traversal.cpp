//
// Created by Mayank Parasar on 2020-03-15.
//

/*
Zigzag (or diagonal) traversal of Matrix
Given a 2D matrix, print all elements of the given matrix in diagonal order.
 For example, consider the following 5 X 4 input matrix.

    1     2     3     4
    5     6     7     8
    9    10    11    12
   13    14    15    16
   17    18    19    20
Diagonal printing of the above matrix is

    1
    5     2
    9     6     3
   13    10     7     4
   17    14    11     8
   18    15    12
   19    16
   20
  */

#include <iostream>
#include <vector>

using namespace std;

void print_zigzag(vector<vector<int>> mat) {
    int max_row = mat.size();
    int max_col = mat[0].size();

    int row = 0;
    int start_col = 1;
    while ( row < max_row ) {
        int curr_row = row;
        int curr_col = 0;
        while(curr_row >= 0 && curr_col < max_col) {
            cout << mat[curr_row][curr_col] << "\t";
            curr_row--;
            curr_col++;
        }
        cout << endl;
        row++;
    }
    // when we come here row == max_row
    row = max_row -1;
    while(start_col < max_col){
        int curr_col = start_col;
        while(curr_col < max_col) {
            cout << mat[row][curr_col] <<"\t";
            row--;
            curr_col++;
        }
        cout << endl;
        // resent row;
        row = max_row - 1;
        start_col++;
    }
}

int main() {

    vector<vector<int>> mat = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16},
                               {17, 18, 19, 20}};

    // print matrix
    for(auto i : mat) {
        for(auto k : i) {
            cout << k <<"\t";
        }
        cout << endl;
    }
    cout << endl;
    print_zigzag(mat);

    return 0;
}