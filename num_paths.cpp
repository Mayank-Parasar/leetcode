//
// Created by Mayank Parasar on 2020-03-27.
//

/*
A maze is a matrix where each cell can either be a 0 or 1. A 0 represents that the cell is empty,
 and a 1 represents a wall that cannot be walked through. You can also only travel either right or down.

Given a nxm matrix, find the number of ways someone can go from the top left corner to the bottom right corner.
 You can assume the two corners will always be 0.

Example:
Input: [[0, 1, 0], [0, 0, 1], [0, 0, 0]]
# 0 1 0
# 0 0 1
# 0 0 0
Output: 2
*/

#include <iostream>
#include <vector>

using namespace std;


int counter = 0;
void num_paths(vector<vector<int>> mat, int row, int col) {
    // cout << "row: " << row << ", col: " << col << ", counter: " << counter << endl;
    // do a DFS on the mat.. starting from 0,0.
    int total_rows = mat.size();
    int total_cols = mat[0].size();
    if((row == total_rows-1) &&
       (col == total_cols-1)) {
        counter++;
        return;
    }
    else if(mat[row][col] == 1) {
        return;
    }
    else {
        // first traverse row-wise
        if(row < total_rows-1)
            num_paths(mat, row+1, col);
        // then column-wise
        if(col < total_cols-1)
            num_paths(mat, row, col+1);
    }
    return;
}


int main() {

    vector<vector<int>> mat = {{0, 1, 0},
                               {0, 0, 1},
                               {0, 0, 0}};

    num_paths(mat, 0, 0);

    cout << "number of paths: " << counter << endl;

    return 0;
}